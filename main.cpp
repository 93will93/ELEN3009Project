
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void handlePlayerInput(Keyboard::Key key, bool isPressed);

int main(){
    //Creating a window
    RenderWindow window(VideoMode(800, 600), "My window");
    
    //This ensures that the window will refresh at the same speed as the monitor to avoid sampling issues
    window.setVerticalSyncEnabled(true); 

    // Creating a Texture for the player spaceship
    Texture playerSpaceshipTexture;
        if(!playerSpaceshipTexture.loadFromFile("Untitled-1.png"))
            cerr << "Player Spaceship Texture could not be loaded" << endl;
            
    //Player Sprite
    Sprite Player;
    Player.setTexture(playerSpaceshipTexture);
    Player.setScale(Vector2f(0.1, 0.1));
    Player.setPosition(Vector2f(380, 530));


    //The Game Loop
   while(window.isOpen()){
        window.clear(Color::Black);      //This sets the window black
        window.draw(Player);
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
            }
            
            if(keyPressed == true){
                switch (event.key.code){
                    case Keyboard::W:
                        Player.move(sf::Vector2f(0, -10));
                        break;
                    case Keyboard::S:
                        Player.move(sf::Vector2f(0, 10));
                        break;
                    case Keyboard::A:
                        Player.move(sf::Vector2f(-10, 0));
                        break;
                    case Keyboard::D:
                        Player.move(sf::Vector2f(10, 0));
                        break;
                        
                }
            }
            
        }
         
        
    }
    
    
	return 0;
}


//Handling Events

//            
//            // This Will output the size of the window after it has been resized by the user
//            if (event.type == sf::Event::Resized){
//                std::cout << "new width: " << event.size.width << std::endl;
//                std::cout << "new height: " << event.size.height << std::endl;
//            }
//            
//           
//                
//        }

