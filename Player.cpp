
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

	this->createMovementComponent(100.0f, 5.f, 5.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE_DOWN", 100.f, 0, 4, 2, 0, 32, 32);
	this->animationComponent->addAnimation("IDLE_UP", 10.f, 0, 7, 2, 0, 32, 32);
	this->animationComponent->addAnimation("IDLE_LEFT", 10.f, 0, 5, 2, 0, 32, 32);
    this->animationComponent->addAnimation("IDLE_RIGHT", 10.f, 0, 6, 2, 0, 32, 32);
	this->animationComponent->addAnimation("WALK_LEFT", 10.f, 0, 1, 2, 0, 32, 32);
	this->animationComponent->addAnimation("WALK_RIGHT", 10.f, 0, 2, 2, 0, 32, 32);
	this->animationComponent->addAnimation("WALK_UP", 10.f, 0, 3, 2, 0, 32, 32);
	this->animationComponent->addAnimation("WALK_DOWN", 10.f, 0, 0, 2, 0, 32, 32);
}


Player::~Player()
{

}

//Funtions
void Player::update(const float& dt)
{
	this->movementComponent->update(dt);

	if (this->movementComponent->getState(IDLE))
		this->animationComponent->play("IDLE_DOWN", dt);
	else if (this->movementComponent->getState(MOVING_LEFT))
		this->animationComponent->play("WALK_LEFT", dt);


}
