#include "GameStates.h"

// Intializer funtions
void GameStates::initKeybinds()
{
	this->keybinds.emplace("MOVE_LEFT",this->supportedKeys->at("A"));
	this->keybinds.emplace("MOVE_RIGHT", this->supportedKeys->at("D"));
	this->keybinds.emplace("MOVE_UP", this->supportedKeys->at("W"));
	this->keybinds.emplace("MOVE_DOWN", this->supportedKeys->at("S"));
	this->keybinds.emplace("CLOSE", this->supportedKeys->at("Escape"));
}

void GameStates::initTextures()
{
	if (!this->textures["PLAYER_SHEET"].loadFromFile("img/character/playersheet_1.png")) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_TEXTURE";
	}

}

void GameStates::initPlayers()
{
	this->player = new Player(0, 0, this->textures["PLAYER_SHEET"]);
}

// Constructors / Destructors
GameStates::GameStates(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys,states)
{
	this->initKeybinds();
	this->initTextures();
	this->initPlayers();
}

GameStates::~GameStates()
{
	delete this->player;
}


void GameStates::endState()
{
	//std::cout << "Ending GameState!" << "\n";
}


void GameStates::updateInput(const float& dt)
{
	this->checkForQuit();


	// Update Player Input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT")))) {
		this->player->move(-1.f, 0.f, dt);
	}
		

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT")))) {
		this->player->move(1.f, 0.f, dt);
	}
		

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))) {
		this->player->move(0.f, -1.f, dt);
	}
		

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN")))) {
		this->player->move(0.f, 1.f, dt);
	}
		

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();

}

void GameStates::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->player->update(dt);
}

void GameStates::render(sf::RenderTarget* target)
{

	if (!target)
		target = this->window;

	this->player->render(this->window);
	
	
}
