#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"

void handlingUserInput(Window window);
int main(){
    RenderWindow window(VideoMode(800, 600), "My window");
    window.setMouseCursorVisible(false);
    //This ensures that the window will refresh at the same speed as the monitor to avoid sampling issues
    window.setVerticalSyncEnabled(true);
    Player player(800, 600);
    
     while(window.isOpen()){
        window.clear(Color::Black);      //This sets the window black
        window.draw(player.getPlayer());
        window.display();               //This applies the changes to the window
        
        
        Event event;
        while(window.pollEvent(event)){
           
            if(event.type ==  Event::Closed){
                window.close();
                break;
            }
            
            if(event.type == Event::KeyPressed){    // Need to check this because mouse was been picked up as input
                player.action(event);  
                
            }          
        }   
        
        
     }
    
    return 0;
}
 