#ifndef BULLET_H
#define BULLET_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>

using namespace sf;
class Bullet{
public:
    //A bullet must have a  starting point. this can be the (x, y) co-ordinates 
    // of the spaceship that shot it.
    Bullet(int x, int y); 
    
    //A bullet must be draw in a window
    void draw(RenderWindow& window);
    
    //Getters of the current position of the bullet. This can be useful to identify colisions
    int getXPos();
    int getYPos();
    
    // This function will create the foward movement of the bullet
    void move(RenderWindow& window);
private:
    // Current (x, y) position of the bullets
    int _xPos;
    int _yPos;
    int _radius;
    int _theta;
    
    //The bullets graphical representation
    CircleShape _bullet;
    
};




#endif