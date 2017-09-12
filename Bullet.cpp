#include "Bullet.h"
#include <iostream>

Bullet::Bullet():
    _xPos{-10},
    _yPos{-10}
    {
        _bullet.setPosition(_xPos, _yPos);
    };

Bullet::Bullet(int x, int y):
    _xPos{x},
    _yPos{y}
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
    auto speedOfBulletInPixels = 6;
//    _xPos = _xPos + speedOfBulletInPixels;
//    _yPos = _yPos + speedOfBulletInPixels;
//    auto xCenterOfWindow = (window.getSize().x)/2;
//    auto yCenterOfWindow = (window.getSize().y)/2;
//    //Applying the distance formula
//    auto xSquared_differnce = (_xPos - xCenterOfWindow)*(_xPos - xCenterOfWindow);
//    auto ySquared_differnce = (_yPos - yCenterOfWindow)*(_yPos - yCenterOfWindow);
//    _radius = sqrt( xSquared_differnce +  ySquared_differnce );
//    
//    _theta = atan((_xPos - xCenterOfWindow)/(_yPos - yCenterOfWindow));
//     //The bullets Position changes relative to the center by decreasing its distance to the center(_radius)
//    _radius = _radius - speedOfBulletInPixels;
//    
//   // new Position of the bullet
//    _xPos = xCenterOfWindow + _radius*cos(_theta);
//    _yPos = yCenterOfWindow  + _radius*sin(_theta);
//    
//    std::cout << _radius <<_xPos << " " <<_yPos << "\n";
    _bullet.move(speedOfBulletInPixels, speedOfBulletInPixels);
}