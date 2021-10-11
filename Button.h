#ifndef BUTTON_H
#define BUTTON_H

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<sstream>

#include"SFML/Graphics.hpp"
#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Audio.hpp"

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button
{
private:	

	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color textIdleColor;
	sf::Color textHoverColor;
	sf::Color textActiveColor;

	sf::Color OutlineIdleColor;
	sf::Color OutlineHoverColor;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;




public:
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text, sf::Color outlineIdle_color, sf::Color outlineHover_color,
		sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
		sf::Color idleColor, sf::Color hovercolor, sf::Color activeColor);
	~Button();

	// Accessors
	const bool isPressed() const;

	//Funtions
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);

};
#endif


