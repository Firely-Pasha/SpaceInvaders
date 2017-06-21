//
// Created by firely-pasha on 6/20/17.
//


#include "Texture2D.h"
#include "Player.h"
#include "GameLevel.h"
#include "Bullet.h"
#include "GameWindow.h"


Player::Player(QString *name, QVector2D *position) : GameObject(name, position, id = -1)
{
    speed = 2;
    canShoot = true;
    hp = 10;

    int spriteX = 36;
    int spriteY = 416;
    int spriteWidth = 13;
    int spriteHeight = 8;
    pause = false;


    texture = new Texture2D("./sprites/SpriteSheet.png", QRect(spriteX, spriteY, spriteWidth, spriteHeight));
    setCollider(new QRect(position->x(), position->y(), texture->getWidth(), texture->getHeight()));
}

void Player::update()
{
    updateCollider();
}

void Player::render()
{
    GameObject::render();

    QPainter painter(GameWindow::getPtr());
    painter.setFont(*GameWindow::font);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    GameWindow::font->setPointSize(20);
    painter.setPen(Qt::yellow);
    QString str = "HP: " + QString::number(hp);
    painter.drawText(500, 80, str);
    str = "Score: " + QString::number(GameLevel::getScore());
    painter.drawText(500, 100, str);


    if (hp <= 0 || GameLevel::gameOver)
    {
        painter.setPen(Qt::darkRed);
        str = "Game Over!";
        GameWindow::font->setPointSize(75);
        painter.setFont(*GameWindow::font);
        painter.drawText(100, 400, str);
        GameLevel::setCanPlay(false);
    }

    if (GameLevel::getScore() >= GameLevel::ENEMY_COUNT * 10)
    {
        painter.setPen(Qt::green);
        str = "You Win!";
        GameWindow::font->setPointSize(75);
        painter.setFont(*GameWindow::font);
        painter.drawText(200, 400, str);
        GameLevel::setCanPlay(false);
    }

    if (pause)
    {
        painter.setPen(Qt::darkMagenta);
        str = "Pause...";
        GameWindow::font->setPointSize(75);
        painter.setFont(*GameWindow::font);
        painter.drawText(230, 400, str);
        GameLevel::setCanPlay(false);
    }

    painter.end();
};

void Player::keyPressEvent(QKeyEvent *event)
{
    if (GameLevel::isCanPlay())
    {
        if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D)
        {
            if (position->x() <= 208 - speed)
            {
                position->setX(position->x() + speed);
            }
        }
        else if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A)
        {
            if (position->x() >= 16 + speed)
            {
                position->setX(position->x() - speed);
            }
        }
        else if (event->key() == Qt::Key_F)
        {
            if (canShoot)
            {
                createBullet();
            }
        }
    }

    if ((event->key() == Qt::Key_P || event->key() == Qt::Key_Escape)
        && !event->isAutoRepeat() && hp > 0
        && GameLevel::getScore() < GameLevel::ENEMY_COUNT * 10)
    {
        GameLevel::setCanPlay(!GameLevel::isCanPlay());
        pause = !GameLevel::isCanPlay();
    }

    if (event->key() == Qt::Key_R && !event->isAutoRepeat())
    {
        GameWindow::restartLevel();
    }
}

void Player::createBullet()
{
    Bullet *bullet;
    QVector2D *pos = new QVector2D(position->x() + texture->getWidth() / 2, position->y() + texture->getHeight() - 10);
    bullet = new Bullet(pos, true, GameLevel::gameObjects.rbegin()->first + 1, &canShoot, new QString("Enemy"), true);
    GameLevel::gameObjects.insert(std::pair<int, GameObject*>(GameLevel::gameObjects.rbegin()->first + 1, bullet->getPtr()));
}

int Player::getHp() const
{
    return hp;
}

void Player::addHp(int hp)
{
    Player::hp += hp;
}
