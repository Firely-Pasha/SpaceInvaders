#include <QApplication>
#include "GameWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GameWindow *gameWindow = new GameWindow();

    gameWindow->setWindowTitle("Battle City Remastered");
    gameWindow->resize(768, 720);
    gameWindow->show();

    return app.exec();
}
