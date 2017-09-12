#include "Enemy.h"

Enemy::Enemy(int xWindow, int yWindow){
    _xPos = (xWindow/2) - 20;
    _yPos = (yWindow/2) - 40;
    
    if(!_EnemyTexture.loadFromFile("enemy.png")){
        std::cerr << "Error Loading Enemy Texture";
    }
    
// //   _EnemyTexture.setSmooth(true);   
    _Enemy.setTexture(_EnemyTexture);
    _Enemy.setScale(Vector2f(0.025, 0.025));
    _Enemy.setPosition(_xPos, _yPos);
}

void Enemy::draw(RenderWindow& window){
        window.draw(_Enemy);
}


Sprite Enemy::getEnemy(){
    return _Enemy;
}