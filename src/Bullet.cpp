//
// Created by firely-pasha on 6/20/17.
//


#include "Texture2D.h"
#include "Bullet.h"
#include "GameLevel.h"
#include "Player.h"

Bullet::Bullet(QVector2D *position, bool upDirection, int id, bool* canShoot, QString* name, bool isPlayer)
        : GameObject(name, position, id)
{
    speed = 0.25 / 2;
    this->upDirection = upDirection;

    shouldBeKilled = false;
    this->isPlayer = isPlayer;

    this->canShoot = canShoot;

    *(this->canShoot) = false;




    QRect *re;
    re = new QRect(31, 432, 1, 4);

    Texture2D *texture2D = new Texture2D("./sprites/SpriteSheet.png", *re);

    setTexture(texture2D);
    QRect *coll = new QRect(0, 0, 1, 4);
    setCollider(coll);
}

Bullet::~Bullet()
{
    delete canShoot;
}

void Bullet::update()
{
    GameObject::update();

    if (upDirection)
    {
        if (position->y() <= 175 - speed)
        {
            position->setY(position->y() + speed);
        }
        else
        {
            (*canShoot) = true;
            shouldBeKilled = true;
        }
    }
    else
    {
        if (position->y() >= 32 - speed)
        {
            position->setY(position->y() - speed);
        }
        else
        {
            (*canShoot) = true;
            shouldBeKilled = true;
        }
    }

    updateCollider();

    if (isPlayer)
    {
        for(std::map<int, GameObject*>::iterator it = GameLevel::gameObjects.begin(); it != GameLevel::gameObjects.end(); ++it)
        {
            QRect coll = *it->second->getCollider();

            if (it->second != this && collider->intersects(coll))
            {
                if (*it->second->getName() == *name)
                {
                    (*canShoot) = true;
                    it->second->shouldBeKilled = true;
                    shouldBeKilled = true;
                    GameLevel::addScore(10);
                    break;
                }
            }
        }
    }
    else if (collider->intersects(*GameLevel::getPlayer()->getCollider()))
    {
        GameLevel::getPlayer()->addHp(-1);
        qDebug() << GameLevel::getPlayer()->getHp();
        shouldBeKilled = true;
    }
}


