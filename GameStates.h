#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class GameStates :
    public State
{
private:
    Entity player;

    // Funtions

    void initKeybinds();

public:
    GameStates(sf::RenderWindow * window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~GameStates();

    //Funtions
    void endState();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

#endif // !GAMESTATE_H