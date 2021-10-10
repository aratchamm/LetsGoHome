#pragma once
#ifndef GAME.H

#include"MainMenuState.h"

class Game
{

private:

	// Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*>states;


	std::map<std::string, int> supportedKeys;

	//Initialization

	void initWindow();
	void initKeys();
	void initStates();
	



	public:
		Game();
		virtual ~Game();

		// Funtions

		// Regular
		void endApplication();

		// Update
		void updateDt();
		void UpdateSFMLEvents();
		void Update();
		
		// Render
		void render();

		//Core
		void run();
};

#endif GAME.H