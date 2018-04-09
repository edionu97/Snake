#pragma once
#include "snake.h"

class controlWindow : public QWidget {
private:
	da& window;

	QPushButton *up, *down, *left, *right;

	void paintEvent(QPaintEvent *p) override;

	void construct();

	void connect();

public:

	controlWindow(da& window);
};