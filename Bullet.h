//
// Created by firely-pasha on 6/20/17.
//

#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H


#include "GameObject.h"

class Bullet : public GameObject
{
private:
    float speed;
    bool* canShoot;
    bool upDirection;
    bool isPlayer;

public:
    Bullet(QVector2D *position, bool upDirection, int id, bool* canShoot, QString *name, bool isPlayer);
    ~Bullet();
    void update() override;
};

#endif //SPACEINVADERS_BULLET_H
