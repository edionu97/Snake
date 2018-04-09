#include "rightCornerWindow.h"

void small::paintEvent(QPaintEvent * p){

	QPainter painter{ this };

	if (hidden) return;

	static std::vector<Qt::GlobalColor> vec{
		Qt::green,Qt::darkCyan,Qt::darkGray,Qt::darkGreen,Qt::darkMagenta,Qt::darkYellow,Qt::white
	};

	static std::mt19937 t{ static_cast <unsigned int> (std::chrono::steady_clock::now().time_since_epoch().count()) };

	std::uniform_int_distribution <int>d(0, vec.size() - 1);


	painter.fillRect(0, 0, width(), height(), QBrush{ vec[d(t)] });

	painter.setPen(Qt::black);

	painter.drawText(width() / 2 - s.size() * 4, height() / 2, QString{ s.data() });
}

small::small(){
	t.setInterval(200); setMaximumHeight(WINDOW /2);

	QObject::connect(&t, &QTimer::timeout, [&]() {
		repaint();
	});

	hide();
}

void small::start(){
	t.start();
}

void small::stop(){
	t.stop(); hidden = true;
}

