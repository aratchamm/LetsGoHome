
#include "Player.h"

// Initializer funtions
void Player::initVariables()
{
}

void Player::initComponents()
{

}

// Constructors / Destructors
Player::Player(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();
	
	this->setPosition(x, y);

	this->createMovementComponent(80.0f, 15.f, 5.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE_DOWN", 10.f, 0, 4, 2, 4, 32, 32);
	this->animationComponent->addAnimation("IDLE_UP", 10.f, 0, 7, 2, 7, 32, 32);
	this->animationComponent->addAnimation("IDLE_LEFT", 10.f, 0, 5, 2, 5, 32, 32);
    this->animationComponent->addAnimation("IDLE_RIGHT", 10.f, 0, 6, 2, 6, 32, 32);
	this->animationComponent->addAnimation("WALK_LEFT", 10.f, 0, 1, 2, 1, 32, 32);
	this->animationComponent->addAnimation("WALK_RIGHT", 10.f, 0, 2, 2, 2, 32, 32);
	this->animationComponent->addAnimation("WALK_UP", 10.f, 0, 3, 2, 3, 32, 32);
	this->animationComponent->addAnimation("WALK_DOWN", 10.f, 0, 0, 2, 0, 32, 32);
}

int player_idle = 'D';

Player::~Player()
{

}

//Funtions
void Player::update(const float& dt)
{
	this->movementComponent->update(dt);

	if (this->movementComponent->getState(IDLE)) {
		if (player_idle == 'D')this->animationComponent->play("IDLE_DOWN", dt);
		if (player_idle == 'U')this->animationComponent->play("IDLE_UP", dt);
		if (player_idle == 'L')this->animationComponent->play("IDLE_LEFT", dt);
		if (player_idle == 'R')this->animationComponent->play("IDLE_RIGHT", dt);

	}
	else if (this->movementComponent->getState(MOVING_LEFT)) {
		this->animationComponent->play("WALK_LEFT", dt);
		player_idle = 'L';
	}
	else if (this->movementComponent->getState(MOVING_RIGHT)) {
		this->animationComponent->play("WALK_RIGHT", dt);
		player_idle = 'R';
	}
	else if (this->movementComponent->getState(MOVING_UP)) {
		this->animationComponent->play("WALK_UP", dt);
		player_idle = 'U';
	}
	else if (this->movementComponent->getState(MOVING_DOWN)) {
		this->animationComponent->play("WALK_DOWN", dt);
		player_idle = 'D';
	}

}
