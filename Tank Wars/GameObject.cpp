#include "GameObject.h"



GameObject::GameObject(Vector2f pos, Texture &tex, IntRect rect)
{
    position.x = pos.x;
    position.y = pos.y;
    sprite.setTexture(tex);
    sprite.setTextureRect(rect);
    sprite.setOrigin(Vector2f((float)rect.width / 2, (float)rect.height / 2));
    speed = 0;
    angle = 0;
}

Vector2f GameObject::getPos()
{
    return position;
}

void GameObject::setSpeed(double speed)
{
    this->speed = convertSpeed(speed);
}

void GameObject::setAngle(double angle)
{
    this->angle = angle;
}

void GameObject::draw(RenderWindow &window)
{
    window.draw(sprite);
}

Sprite GameObject::getSprite()
{
    return sprite;
}

bool GameObject::checkCollision(GameObject *obj)
{
    if (this->sprite.getGlobalBounds().intersects(obj->getSprite().getGlobalBounds())) {
        if (Collision::BoundingBoxTest(sprite, obj->getSprite())) {
            return true;
        }
    } else {
        return false;
    }
}

// �������������� ���������� �� � � ����
double convertMeters(double meters)
{
    return (meters * 21.34);
}

// �������������� �������� �� ��/� � ����/�
double convertSpeed(double speed)
{
    return (speed * 5.92);
}

double sqr(double x)
{
    return x*x;
}