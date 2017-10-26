//
// Created by firely-pasha on 6/20/17.
//

#include "Enemy.h"
#include "GameLevel.h"
#include "Texture2D.h"
#include "Bullet.h"

Enemy::Enemy(QString* name, QVector2D *position, int id) : GameObject(name, position, id)
{
    speed = 0.25;
    canShoot = true;
    
    int spriteX = 2;
    int spriteY = 431;
    int spriteWidth = 16;
    int spriteHeight = 7;

    shouldBeKilled = false;

    cooldown = rand() % 10000 + 3000;

    texture = new Texture2D(":resources/sprites/SpriteSheet.png", QRect(spriteX, spriteY, spriteWidth, spriteHeight));
    setCollider(new QRect(position->x(), position->y(), texture->getWidth(), texture->getHeight()));
}

void Enemy::update()
{
    position->setX(position->x() - speed);


    if (position->x() >= 208 || position->x() <= 16)
    {
        speed *= -1;
        position->setY(position->y() - 10);
    }

    if (position->y() < 42)
    {
        GameLevel::gameOver = true;
    }

    updateCollider();

    cooldown--;


    if (cooldown <= 0)
    {
        createBullet();
        cooldown = rand() % 10000 + 5000;;
    }
}

void Enemy::createBullet()
{
    Bullet *bullet;
    QVector2D *pos = new QVector2D(position->x() + texture->getWidth() / 2, position->y());
    bullet = new Bullet(pos, false, GameLevel::gameObjects.rbegin()->first + 1, &canShoot, new QString("Player"), false);
    GameLevel::gameObjects.insert(std::pair<int, GameObject*>(GameLevel::gameObjects.rbegin()->first + 1, bullet->getPtr()));
}
