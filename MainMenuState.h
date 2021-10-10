
#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include"GameStates.h"
#include"Button.h"


class MainMenuState :
	public State
{
private:

    // Variables
    sf::Texture bgTexture;
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button*>buttons;

    // Funtions
    void initVariables();
    void initBackground();
    void initFonts();
    void initKeybinds();
    void initButtons();

public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~MainMenuState();

    //Funtions
    void endState();

    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget* target = NULL);
    void render(sf::RenderTarget* target = NULL);
};

#endif // !MAINMENUSTATE_H



