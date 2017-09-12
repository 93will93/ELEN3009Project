#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Bullet.h"

int main(){
    RenderWindow window(VideoMode(800, 600), "Bullet");
    window.setMouseCursorVisible(false);
    //This ensures that the window will refresh at the same speed as the monitor to avoid sampling issues
    window.setVerticalSyncEnabled(true);
    Bullet bullet(10, 10);
    
    while(window.isOpen()){
        window.clear(Color::Black);      //This sets the window black
        bullet.draw(window);
        window.display();               //This applies the changes to the window
        
        
        
        Event event;
        while(window.pollEvent(event)){
           
            if(event.type ==  Event::Closed){
                window.close();
                break;
            }
            
            // Press any Key and Bullet moves
            if(event.type == Event::KeyPressed){  
                bullet.move(window); 
                
            }      
         
        }   
        
        
        
     }
    
    return 0;
}