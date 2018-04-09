#include "controler.h"

int main(int argc, char *argv[]){
	
	QApplication a(argc, argv);

	da *  b = new da{};

	scoreWindow *wind = new scoreWindow{ "scores.txt" };

	small * s = new small{};

	controler c{ *b,*wind,*s };

	c.run();

	return a.exec();
}


