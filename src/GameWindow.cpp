#include "GameWindow.h"

GameWindow* GameWindow::ptr = NULL;
QFont* GameWindow::font = NULL;
GameLevel* GameWindow::level = NULL;

void GameWindow::initializeGL()
{
    ptr = this;

    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    glEnable(GL_CULL_FACE);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, width(), height());
    glOrtho(0, GAME_WIDTH,
            0, GAME_HEIGHT,
            0., 1.);

    setMaximumSize(width(), height());
    setMinimumSize(width(), height());

    level = new GameLevel();

    int id = QFontDatabase::addApplicationFont("./sprites/ARCADECLASSIC.TTF");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    font = new QFont(family, 20);
}

void GameWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    update();

    if (level != nullptr)
        level->paint();


    QPainter painter(this);
    font->setPointSize(20);
    painter.setPen(Qt::yellow);
    painter.setFont(*font);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.drawText(100, 80, "A/D \t-  Move "); // z = pointT4.z + distOverOp / 4
    painter.drawText(100, 100, "F  \t-  Fire "); // z = pointT4.z + distOverOp / 4
    painter.drawText(100, 120, "R  \t-  Restart"); // z = pointT4.z + distOverOp / 4
    painter.drawText(100, 140, "ESC\t-  Pause"); // z = pointT4.z + distOverOp / 4
    painter.end();
}

void GameWindow::update()
{
    QOpenGLWidget::update();

    if (level != nullptr)
        level->update();
}


void GameWindow::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, width(), height());
    glOrtho(0, GAME_WIDTH,
            0, GAME_HEIGHT,
            0., 1.);
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    QWidget::keyPressEvent(event);

    if (level != nullptr)
        level->keyPressEvent(event);
}

GameWindow *GameWindow::getPtr()
{
    return ptr;
}

void GameWindow::restartLevel()
{

    delete(level);
    level = new GameLevel();
}