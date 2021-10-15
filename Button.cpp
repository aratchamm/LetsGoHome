#include "Button.h"

Button::Button(float x, float y, float width, float height, 
	sf::Font* font, std::string text, sf::Color outlineIdle_color, sf::Color outlineHover_color,
	sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
	sf::Color idleColor, sf::Color hovercolor, sf::Color activeColor)
{

	this->buttonState = BTN_IDLE;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setFillColor(idleColor);

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(text_idle_color);
	this->text.setCharacterSize(44);
	this->text.setLetterSpacing(5);
	this->text.setOutlineColor(outlineIdle_color);
	this->text.setOutlineThickness(2);

	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width /2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) / 2.f - this->text.getGlobalBounds().height / 2.f
	);

	this->textIdleColor = text_idle_color;
	this->textActiveColor = text_active_color;
	this->textHoverColor = text_hover_color;

	this->OutlineIdleColor = outlineIdle_color;
	this->OutlineHoverColor = outlineHover_color;

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

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
		this->text.setFillColor(this->textIdleColor);
		this->text.setOutlineColor(this->OutlineIdleColor);

		break;

	case BTN_HOVER:
		this->shape.setFillColor(this->idleColor);
		this->text.setFillColor(this->textHoverColor);
		this->text.setOutlineColor(this->OutlineHoverColor);
		break;


	case BTN_ACTIVE:
		this->shape.setFillColor(this->idleColor);
		this->text.setFillColor(this->textActiveColor);
		this->text.setOutlineColor(this->OutlineHoverColor);
		break;

	default:
		this->shape.setFillColor(sf::Color::Transparent);
		break;
	}
}

void Button::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
	target.draw(this->text);
}

