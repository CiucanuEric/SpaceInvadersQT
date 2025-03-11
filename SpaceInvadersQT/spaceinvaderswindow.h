#ifndef SPACEINVADERSWINDOW_H
#define SPACEINVADERSWINDOW_H

#include <QMainWindow>
#include <QWidget.h>
#include "SpaceInvadersWidget.h"
#include "InfoWidget.h"

QT_BEGIN_NAMESPACE
class QWidget;
class QFrame;
QT_END_NAMESPACE

class SpaceInvadersWindow : public QMainWindow
{
    Q_OBJECT

private:
    InfoWidget* infoWidget;
    SpaceInvadersWidget* gameFrame;

public:
    SpaceInvadersWindow(QWidget* parent = nullptr);
    ~SpaceInvadersWindow();
};
#endif // SPACEINVADERSWINDOW_H
