#ifndef STATE_H
#define STATE_H


#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<stack>
#include<map>
#include<vector>

#include"SFML/Graphics.hpp"
#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Network.hpp"
#include"SFML/Audio.hpp"
#include<vector>

class State
{
private:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textires;
	bool quit;



public:
	State(sf::RenderWindow* window);
	virtual ~State();

	const bool& getQuit() const;


	virtual void checkForQuit();
	virtual void endState() = 0; 
	virtual void updateKeybinds(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif // STATE_H
