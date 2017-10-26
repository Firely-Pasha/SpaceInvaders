//
// Created by firely-pasha on 6/20/17.
//

#ifndef SPACEINVADERS_GAMEOBJECT_H
#define SPACEINVADERS_GAMEOBJECT_H


#include <QtCore/QPoint>
#include <QtCore/QRect>
#include <QtCore/QString>
#include <QVector2D>

class Texture2D;

class GameObject
{
protected:
    QString* name;
    QVector2D* position;
    QRect* collider;
    Texture2D* texture;
    int id;

public:
    GameObject(QString* name, QVector2D* position, int id);
    ~GameObject();

    void render();
    virtual void update();

    void setTexture(Texture2D* texture);
    QRect *getCollider() const;
    void setCollider(QRect *collider);
    QString* getName();

    int getId() const;

    GameObject *getPtr();

    void updateCollider();
    bool shouldBeKilled;
};



#endif //SPACEINVADERS_GAMEOBJECT_H
