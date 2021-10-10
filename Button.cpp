#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hovercolor, sf::Color activeColor)
{

	this->buttonState = BTN_IDLE;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color(79, 109, 189, 255));
	this->text.setCharacterSize(44);
	this->text.setLetterSpacing(5);
	this->text.setOutlineColor(sf::Color::White);
	this->text.setOutlineThickness(2);

	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width /2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) / 2.f - this->text.getGlobalBounds().height / 2.f
	);

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->shape.setFillColor(this->idleColor);
	this->shape.setFillColor(this->hoverColor);
	this->shape.setFillColor(this->activeColor);



}

Button::~Button()
{
}

const bool Button::isPressed() const
{
	if (this->buttonState == BTN_ACTIVE)
		return true;

	return false;
}

// Accessors

// Funtions

void Button::update(const sf::Vector2f mousePos)
{
	/* update the booleans for hover and pressed*/

	// Idle
	this->buttonState = BTN_IDLE;

	// Hover
	
	if (this->shape.getGlobalBounds().contains(mousePos)) {

		this->buttonState = BTN_HOVER;

		// Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->buttonState = BTN_ACTIVE;

		}
	}

	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->shape.setFillColor(this->idleColor);
		break;

	case BTN_HOVER:
		this->shape.setFillColor(this->idleColor);
		break;


	case BTN_ACTIVE:
		this->shape.setFillColor(this->idleColor);
		break;

	default:
		this->shape.setFillColor(sf::Color(79, 109, 179, 255));
		break;
	}
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}

