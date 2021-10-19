#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <sfeMovie/Movie.hpp>
#include <string>
#include <iostream>
#include <algorithm>
#include <SFML/OpenGL.hpp>

#include"MainMenu.h"

void my_pause() {
#ifdef SFML_SYSTEM_WINDOWS
	system("PAUSE");
#endif
}




int main()
{

	// Create video logo //

	std::string logoFile = "img/bg/menu_logo.mp4";
	std::cout << "Going to open movie file \"" << logoFile << "\"" << std::endl;

	sfe::Movie movieLogo;
	if (!movieLogo.openFromFile(logoFile)) {
		my_pause();
		return 1;
	}

	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
	float width = std::min(static_cast<float>(desktopMode.width), movieLogo.getSize().x);
	float height = std::min(static_cast<float>(desktopMode.height), movieLogo.getSize().y);


	// Create short screne //

	std::string mediaFile = "img/bg/short screne.mp4";
	std::cout << "Going to open movie file \"" << mediaFile << "\"" << std::endl;

	sfe::Movie movie;
	if (!movie.openFromFile(mediaFile)) {
		my_pause();
		return 1;
	}

	int frame = 0;
	int frameAbout = 0;
	int frameMenu = 0;
	int frameScore = 0;
	int row = 0;
	int frameCounter = 0;
	int frameAboutCounter = 0;
	int frameMenuCounter = 0;
	int frameScoreCounter = 0;



	// Create the main window //

	sf::Vector2i screenDimensions(1920, 1080);

	sf::RenderWindow MENU(sf::VideoMode(screenDimensions.x, screenDimensions.y), "LET'S GO HOME");
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

	MENU.setKeyRepeatEnabled(false);
	MENU.setFramerateLimit(60);

	// Create the player window //

	sf::RectangleShape Pbackground(sf::Vector2f(1490.f, 936.f));
	Texture PlayerTexture;
	PlayerTexture.loadFromFile("img/bg/bg.png");
	Pbackground.setTexture(&PlayerTexture);
	Pbackground.setScale(4.f, 4.f);

	// water animation //

	sf::Texture waterTexture;
	sf::Sprite water;

	if (!waterTexture.loadFromFile("img/bg/water_animation.png"))
		std::cout << "Error could not load water" << std::endl;
	water.setTexture(waterTexture);

	
	// bg about //

	sf::Texture aboutTexture;
	sf::Sprite about;

	if (!aboutTexture.loadFromFile("img/bg/about_animation.png"))
		std::cout << "Error could not load about bg" << std::endl;
	about.setTexture(aboutTexture);

	// bg score //

	sf::Texture scoreTexture;
	sf::Sprite score;

	if (!scoreTexture.loadFromFile("img/bg/score_animation.png"))
		std::cout << "Error could not load about bg" << std::endl;
	score.setTexture(scoreTexture);

	// Create Sprite button //

	sf::RectangleShape StartButton(sf::Vector2f(165.0f, 60.0f));
	StartButton.setPosition({ 530.f, 570.f });
	StartButton.setFillColor(sf::Color::Transparent);

	sf::RectangleShape ScoreButton(sf::Vector2f(165.0f, 60.0f));
	ScoreButton.setPosition({ 780.f, 570.f });
	ScoreButton.setFillColor(sf::Color::Transparent);

	sf::RectangleShape AboutButton(sf::Vector2f(165.0f, 60.0f));
	AboutButton.setPosition({ 1030.f, 570.f });
	AboutButton.setFillColor(sf::Color::Transparent);

	sf::RectangleShape ExitButton(sf::Vector2f(145.0f, 60.0f));
	ExitButton.setPosition({ 1270.f, 570.f });
	ExitButton.setFillColor(sf::Color::Transparent);


	/***************************************************** game zone ***************************************************************/

	
	// create tileset //

	sf::RectangleShape Tileset(sf::Vector2f(145.0f, 60.0f));
	Tileset.setPosition({ 1270.f, 570.f });
	Tileset.setFillColor(sf::Color::Red);

	// create player //

	sf::Texture pTexture;
	sf::Sprite player;
	sf::Clock clock;

	if (!pTexture.loadFromFile("img/character/playersheet_1.png"))
		std::cout << "Error could not load player image" << std::endl;
	player.setTexture(pTexture);
	player.setScale(3.f, 3.f);

	// create view //

	sf::View view;
	view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y)); 
	sf::Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);  


	// Create Sprite button //

	sf::Texture Hover_scoreTexture;
	sf::Sprite Hover_scoreSprite;

	if (!Hover_scoreTexture.loadFromFile("img/bg/choose.png"))
		std::cout << "Error could not load choose image" << std::endl;
	Hover_scoreSprite.setTexture(Hover_scoreTexture);
	Hover_scoreSprite.setScale(0.3f, 0.3f);
	Hover_scoreSprite.setPosition(-100, -100);

	sf::Texture Hover_startTexture;
	sf::Sprite Hover_startSprite;

	if (!Hover_startTexture.loadFromFile("img/bg/choose.png"))
		std::cout << "Error could not load choose image" << std::endl;
	Hover_startSprite.setTexture(Hover_startTexture);
	Hover_startSprite.setScale(0.3f, 0.3f);
	Hover_startSprite.setPosition(-100, -100);

	sf::Texture Hover_aboutTexture;
	sf::Sprite Hover_aboutSprite;

	if (!Hover_aboutTexture.loadFromFile("img/bg/choose.png"))
		std::cout << "Error could not load choose image" << std::endl;
	Hover_aboutSprite.setTexture(Hover_aboutTexture);
	Hover_aboutSprite.setScale(0.3f, 0.3f);
	Hover_aboutSprite.setPosition(-100, -100);

	sf::Texture Hover_exitTexture;
	sf::Sprite Hover_exitSprite;

	if (!Hover_exitTexture.loadFromFile("img/bg/choose.png"))
		std::cout << "Error could not load choose image" << std::endl;
	Hover_exitSprite.setTexture(Hover_exitTexture);
	Hover_exitSprite.setScale(0.3f, 0.3f);
	Hover_exitSprite.setPosition(-100, -100);

	sf::Texture ExitSpriteTexture;
	sf::Sprite ExitSprite;

	if (!ExitSpriteTexture.loadFromFile("img/bg/exit.png"))
		std::cout << "Error could not load exit button" << std::endl;
	ExitSprite.setTexture(ExitSpriteTexture);
	ExitSprite.setScale(0.7f, 0.7f);

	sf::Texture ScoreSpriteTexture;
	sf::Sprite ScoreSprite;

	if (!ScoreSpriteTexture.loadFromFile("img/bg/score.png"))
		std::cout << "Error could not load choose image" << std::endl;
	ScoreSprite.setTexture(ScoreSpriteTexture);

	// create black sprite

	sf::Texture BlackTexture;
	sf::Sprite BlackSprite;

	if (!BlackTexture.loadFromFile("img/bg/black.png"))
		std::cout << "Error could not load black image" << std::endl;
	BlackSprite.setTexture(BlackTexture);

	sf::Texture PauseTexture;
	sf::Sprite PauseButton;

	if (!PauseTexture.loadFromFile("img/button/pause.png"))
		std::cout << "Error could not load pause button" << std::endl;
	PauseButton.setTexture(PauseTexture);
	PauseButton.setScale(1.5f, 1.5f);

	sf::Texture PlayTexture;
	sf::Sprite PlayButton;

	if (!PlayTexture.loadFromFile("img/button/play.png"))
		std::cout << "Error could not load play button" << std::endl;
	PlayButton.setTexture(PlayTexture);

	sf::Texture QuitTexture;
	sf::Sprite QuitButton;

	if (!QuitTexture.loadFromFile("img/button/quit.png"))
		std::cout << "Error could not load quit button" << std::endl;
	QuitButton.setTexture(QuitTexture);
	
	sf::Texture MenuTexture;
	sf::Sprite MenuButton;

	if (!MenuTexture.loadFromFile("img/button/menu.png"))
		std::cout << "Error could not load menu button" << std::endl;
	MenuButton.setTexture(MenuTexture);

	movieLogo.fit(0, 0, width, height);
	movieLogo.play();

	float dt;
	Clock dt_clock;

	const float movementSpeed = 300.f;
	Vector2f velocity;


	while (MENU.isOpen()) 
	{

		Event event;
		while (MENU.pollEvent(event)) 
		{

			while (MENU.pollEvent(event)) {
				if (event.type == Event::Closed) {
					MENU.close();
				}
				if (event.type == Event::KeyPressed) {
					if (event.key.code == Keyboard::Escape) {
						MENU.close();
					}
				}
			}


			int x = mainMenu.MainMenuPressed();

			// Check hover

			if (StartButton.getGlobalBounds().contains(MENU.mapPixelToCoords(sf::Mouse::getPosition(MENU))))
			{
				mainMenu.HoverMouse_start();	
				Hover_startSprite.setPosition(485, 590);

			}
			if (ScoreButton.getGlobalBounds().contains(MENU.mapPixelToCoords(sf::Mouse::getPosition(MENU))))
			{
				mainMenu.HoverMouse_score();
				Hover_scoreSprite.setPosition(735, 590);

			}
			if (AboutButton.getGlobalBounds().contains(MENU.mapPixelToCoords(sf::Mouse::getPosition(MENU))))
			{
				mainMenu.HoverMouse_about();
				Hover_aboutSprite.setPosition(985, 590);
			}
			if (ExitButton.getGlobalBounds().contains(MENU.mapPixelToCoords(sf::Mouse::getPosition(MENU))))
			{
				mainMenu.HoverMouse_exit();
				Hover_exitSprite.setPosition(1235, 590);
			}

			if (!StartButton.getGlobalBounds().contains(MENU.mapPixelToCoords(sf::Mouse::getPosition(MENU))))
			{
				mainMenu.UnHoverMouse_start();
				Hover_startSprite.setPosition(-100, -100);
			}
			if (!ScoreButton.getGlobalBounds().contains(MENU.mapPixelToCoords(sf::Mouse::getPosition(MENU))))
			{
				mainMenu.UnHoverMouse_score();
				Hover_scoreSprite.setPosition(-100, -100);

			}
			if (!AboutButton.getGlobalBounds().contains(MENU.mapPixelToCoords(sf::Mouse::getPosition(MENU))))
			{
				mainMenu.UnHoverMouse_about();

				Hover_aboutSprite.setPosition(-100, -100);
			}
			if (!ExitButton.getGlobalBounds().contains(MENU.mapPixelToCoords(sf::Mouse::getPosition(MENU))))
			{
				mainMenu.UnHoverMouse_exit();

				Hover_exitSprite.setPosition(-100, -100);
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (StartButton.getGlobalBounds().contains(MENU.mapPixelToCoords(sf::Mouse::getPosition(MENU))))
				{
					x = 1;
				}
				if (ScoreButton.getGlobalBounds().contains(MENU.mapPixelToCoords(sf::Mouse::getPosition(MENU))))
				{
					x = 2;
				}
				if (AboutButton.getGlobalBounds().contains(MENU.mapPixelToCoords(sf::Mouse::getPosition(MENU))))
				{
					x = 3;
				}
				if (ExitButton.getGlobalBounds().contains(MENU.mapPixelToCoords(sf::Mouse::getPosition(MENU))))
				{
					x = 4;
				}
			}
			if (event.type == Event::Closed) 
			{
				MENU.close();
			}

			if (x == 1)
			{

				RenderWindow SHORTSCRENE(VideoMode(screenDimensions.x, screenDimensions.y), "LET'S GO HOME");

				movie.fit(0, 0, 1920, 1080);
				movie.play();
				BlackSprite.setPosition(-100000, -100000);
				PauseButton.setPosition(-100000, -100000);
				PlayButton.setPosition(-100000, -100000);
				QuitButton.setPosition(-100000, -100000);
				MenuButton.setPosition(-100000, -100000);


				while (SHORTSCRENE.isOpen()) {
					sf::Event ev;
					while (SHORTSCRENE.pollEvent(ev)) {

						if (ev.type == sf::Event::KeyPressed) {
							switch (ev.key.code) {
							case sf::Keyboard::Space: {

								x = 'P';
								movie.stop();
								SHORTSCRENE.close();
								break;
							}
							default:
								break;
							}
						}
					}

					SHORTSCRENE.clear();
					movie.update();
					SHORTSCRENE.draw(movie);

					SHORTSCRENE.display();




				}

				if (x == 'P') {

					RenderWindow Play(VideoMode(screenDimensions.x, screenDimensions.y), "LET'S GO HOME");

					const float gridSize = 64.f;

					//Walls
					std::vector<RectangleShape> walls;

					RectangleShape wall;
					wall.setFillColor(Color::Red);
					wall.setSize(Vector2f(gridSize, gridSize));
					/*wall.setPosition(gridSize * 10, gridSize * 39);
					walls.push_back(wall);
					wall.setPosition(gridSize * 11, gridSize * 39);
					walls.push_back(wall);
					wall.setPosition(gridSize * 12, gridSize * 39);
					walls.push_back(wall);
					wall.setPosition(gridSize * 13, gridSize * 39);
					walls.push_back(wall);
					wall.setPosition(gridSize * 14, gridSize * 39);
					walls.push_back(wall);
					wall.setPosition(gridSize * 15, gridSize * 39);
					walls.push_back(wall);
					wall.setPosition(gridSize * 16, gridSize * 39);
					walls.push_back(wall);
					wall.setPosition(gridSize * 17, gridSize * 39);
					walls.push_back(wall);
					wall.setPosition(gridSize * 18, gridSize * 39);
					walls.push_back(wall);
					wall.setPosition(gridSize * 19, gridSize * 39);
					walls.push_back(wall);
					wall.setPosition(gridSize * 17, gridSize * 40);
					walls.push_back(wall);
					wall.setPosition(gridSize * 18, gridSize * 40);
					walls.push_back(wall);
					wall.setPosition(gridSize * 19, gridSize * 40);
					walls.push_back(wall);
					wall.setPosition(gridSize * 20, gridSize * 40);
					walls.push_back(wall);

					wall.setPosition(gridSize * 20, gridSize * 39);
					walls.push_back(wall);
					wall.setPosition(gridSize * 10, gridSize * 40);
					walls.push_back(wall);
					wall.setPosition(gridSize * 11, gridSize * 40);
					walls.push_back(wall);
					wall.setPosition(gridSize * 12, gridSize * 40);
					walls.push_back(wall);
					wall.setPosition(gridSize * 13, gridSize * 40);
					walls.push_back(wall);*/

					wall.setPosition(gridSize * 9, gridSize * 40);
					walls.push_back(wall);
					wall.setPosition(gridSize * 9, gridSize * 41);
					walls.push_back(wall);
					wall.setPosition(gridSize * 9, gridSize * 42);
					walls.push_back(wall);
					wall.setPosition(gridSize * 9, gridSize * 43);
					walls.push_back(wall);
					wall.setPosition(gridSize * 9, gridSize * 44);
					walls.push_back(wall);
					wall.setPosition(gridSize * 9, gridSize * 45);
					walls.push_back(wall);
					wall.setPosition(gridSize * 9, gridSize * 46);
					walls.push_back(wall);
					wall.setPosition(gridSize * 9, gridSize * 47);
					walls.push_back(wall);
					wall.setPosition(gridSize * 9, gridSize * 48);
					walls.push_back(wall);
					wall.setPosition(gridSize * 9, gridSize * 49);
					walls.push_back(wall);
					wall.setPosition(gridSize * 10, gridSize * 50);
					walls.push_back(wall);
					wall.setPosition(gridSize * 10, gridSize * 40);
					walls.push_back(wall);
					wall.setPosition(gridSize * 11, gridSize * 50);
					walls.push_back(wall);
					wall.setPosition(gridSize * 10, gridSize * 40);
					walls.push_back(wall);
					wall.setPosition(gridSize * 12, gridSize * 40);
					walls.push_back(wall);
					wall.setPosition(gridSize * 12, gridSize * 51);
					walls.push_back(wall);
					wall.setPosition(gridSize * 12, gridSize * 42);
					walls.push_back(wall);
					wall.setPosition(gridSize * 12, gridSize * 43);
					walls.push_back(wall);
					wall.setPosition(gridSize * 12, gridSize * 44);
					walls.push_back(wall);
					wall.setPosition(gridSize * 12, gridSize * 45);
					walls.push_back(wall);
					wall.setPosition(gridSize * 12, gridSize * 46);
					walls.push_back(wall);
					wall.setPosition(gridSize * 13, gridSize * 41);
					walls.push_back(wall);
					wall.setPosition(gridSize * 13, gridSize * 46);
					walls.push_back(wall);
					wall.setPosition(gridSize * 13, gridSize * 51);
					walls.push_back(wall);
					wall.setPosition(gridSize * 14, gridSize * 51);
					walls.push_back(wall);
					wall.setPosition(gridSize * 14, gridSize * 46);
					walls.push_back(wall);
					wall.setPosition(gridSize * 15, gridSize * 51);
					walls.push_back(wall);
					wall.setPosition(gridSize * 15, gridSize * 46);
					walls.push_back(wall);
					wall.setPosition(gridSize * 16, gridSize * 50);
					walls.push_back(wall);
					wall.setPosition(gridSize * 16, gridSize * 46);
					walls.push_back(wall);
					wall.setPosition(gridSize * 16, gridSize * 41);
					walls.push_back(wall);
					wall.setPosition(gridSize * 16, gridSize * 42);
					walls.push_back(wall);
					wall.setPosition(gridSize * 16, gridSize * 44);
					walls.push_back(wall);
					wall.setPosition(gridSize * 17, gridSize * 33);
					walls.push_back(wall);
					wall.setPosition(gridSize * 17, gridSize * 34);
					walls.push_back(wall);
					wall.setPosition(gridSize * 17, gridSize * 35);
					walls.push_back(wall);
					wall.setPosition(gridSize * 17, gridSize * 36);
					walls.push_back(wall);
					wall.setPosition(gridSize * 17, gridSize * 40);
					walls.push_back(wall);
					wall.setPosition(gridSize * 17, gridSize * 44);
					walls.push_back(wall);
					wall.setPosition(gridSize * 17, gridSize * 50);
					walls.push_back(wall);
					wall.setPosition(gridSize * 17, gridSize * 46);
					walls.push_back(wall);
					wall.setPosition(gridSize * 18, gridSize * 47);
					walls.push_back(wall);
					wall.setPosition(gridSize * 19, gridSize * 46);
					walls.push_back(wall);
					wall.setPosition(gridSize * 18, gridSize * 40);
					walls.push_back(wall);
					wall.setPosition(gridSize * 19, gridSize * 40);
					walls.push_back(wall);
					wall.setPosition(gridSize * 20, gridSize * 40);
					walls.push_back(wall);
					wall.setPosition(gridSize * 20, gridSize * 46);
					walls.push_back(wall);
					wall.setPosition(gridSize * 20, gridSize * 45);
					walls.push_back(wall);
					wall.setPosition(gridSize * 20, gridSize * 43);
					walls.push_back(wall);
					wall.setPosition(gridSize * 19, gridSize * 45);
					walls.push_back(wall);
					wall.setPosition(gridSize * 18, gridSize * 43);
					walls.push_back(wall);
					wall.setPosition(gridSize * 18, gridSize * 50);
					walls.push_back(wall);
					wall.setPosition(gridSize * 19, gridSize * 50);
					walls.push_back(wall);
					wall.setPosition(gridSize * 20, gridSize * 50);
					walls.push_back(wall);
					wall.setPosition(gridSize * 20, gridSize * 37);
					walls.push_back(wall);
					wall.setPosition(gridSize * 20, gridSize * 38);
					walls.push_back(wall);
					wall.setPosition(gridSize * 20, gridSize * 39);
					walls.push_back(wall);
					wall.setPosition(gridSize * 20, gridSize * 32);
					walls.push_back(wall);
					wall.setPosition(gridSize * 19, gridSize * 32);
					walls.push_back(wall);
					wall.setPosition(gridSize * 18, gridSize * 32);
					walls.push_back(wall);
					wall.setPosition(gridSize * 19, gridSize * 37);
					walls.push_back(wall);
					wall.setPosition(gridSize * 18, gridSize * 37);
					walls.push_back(wall);
					wall.setPosition(gridSize * 17, gridSize * 34);
					walls.push_back(wall);
					wall.setPosition(gridSize * 17, gridSize * 35);
					walls.push_back(wall);
					wall.setPosition(gridSize * 17, gridSize * 36);
					walls.push_back(wall);
					wall.setPosition(gridSize * 21, gridSize * 50);
					walls.push_back(wall);
					wall.setPosition(gridSize * 22, gridSize * 50);
					walls.push_back(wall);
					wall.setPosition(gridSize * 21, gridSize * 33);
					walls.push_back(wall);
					wall.setPosition(gridSize * 22, gridSize * 33);
					walls.push_back(wall);
					wall.setPosition(gridSize * 23, gridSize * 50);
					walls.push_back(wall);
					wall.setPosition(gridSize * 24, gridSize * 32);
					walls.push_back(wall);
					wall.setPosition(gridSize * 25, gridSize * 32);
					walls.push_back(wall);
					wall.setPosition(gridSize * 27, gridSize * 33);
					walls.push_back(wall);
					wall.setPosition(gridSize * 29, gridSize * 33);
					walls.push_back(wall);
					wall.setPosition(gridSize * 31, gridSize * 33);
					walls.push_back(wall);
					wall.setPosition(gridSize * 31, gridSize * 28);
					walls.push_back(wall);
					wall.setPosition(gridSize * 33, gridSize * 33);
					walls.push_back(wall);
					wall.setPosition(gridSize * 34, gridSize * 33);
					walls.push_back(wall);
					wall.setPosition(gridSize * 33, gridSize * 32);
					walls.push_back(wall);
					wall.setPosition(gridSize * 34, gridSize * 32);
					walls.push_back(wall);
					wall.setPosition(gridSize * 25, gridSize * 46);
					walls.push_back(wall);
					wall.setPosition(gridSize * 25, gridSize * 47);
					walls.push_back(wall);
					wall.setPosition(gridSize * 25, gridSize * 48);
					walls.push_back(wall);
					wall.setPosition(gridSize * 25, gridSize * 49);
					walls.push_back(wall);
					wall.setPosition(gridSize * 25, gridSize * 50);
					walls.push_back(wall);
					wall.setPosition(gridSize * 32, gridSize * 30);
					walls.push_back(wall);
					wall.setPosition(gridSize * 32, gridSize * 31);
					walls.push_back(wall);
					wall.setPosition(gridSize * 32, gridSize * 28);
					walls.push_back(wall);
					wall.setPosition(gridSize * 33, gridSize * 28);
					walls.push_back(wall);
					wall.setPosition(gridSize * 33, gridSize * 29);
					walls.push_back(wall);
					wall.setPosition(gridSize * 30, gridSize * 25);
					walls.push_back(wall);
					wall.setPosition(gridSize * 30, gridSize * 26);
					walls.push_back(wall);
					wall.setPosition(gridSize * 30, gridSize * 27);
					walls.push_back(wall);
					wall.setPosition(gridSize * 31, gridSize * 19);
					walls.push_back(wall);
					wall.setPosition(gridSize * 31, gridSize * 21);
					walls.push_back(wall);
					wall.setPosition(gridSize * 31, gridSize * 23);
					walls.push_back(wall);
					wall.setPosition(gridSize * 32, gridSize * 24);
					walls.push_back(wall);
					wall.setPosition(gridSize * 33, gridSize * 25);
					walls.push_back(wall);
					wall.setPosition(gridSize * 33, gridSize * 24);
					walls.push_back(wall);
					wall.setPosition(gridSize * 32, gridSize * 18);
					walls.push_back(wall);
					wall.setPosition(gridSize * 33, gridSize * 18);
					walls.push_back(wall);
					wall.setPosition(gridSize * 34, gridSize * 18);
					walls.push_back(wall);
					wall.setPosition(gridSize * 34, gridSize * 17);
					walls.push_back(wall);
					wall.setPosition(gridSize * 35, gridSize * 15);
					walls.push_back(wall);
					wall.setPosition(gridSize * 36, gridSize * 15);
					walls.push_back(wall);
					wall.setPosition(gridSize * 37, gridSize * 15);
					walls.push_back(wall);
					wall.setPosition(gridSize * 38, gridSize * 16);
					walls.push_back(wall);
					wall.setPosition(gridSize * 38, gridSize * 18);
					walls.push_back(wall);
					wall.setPosition(gridSize * 38, gridSize * 19);
					walls.push_back(wall);
					wall.setPosition(gridSize * 38, gridSize * 22);
					walls.push_back(wall);
					wall.setPosition(gridSize * 38, gridSize * 24);
					walls.push_back(wall);
					wall.setPosition(gridSize * 38, gridSize * 26);
					walls.push_back(wall);
					wall.setPosition(gridSize * 39, gridSize * 18);
					walls.push_back(wall);
					wall.setPosition(gridSize * 39, gridSize * 27);
					walls.push_back(wall);
					wall.setPosition(gridSize * 36, gridSize * 24);
					walls.push_back(wall);
					wall.setPosition(gridSize * 37, gridSize * 26);
					walls.push_back(wall);
					wall.setPosition(gridSize * 37, gridSize * 8);
					walls.push_back(wall);
					wall.setPosition(gridSize * 37, gridSize * 29);
					walls.push_back(wall);
					wall.setPosition(gridSize * 37, gridSize * 27);
					walls.push_back(wall);
					wall.setPosition(gridSize * 37, gridSize * 24);
					walls.push_back(wall);
					wall.setPosition(gridSize * 36, gridSize * 25);
					walls.push_back(wall);
					wall.setPosition(gridSize * 25, gridSize * 39);
					walls.push_back(wall);
					wall.setPosition(gridSize * 25, gridSize * 40);
					walls.push_back(wall);
					wall.setPosition(gridSize * 26, gridSize * 39);
					walls.push_back(wall);
					wall.setPosition(gridSize * 26, gridSize * 40);
					walls.push_back(wall);
					wall.setPosition(gridSize * 27, gridSize * 40);
					walls.push_back(wall);
					wall.setPosition(gridSize * 26, gridSize * 46);
					walls.push_back(wall);
					wall.setPosition(gridSize * 27, gridSize * 36);
					walls.push_back(wall);
					wall.setPosition(gridSize * 29, gridSize * 36);
					walls.push_back(wall);
					wall.setPosition(gridSize * 31, gridSize * 36);
					walls.push_back(wall);
					wall.setPosition(gridSize * 32, gridSize * 38);
					walls.push_back(wall);
					wall.setPosition(gridSize * 34, gridSize * 38);
					walls.push_back(wall);
					wall.setPosition(gridSize * 27, gridSize * 38);
					walls.push_back(wall);
					wall.setPosition(gridSize * 28, gridSize * 41);
					walls.push_back(wall);
					wall.setPosition(gridSize * 30, gridSize * 41);
					walls.push_back(wall);
					wall.setPosition(gridSize * 31, gridSize * 41);
					walls.push_back(wall);
					wall.setPosition(gridSize * 28, gridSize * 44);
					walls.push_back(wall);
					wall.setPosition(gridSize * 30, gridSize * 44);
					walls.push_back(wall);
					wall.setPosition(gridSize * 31, gridSize * 44);
					walls.push_back(wall);
					wall.setPosition(gridSize * 27, gridSize * 45);
					walls.push_back(wall);
					wall.setPosition(gridSize * 32, gridSize * 39);
					walls.push_back(wall);
					wall.setPosition(gridSize * 33, gridSize * 39);
					walls.push_back(wall);
					wall.setPosition(gridSize * 34, gridSize * 39);
					walls.push_back(wall);
					wall.setPosition(gridSize * 32, gridSize * 45);
					walls.push_back(wall);
					wall.setPosition(gridSize * 33, gridSize * 44);
					walls.push_back(wall);
					wall.setPosition(gridSize * 35, gridSize * 43);
					walls.push_back(wall);
					wall.setPosition(gridSize * 37, gridSize * 43);
					walls.push_back(wall);
					wall.setPosition(gridSize * 38, gridSize * 43);
					walls.push_back(wall);
					wall.setPosition(gridSize * 40, gridSize * 42);
					walls.push_back(wall);
					wall.setPosition(gridSize * 39, gridSize * 39);
					walls.push_back(wall);
					wall.setPosition(gridSize * 38, gridSize * 39);
					walls.push_back(wall);
					wall.setPosition(gridSize * 38, gridSize * 37);
					walls.push_back(wall);
					wall.setPosition(gridSize * 38, gridSize * 35);
					walls.push_back(wall);
					wall.setPosition(gridSize * 38, gridSize * 33);
					walls.push_back(wall);
					wall.setPosition(gridSize * 37, gridSize * 32);
					walls.push_back(wall);
					wall.setPosition(gridSize * 37, gridSize * 33);
					walls.push_back(wall);
					wall.setPosition(gridSize * 34, gridSize * 43);
					walls.push_back(wall);
					wall.setPosition(gridSize * 40, gridSize * 40);
					walls.push_back(wall);
					wall.setPosition(gridSize * 38, gridSize * 30);
					walls.push_back(wall);
					wall.setPosition(gridSize * 38, gridSize * 31);
					walls.push_back(wall);
					wall.setPosition(gridSize * 76, gridSize * 31);
					walls.push_back(wall);
					wall.setPosition(gridSize * 38, gridSize * 32);
					walls.push_back(wall);
					wall.setPosition(gridSize * 38, gridSize * 3);
					walls.push_back(wall);
					wall.setPosition(gridSize * 76, gridSize * 31);
					walls.push_back(wall);
					wall.setPosition(gridSize * 76, gridSize * 33);
					walls.push_back(wall);
					wall.setPosition(gridSize * 70, gridSize * 31);
					walls.push_back(wall);
					wall.setPosition(gridSize * 68, gridSize * 31);
					walls.push_back(wall);
					wall.setPosition(gridSize * 66, gridSize * 31);
					walls.push_back(wall);
					wall.setPosition(gridSize * 62, gridSize * 31);
					walls.push_back(wall);
					wall.setPosition(gridSize * 60, gridSize * 31);
					walls.push_back(wall);
					wall.setPosition(gridSize * 58, gridSize * 31);
					walls.push_back(wall);
					wall.setPosition(gridSize * 56, gridSize * 31);
					walls.push_back(wall);
					wall.setPosition(gridSize * 54, gridSize * 31);
					walls.push_back(wall);
					wall.setPosition(gridSize * 52, gridSize * 31);
					walls.push_back(wall);
					wall.setPosition(gridSize * 50, gridSize * 31);
					walls.push_back(wall);
					wall.setPosition(gridSize * 44, gridSize * 31);
					walls.push_back(wall);
					wall.setPosition(gridSize * 49, gridSize * 30);
					walls.push_back(wall);
					wall.setPosition(gridSize * 49, gridSize * 28);
					walls.push_back(wall);
					wall.setPosition(gridSize * 49, gridSize * 26);
					walls.push_back(wall);
					wall.setPosition(gridSize * 75, gridSize * 34);
					walls.push_back(wall);
					wall.setPosition(gridSize * 73, gridSize * 34);
					walls.push_back(wall);
					wall.setPosition(gridSize * 71, gridSize * 34);
					walls.push_back(wall);
					wall.setPosition(gridSize * 69, gridSize * 34);
					walls.push_back(wall);
					wall.setPosition(gridSize * 67, gridSize * 34);
					walls.push_back(wall);
					wall.setPosition(gridSize * 65, gridSize * 34);
					walls.push_back(wall);
					wall.setPosition(gridSize * 63, gridSize * 34);
					walls.push_back(wall);
					wall.setPosition(gridSize * 61, gridSize * 34);
					walls.push_back(wall);
					wall.setPosition(gridSize * 59, gridSize * 34);
					walls.push_back(wall);
					wall.setPosition(gridSize * 44, gridSize * 34);
					walls.push_back(wall);
					wall.setPosition(gridSize * 44, gridSize * 32);
					walls.push_back(wall);
					wall.setPosition(gridSize * 45, gridSize * 35);
					walls.push_back(wall);
					wall.setPosition(gridSize * 47, gridSize * 35);
					walls.push_back(wall);
					wall.setPosition(gridSize * 48, gridSize * 35);
					walls.push_back(wall);
					wall.setPosition(gridSize * 49, gridSize * 36);
					walls.push_back(wall);
					wall.setPosition(gridSize * 51, gridSize * 36);
					walls.push_back(wall);
					wall.setPosition(gridSize * 53, gridSize * 36);
					walls.push_back(wall);
					wall.setPosition(gridSize * 55, gridSize * 36);
					walls.push_back(wall);
					wall.setPosition(gridSize * 57, gridSize * 36);
					walls.push_back(wall);
					wall.setPosition(gridSize * 44, gridSize * 27);
					walls.push_back(wall);
					wall.setPosition(gridSize * 44, gridSize * 29);
					walls.push_back(wall);
					wall.setPosition(gridSize * 45, gridSize * 30);
					walls.push_back(wall);
					wall.setPosition(gridSize * 40, gridSize * 24);
					walls.push_back(wall);
					wall.setPosition(gridSize * 42, gridSize * 24);
					walls.push_back(wall);
					wall.setPosition(gridSize * 43, gridSize * 24);
					walls.push_back(wall);
					wall.setPosition(gridSize * 43, gridSize * 26);
					walls.push_back(wall);
					wall.setPosition(gridSize * 40, gridSize * 19);
					walls.push_back(wall);
					wall.setPosition(gridSize * 42, gridSize * 19);
					walls.push_back(wall);
					wall.setPosition(gridSize * 44, gridSize * 20);
					walls.push_back(wall);
					wall.setPosition(gridSize * 46, gridSize * 20);
					walls.push_back(wall);
					wall.setPosition(gridSize * 48, gridSize * 20);
					walls.push_back(wall);
					wall.setPosition(gridSize * 49, gridSize * 20);
					walls.push_back(wall);
					wall.setPosition(gridSize * 49, gridSize * 19);
					walls.push_back(wall);
					wall.setPosition(gridSize * 47, gridSize * 19);
					walls.push_back(wall);
					wall.setPosition(gridSize * 46, gridSize * 18);
					walls.push_back(wall);
					wall.setPosition(gridSize * 46, gridSize * 16);
					walls.push_back(wall);
					wall.setPosition(gridSize * 47, gridSize * 15);
					walls.push_back(wall);
					wall.setPosition(gridSize * 48, gridSize * 15);
					walls.push_back(wall);
					wall.setPosition(gridSize * 49, gridSize * 13);
					walls.push_back(wall);
					wall.setPosition(gridSize * 51, gridSize * 13);
					walls.push_back(wall);
					wall.setPosition(gridSize * 53, gridSize * 13);
					walls.push_back(wall);
					


					player.setPosition(850.f, 3000.f);

					//Collision
					FloatRect nextPos;


					int ExitButtonCheck = 0;

					int collision_check = 0;

					//Start the game loop
					while (Play.isOpen()) {

						dt = dt_clock.restart().asSeconds();
						clock.restart();

						sf::Event aevent;
						while (Play.pollEvent(aevent)) {
							if (aevent.type == Event::Closed) {
								Play.close();
							}
							if (aevent.type == Event::KeyPressed) {
								if (aevent.key.code == Keyboard::Escape) {
									if (ExitButtonCheck == 0) {
										ExitButtonCheck = 1;
										BlackSprite.setPosition(0,0);
									}
									else if (ExitButtonCheck == 1) {
										ExitButtonCheck = 0;
										BlackSprite.setPosition(-100000, -100000);
										PauseButton.setPosition(-100000, -100000);
										PlayButton.setPosition(-100000, -100000);
										QuitButton.setPosition(-100000, -100000);
										MenuButton.setPosition(-100000, -100000);
									}
								}

							}
							
						}

						//Player movement
						velocity.y = 0.f;
						velocity.x = 0.f;

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && ExitButtonCheck == 0) {
							velocity.y += movementSpeed * dt;
						}

						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && ExitButtonCheck == 0) {
							velocity.x += -movementSpeed * dt;	
						}

						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && ExitButtonCheck == 0) {
							velocity.x += movementSpeed * dt;
						}

						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ExitButtonCheck == 0) {
							velocity.y += -movementSpeed * dt;
						}

						if (velocity.y > 0.f) {
							row = 0;
						}
						else if (velocity.x < 0.f) {
							row = 1;
							
						}
						else if (velocity.x > 0.f) {
							row = 2;
						}
						else if (velocity.y < 0.f) {
							row = 3;
						}


						// Idle check
						
						if (row == 2 && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)  && ExitButtonCheck == 0)row = 6;
						else if (row == 3 && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ExitButtonCheck == 0)row = 7;
						else if (row == 0 && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && ExitButtonCheck == 0)row = 4;
						else if (row == 1 && !sf::Keyboard::isKeyPressed(sf::Keyboard::A) && ExitButtonCheck == 0)row = 5;

						//Collision
						for (auto& wall : walls)
						{
							FloatRect playerBounds = player.getGlobalBounds();
							FloatRect wallBounds = wall.getGlobalBounds();

							nextPos = playerBounds;
							nextPos.left += velocity.x;
							nextPos.top += velocity.y;

							if (wallBounds.intersects(nextPos))
							{
								//Bottom collision
								if (playerBounds.top < wallBounds.top
									&& playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
									&& playerBounds.left < wallBounds.left + wallBounds.width
									&& playerBounds.left + playerBounds.width > wallBounds.left
									)
								{
									velocity.y = 0.f;
									player.setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
								}

								//Top collision
								else if (playerBounds.top > wallBounds.top
									&& playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
									&& playerBounds.left < wallBounds.left + wallBounds.width
									&& playerBounds.left + playerBounds.width > wallBounds.left
									)
								{
									velocity.y = 0.f;
									player.setPosition(playerBounds.left, wallBounds.top + wallBounds.height);
								}

								//Right collision
								if (playerBounds.left < wallBounds.left
									&& playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
									&& playerBounds.top < wallBounds.top + wallBounds.height
									&& playerBounds.top + playerBounds.height > wallBounds.top
									)
								{
									velocity.x = 0.f;
									player.setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
								}

								//Left collision
								else if (playerBounds.left > wallBounds.left
									&& playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
									&& playerBounds.top < wallBounds.top + wallBounds.height
									&& playerBounds.top + playerBounds.height > wallBounds.top
									)
								{
									velocity.x = 0.f;
									player.setPosition(wallBounds.left + wallBounds.width, playerBounds.top);
								}
							}
						}

						if (position.x == player.getPosition().x + 25) {

							if (ExitButtonCheck == 1) {
								PauseButton.setPosition(player.getPosition().x - 170, player.getPosition().y - 200);
								PlayButton.setPosition(player.getPosition().x - 105, player.getPosition().y - 50);
								MenuButton.setPosition(player.getPosition().x -105, player.getPosition().y + 30);
								QuitButton.setPosition(player.getPosition().x - 105, player.getPosition().y + 110);
							}
							ScoreSprite.setPosition(player.getPosition().x - 935, player.getPosition().y - 500);

						}

						if (position.x == screenDimensions.x / 2) {
							if (ExitButtonCheck == 1) {
								PauseButton.setPosition(750, player.getPosition().y - 200);
								PlayButton.setPosition(815, player.getPosition().y - 50);
								MenuButton.setPosition(815, player.getPosition().y + 30);
								QuitButton.setPosition(815, player.getPosition().y + 110);
							}
							ScoreSprite.setPosition(0, player.getPosition().y - 500);
						}


						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							if (QuitButton.getGlobalBounds().contains(Play.mapPixelToCoords(sf::Mouse::getPosition(Play))))
							{
								Play.close();
								MENU.close();
							}

							if (MenuButton.getGlobalBounds().contains(Play.mapPixelToCoords(sf::Mouse::getPosition(Play))))
							{
								Play.close();
							}

							if (PlayButton.getGlobalBounds().contains(Play.mapPixelToCoords(sf::Mouse::getPosition(Play))))
							{
								ExitButtonCheck = 0;
								BlackSprite.setPosition(-100000, -100000);
								PauseButton.setPosition(-100000, -100000);
								PlayButton.setPosition(-100000, -100000);
								QuitButton.setPosition(-100000, -100000);
								MenuButton.setPosition(-100000, -100000);
							}
						}

						//Update model
						
						if (ExitButtonCheck == 0) {

							player.setTextureRect(sf::IntRect(32 * frame, 32 * row, 32, 32));

							if (frameCounter == 100) {
								frame = (frame + 1) % 3;
								frameCounter = 0;
							}
							frameCounter++;

						}
						

						if (player.getPosition().x + 25 > screenDimensions.x / 2)
							position.x = player.getPosition().x + 25;
						else
							position.x = screenDimensions.x / 2;

						if (player.getPosition().y + 25 > screenDimensions.y / 2)
							position.y = player.getPosition().y + 25;
						else
							position.y = screenDimensions.y / 2;

						
						player.move(velocity);

						Play.clear();
						view.setCenter(position); //ตั้งศูนย์กลางของมุมมองตามตำแหน่งของ position
						Play.setView(view); //ใช้งานมุมมอง
						Play.draw(Pbackground); //วาด background
						Play.draw(player); //วาด player

						for (auto& i : walls)
						{
							Play.draw(i);
						}

						Play.draw(ScoreSprite);
						Play.draw(BlackSprite);
						Play.draw(PauseButton);
						Play.draw(PlayButton);
						Play.draw(QuitButton);
						Play.draw(MenuButton);
						Play.display();

					}
				}

			}
			if (x == 2) {

				sf::RenderWindow SCORE(sf::VideoMode(screenDimensions.x, screenDimensions.y), "LET'S GO HOME");

				ExitSprite.setPosition(0, 0);

				while (SCORE.isOpen()) {

					Event aevent;
					while (SCORE.pollEvent(aevent)) {
						if (aevent.type == Event::Closed) {
							SCORE.close();
						}
						if (aevent.type == Event::KeyPressed) {
							if (aevent.key.code == Keyboard::Escape) {
								SCORE.close();
							}
						}
					}

					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (ExitSprite.getGlobalBounds().contains(SCORE.mapPixelToCoords(sf::Mouse::getPosition(SCORE))))
						{
							SCORE.close();
						}

					}

					//Update score bg
					score.setTextureRect(sf::IntRect(1920 * frameScore, 1080 * 0, 1920, 1080));


					if (frameScoreCounter == 80) {
						frameScore = (frameScore + 1) % 8;
						frameScoreCounter = 0;
					}
					frameScoreCounter++;


					SCORE.clear();
					SCORE.draw(score);
					SCORE.draw(ExitSprite);
					SCORE.display();
				}
			}
			if (x == 3) {

				sf::RenderWindow ABOUT(sf::VideoMode(screenDimensions.x, screenDimensions.y), "LET'S GO HOME");

				ExitSprite.setPosition(0,0);

				while (ABOUT.isOpen()) {

					Event aevent;
					while (ABOUT.pollEvent(aevent)) {
						if (aevent.type == Event::Closed) {
							ABOUT.close();
						}
						if (aevent.type == Event::KeyPressed) {
							if (aevent.key.code == Keyboard::Escape) {
								ABOUT.close();
							}
						}
					}

					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (ExitSprite.getGlobalBounds().contains(ABOUT.mapPixelToCoords(sf::Mouse::getPosition(ABOUT))))
						{
							ABOUT.close();
						}

					}


					//Update bg
					about.setTextureRect(sf::IntRect(1920 * frameAbout, 1080 * 0, 1920, 1080));


					if (frameAboutCounter == 200) {
						frameAbout = (frameAbout + 1) % 4;
						frameAboutCounter = 0;
					}
					frameAboutCounter++;

					ABOUT.clear();
					ABOUT.draw(about);
					ABOUT.draw(ExitSprite);
					ABOUT.display();

				}
			}
			if (x == 4)
				MENU.close();
			break;
		}

		//Update water
		water.setTextureRect(sf::IntRect(1920 * frameMenu, 1080 * 0, 1920, 1080));


		if (frameMenuCounter == 20) {
			frameMenu = (frameMenu + 1) % 5;
			frameMenuCounter = 0;
		}
		frameMenuCounter++;
	
		MENU.clear();
		movieLogo.update();
		MENU.draw(water);
		MENU.draw(movieLogo);
		MENU.draw(StartButton);
		MENU.draw(AboutButton);
		MENU.draw(ScoreButton);
		MENU.draw(Hover_startSprite);
		MENU.draw(Hover_aboutSprite);
		MENU.draw(Hover_scoreSprite);
		MENU.draw(Hover_exitSprite);
		MENU.draw(ExitButton);
		mainMenu.draw(MENU);
		MENU.display();


	}
}
