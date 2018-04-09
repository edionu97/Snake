#pragma once

#include <fstream>
#include <qlabel>
#include <qwidget>
#include <qlayout>
#include <string>
#include <qpainter>
#include "first.h"

using std::fstream;
using std::string;
using std::ifstream;
using std::ofstream;

class scoreWindow : public QWidget {

	Q_OBJECT
private:

	bool lastUnseted = true;

	string fileName;

	firstTime first;
	
	QLabel *curentL, *bestL, *lastL;

	int best, last,current;

	void readScores();

	void writeResults();

	void createIfNotExists();

	void reload();

	void assemble();

	void paintEvent(QPaintEvent *p) override;

public:

	scoreWindow(const string& file);

private slots:
	
	void modifyScore(int score) {
		current += score, reload();
	}
};
