#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Enemy.h"

int main(){
    RenderWindow window(VideoMode(800, 600), "Enemy");
    window.setMouseCursorVisible(false);
    //This ensures that the window will refresh at the same speed as the monitor to avoid sampling issues
    window.setVerticalSyncEnabled(true);
    Enemy enemy(800, 600);
    
    while(window.isOpen()){
        
        
        
        Event event;
        while(window.pollEvent(event)){
           
            if(event.type ==  Event::Closed){
                window.close();
                break;
            }
            
            
            
         
        }   
        
        window.clear(Color::Black);      //This sets the window black
        enemy.draw(window);
        window.display();               //This applies the changes to the window
        
     }
    
    return 0;
}