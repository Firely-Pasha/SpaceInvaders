//
// Created by firely-pasha on 6/20/17.
//

#include "GameObject.h"
#include "Texture2D.h"

GameObject::GameObject(QString* name, QVector2D* position, int id)
{
    this->position = position;
    this->name = name;
    collider = new QRect(0, 0, 0, 0);
    texture = NULL;
    this->id = id;
    shouldBeKilled = false;
}

GameObject::~GameObject()
{
    delete (position);
    delete (name);
    delete (collider);
    delete (texture);
}

void GameObject::render()
{
    if (texture != NULL)
    {
        texture->draw(*position);
    }
}

void GameObject::update()
{
}

void GameObject::updateCollider() {
    collider->setX(position->x());
    collider->setY(position->y());

    collider->setWidth(texture->getWidth());
    collider->setHeight(texture->getHeight());
}

void GameObject::setTexture(Texture2D* texture)
{
    GameObject::texture = texture;
}

QRect *GameObject::getCollider() const
{
    return collider;
}

void GameObject::setCollider(QRect *collider)
{
    GameObject::collider = collider;
}

GameObject* GameObject::getPtr()
{
    return this;
}

QString* GameObject::getName()
{
    return name;
}

int GameObject::getId() const
{
    return id;
}