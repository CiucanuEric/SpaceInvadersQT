#include "Player.h"

void Player::draw(QPainter* painter)
{
	Size currentSize = getSize();
	Location currentLocation = getLocation();
	painter->drawLine(currentLocation.X, currentLocation.Y + currentSize.H, currentLocation.X + currentSize.W, currentLocation.Y + currentSize.H);
	painter->drawLine(currentLocation.X + currentSize.W, currentLocation.Y + currentSize.H, currentLocation.X + currentSize.W / 2, currentLocation.Y);
	painter->drawLine(currentLocation.X, currentLocation.Y + currentSize.H, currentLocation.X + currentSize.W / 2, currentLocation.Y);
}

Player::Player(int x, int y, int w, int h) :Entity(x, y, w, h)
{
	setMoveSpeed(5);
}

void Player::update()
{

}
