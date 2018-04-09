#include "controler.h"

void controler::connect() {

	QObject::connect(&t, &QTimer::timeout, [&]() {
		window.repaint();
	});

	QObject::connect(&timerGift, &QTimer::timeout, [&]() {
		timerGift.setInterval(getTimerInterval());
		hideTimer.start();
		emit spawn();
	});

	QObject::connect(&hideTimer, &QTimer::timeout, [&]() {
		emit hideWindow();
	});

	QObject::connect(&window, SIGNAL(gameOver()), this, SLOT(stopGame()));

	QObject::connect(this, SIGNAL(stopRepaintings()), &window, SLOT(noRepaintings()));

	QObject::connect(&window, SIGNAL(scoreHasChanged(int)), &score, SLOT(modifyScore(int)));

	QObject::connect(this, SIGNAL(spawn()), &window, SLOT(spawnGift()));

	QObject::connect(this, SIGNAL(hideWindow()), &window, SLOT(timeToHide()));

	QObject::connect(&window, SIGNAL(hiden()), this, SLOT(stopHider()));

	QObject::connect(&window, SIGNAL(startWindow(int, const string&)), &smallWindow, SLOT(startRepainting(int, const string&)));

	QObject::connect(&window, SIGNAL(stopWindow()), &smallWindow, SLOT(stopRepainting()));

	QObject::connect(&window, SIGNAL(modifySpeedU()), this, SLOT(speedUp()));

	QObject::connect(&window, SIGNAL(modifySpeedD()), this, SLOT(speedDown()));
}

void controler::move() {
	t.start(); connect();
}

void controler::assemble() {

	QGridLayout *lay = new QGridLayout{ this };
	lay->addWidget(&window, 0, 1), lay->addWidget(&movement, 1, 0), lay->addWidget(&score, 0, 0), lay->addWidget(&smallWindow, 1, 1);
	smallWindow.start();
}

int controler::getTimerInterval() const {
	
	static mt19937 t{ static_cast <unsigned int> (std::chrono::steady_clock::now().time_since_epoch().count()) };
	
	static uniform_int_distribution < int > d(MIN_HIDE, MAX_HIDE);

	return d(t);
}

controler::controler(da & window, scoreWindow & score, small& s) : window{ window }, movement{ window }, score{ score }, smallWindow{ s } {
	setWindowTitle("ANOTHER KIND OF SNAKE"),t.setInterval(SNAKE_SPEED), window.addRect();

	assemble(); setMaximumSize(window.width(), window.height());

	timerGift.setInterval(getTimerInterval()), hideTimer.setInterval(HIDE_TIME);

	timerGift.start();
}

void controler::run() {
	show(), move();
}
