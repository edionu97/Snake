#include "control.h"

void controlWindow::paintEvent(QPaintEvent * p){
	QPainter painter{ this };

	painter.drawRect(0, 0, width() -1, height()-1);
}

void controlWindow::construct() {
	QGridLayout * lay = new QGridLayout{ this };

	up = new QPushButton{ "&W" };
	down = new QPushButton{ "&S" };
	left = new QPushButton{ "&A" };
	right = new QPushButton{ "&D" };

	lay->addWidget(up, 0, 1), lay->addWidget(left, 1, 0), lay->addWidget(right, 1, 2), lay->addWidget(down, 2, 1);
}

void controlWindow::connect() {

	QObject::connect(up, &QPushButton::clicked, [&]() {
		window.goUp();
	});

	QObject::connect(down, &QPushButton::clicked, [&]() {
		window.goDown();
	});

	QObject::connect(right, &QPushButton::clicked, [&]() {
		window.goRight();
	});

	QObject::connect(left, &QPushButton::clicked, [&]() {
		window.goLeft();
	});
}

controlWindow::controlWindow(da & window) : window{ window } {
	construct(); connect();
}
