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
		void updateDt();
		void Update();
		void UpdateSFMLEvents();
		void render();
		void run();
};

#endif GAME.H