#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

#define PI 3.14159265

using namespace sf;

class Player{
public:
    // The constructor creates a player object correctly positon for any window size
    // No default constructor is provided as the Player class invariant is such that the player must
    // appear in the same position for any window size therefore the window size is required to create the Player
    Player(int xWindow, int yWindow);
    
    // The action function choses what action the player takes. SFML events are a union therefore only one event can
    // take place at a time. action choses what event is happening( Player is Shotting or Moving)
    void action(Event event);
    
    // Accessors of Position might be useful to know where a bullet is shot from
    int getXPos();
    int getYPos();
    bool isShotFired();
    
    // Useful to get the graphgical represetnation of the player class.
    Sprite getPlayer();
    
    //This function will draw the player in the window.
    void draw(RenderWindow& window);
    void shoot(bool shooting);
    
private: 
    // Current Position of the Player
    int _xPos;
    int _yPos;
    
    // Center of rotation for the player
    int _xOrigen;
    int _yOrigen;
    
    // Angle and Radius of Rotation
    float _theta;
    int  _radius;
    
    // Sprite Object graphical representation of the Object
    Texture _playerSpaceshipTexture;
    Sprite _Player;
    
    //Moving Functions
    void Move(Event event);
    void angleOfRotation();
    
    //When player shoots this function is called

    bool _shotFired;
    
    //Tools to perform angle convertions
    float radiansToDegrees(float x);
    float degreesToRadians(float x);
};

#endif