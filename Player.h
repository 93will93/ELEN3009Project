#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Player{
public:
    Player(int xWindow, int yWindow);
    void move(Event event);
    int getXPos();
    int getYPos();
    Sprite getPlayer();
    
private:    
    int _xPos;
    int _yPos;
    Texture _playerSpaceshipTexture;
    Sprite _Player;
};

#endif