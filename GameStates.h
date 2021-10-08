#ifndef GAMESTATE_H

#include "State.h"

class GameStates :
    public State
{
private:

public:
    GameStates(sf::RenderWindow* window);
    virtual ~GameStates();

    //Funtions
    void endState();

    void updateKeybinds(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};

#endif // !GAMESTATE_H