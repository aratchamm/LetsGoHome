#pragma once
#ifndef GAME.H



#include"GameStates.h"

class Game
{

private:

	// Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*>states;


	//Initialization

	void initWindow();
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