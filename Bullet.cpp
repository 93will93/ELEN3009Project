#include "Bullet.h"
#include <iostream>


Bullet::Bullet(int x, int y, int radius):
    _xPos{x},
    _yPos{y},
    _radius{radius}
    {
        _bullet.setRadius(5);
        _bullet.setFillColor(Color::White);
        _bullet.setPosition(_xPos, _yPos);
    }
    
void Bullet::draw(RenderWindow& window){
    window.draw(_bullet);
}
void Bullet::setPosition(int x, int y){
    _xPos = 0;
    _yPos = 0;
    _bullet.setPosition(_xPos, _yPos);
}

int Bullet::getXPos(){
    return _xPos;
}

int Bullet::getYPos(){
    return _yPos;
}

void Bullet::move(RenderWindow& window){
    auto speedOfBulletInPixels = 5;
    
    int xCenterOfWindow = (window.getSize().x)/2;
    int yCenterOfWindow = (window.getSize().y)/2;
    auto xIncrement = speedOfBulletInPixels*(xCenterOfWindow - _xPos )/_radius;
    auto yIncrement = speedOfBulletInPixels*(yCenterOfWindow - _yPos )/_radius;
    
    _bullet.move(xIncrement, yIncrement);
}