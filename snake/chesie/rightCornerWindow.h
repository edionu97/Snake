#pragma once
#include <qpainter>
#include <qwidget>
#include <qlabel>
#include <qtimer>
#include <chrono>
#include <random>
#include <string>
#include <vector>
#include <string>
#include <qdebug>

#define WINDOW 50

using std::string;

class small : public QWidget {
	Q_OBJECT

private:

	std::string s{ "POWER" };

	QTimer t;

	bool hidden = true;

	void paintEvent(QPaintEvent *p) override;
	
public:

	small();

	void start();

	void stop();

private slots:

	void startRepainting(int hidden, const string& message) {
		s = message, this->hidden = hidden, start(), show();
	}

	void stopRepainting() {
		stop(),hide();
	}

};