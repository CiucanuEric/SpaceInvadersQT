#pragma once

#include <qwidget.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>
#include <qimage.h>
#include <qlabel.h>
#include <qpixmap.h>

QT_BEGIN_NAMESPACE
class QLCDNumber;
class QImage;
class QPushButton;
class QLabel;
class QPixmap;
class QPainter;
QT_END_NAMESPACE

class InfoWidget :public QWidget
{
public:
	InfoWidget();
	QPushButton* BT_Start;
	QPushButton* BT_Quit;
	QLCDNumber* LCD_score;
	QLCDNumber* LCD_enemyDestroyed;
	QLCDNumber* LCD_shotsFired;
private:
	QImage* IMG_spaceInvaders;
	QLabel* L_score;
	QLabel* L_enemyDestroyed;
	QLabel* L_shotsFired;
	QLabel* L_image;
	QPixmap PIX_imagePath;
	QImage test;


	QWidget* W_buttonWidget;
};