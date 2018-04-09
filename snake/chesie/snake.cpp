#include "snake.h"

inline bool da::identical() const {
	char element = directions[0];

	for (int i = 1; i < directions.size(); ++i)
		if (directions[0] != directions[i])return false;

	return true;
}

inline bool da::bodyIntersects(const QRect & rect) const{

	for (const auto& r : snake_rects) {
		if (r == rect || !r.intersects(rect)) continue;
		return true;
	}

	return false;
}

inline bool da::checkGameOver(){

	if (isInvincible || snake_rects.size() == 2)return false;

	for (const auto& r : snake_rects)
		if (bodyIntersects(r)) {
			emit gameOver(), emit stopWindow();
			return true;
		}

	return false;
}

inline void da::updateDirections() {

	static int k = 0;

	if (identical()) {
		k = 0; return;
	}

	++k;

	if (k % 3 != 0)return;

	for (int i = 0; i < directions.size() - 1; ++i)directions[i] = directions[i + 1];
}

pair<int, int> da::getFoodCenter() {

	mt19937 t{ static_cast <unsigned int> (std::chrono::steady_clock::now().time_since_epoch().count()) };

	uniform_int_distribution <int >dx(FOOD_HEIGHT, WINDWOW_SIZE - FOOD_HEIGHT), dy(FOOD_HEIGHT, WINDWOW_SIZE - FOOD_HEIGHT);

	return make_pair(dx(t),dy(t));
}

int da::getValue() const{

	static mt19937 t{ static_cast <unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()) };

	static uniform_int_distribution <int>d(1, 100);

	if (specialPower.first == 0) return d(t) * 2;

	return d(t);
}

int da::checkIfEatSpecial(const QRect & head) const {
	return head.intersects(QRect{ giftCoord.first,giftCoord.second,SPECIAL_GIFT,SPECIAL_GIFT });
}

inline bool da::snakeIntersectsFood(const QRect & r) const {
	auto head = snake_rects.back();

	return head.intersects(r);
}

void da::paintEvent(QPaintEvent * p) {

	QPainter painter{ this };

	drawWindowBackGround(painter);

	drawSpecialGift(painter);

	drawSnake(painter);

	updateDirections();

	drawFood(painter);
}

void da::drawSnake(QPainter & painter) {

	painter.setBrush(Qt::gray);

	int directionIndex = -1;

	for (auto& rect : snake_rects) {

		++directionIndex;

		if (movementIsEanbled) {

			switch (directions[directionIndex]) {
				case 'R': rect = moveRight(rect); break;
				case 'L': rect = moveLeft(rect); break;
				case 'U': rect = moveUp(rect); break;
				case 'D': rect = moveDown(rect); break;
			}

		}

		if (directionIndex == directions.size() - 2)painter.setBrush(Qt::black);

		painter.drawRect(rect);

		if (shouldDrawSpecial && checkIfEatSpecial(rect)) {
			shouldDrawSpecial = false,specialPower = chooseASpecialPower();
			emit  startWindow(false, specialPower.second); adjustSnakeBehaviour();
		}
	}

	checkGameOver();
}

void da::drawWindowBackGround(QPainter & painter) const {
	painter.setBrush(Qt::white);
	painter.drawRect(0, 0, width() - 1, height() - 1);
}



void da::drawFood(QPainter & painter) {
	painter.setBrush(Qt::gray);

	QRect r{ foodCoord.first,foodCoord.second,FOOD_HEIGHT,FOOD_HEIGHT };

	if (snakeIntersectsFood(r)) {
		foodCoord = getFoodCenter(), addRect(), updateScore();
	}

	painter.drawRect(r);
}

void da::drawSpecialGift(QPainter & painter){

	painter.setBrush(Qt::black);

	if (shouldSpawnSpecial && movementIsEanbled) {
		giftCoord = spawnSpecialGift(); shouldSpawnSpecial = false; 
		emit stopWindow();
	}
	
	QRect r{ giftCoord.first, giftCoord.second, SPECIAL_GIFT, SPECIAL_GIFT };

	if(shouldDrawSpecial)painter.drawRect(r);

	painter.setBrush(Qt::gray);
}

QRect da::moveLeft(const QRect & rect) const {

	int x1, y1, x2, y2;
	rect.getCoords(&x1, &y1, &x2, &y2);

	if (x1 - SNAKE_BODY / 2 <= 0)return QRect{ width(),y1,SNAKE_BODY,SNAKE_BODY };

	return QRect{ x1 - SNAKE_BODY / 2,y1,SNAKE_BODY,SNAKE_BODY };
}

QRect da::moveRight(const QRect & rect) const {

	int x1, y1, x2, y2;
	rect.getCoords(&x1, &y1, &x2, &y2);

	if (x1 + SNAKE_BODY / 2 >= width())return QRect{ 0, y1,SNAKE_BODY,SNAKE_BODY };

	return QRect{ x1 + SNAKE_BODY / 2 , y1,SNAKE_BODY,SNAKE_BODY };
}

