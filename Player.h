//
// Created by firely-pasha on 6/20/17.
//

#ifndef SPACEINVADERS_PLAYER_H
#define SPACEINVADERS_PLAYER_H


#include "GameObject.h"
#include <QKeyEvent>

class GameObject;

class Player : public GameObject
{
private:
    int speed;
    bool canShoot;
    int hp;
    bool pause;

public:
    Player(QString *name, QVector2D *position);
    void keyPressEvent(QKeyEvent *event);

    void update();
    void render();
    void createBullet();

    int getHp() const;

    void addHp(int hp);
};


#endif //SPACEINVADERS_PLAYER_H
