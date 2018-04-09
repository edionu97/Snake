#include "scoreWindow.h"
#define RECT_SIZE  80

void scoreWindow::readScores() {
	ifstream f{ fileName };
	current = 0;
	f >> last >> best;
	f.close();
}

void scoreWindow::writeResults(){
	ofstream g{ fileName };
	g << last << '\n' << best;
	g.close();
}

void scoreWindow::createIfNotExists(){
	ifstream f{ fileName };

	if (!f.is_open()) {
		ofstream{ fileName };
		return;
	}
}

void scoreWindow::reload(){

	best = std::max(best, current);
	
	if (current)first.close();

	if(!lastUnseted)last = current;

	writeResults();

	bestL->setText(QString{ "Best score: " } +QString::number(best));
	curentL->setText(QString{ "Curent score: " } +QString::number(current));
	
	if (lastUnseted) {
		lastL->setText(QString{ "Last score: " } +QString::number(last)), lastUnseted = false;
	}

}

void scoreWindow::assemble(){

	QVBoxLayout *lay = new QVBoxLayout{ this };

	bestL = new QLabel{ "Best score: 0" };
	lastL = new QLabel{ "Last score: 0" };
	curentL = new QLabel{ "Curent score: 0" };

	lay->addWidget(bestL), lay->addWidget(lastL), lay->addWidget(curentL);
}

void scoreWindow::paintEvent(QPaintEvent * p){
	QPainter painter{ this };

	int dim = (width() - 1) / 3;

	painter.drawRect(0, 0, width() - 1, height() - 1);
	
	painter.drawRect(0, dim + RECT_SIZE, width() - 1, height() - 1);

	painter.drawRect(0, 3*dim + RECT_SIZE , width() - 1, height() - 1);
}

scoreWindow::scoreWindow(const string& file) : fileName{ file } {
	createIfNotExists();
	readScores(); assemble();
	if (best == 0)first.show();
	reload();
}

