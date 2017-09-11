#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"

int main(){
    RenderWindow window(VideoMode(800, 600), "My window");
    
    //This ensures that the window will refresh at the same speed as the monitor to avoid sampling issues
    window.setVerticalSyncEnabled(true);
    Player player(800, 600);
    
     while(window.isOpen()){
        window.clear(Color::Black);      //This sets the window black
        window.draw(player.getPlayer());
        window.display();               //This applies the changes to the window
        
        
        Event event;
        bool keyPressed;
        while(window.pollEvent(event)){
            // Checks if user attempts at closing the window
            switch (event.type){
                case Event::KeyPressed:
                    keyPressed = true;
                    break;
                case Event::KeyReleased:
                    keyPressed = false;
                    break;
                case Event::Closed:
                    window.close();
                    break;
                default:
                    continue;
            }
            
            player.move(event);
        }
        
        
     }
    
    return 0;
}