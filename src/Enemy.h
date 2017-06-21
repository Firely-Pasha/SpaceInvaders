//
// Created by firely-pasha on 6/20/17.
//

#ifndef SPACEINVADERS_ENEMY_H
#define SPACEINVADERS_ENEMY_H


#include <QtCore/QJsonObject>
#include <QVector2D>

#include "GameObject.h"

class Texture2D;

class Enemy : public GameObject
{
private:
    float speed;
    bool canShoot;
    int cooldown;
public:
    Enemy(QString* name, QVector2D *position, int id);

    void update();
    void createBullet();
};



#endif //SPACEINVADERS_ENEMY_H
