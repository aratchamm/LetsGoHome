#include "GameStates.h"

void GameStates::initKeybinds()
{
	this->keybinds.emplace("MOVE_LEFT",this->supportedKeys->at("A"));
	this->keybinds.emplace("MOVE_RIGHT", this->supportedKeys->at("D"));
	this->keybinds.emplace("MOVE_UP", this->supportedKeys->at("W"));
	this->keybinds.emplace("MOVE_DOWN", this->supportedKeys->at("S"));
}

GameStates::GameStates(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys,states)
{
	this->initKeybinds();
}

GameStates::~GameStates()
{

}


void GameStates::endState()
{
	//std::cout << "Ending GameState!" << "\n";
}


void GameStates::updateInput(const float& dt)
{
	this->checkForQuit();


	// Update Player Input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player.move(dt, -1.f, 0.f);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player.move(dt, 1.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player.move(dt, 0.f, -1.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player.move(dt, 0.f, 1.f);
}

void GameStates::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->player.update(dt);
}

void GameStates::render(sf::RenderTarget* target)
{

	

	if (!target)
		target = this->window;

	this->player.render(this->window);
	
	
}
