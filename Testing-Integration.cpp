#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"
#include "SplashWindow.h"

#include <vector>
#include <memory>


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

int main(){
    
    SplashWindow windowIntro;
    windowIntro.run();
    
    if(windowIntro.isQuitingGame()){
        return 0;
    }
    
    RenderWindow window(VideoMode(800, 600), "Integrated Test 1");
    window.setMouseCursorVisible(false);
    
    //This ensures that the window will refresh at the same speed as the monitor to avoid sampling issues
    window.setVerticalSyncEnabled(true);
    
    auto player_ptr = make_unique<Player>(800, 600);
    auto enemy_ptr = make_unique<Enemy>(800, 600);
    
    std::vector<Bullet> vectorOfBullets;
    
    while(window.isOpen()){

              //This applies the changes to the window
        
        
        
        Event event;
        while(window.pollEvent(event)){
           
            if(event.type ==  Event::Closed){
                window.close();
                break;
            }
            
            // Press any Key and Bullet moves
            if(event.type == Event::KeyPressed){  
                player_ptr->action(event); 
                
            }
            
            if(player_ptr->isShotFired()){
                auto newBullet = make_unique<Bullet>(player_ptr->getXPos(), player_ptr->getYPos(), player_ptr->getRadius());
                vectorOfBullets.push_back(*newBullet);
                player_ptr->shoot(false);
            
            }

         
        }
        

        window.clear(Color::Black);      //This sets the window black
        for( auto it = begin(vectorOfBullets); it != end(vectorOfBullets); it++){
            it->draw(window);
            it->move(window);
        }
       

        player_ptr->draw(window);
        enemy_ptr->draw(window);

        window.display(); 
     }
    
    return 0;
}