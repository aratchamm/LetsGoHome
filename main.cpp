#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include"MainMenu.h"

int main()
{

	int frame = 0;
	int frameLogo = 0;
	int row = 0;
	int frameCounter = 0;
	int frameLogoCounter = 0;

	// Create the main window

	sf::Vector2i screenDimensions(1920, 1080);

	sf::RenderWindow MENU(sf::VideoMode(screenDimensions.x, screenDimensions.y), "LET'S GO HOME", sf::Style::Close | sf::Style::Resize);
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

	MENU.setKeyRepeatEnabled(false);
	MENU.setFramerateLimit(60);

	/*************************** สร้างภาพ background game *****************************/

	sf::RectangleShape Pbackground(sf::Vector2f(2405.f, 2405.f));
	Texture PlayerTexture;
	PlayerTexture.loadFromFile("img/bg/bg.png");
	Pbackground.setTexture(&PlayerTexture);


	// water animation //

	sf::Texture waterTexture;
	sf::Sprite water;

	if (!waterTexture.loadFromFile("img/bg/water_animation.png"))
		std::cout << "Error could not load water" << std::endl;
	water.setTexture(waterTexture);

	// logo animation //

	sf::Texture logoTexture;
	sf::Sprite logo;

	if (!logoTexture.loadFromFile("img/bg/logo_animation.png"))
		std::cout << "Error could not load logo" << std::endl;
	logo.setTexture(logoTexture);
	logo.setScale(2.f, 2.f);
	logo.setPosition(450, 140);

	

	/*************************** สร้างภาพ background about *****************************/

	sf::RectangleShape Abackground(sf::Vector2f(1920.f, 1080.f));
	Texture AboutTexture;
	AboutTexture.loadFromFile("img/bg/menu.png");
	Abackground.setTexture(&AboutTexture);

	/*************************** สร้างภาพ background score *****************************/

	sf::RectangleShape Sbackground(sf::Vector2f(1920.f, 1080.f));
	Texture ScoreTexture;
	ScoreTexture.loadFromFile("img/bg/menu.png");
	Sbackground.setTexture(&ScoreTexture);

	/***************************************************** game zone ***************************************************************/

	

	/*************************** สร้าง player *****************************/
	sf::Texture pTexture;
	sf::Sprite player;
	sf::Clock clock;

	if (!pTexture.loadFromFile("img/character/playersheet_1.png"))
		std::cout << "Error could not load player image" << std::endl;
	player.setTexture(pTexture);
	player.setScale(2.f, 2.f);

	/*********************************สร้างมุมมอง********************************/
	sf::View view;
	view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y)); //กำหนดมุมมองเป็นรูปสี่เหลี่ยมผืนผ้าเริ่มที่ตำแหน่ง (0,0) และมีขนาดเท่ากับขนาดของจอภาพ
	sf::Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);  //สร้างตัวแปร position เพื่อเก็บค่าตำแหน่ง



	//Main Menu Open

	while (MENU.isOpen()) 
	{
		Event event;
		while (MENU.pollEvent(event)) 
		{
			if (event.type == Event::Closed) 
			{
				MENU.close();
			}
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Left) 
				{
					mainMenu.MoveLeft();
					break;
				}
				if (event.key.code == Keyboard::Right) {
					mainMenu.MoveRight();
					break;
				}
				if (event.key.code == Keyboard::Return) {
					RenderWindow Play(VideoMode(screenDimensions.x, screenDimensions.y), "LET'S GO HOME");
					RenderWindow Score(VideoMode(screenDimensions.x, screenDimensions.y), "LET'S GO HOME");
					RenderWindow About(VideoMode(screenDimensions.x, screenDimensions.y), "LET'S GO HOME");
					
					int x = mainMenu.MainMenuPressed();

					if (x == 1)
					{

						//Start the game loop
						while (Play.isOpen()) {
							clock.restart();
							sf::Event aevent;
							while (Play.pollEvent(aevent)) {
								if (aevent.type == Event::Closed) {
									Play.close();
								}
								if (aevent.type == Event::KeyPressed) {
									if (aevent.key.code == Keyboard::Escape) {
										Play.close();
									}
								}
							}

							//Update model
							player.setTextureRect(sf::IntRect(32 * frame, 32 * row, 32, 32));

							if (frameCounter == 100) {
								frame = (frame + 1) % 3;
								frameCounter = 0;
							}
							frameCounter++;

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
								player.setTextureRect(sf::IntRect(32 * frame, 32 * 0, 32, 32));
								player.move(0, 0.5f);
								row = 0;
							}

							else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
								player.setTextureRect(sf::IntRect(32 * frame, 32 * 1, 32, 32));
								player.move(-0.5f, 0);
								row = 1;
							}

							else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
								player.setTextureRect(sf::IntRect(32 * frame, 32 * 2, 32, 32));
								player.move(0.5f, 0);
								row = 2;
							}

							else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
								player.setTextureRect(sf::IntRect(32 * frame, 32 * 3, 32, 32));
								player.move(0, -0.5f);
								row = 3;
							}

							// Idle check
							else if (row == 2 && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))player.setTextureRect(sf::IntRect(32 * frame, 32 * 6, 32, 32));
							else if (row == 3 && !sf::Keyboard::isKeyPressed(sf::Keyboard::W))player.setTextureRect(sf::IntRect(32 * frame, 32 * 7, 32, 32));
							else if (row == 0 && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))player.setTextureRect(sf::IntRect(32 * frame, 32 * 4, 32, 32));
							else if (row == 1 && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))player.setTextureRect(sf::IntRect(32 * frame, 32 * 5, 32, 32));

							sf::Vector2i mousePosition = sf::Mouse::getPosition(Play);

							if (player.getPosition().x + 25 > screenDimensions.x / 2)
								position.x = player.getPosition().x + 25;
							else
								position.x = screenDimensions.x / 2;

							if (player.getPosition().y + 25 > screenDimensions.y / 2)
								position.y = player.getPosition().y + 25;
							else
								position.y = screenDimensions.y / 2;

							About.close();
							Score.close();
							Play.clear();

							view.setCenter(position); //ตั้งศูนย์กลางของมุมมองตามตำแหน่งของ position
							Play.setView(view); //ใช้งานมุมมอง
							Play.draw(Pbackground); //วาด background
							Play.draw(player); //วาด player

							Play.display();

						}
					}
					if (x == 2) {

						while (Score.isOpen()) {

							Event aevent;
							while (Score.pollEvent(aevent)) {
								if (aevent.type == Event::Closed) {
									Score.close();
								}
								if (aevent.type == Event::KeyPressed) {
									if (aevent.key.code == Keyboard::Escape) {
										Score.close();
									}
								}
							}

							Play.close();
							Score.clear();
							About.close();

							Score.draw(Sbackground);

							Score.display();
						}
					}
					if (x == 3) {

						while (About.isOpen()) {

							Event aevent;
							while (About.pollEvent(aevent)) {
								if (aevent.type == Event::Closed) {
									About.close();
								}
								if (aevent.type == Event::KeyPressed) {
									if (aevent.key.code == Keyboard::Escape) {
										About.close();
									}
								}
							}

							Play.close();
							Score.clear();
							About.clear();

							About.draw(Abackground);

							About.display();
						}
					}
					if (x == 4)
						MENU.close();
					break;

				}
			}
		}

		//Update water
		water.setTextureRect(sf::IntRect(1920 * frame, 1080 * 0, 1920, 1080));


		if (frameCounter == 20) {
			frame = (frame + 1) % 5;
			frameCounter = 0;
		}
		frameCounter++;

		//Update logo
		logo.setTextureRect(sf::IntRect(482 * frameLogo, 175 * 0, 482, 175));

		if (frameLogoCounter == 5000) {
			frameLogo = (frameLogo + 1) % 21;
			frameLogoCounter = 0;
		}
		frameLogoCounter++;
		
		


		MENU.clear();
		MENU.draw(water);
		MENU.draw(logo);
		mainMenu.draw(MENU);
		MENU.display();


	}

}