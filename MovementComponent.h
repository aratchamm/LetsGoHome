#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H


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

enum movement_state{IDLE=0, MOVING, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN};

class MovementComponent
{
private:

	sf::Sprite& sprite;

	float maxVelocity;
	float acceleration;
	float deceleration;

	sf::Vector2f velocity;
	
	// Intializer funtions

public:
	MovementComponent(sf::Sprite& sprite, 
		float maxVelocity,float acceleration, float deceleration);
	virtual ~MovementComponent();

	// Accessors
	const sf::Vector2f& getVelocity() const;

	//Funtions
	const bool getState(const short unsigned state) const;
	const bool idle() const;
	const bool moving() const;
	const bool movingLeft() const;
	const bool movingRight() const;

	void move(const float dir_x, const float dir_y, const float& dt);
	void update(const float& dt);

};
#endif