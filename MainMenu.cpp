#include "MainMenu.h"

MainMenu::MainMenu(float width, float height)
{
	if (!font.loadFromFile("Fonts/Pixeboy-z8XGD.ttf")) {
		std::cout << "No font is here" << std::endl;
	}

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color(76, 107, 179, 255));
	mainMenu[1].setOutlineColor(sf::Color::White);
	mainMenu[1].setOutlineThickness(2);
	mainMenu[1].setString("START");
	mainMenu[1].setCharacterSize(42);
	mainMenu[1].setLetterSpacing(5);
	mainMenu[1].setPosition(290, 380);

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color(76, 107, 179, 255));
	mainMenu[2].setOutlineColor(sf::Color::White);
	mainMenu[2].setOutlineThickness(2);
	mainMenu[2].setString("SCORE");
	mainMenu[2].setCharacterSize(42);
	mainMenu[2].setLetterSpacing(5);
	mainMenu[2].setPosition(490, 380);

	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(sf::Color(76, 107, 179, 255));
	mainMenu[3].setOutlineColor(sf::Color::White);
	mainMenu[3].setOutlineThickness(2);
	mainMenu[3].setString("ABOUT");
	mainMenu[3].setCharacterSize(42);
	mainMenu[3].setLetterSpacing(5);
	mainMenu[3].setPosition(690, 380);

	mainMenu[4].setFont(font);
	mainMenu[4].setFillColor(sf::Color(76, 107, 179, 255));
	mainMenu[4].setOutlineColor(sf::Color::White);
	mainMenu[4].setOutlineThickness(2);
	mainMenu[4].setString("EXIT");
	mainMenu[4].setCharacterSize(42);
	mainMenu[4].setLetterSpacing(5);
	mainMenu[4].setPosition(900, 380);
	
	
	MainMenuSelected = 0;

}

MainMenu::~MainMenu()
{
}

void MainMenu::draw(sf::RenderWindow& window)
{
	for (int i = 1; i < Max_main_menu; i++) {
		window.draw(mainMenu[i]);
	}
}


void MainMenu::HoverMouse_start() {

	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setOutlineColor(Color(76, 107, 179, 255));
	mainMenu[1].setOutlineThickness(2);

}

void MainMenu::HoverMouse_score() {

	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setOutlineColor(Color(76, 107, 179, 255));
	mainMenu[2].setOutlineThickness(2);

}

void MainMenu::HoverMouse_about() {

	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setOutlineColor(Color(76, 107, 179, 255));
	mainMenu[3].setOutlineThickness(2);

}

void MainMenu::HoverMouse_exit() {

	mainMenu[4].setFillColor(Color::White);
	mainMenu[4].setOutlineColor(Color(76, 107, 179, 255));
	mainMenu[4].setOutlineThickness(2);
}

void MainMenu::UnHoverMouse_start() {

	mainMenu[1].setOutlineColor(Color::White);
	mainMenu[1].setOutlineThickness(2);
	mainMenu[1].setFillColor(Color(76, 107, 179, 255));
}

void MainMenu::UnHoverMouse_score()
{
	mainMenu[2].setOutlineColor(Color::White);
	mainMenu[2].setOutlineThickness(2);
	mainMenu[2].setFillColor(Color(76, 107, 179, 255));
}

void MainMenu::UnHoverMouse_about()
{
	mainMenu[3].setOutlineColor(Color::White);
	mainMenu[3].setOutlineThickness(2);
	mainMenu[3].setFillColor(Color(76, 107, 179, 255));
}

void MainMenu::UnHoverMouse_exit()
{
	mainMenu[4].setOutlineColor(Color::White);
	mainMenu[4].setOutlineThickness(2);
	mainMenu[4].setFillColor(Color(76, 107, 179, 255));
}
