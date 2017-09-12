#include "Player.h"


Player::Player(int xWindow, int yWindow){

    /// This has to be fixed with the size of the sprite
        _xPos = (xWindow/2) - 20; // This is half of the x axis and - 20 because of the size of the sprite
        _yPos = yWindow - 70 ;    // -70 because of the sizie of sprite
        _theta = (PI)/2;       // 270 degrees.
        _radius = _yPos/2 -20 ;
        
        //Setting up the origin
        _xOrigen = _xPos ;
        _yOrigen = (yWindow/2) - 40;
        
        if(!_playerSpaceshipTexture.loadFromFile("player.png")){
            std::cerr << "Error Loading Player Texture";
        }
        _playerSpaceshipTexture.setSmooth(true);   
        _Player.setTexture(_playerSpaceshipTexture);
        _Player.setScale(Vector2f(0.1, 0.1));
        _Player.setPosition(_xPos, _yPos);
}

void Player::draw(RenderWindow& window){
    window.draw(_Player);
}
 ///***********************************
 /// Player actions Functions
 ///***********************************
 void Player::action(Event event){

     switch (event.key.code){
            case Keyboard::W:
            case Keyboard::D:
                Move(event);
                break;                
            case Keyboard::S:
            case Keyboard::A:
                Move(event);
                break;
            case Keyboard::Space:
                shoot();
                break;
            default:
                break;
     }             
 }
 
 void Player::shoot(){
      std::cout << "Shooting";
 }

void Player::Move(Event event){ //This function uses angleOfRotation to move clockwise or anticlockwise
 
    if(event.key.code == Keyboard::D || event.key.code == Keyboard::W){
        _theta = _theta + degreesToRadians(5);
        angleOfRotation();
    }
    if(event.key.code == Keyboard::A || event.key.code == Keyboard::S ){
        _theta = _theta + degreesToRadians(-5);
        angleOfRotation();
    }
}

void Player::angleOfRotation(){ // This function uses the _theta and _radius values to calculate the postion in a unit circle
        _xPos = _xOrigen + _radius*cos(_theta);
        _yPos = _yOrigen + _radius*sin(_theta);
        _Player.setPosition(_xPos, _yPos);
}

 ///***********************************
 /// Getter Functions
 ///***********************************
Sprite Player::getPlayer(){
     return _Player;
}
 
int Player::getXPos(){
     return _xPos;
 }

int Player::getYPos(){
     return _yPos;
 }
 
 ///***********************************
 /// Convertion Functions
 ///***********************************
float Player::radiansToDegrees(float x){
     return (x*180)/PI;
 }
 
float Player:: degreesToRadians(float x){
     return (x*PI)/180;
 }