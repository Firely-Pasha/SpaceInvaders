//
// Created by firely-pasha on 6/20/17.
//

#ifndef SPACEINVADERS_GAMELEVEL_H
#define SPACEINVADERS_GAMELEVEL_H


#include <QDebug>
#include <QtCore/QJsonDocument>
#include <QtCore/QFile>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>
#include <QtGui/QKeyEvent>
#include <map>

class Player;
class GameObject;
class Texture2D;

class GameLevel
{
private:
    static Player *player;
    static int score ;
    static bool canPlay;

public:
    static std::map<int, GameObject*> gameObjects;
    static const int ENEMY_COUNT;
    static bool gameOver;

    GameLevel();
    ~GameLevel();

    void paint();
    void update();

    static int getScore();
    static void addScore(int score);
    static Player *getPlayer();
    static bool isCanPlay();
    static void setCanPlay(bool canPlay);

    void keyPressEvent(QKeyEvent *event);
};


#endif //SPACEINVADERS_GAMELEVEL_H
