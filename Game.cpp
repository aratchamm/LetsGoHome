#include "Game.h"

// Static funtions

//Initializer funtion

void Game::initWindow()
{
	std::ifstream ifs("Config/window.ini");

	std::string title = "None";
	sf::VideoMode window_bounds(800, 600);
	unsigned framerate_limit = 120;
	bool vertical_sunc_ebabled = false;
	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sunc_ebabled;
	}

	ifs.close();

	
	
	this->window = new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sunc_ebabled);
}

void Game::initStates()
{
	this->states.push(new GameStates(this->window));
}


Game::Game() {

	this->initWindow();
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

void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();

	
}
