#include "first.h"

void firstTime::readAndAppendToString() {

	ifstream f{ "first.txt" };

	string readed;

	while (getline(f, readed)) {
		whatToWrite += readed;
		whatToWrite.push_back('\n');
	}

	f.close();
}

firstTime::firstTime(){
	readAndAppendToString();
	QVBoxLayout *lay = new QVBoxLayout{ this };
	lista.addItem(QString{ whatToWrite.data() });
	lay->addWidget(&lista);
	setMinimumSize(1000, 150), setWindowTitle("TIPS AND TRICKS");
}
