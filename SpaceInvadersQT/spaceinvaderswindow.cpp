#include "spaceinvaderswindow.h"
#include "SpaceInvadersWidget.h"

#include <qlcdnumber.h>
#include <qgridlayout.h>
#include <qpushbutton.h>
#include <qmenubar.h>

SpaceInvadersWindow::SpaceInvadersWindow(QWidget* parent) : QMainWindow(parent)
{

    QWidget* MainWidget = new QWidget(parent);
    setCentralWidget(MainWidget);
    gameFrame = new SpaceInvadersWidget();
    infoWidget = new InfoWidget();

    connect(infoWidget->BT_Start,&QPushButton::clicked,gameFrame,&SpaceInvadersWidget::start);
    connect(gameFrame, &SpaceInvadersWidget::updateScore, infoWidget->LCD_score, QOverload<int>::of(&QLCDNumber::display));
    connect(gameFrame, &SpaceInvadersWidget::updateShots, infoWidget->LCD_shotsFired, QOverload<int>::of(&QLCDNumber::display));
    connect(gameFrame, &SpaceInvadersWidget::updateEnemyDestroyed, infoWidget->LCD_enemyDestroyed, QOverload<int>::of(&QLCDNumber::display));
    connect(infoWidget->BT_Quit, SIGNAL(clicked()), this, SLOT(close()));
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(gameFrame, 0, 0);
    layout->addWidget(infoWidget, 0, 1);
    MainWidget->setLayout(layout);
    //QMenu *fileMenu=menuBar()->addMenu(tr("File"));
    //fileMenu->addAction(tr("Balls"));

    setWindowTitle(tr("SpaceInvaders"));
    resize(550, 370);
    this->setMouseTracking(true);
}

SpaceInvadersWindow::~SpaceInvadersWindow() {}
