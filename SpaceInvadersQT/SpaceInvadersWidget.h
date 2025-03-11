#pragma once

#include <QFrame>
#include <QPainter>
#include <QKeyEvent>
#include <QBasicTimer>
#include <iostream>
#include <qtimer.h>
#include <qoverload.h>
#include <vector>

#include "Alien.h"
#include "Player.h"
#include "Projectile.h"
#include "CollisionChecker.h"
#include <cstdlib>



class SpaceInvadersWidget :public QFrame
{
	Q_OBJECT

private:
	QBasicTimer* timer;
	QPainter* painter;

	vector<Alien> aliens;
	Player* player;
	vector<Projectile> projectiles;
	
	bool isStarted = false;

	int score=0, shots=0, enemyDestroyed=0;

public:
	SpaceInvadersWidget();
	void shotsIncrement();
	void scoreAdd(int value);
	void enemyDestroyedIncrement();
	vector<Alien>* getAliens() { return &aliens; };
	vector<Projectile>* getProjectiles(){ return &projectiles; };
	void treatCollision();
public slots:
	void start();
	void restart();
signals:
	void updateShots(int value);
	void updateEnemyDestroyed(int value);
	void updateScore(int value);
protected:
	void keyPressEvent(QKeyEvent* event) override;
	void paintEvent(QPaintEvent* event) override;
	void timerEvent(QTimerEvent* event) override;
};