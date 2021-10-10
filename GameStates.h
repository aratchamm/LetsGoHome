#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class GameStates :
    public State
{
private:
    Player *player;

    // Funtions

    void initKeybinds();
    void initTextures();
    void initPlayers();

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