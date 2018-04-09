#pragma once
#include <QtWidgets/QApplication>
#include <qtimer>
#include <qwidget>
#include <qpainter>
#include <qdebug>
#include <vector>
#include <qpushbutton>
#include <qlayout>
#include <random>
#include <chrono>
#include <utility>
#include <string>
#include <qtimer>

#define FOOD_HEIGHT 9
#define SNAKE_BODY 10
#define WINDWOW_SIZE 500
#define SPECIAL_GIFT 10
#define TIME_RIGHT 1500
#define S_FOOD_SPAWN_TIME 1400


using std::vector;
using std::uniform_int_distribution;
using std::mt19937;
using std::pair;
using std::string;
using std::make_pair;

class da : public QWidget {
	Q_OBJECT

private:

	int scor = 0;

	QTimer timer;

	QTimer smartFoodTimer;

	pair<int, string> specialPower{ -1, "DEFAULT" };

	bool foodEaten = false,movementIsEanbled = true,shouldSpawnSpecial = false,shouldDrawSpecial = false,isInvincible = false,smartFood = false;

	vector < QRect > snake_rects;

	vector < char > directions;

	vector < pair<int,string> > special_powers;

	pair <int, int> foodCoord,giftCoord;

	pair < int, int > getFoodCenter();

	pair<int, int> spawnSpecialGift() const;

	pair<int,string> chooseASpecialPower() const;

	QRect moveLeft(const QRect& rect) const;

	QRect moveRight(const QRect& rect) const;

	QRect moveDown(const QRect& rect) const;

	QRect moveUp(const QRect& rect) const;

	int getValue() const;

	int checkIfEatSpecial(const QRect& head) const;

	inline bool identical() const;

	inline bool bodyIntersects(const QRect& rect) const;

	inline bool checkGameOver();

	inline void updateDirections();

	inline bool snakeIntersectsFood(const QRect& r) const;

	void paintEvent(QPaintEvent *p) override;

	void drawSnake(QPainter& painter);

	void drawWindowBackGround(QPainter& painter) const;

	void drawFood(QPainter& painter);

	void drawSpecialGift(QPainter& painter);

	void updateScore();

	void setSpecialPower();
	
	void adjustSnakeBehaviour();

	void timeout();

	void timeToRespawn();

public:

	da();

	void addRect();

	void delRect();

	void goDown();

	void goRight();

	void goUp();

	void goLeft();

signals:

	void gameOver();

	void scoreHasChanged(int);

	void hiden();

	void startWindow(int, const string&);

	void stopWindow();

	void modifySpeedU();

	void modifySpeedD();

private slots:

	void noRepaintings() {
		movementIsEanbled = false;
	}

	void spawnGift() {
		shouldSpawnSpecial = shouldDrawSpecial = true;
		specialPower = { -1, "DEFAULT" }, adjustSnakeBehaviour(), isInvincible = smartFood = false;
		smartFoodTimer.stop();
	}

	void timeToHide() {
		shouldDrawSpecial = shouldSpawnSpecial = false;
		emit hiden();
	}
};