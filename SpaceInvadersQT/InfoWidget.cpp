#include "InfoWidget.h"
#include <QGridLayout.h>
#include <qrect.h>


InfoWidget::InfoWidget()
{
	LCD_score = new QLCDNumber(5);
	LCD_enemyDestroyed = new QLCDNumber(5);
	LCD_shotsFired = new QLCDNumber(5);

	BT_Start = new QPushButton("Start");
	BT_Quit = new QPushButton("Quit");

	L_score = new QLabel("Score");
	L_enemyDestroyed = new QLabel("Enemy Destroyed");
	L_shotsFired = new QLabel("Shots Fired");
	L_image = new QLabel();
	PIX_imagePath.load(tr("Resources/SpaceInvadersLogo.png"));
	PIX_imagePath = PIX_imagePath.scaled(200, 80);


	L_score->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	L_enemyDestroyed->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	L_shotsFired->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	L_image->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

	L_score->setFixedHeight(10);
	L_enemyDestroyed->setFixedHeight(10);
	L_shotsFired->setFixedHeight(10);
	L_image->setPixmap(PIX_imagePath);

	W_buttonWidget = new QWidget();

	QGridLayout* mainLayout = new QGridLayout, * buttonLayout = new QGridLayout;

	buttonLayout->addWidget(BT_Start, 0, 0);
	buttonLayout->addWidget(BT_Quit, 0, 1);

	W_buttonWidget->setLayout(buttonLayout);

	mainLayout->addWidget(L_score, 0, 0);
	mainLayout->addWidget(LCD_score, 1, 0);
	mainLayout->addWidget(L_enemyDestroyed, 2, 0);
	mainLayout->addWidget(LCD_enemyDestroyed, 3, 0);
	mainLayout->addWidget(L_shotsFired, 4, 0);
	mainLayout->addWidget(LCD_shotsFired, 5, 0);
	mainLayout->addWidget(L_image, 6, 0);
	mainLayout->addWidget(W_buttonWidget, 7, 0);


	setLayout(mainLayout);

}
