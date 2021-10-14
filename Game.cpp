#include "Game.h"

// Static funtions

//Initializer funtion

void Game::initWindow()
{

	std::string title = "None";
	sf::VideoMode window_bounds(1920, 1080);
	unsigned framerate_limit = 120;
	bool vertical_sunc_ebabled = false;
	
	
	this->window = new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sunc_ebabled);
}

void Game::initKeys()
{
	this->supportedKeys.emplace("Escape", sf::Keyboard::Key::Escape);
	this->supportedKeys.emplace("A", sf::Keyboard::Key::A);
	this->supportedKeys.emplace("D", sf::Keyboard::Key::D);
	this->supportedKeys.emplace("W", sf::Keyboard::Key::W);
	this->supportedKeys.emplace("S", sf::Keyboard::Key::S);

}

void Game::initStates()
{
	this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
}

Game::Game() {

	this->initWindow();
	this->initKeys();
	this->initStates();
}

Game::~Game() {

	delete this->window;

	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
		
	
}

// Funtions
void Game::UpdateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent)) {
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}

}

void Game::Update()
{
	
	this->UpdateSFMLEvents();

	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit()) {

			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
		
	}		

	// Application end
	else {
		this->endApplication();
		this->window->close();
	}
	
}

void Game::render()
{

	this->window->clear();

	// Render item
	if (!this->states.empty())
		this->states.top()->render(this->window);
	this->window->display();

	
}

void Game::run()
{
	while (this->window->isOpen()) {
		this->updateDt();
		this->Update();
		this->render();
	}

}

void Game::endApplication()
{
}

void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();

	
}
