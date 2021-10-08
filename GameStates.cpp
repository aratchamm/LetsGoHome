#include "GameStates.h"

GameStates::GameStates(sf::RenderWindow* window)
	:State(window)
{

}

GameStates::~GameStates()
{

}


void GameStates::endState()
{
	std::cout << "Ending GameState!" << "\n";
}


void GameStates::updateKeybinds(const float& dt)
{
	this->checkForQuit();
}

void GameStates::update(const float& dt)
{
	this->updateKeybinds(dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		std::cout << "A" << "\n";
}

void GameStates::render(sf::RenderTarget* target)
{

}
