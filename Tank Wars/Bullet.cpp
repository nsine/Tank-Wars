#include "Bullet.h"


Bullet::Bullet(Vector2f pos, float angle, Texture *tex, IntRect rect) :
GameObject(pos, *tex, rect)
{
    texture = tex;
    this->angle = angle;
    sprite.setRotation(angle);
    speed = convertSpeed(100);
    dx = (speed) / 800 * cos(angle * 3.14 / 180);
    dy = (speed) / 800 * sin(angle * 3.14 / 180);
    life = true;
}

void Bullet::update(double time, View &view, RenderWindow &window,
    Player &player, std::list<Enemy*> &enemies, std::list<Animation*> &anims)
{
    position.x += dx * time;
    position.y += dy * time;

    if ((position.x > (view.getCenter().x + (window.getSize().x / 2))) ||
        (position.y > (view.getCenter().y + (window.getSize().y / 2))) ||
        (position.x < (view.getCenter().x - (window.getSize().x / 2))) ||
        (position.y < (view.getCenter().y - (window.getSize().y / 2)))) {
        dx = 0;
        life = false;
    }

    /*GameObject *objPlayer = &player;
    if (checkCollision(objPlayer)) {
        life = false;
    }*/

    for (std::list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
        GameObject *obj_enemy = *it;
        if (checkCollision(obj_enemy) == true) {
            life = false;
            anims.push_back(new Animation(*texture, 13, false, IntRect(0, 10, 40, 40), Vector2f(position.x, position.y)));
        }
    }
    sprite.setPosition(position.x, position.y);
}

bool Bullet::isAlive()
{
    return life;
}