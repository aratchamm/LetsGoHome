#include "MainMenu.h"

MainMenu::MainMenu(float width, float height)
{
	if (!font.loadFromFile("Fonts/Pixeboy-z8XGD.ttf")) {
		std::cout << "No font is here" << std::endl;
	}

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color(79, 109, 179, 255));
	mainMenu[1].setOutlineColor(sf::Color::White);
	mainMenu[1].setOutlineThickness(3);
	mainMenu[1].setString("START");
	mainMenu[1].setCharacterSize(50);
	mainMenu[1].setLetterSpacing(5);
	mainMenu[1].setPosition(530, 550);

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color(79, 109, 179, 255));
	mainMenu[2].setOutlineColor(sf::Color::White);
	mainMenu[2].setOutlineThickness(3);
	mainMenu[2].setString("SCORE");
	mainMenu[2].setCharacterSize(50);
	mainMenu[2].setLetterSpacing(5);
	mainMenu[2].setPosition(780, 550);

	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(sf::Color(79, 109, 179, 255));
	mainMenu[3].setOutlineColor(sf::Color::White);
	mainMenu[3].setOutlineThickness(3);
	mainMenu[3].setString("ABOUT");
	mainMenu[3].setCharacterSize(50);
	mainMenu[3].setLetterSpacing(5);
	mainMenu[3].setPosition(1030, 550);

	mainMenu[4].setFont(font);
	mainMenu[4].setFillColor(sf::Color(79, 109, 179, 255));
	mainMenu[4].setOutlineColor(sf::Color::White);
	mainMenu[4].setOutlineThickness(3);
	mainMenu[4].setString("EXIT");
	mainMenu[4].setCharacterSize(50);
	mainMenu[4].setLetterSpacing(5);
	mainMenu[4].setPosition(1280, 550);
	
	
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

void MainMenu::MoveLeft()
{

	if (MainMenuSelected - 1 >= 0) {

		mainMenu[MainMenuSelected].setFillColor(Color(79, 109, 179, 255));
		mainMenu[MainMenuSelected].setOutlineColor(Color::White);
		mainMenu[MainMenuSelected].setOutlineThickness(3);

		MainMenuSelected--;

		if (MainMenuSelected == 0) {
			MainMenuSelected = 4;
		}

		mainMenu[MainMenuSelected].setFillColor(Color::White);
		mainMenu[MainMenuSelected].setOutlineColor(Color(79, 109, 179, 255));
		mainMenu[MainMenuSelected].setOutlineThickness(3);

	}
}

//Move Right


void MainMenu::MoveRight()
{

	if (MainMenuSelected + 1 <= Max_main_menu) {

		mainMenu[MainMenuSelected].setOutlineColor(Color::White);
		mainMenu[MainMenuSelected].setOutlineThickness(3);
	    mainMenu[MainMenuSelected].setFillColor(Color(79, 109, 179, 255));

		MainMenuSelected++;

		if (MainMenuSelected == 5) {
			MainMenuSelected = 1;
		}

		mainMenu[MainMenuSelected].setFillColor(Color::White);
		mainMenu[MainMenuSelected].setOutlineColor(Color(79, 109, 179, 255));
		mainMenu[MainMenuSelected].setOutlineThickness(3);
	}

}
