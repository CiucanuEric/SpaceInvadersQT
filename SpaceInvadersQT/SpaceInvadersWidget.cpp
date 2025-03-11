#include "SpaceInvadersWidget.h"

#define FPS 60
#define FPS_STEP 1000/FPS

SpaceInvadersWidget::SpaceInvadersWidget()
{
    painter = new QPainter(this);
    setFrameStyle(QFrame::Box);
    setFocusPolicy(Qt::WheelFocus);
    
    timer = new QBasicTimer();
    timer->start(FPS_STEP, this);
}

void SpaceInvadersWidget::start()
{
    if (isStarted)
    {
        restart();
    }
    srand(time(0));
    setFixedSize(width(), height());
    isStarted = true;
    std::cout << frameRect().width() << " " << frameRect().height() << endl;

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            aliens.push_back(Alien(width() / 30 * (i+1) + width() / 10 * i, height() / 30 * (j+1) + height() / 10 * j, width() / 10, height() / 10));
        }
    }
    QRect currentFrame = frameRect();

    player = new Player(currentFrame.width() / 2 - currentFrame.width() / 40, currentFrame.height()-currentFrame.height()/9, currentFrame.width()/20, currentFrame.height()/20);
}   
void SpaceInvadersWidget::restart()
{
    aliens.clear();
    projectiles.clear();
    delete player;
}

void SpaceInvadersWidget::treatCollision()
{
        for (int i = 0; i < aliens.size(); i++)
        {
            for (int j = 0; j < projectiles.size(); j++)
            {
                if (CollisionChecker::isIntersecting(&aliens[i], &projectiles[j]))
                {
                    scoreAdd(aliens[i].score);
                    aliens.erase(aliens.begin() + i);
                    projectiles.erase(projectiles.begin() + j);
                    emit updateScore(score);

                    enemyDestroyedIncrement();
                    emit updateEnemyDestroyed(enemyDestroyed);

                    goto alienDead;
                }
                else if (CollisionChecker::isOutOfBounds(&projectiles[j], frameRect()))
                {
                    projectiles.erase(projectiles.begin() + i);
                }
            }
        alienDead:;
        }
}

// ====================================================================================================
// ---------------------------------------------- EVENTS ----------------------------------------------
// ====================================================================================================

void SpaceInvadersWidget::keyPressEvent(QKeyEvent* event)
{
    if (isStarted)
    {
        int key = event->key();
        switch (event->key())
        {
        case Qt::Key_D:
            player->setLocation({ player->getLocation().X + player->getMoveSpeed(),player->getLocation().Y });
            if (CollisionChecker::isOutOfBounds(player, frameRect()))
            {
                player->setLocation({ player->getLocation().X - player->getMoveSpeed(),player->getLocation().Y });
            }
            break;
        case Qt::Key_A:
            player->setLocation({ player->getLocation().X - player->getMoveSpeed(),player->getLocation().Y });
            if (CollisionChecker::isOutOfBounds(player, frameRect()))
            {
                player->setLocation({ player->getLocation().X + player->getMoveSpeed(),player->getLocation().Y });
            }
            break;
        case Qt::Key_Space:
            projectiles.push_back(Projectile(player->getLocation().X + player->getSize().W / 2, player->getLocation().Y - 11, height()/30, width()/25, height() / 30));
            shotsIncrement();
            emit updateShots(shots);
            break;
        default:
            QFrame::keyPressEvent(event);
        }
        //cout << CollisionChecker::isOutOfBounds(player, frameRect())<< "|"<<player->getLocation().X <<" "<< player->getLocation().Y << endl;
    }
}

void SpaceInvadersWidget::paintEvent(QPaintEvent* event)
{
    if (isStarted)
    {
        QPainter painter(this);
        player->draw(&painter);
        for (int i = 0; i < aliens.size(); i++)
        {
            aliens[i].draw(&painter);
        }

        for (int i = 0; i < projectiles.size(); i++)
        {
            projectiles[i].draw(&painter);
        }
        painter.end();
    }
    QFrame::paintEvent(event);
}

void SpaceInvadersWidget::timerEvent(QTimerEvent* event)
{
    if (isStarted)
    {
        player->update();
        for (int i = 0; i < aliens.size(); i++)
        {
            aliens[i].update();
        }
        if (!aliens.size())
        {
            for (int i = 0; i < rand() % 10; i++)
            {
                int w = width() / 10;
                int h = height() / 10;
                int local_rand = rand() % 7;
                int x = width() / 30 * (local_rand + 1) + width() / 10 * local_rand;
                local_rand = rand() % 4;
                int y = height() / 30 * (local_rand + 1) + height() / 10 * local_rand;
                aliens.push_back(Alien(x, y, w, h));
            }
        }

        for (int j = 0; j < projectiles.size(); j++)
        {
            projectiles[j].update();
        }
        treatCollision();
        update();
    }
    else
    {
        QFrame::timerEvent(event);
    }
}

// ====================================================================================================
// ---------------------------------------------- SIGNALS ---------------------------------------------
// ====================================================================================================

void SpaceInvadersWidget::shotsIncrement()
{
    shots++;
}

void SpaceInvadersWidget::scoreAdd(int value)
{
    score += value;
}

void SpaceInvadersWidget::enemyDestroyedIncrement()
{
    enemyDestroyed++;
}