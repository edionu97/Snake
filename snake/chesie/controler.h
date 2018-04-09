#pragma once
#include <qmessagebox>
#include "control.h"
#include "scoreWindow.h"
#include "rightCornerWindow.h"

#define SNAKE_SPEED 40
#define MIN_HIDE 10000
#define MAX_HIDE 100000
#define MIN_PLAY 15
#define MAX_PLAY 100
#define REDUCE_SPEED 2
#define INCREASE_SPEED 2
#define HIDE_TIME MIN_HIDE / 2 

class controler : public QWidget {

	Q_OBJECT

private:

	da & window;

	scoreWindow & score;

	small & smallWindow;

	QMessageBox gameOverBox;

	QTimer t;

	QTimer timerGift;

	QTimer hideTimer;

	controlWindow movement;

	void connect();

	void move();

	void assemble();

	int getTimerInterval() const;

public:

	controler(da& window, scoreWindow& score,small& s);

	void run();

private slots:

	void stopGame() {
		static int showOnce = 0;

		t.stop();

		gameOverBox.setText("Eary,you've done an ilegal move so GAME OVER!!!");

		gameOverBox.setWindowTitle("GAME OVER");

		if (!showOnce)gameOverBox.show(), showOnce = 1;

		emit stopRepaintings();
	}

	void stopHider() {
		hideTimer.stop();
	}

	void speedUp() {
		t.setInterval(t.interval() - INCREASE_SPEED < MIN_PLAY ? MIN_PLAY : t.interval() - INCREASE_SPEED);
	}

	void speedDown() {
		t.setInterval(t.interval() + REDUCE_SPEED > MAX_PLAY ? MAX_PLAY : t.interval() + REDUCE_SPEED);
	}

signals:

	void stopRepaintings();

	void spawn();

	void hideWindow();
};