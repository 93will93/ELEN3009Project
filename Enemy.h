#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

using namespace sf;
class Enemy{
public:
    Enemy(int xWindow, int yWindow);
    
    void draw(RenderWindow& window);
    Sprite getEnemy();
    
private:
    int _xPos;
    int _yPos;
    
    Texture _EnemyTexture;
    Sprite _Enemy;
    
};







#endif