QRect da::moveDown(const QRect & rect) const {
	int x1, y1, x2, y2;
	rect.getCoords(&x1, &y1, &x2, &y2);

	if (y1 + SNAKE_BODY / 2 >= height())return QRect{ x1,0,SNAKE_BODY,SNAKE_BODY };

	return QRect{ x1,y1 + SNAKE_BODY / 2,SNAKE_BODY,SNAKE_BODY };
}

QRect da::moveUp(const QRect & rect) const {
	int x1, y1, x2, y2;

	rect.getCoords(&x1, &y1, &x2, &y2);

	if (y1 - SNAKE_BODY / 2 <= 0)return QRect{ x1,height(),SNAKE_BODY,SNAKE_BODY };

	return QRect{ x1,y1 - SNAKE_BODY / 2,SNAKE_BODY,SNAKE_BODY };
}

void da::updateScore(){
	scor += getValue();
	emit scoreHasChanged(scor);
}

void da::setSpecialPower(){
	special_powers.push_back({ 0,"DOUBLE_VALUE" });
	special_powers.push_back({ 1,"SPEED_UP" });
	special_powers.push_back({ 2,"SIZE_UP" });
	special_powers.push_back({ 3,"SPEED_DOWN" });
	special_powers.push_back({ 4,"SIZE_DOWN" });
	special_powers.push_back({ 5,"INVINCIBLE" });
	special_powers.push_back({ 6,"SMART_FOOD" });
}

pair<int,string> da::chooseASpecialPower() const{
	
	static mt19937 t{ static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()) };

	static uniform_int_distribution<int>d(0, special_powers.size() - 1);

	return special_powers[d(t)];
}

void da::adjustSnakeBehaviour(){

	switch (specialPower.first){
		case -1: return;
		case 0: return;
		case 1:emit modifySpeedU(); timer.start(); break;
		case 2:addRect(); timer.start(); break;
		case 3:emit modifySpeedD(); timer.start(); break;
		case 4:delRect(); timer.start(); break;
		case 5:isInvincible = true; break;
		case 6:smartFoodTimer.start(); smartFood = true; break;
	}

}

void da::timeout() {
	timer.stop();
	emit stopWindow();
}

void da::timeToRespawn(){
	foodCoord = getFoodCenter();
}

pair<int,int> da::spawnSpecialGift() const{
	 
	static mt19937 t{ static_cast <unsigned int> (std::chrono::steady_clock::now().time_since_epoch().count()) };

	static uniform_int_distribution <int> dx(SPECIAL_GIFT, WINDWOW_SIZE - SPECIAL_GIFT), dy(SPECIAL_GIFT, WINDWOW_SIZE - SPECIAL_GIFT);

	return make_pair(dx(t), dy(t));
}

da::da() {

	snake_rects.push_back({ SNAKE_BODY,SNAKE_BODY / 2 ,SNAKE_BODY,SNAKE_BODY });
	directions.push_back('R'); directions.push_back('R');

	foodCoord = getFoodCenter();

	setMinimumSize(WINDWOW_SIZE, WINDWOW_SIZE), setMaximumSize(WINDWOW_SIZE, WINDWOW_SIZE);

	setSpecialPower(), timer.setInterval(TIME_RIGHT), smartFoodTimer.setInterval(S_FOOD_SPAWN_TIME);

	QObject::connect(&timer, &QTimer::timeout, [&]() {
		timeout();
	});

	QObject::connect(&smartFoodTimer, &QTimer::timeout, [&]() {
		timeToRespawn();
	});

}

void da::addRect() {

	auto rect = snake_rects[0];

	int x1, y1, x2, y2;

	directions.emplace(directions.begin(), directions[0]);
	snake_rects.emplace(snake_rects.begin(), snake_rects[0]);

	switch (directions[0]) {
		case 'R': rect = moveLeft(rect); break;
		case 'L': rect = moveRight(rect); break;
		case 'U': rect = moveDown(rect); break;
		case 'D': rect = moveUp(rect); break;
	}

	rect.getCoords(&x1, &y1, &x2, &y2);

	switch (directions[0]) {
		case 'R': x1 -= SNAKE_BODY; directions[0] = 'R'; break;
		case 'L': x1 += SNAKE_BODY; directions[0] = 'L'; break;
		case 'U': y1 += SNAKE_BODY; directions[0] = 'U'; break;
		case 'D': y1 -= SNAKE_BODY; directions[0] = 'D'; break;
	}

	snake_rects[0] = QRect{ x1,y1 ,SNAKE_BODY,SNAKE_BODY };
}

void da::delRect(){

	if (snake_rects.size() <= 2)return;

	snake_rects.erase(snake_rects.begin());

	directions.erase(directions.begin());
}

void da::goDown() {
	directions[directions.size() - 1] = 'D';
}

void da::goRight() {
	directions[directions.size() - 1] = 'R';
}

void da::goUp() {
	directions[directions.size() - 1] = 'U';
}

void da::goLeft() {
	directions[directions.size() - 1] = 'L';
}
