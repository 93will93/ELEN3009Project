#include "Player.h"


Player::Player(int xWindow, int yWindow){
    /// This has to be fixed with the size of the sprite
        _xPos = (xWindow/2) - 20; // This is half of the x axis and - 20 because of the size of the sprite
        _yPos = yWindow - 70 ;    // -70 because of the sizie of sprite      
        if(!_playerSpaceshipTexture.loadFromFile("Untitled-1.png")){
            std::cerr << "Error Loading Player Texture";
        }
         _playerSpaceshipTexture.setSmooth(true);   
        _Player.setTexture(_playerSpaceshipTexture);
        _Player.setScale(Vector2f(0.1, 0.1));
        _Player.setPosition(380, 530);
}

 Sprite Player::getPlayer(){
     return _Player;
 }
 
 void Player::move(Event event){
    
     int pixelsToMove = 15; // This is how many pixels the player moves to the chosen direction
     switch (event.key.code){
            case Keyboard::W:
                _Player.move(sf::Vector2f(0, -pixelsToMove));
                _yPos = _yPos - pixelsToMove;
                break;
            case Keyboard::S:
                _Player.move(sf::Vector2f(0, pixelsToMove));
                _yPos = _yPos - pixelsToMove;
                break;
            case Keyboard::A:
                _Player.move(sf::Vector2f(-pixelsToMove, 0));
                _xPos = _xPos - pixelsToMove;
                break;
            case Keyboard::D:
                _Player.move(sf::Vector2f(pixelsToMove, 0));
                _xPos = _xPos + pixelsToMove;
                break;
            case Keyboard::Space:
                std::cout << "Shooting";
                break;
            default:
                break;
     }             
 }
 
 
 int Player::getXPos(){
     return _xPos;
 }
 
 int Player::getYPos(){
     return _yPos;
 }