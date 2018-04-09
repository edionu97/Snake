#pragma once
#include <string>
#include <qwidget>
#include <fstream>
#include <qlistwidget>
#include <qlayout>

using std::ifstream;
using std::string;
using std::getline;


class firstTime : public QWidget {

private:

	string whatToWrite;

	QListWidget lista;
	
	void readAndAppendToString();
	

public:

	firstTime();
};