#ifndef SPACEINVADERS_GAMEWINDOW_H
#define SPACEINVADERS_GAMEWINDOW_H

#include <QtWidgets/QOpenGLWidget>
#include <QtOpenGL/QtOpenGL>
#include <QOpenGLFunctions>
#include <QTimer>
#include <GL/gl.h>
#include <QtGui/QKeyEvent>
#include <QtWidgets/QWidget>
#include "GameLevel.h"

class GameLevel;

class GameWindow : public QOpenGLWidget, protected QOpenGLFunctions
{
Q_OBJECT;

public:
    static int const GAME_WIDTH = 256;
    static int const GAME_HEIGHT = 240;
    static QFont *font;
    static GameLevel *level;
private:
    static GameWindow* ptr;

    void initializeGL();
    void paintGL();
    void update();
    void resizeGL(int nWidth, int nHeight);
    void keyPressEvent(QKeyEvent* event);

public:
    static GameWindow *getPtr();
    static void restartLevel();

private:
Q_SIGNALS:
    void updateGL();
};


#endif //SPACEINVADERS_GAMEWINDOW_H