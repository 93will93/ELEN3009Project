#ifndef SPLASHWINDOW_H
#define SPLASHWINDOW_H



#include <SFML/Graphics.hpp>

using namespace sf;

class SplashWindow{
public:
    SplashWindow();
    void run();
    bool isQuitingGame();
private:
    void createWindow();
    void settingUpText();
    void hadleUserDecision(const Event& event);
    

    bool _isPlayerQuiting;
    
    Font _font;
    
    Text _instructionText;
    Text _continueOrQuitText;
    Text _continuePrompt;
    Text _gameRulesText;
//    Vector2i _windowSize;
    RenderWindow _window;
};
#endif