
/*


//
//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
//#include <SFML/Config.hpp>
//#include <sfeMovie/Movie.hpp>
//#include <string>
//#include <iostream>
//#include <algorithm>
//#include <SFML/OpenGL.hpp>
//
//#include"MainMenu.h"
//
//void my_pause() {
//#ifdef SFML_SYSTEM_WINDOWS
//	system("PAUSE");
//#endif
//}
//
//
//
//
//int main()
//{
//
//	// Create video logo //
//
//	std::string logoFile = "img/bg/menu_logo.mp4";
//	std::cout << "Going to open movie file \"" << logoFile << "\"" << std::endl;
//
//	sfe::Movie movieLogo;
//	if (!movieLogo.openFromFile(logoFile)) {
//		my_pause();
//		return 1;
//	}
//
//	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
//	float width = std::min(static_cast<float>(desktopMode.width), movieLogo.getSize().x);
//	float height = std::min(static_cast<float>(desktopMode.height), movieLogo.getSize().y);
//
//
//	// Create short screne //
//
//	std::string mediaFile = "img/bg/short screne.mp4";
//	std::cout << "Going to open movie file \"" << mediaFile << "\"" << std::endl;
//
//	sfe::Movie movie;
//	if (!movie.openFromFile(mediaFile)) {
//		my_pause();
//		return 1;
//	}
//
//	int frame = 0;
//	int frameAbout = 0;
//	int frameMenu = 0;
//	int frameScore = 0;
//	int row = 0;
//	int frameCounter = 0;
//	int frameAboutCounter = 0;
//	int frameMenuCounter = 0;
//	int frameScoreCounter = 0;
//
//
//
//	// Create the main window //
//
//	sf::Vector2i screenDimensions(1920, 1080);
//
//	// Create the player window //
//
//	sf::RectangleShape Pbackground(sf::Vector2f(1490.f, 936.f));
//	Texture PlayerTexture;
//	PlayerTexture.loadFromFile("img/bg/bg.png");
//	Pbackground.setTexture(&PlayerTexture);
//	Pbackground.setScale(4.f, 4.f);
//
//	// water animation //
//
//	sf::Texture waterTexture;
//	sf::Sprite water;
//
//	if (!waterTexture.loadFromFile("img/bg/water_animation.png"))
//		std::cout << "Error could not load water" << std::endl;
//	water.setTexture(waterTexture);
//
//
//	// bg about //
//
//	sf::Texture aboutTexture;
//	sf::Sprite about;
//
//	if (!aboutTexture.loadFromFile("img/bg/about_animation.png"))
//		std::cout << "Error could not load about bg" << std::endl;
//	about.setTexture(aboutTexture);
//
//	// bg score //
//
//	sf::Texture scoreTexture;
//	sf::Sprite score;
//
//	if (!scoreTexture.loadFromFile("img/bg/score_animation.png"))
//		std::cout << "Error could not load about bg" << std::endl;
//	score.setTexture(scoreTexture);
//
//	// Create Sprite button //
//
//	sf::RectangleShape StartButton(sf::Vector2f(165.0f, 60.0f));
//	StartButton.setPosition({ 530.f, 570.f });
//	StartButton.setFillColor(sf::Color::Transparent);
//
//	sf::RectangleShape ScoreButton(sf::Vector2f(165.0f, 60.0f));
//	ScoreButton.setPosition({ 780.f, 570.f });
//	ScoreButton.setFillColor(sf::Color::Transparent);
//
//	sf::RectangleShape AboutButton(sf::Vector2f(165.0f, 60.0f));
//	AboutButton.setPosition({ 1030.f, 570.f });
//	AboutButton.setFillColor(sf::Color::Transparent);
//
//	sf::RectangleShape ExitButton(sf::Vector2f(145.0f, 60.0f));
//	ExitButton.setPosition({ 1270.f, 570.f });
//	ExitButton.setFillColor(sf::Color::Transparent);
//
//
//	/***************************************************** game zone ***************************************************************/
//
//
//	// create tileset //
//
//	sf::RectangleShape Tileset(sf::Vector2f(145.0f, 60.0f));
//	Tileset.setPosition({ 1270.f, 570.f });
//	Tileset.setFillColor(sf::Color::Red);
//
//	// create player //
//
//	sf::Texture pTexture;
//	sf::Sprite player;
//	sf::Clock clock;
//
//	if (!pTexture.loadFromFile("img/character/playersheet_1.png"))
//		std::cout << "Error could not load player image" << std::endl;
//	player.setTexture(pTexture);
//	player.setScale(3.f, 3.f);
//
//	// create view //
//
//	sf::View view;
//	view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
//	sf::Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);
//
//	// create black sprite
//
//	sf::Texture BlackTexture;
//	sf::Sprite BlackSprite;
//
//	if (!BlackTexture.loadFromFile("img/bg/black.png"))
//		std::cout << "Error could not load black image" << std::endl;
//	BlackSprite.setTexture(BlackTexture);
//
//	sf::Texture PauseTexture;
//	sf::Sprite PauseButton;
//
//	if (!PauseTexture.loadFromFile("img/button/pause.png"))
//		std::cout << "Error could not load pause button" << std::endl;
//	PauseButton.setTexture(PauseTexture);
//	PauseButton.setScale(1.5f, 1.5f);
//
//	sf::Texture PlayTexture;
//	sf::Sprite PlayButton;
//
//	if (!PlayTexture.loadFromFile("img/button/play.png"))
//		std::cout << "Error could not load play button" << std::endl;
//	PlayButton.setTexture(PlayTexture);
//
//	sf::Texture QuitTexture;
//	sf::Sprite QuitButton;
//
//	if (!QuitTexture.loadFromFile("img/button/quit.png"))
//		std::cout << "Error could not load quit button" << std::endl;
//	QuitButton.setTexture(QuitTexture);
//
//	sf::Texture MenuTexture;
//	sf::Sprite MenuButton;
//
//	if (!MenuTexture.loadFromFile("img/button/menu.png"))
//		std::cout << "Error could not load menu button" << std::endl;
//	MenuButton.setTexture(MenuTexture);
//
//	movieLogo.fit(0, 0, width, height);
//	movieLogo.play();
//
//
//
//	RenderWindow Play(VideoMode(screenDimensions.x, screenDimensions.y), "LET'S GO HOME");
//
//	sf::RectangleShape tileset1(sf::Vector2f(630.0f, 4500.0f));
//	tileset1.setFillColor(sf::Color::Red);
//
//	sf::RectangleShape tileset2(sf::Vector2f(2500.0f, 3500.0f));
//	tileset2.setFillColor(sf::Color::Red);
//
//	sf::RectangleShape tileset3(sf::Vector2f(4219.f, 632.f));
//	tileset3.setFillColor(sf::Color::Red);
//
//	sf::RectangleShape tileset4(sf::Vector2f(2022.f, 989.f));
//	tileset4.setFillColor(sf::Color::Red);
//
//	sf::RectangleShape tileset5(sf::Vector2f(482.f, 991.f));
//	tileset5.setFillColor(sf::Color::Red);
//
//	sf::RectangleShape tileset6(sf::Vector2f(350.f, 460.f));
//	tileset6.setFillColor(sf::Color::Red);
//
//	sf::RectangleShape tileset7(sf::Vector2f(16.f, 460.f));
//	tileset7.setFillColor(sf::Color::Red);
//
//	sf::RectangleShape tileset8(sf::Vector2f(582.f, 279.f));
//	tileset8.setFillColor(sf::Color::Red);
//
//	sf::RectangleShape tileset9(sf::Vector2f(814.f, 551.f));
//	tileset9.setFillColor(sf::Color::Red);
//
//	sf::RectangleShape tileset10(sf::Vector2f(350.f, 460.f));
//	tileset10.setFillColor(sf::Color::Red);
//	sf::RectangleShape tileset11(sf::Vector2f(350.f, 460.f));
//	tileset11.setFillColor(sf::Color::Red);
//	sf::RectangleShape tileset12(sf::Vector2f(350.f, 460.f));
//	tileset12.setFillColor(sf::Color::Red);
//	sf::RectangleShape tileset13(sf::Vector2f(350.f, 460.f));
//	tileset13.setFillColor(sf::Color::Red);
//	sf::RectangleShape tileset14(sf::Vector2f(350.f, 460.f));
//	tileset14.setFillColor(sf::Color::Red);
//	sf::RectangleShape tileset15(sf::Vector2f(350.f, 460.f));
//	tileset15.setFillColor(sf::Color::Red);
//	sf::RectangleShape tileset16(sf::Vector2f(350.f, 460.f));
//	tileset16.setFillColor(sf::Color::Red);
//	sf::RectangleShape tileset17(sf::Vector2f(350.f, 460.f));
//	tileset17.setFillColor(sf::Color::Red);
//	sf::RectangleShape tileset18(sf::Vector2f(350.f, 460.f));
//	tileset18.setFillColor(sf::Color::Red);
//	sf::RectangleShape tileset19(sf::Vector2f(350.f, 460.f));
//	tileset19.setFillColor(sf::Color::Red);
//	sf::RectangleShape tileset20(sf::Vector2f(350.f, 460.f));
//	tileset20.setFillColor(sf::Color::Red);
//
//
//
//
//	tileset1.setPosition(0.f, 0.f);
//	tileset2.setPosition(4855.f, 0.f);
//	tileset3.setPosition(0.f, 3186.f);
//	tileset4.setPosition(2838.f, 2195.f);
//	tileset5.setPosition(2462.f, 2195.f);
//	tileset6.setPosition(2115.f, 2720.f);
//	tileset7.setPosition(2109.f, 2726.f);
//	tileset8.setPosition(777.f, 2770.f);
//	tileset9.setPosition(551.f, 2348.f);
//
//	tileset10.setPosition(2115.f, 2726.f);
//	tileset11.setPosition(2115.f, 2726.f);
//	tileset12.setPosition(2115.f, 2726.f);
//	tileset13.setPosition(2115.f, 2726.f);
//	tileset14.setPosition(2115.f, 2726.f);
//	tileset15.setPosition(2115.f, 2726.f);
//	tileset16.setPosition(2115.f, 2726.f);
//	tileset17.setPosition(2115.f, 2726.f);
//	tileset18.setPosition(2115.f, 2726.f);
//	tileset19.setPosition(2115.f, 2726.f);
//	tileset20.setPosition(2115.f, 2726.f);
//
//	player.setPosition(1850.f, 3000.f);
//
//
//	int ExitButtonCheck = 0;
//
//	int collision_check = 0;
//
//	//Start the game loop
//	while (Play.isOpen()) {
//
//		clock.restart();
//		sf::Event aevent;
//		while (Play.pollEvent(aevent)) {
//			if (aevent.type == Event::Closed) {
//				Play.close();
//			}
//			if (aevent.type == Event::MouseMoved) {
//				std::cout << "\nX: " << aevent.mouseMove.x << "\tY: " << aevent.mouseMove.y << std::endl;
//			}
//			if (aevent.type == Event::KeyPressed) {
//				if (aevent.key.code == Keyboard::Escape) {
//					if (ExitButtonCheck == 0) {
//						ExitButtonCheck = 1;
//						BlackSprite.setPosition(0, 0);
//					}
//					else if (ExitButtonCheck == 1) {
//						ExitButtonCheck = 0;
//						BlackSprite.setPosition(-100000, -100000);
//						PauseButton.setPosition(-100000, -100000);
//						PlayButton.setPosition(-100000, -100000);
//						QuitButton.setPosition(-100000, -100000);
//						MenuButton.setPosition(-100000, -100000);
//					}
//				}
//
//			}
//
//		}
//
//		if (position.x == player.getPosition().x + 25) {
//
//			if (ExitButtonCheck == 1) {
//				PauseButton.setPosition(player.getPosition().x - 170, player.getPosition().y - 200);
//				PlayButton.setPosition(player.getPosition().x - 105, player.getPosition().y - 50);
//				MenuButton.setPosition(player.getPosition().x - 105, player.getPosition().y + 30);
//				QuitButton.setPosition(player.getPosition().x - 105, player.getPosition().y + 110);
//			}
//
//		}
//
//		if (position.x == screenDimensions.x / 2) {
//			if (ExitButtonCheck == 1) {
//				PauseButton.setPosition(750, player.getPosition().y - 200);
//				PlayButton.setPosition(815, player.getPosition().y - 50);
//				MenuButton.setPosition(815, player.getPosition().y + 30);
//				QuitButton.setPosition(815, player.getPosition().y + 110);
//			}
//		}
//
//		// check collission //
//
//		//if (player.getGlobalBounds().intersects(tileset1.getGlobalBounds()))collision_check = 'A';
//		//if (player.getGlobalBounds().intersects(tileset2.getGlobalBounds()) || player.getGlobalBounds().intersects(tileset5.getGlobalBounds()) || player.getGlobalBounds().intersects(tileset7.getGlobalBounds()))collision_check = 'D';
//		//if (player.getGlobalBounds().intersects(tileset3.getGlobalBounds()) || player.getGlobalBounds().intersects(tileset4.getGlobalBounds()) || player.getGlobalBounds().intersects(tileset6.getGlobalBounds()))collision_check = 'S';
//		//if (player.getGlobalBounds().intersects(tileset8.getGlobalBounds()) || player.getGlobalBounds().intersects(tileset9.getGlobalBounds()))collision_check = 'W';
//
//		//if (player.getGlobalBounds().intersects(tileset3.getGlobalBounds()) && player.getGlobalBounds().intersects(tileset1.getGlobalBounds()))collision_check = 'AS';
//		//if (player.getGlobalBounds().intersects(tileset9.getGlobalBounds()) && player.getGlobalBounds().intersects(tileset1.getGlobalBounds()))collision_check = 'WA';
//		//if (player.getGlobalBounds().intersects(tileset9.getGlobalBounds()) && player.getGlobalBounds().intersects(tileset8.getGlobalBounds()))collision_check = 'WD';
//		//if (player.getGlobalBounds().intersects(tileset6.getGlobalBounds()) && player.getGlobalBounds().intersects(tileset5.getGlobalBounds()))collision_check = 'SD';
//
//
//		if (player.getPosition().x - 1 == tileset1.setPosition(0.f, 0.f))collision_check = 'S';
//
//		if (!player.getGlobalBounds().intersects(tileset1.getGlobalBounds()) &&
//			!player.getGlobalBounds().intersects(tileset2.getGlobalBounds()) &&
//			!player.getGlobalBounds().intersects(tileset3.getGlobalBounds()) &&
//			!player.getGlobalBounds().intersects(tileset4.getGlobalBounds()) &&
//			!player.getGlobalBounds().intersects(tileset5.getGlobalBounds()) &&
//			!player.getGlobalBounds().intersects(tileset6.getGlobalBounds()) &&
//			!player.getGlobalBounds().intersects(tileset7.getGlobalBounds()) &&
//			!player.getGlobalBounds().intersects(tileset8.getGlobalBounds()) &&
//			!player.getGlobalBounds().intersects(tileset9.getGlobalBounds()) &&
//			!player.getGlobalBounds().intersects(tileset10.getGlobalBounds()) &&
//			!player.getGlobalBounds().intersects(tileset11.getGlobalBounds()) &&
//			!player.getGlobalBounds().intersects(tileset12.getGlobalBounds()) &&
//			!player.getGlobalBounds().intersects(tileset13.getGlobalBounds()) &&
//			!player.getGlobalBounds().intersects(tileset14.getGlobalBounds()) &&
//			!player.getGlobalBounds().intersects(tileset15.getGlobalBounds()) &&
//			!player.getGlobalBounds().intersects(tileset16.getGlobalBounds()) &&
//			!player.getGlobalBounds().intersects(tileset17.getGlobalBounds()) &&
//			!player.getGlobalBounds().intersects(tileset18.getGlobalBounds()) &&
//			!player.getGlobalBounds().intersects(tileset19.getGlobalBounds()) &&
//			!player.getGlobalBounds().intersects(tileset20.getGlobalBounds())
//			)
//			collision_check = 0;
//
//
//
//
//		//Update model
//
//		if (ExitButtonCheck == 0) {
//
//			player.setTextureRect(sf::IntRect(32 * frame, 32 * row, 32, 32));
//
//			if (frameCounter == 100) {
//				frame = (frame + 1) % 3;
//				frameCounter = 0;
//			}
//			frameCounter++;
//
//		}
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && ExitButtonCheck == 0) {
//			player.setTextureRect(sf::IntRect(32 * frame, 32 * 0, 32, 32));
//			if (collision_check != 'S' && collision_check != 'AS' && collision_check != 'SD') {
//				player.move(0, 3.f);
//			}
//			row = 0;
//		}
//
//		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && ExitButtonCheck == 0) {
//			player.setTextureRect(sf::IntRect(32 * frame, 32 * 1, 32, 32));
//			if (collision_check != 'A' && collision_check != 'AS' && collision_check != 'WA') {
//				player.move(-3.f, 0);
//			}
//			row = 1;
//		}
//
//		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && ExitButtonCheck == 0) {
//			player.setTextureRect(sf::IntRect(32 * frame, 32 * 2, 32, 32));
//			if (collision_check != 'D' && collision_check != 'SD' && collision_check != 'WD') {
//				player.move(3.f, 0);
//			}
//			row = 2;
//		}
//
//		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ExitButtonCheck == 0) {
//			player.setTextureRect(sf::IntRect(32 * frame, 32 * 3, 32, 32));
//			if (collision_check != 'W' && collision_check != 'WA' && collision_check != 'WD') {
//				player.move(0, -3.f);
//			}
//
//			row = 3;
//		}
//
//		
//
//
//		// Idle check
//		else if (row == 2 && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) && ExitButtonCheck == 0)player.setTextureRect(sf::IntRect(32 * frame, 32 * 6, 32, 32));
//		else if (row == 3 && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ExitButtonCheck == 0)player.setTextureRect(sf::IntRect(32 * frame, 32 * 7, 32, 32));
//		else if (row == 0 && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && ExitButtonCheck == 0)player.setTextureRect(sf::IntRect(32 * frame, 32 * 4, 32, 32));
//		else if (row == 1 && !sf::Keyboard::isKeyPressed(sf::Keyboard::A) && ExitButtonCheck == 0) player.setTextureRect(sf::IntRect(32 * frame, 32 * 5, 32, 32));
//
//		if (player.getPosition().x + 25 > screenDimensions.x / 2)
//			position.x = player.getPosition().x + 25;
//		else
//			position.x = screenDimensions.x / 2;
//
//		if (player.getPosition().y + 25 > screenDimensions.y / 2)
//			position.y = player.getPosition().y + 25;
//		else
//			position.y = screenDimensions.y / 2;
//
//		Play.clear();
//		view.setCenter(position); //ตั้งศูนย์กลางของมุมมองตามตำแหน่งของ position
//		Play.setView(view); //ใช้งานมุมมอง
//		Play.draw(Pbackground); //วาด background
//		Play.draw(player); //วาด player
//
//		// draw tileset //
//		Play.draw(tileset1);
//		Play.draw(tileset2);
//		Play.draw(tileset3);
//		Play.draw(tileset4);
//		Play.draw(tileset5);
//		Play.draw(tileset6);
//		Play.draw(tileset6);
//		Play.draw(tileset7);
//		Play.draw(tileset8);
//		Play.draw(tileset9);
//		Play.draw(tileset10);
//		Play.draw(tileset11);
//		Play.draw(tileset12);
//		Play.draw(tileset13);
//		Play.draw(tileset14);
//		Play.draw(tileset15);
//		Play.draw(tileset16);
//		Play.draw(tileset17);
//		Play.draw(tileset18);
//		Play.draw(tileset19);
//		Play.draw(tileset20);
//
//		Play.display();
//
//	}
//
//

//}

/*

#include<iostream>
#include<cmath>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"

using namespace sf;

int main()
{
	const unsigned WINDOW_WIDTH = 800;
	const unsigned WINDOW_HEIGHT = 600;
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
	window.setFramerateLimit(120);

	float dt;
	Clock dt_clock;

	const float gridSize = 50.f;

	//Player
	const float movementSpeed = 100.f;
	Vector2f velocity;
	RectangleShape player;
	player.setFillColor(Color::Green);
	player.setSize(Vector2f(20, 20));

	//Walls
	std::vector<RectangleShape> walls;

	RectangleShape wall;
	wall.setFillColor(Color::Red);
	wall.setSize(Vector2f(gridSize, gridSize));
	wall.setPosition(gridSize * 1, gridSize * 1);

	walls.push_back(wall);

	//Collision
	FloatRect nextPos;

	while (window.isOpen())
	{
		dt = dt_clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Player movement
		velocity.y = 0.f;
		velocity.x = 0.f;

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			velocity.y += -movementSpeed * dt;
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			velocity.y += movementSpeed * dt;
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			velocity.x += -movementSpeed * dt;
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			velocity.x += movementSpeed * dt;
		}

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

		player.move(velocity);

		//Collision screen
		//Left collision
		if (player.getPosition().x < 0.f)
			player.setPosition(0.f, player.getPosition().y);
		//Top collision
		if (player.getPosition().y < 0.f)
			player.setPosition(player.getPosition().x, 0.f);
		//Right collision
		if (player.getPosition().x + player.getGlobalBounds().width > WINDOW_WIDTH)
			player.setPosition(WINDOW_WIDTH - player.getGlobalBounds().width, player.getPosition().y);
		//Bottom collision
		if (player.getPosition().y + player.getGlobalBounds().height > WINDOW_HEIGHT)
			player.setPosition(player.getPosition().x, WINDOW_HEIGHT - player.getGlobalBounds().height);

		//Render
		window.clear();

		window.draw(player);

		for (auto& i : walls)
		{
			window.draw(i);
		}

		window.display();
	}

	return 0;
}





*/