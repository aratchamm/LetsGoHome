#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <sfeMovie/Movie.hpp>
#include <string>
#include <iostream>
#include <algorithm>

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
	

	movieLogo.fit(0, 0, width, height);
	movieLogo.play();





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
				MENU.clear();

				movie.fit(0, 0, 1920, 1080);
				movie.play();
				BlackSprite.setPosition(-100000, -100000);
				PauseButton.setPosition(-100000, -100000);
				PlayButton.setPosition(-100000, -100000);
				QuitButton.setPosition(-100000, -100000);


				while (MENU.isOpen()) {
					sf::Event ev;
					while (MENU.pollEvent(ev)) {
						// Window closure
						if (ev.type == sf::Event::Closed ||
							(ev.type == sf::Event::KeyPressed &&
								ev.key.code == sf::Keyboard::Escape)) {
							MENU.close();

						}

						if (ev.type == sf::Event::KeyPressed) {
							switch (ev.key.code) {
							case sf::Keyboard::Space: {
								x = 'P';
								movie.stop();
								MENU.close();

								break;
							}
							default:
								break;
							}
						}
					}

					movie.update();

					// Render movie

					MENU.draw(movie);
					MENU.display();




				}

				if (x == 'P') {

					RenderWindow Play(VideoMode(screenDimensions.x, screenDimensions.y), "LET'S GO HOME");

					player.setPosition(810.f, 3000.f);

					int ExitButtonCheck = 0;

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
									}
								}
							}
						}

						if (position.x == player.getPosition().x + 25) {

							if (ExitButtonCheck == 1) {
								PauseButton.setPosition(player.getPosition().x - 170, player.getPosition().y - 120);
								PlayButton.setPosition(player.getPosition().x - 105, player.getPosition().y + 30);
								QuitButton.setPosition(player.getPosition().x -105, player.getPosition().y + 120);
							}
							ScoreSprite.setPosition(player.getPosition().x - 935, player.getPosition().y - 500);

						}

						if (position.x == screenDimensions.x / 2) {
							if (ExitButtonCheck == 1) {
								PauseButton.setPosition(750, player.getPosition().y - 120);
								PlayButton.setPosition(815, player.getPosition().y + 30);
								QuitButton.setPosition(815, player.getPosition().y + 120);
							}
							ScoreSprite.setPosition(0, player.getPosition().y - 500);
						}


						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							if (QuitButton.getGlobalBounds().contains(Play.mapPixelToCoords(sf::Mouse::getPosition(Play))))
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
						

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && ExitButtonCheck == 0) {
							player.setTextureRect(sf::IntRect(32 * frame, 32 * 0, 32, 32));
							player.move(0, 0.5f);
							row = 0;
						}

						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && ExitButtonCheck == 0) {
							player.setTextureRect(sf::IntRect(32 * frame, 32 * 1, 32, 32));
							player.move(-0.5f, 0);
							row = 1;
						}

						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && ExitButtonCheck == 0) {
							player.setTextureRect(sf::IntRect(32 * frame, 32 * 2, 32, 32));
							player.move(0.5f, 0);
							row = 2;
						}

						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ExitButtonCheck == 0) {
							player.setTextureRect(sf::IntRect(32 * frame, 32 * 3, 32, 32));
							player.move(0, -0.5f);
							row = 3;
						}

						// Idle check
						else if (row == 2 && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) && ExitButtonCheck == 0)player.setTextureRect(sf::IntRect(32 * frame, 32 * 6, 32, 32));
						else if (row == 3 && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ExitButtonCheck == 0)player.setTextureRect(sf::IntRect(32 * frame, 32 * 7, 32, 32));
						else if (row == 0 && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && ExitButtonCheck == 0)player.setTextureRect(sf::IntRect(32 * frame, 32 * 4, 32, 32));
						else if (row == 1 && !sf::Keyboard::isKeyPressed(sf::Keyboard::A) && ExitButtonCheck == 0) player.setTextureRect(sf::IntRect(32 * frame, 32 * 5, 32, 32));

						sf::Vector2i mousePosition = sf::Mouse::getPosition(MENU);

						if (player.getPosition().x + 25 > screenDimensions.x / 2)
							position.x = player.getPosition().x + 25;
						else
							position.x = screenDimensions.x / 2;

						if (player.getPosition().y + 25 > screenDimensions.y / 2)
							position.y = player.getPosition().y + 25;
						else
							position.y = screenDimensions.y / 2;

						view.setCenter(position); //ตั้งศูนย์กลางของมุมมองตามตำแหน่งของ position
						Play.setView(view); //ใช้งานมุมมอง
						Play.draw(Pbackground); //วาด background

						Play.draw(player); //วาด player
						Play.draw(ScoreSprite);
						Play.draw(BlackSprite);
						Play.draw(PauseButton);
						Play.draw(PlayButton);
						Play.draw(QuitButton);
						Play.display();

					}
				}




			}
			if (x == 2) {


				MENU.clear();

				while (MENU.isOpen()) {

					Event aevent;
					while (MENU.pollEvent(aevent)) {
						if (aevent.type == Event::Closed) {
							MENU.close();
						}
						if (aevent.type == Event::KeyPressed) {
							if (aevent.key.code == Keyboard::Escape) {
								MENU.close();
							}
						}
					}

					//Update score bg
					score.setTextureRect(sf::IntRect(1920 * frameScore, 1080 * 0, 1920, 1080));


					if (frameScoreCounter == 80) {
						frameScore = (frameScore + 1) % 8;
						frameScoreCounter = 0;
					}
					frameScoreCounter++;



					

					MENU.draw(score);


					MENU.display();
				}
			}
			if (x == 3) {

				MENU.clear();

				while (MENU.isOpen()) {

					Event aevent;
					while (MENU.pollEvent(aevent)) {
						if (aevent.type == Event::Closed) {
							MENU.close();
						}
						if (aevent.type == Event::KeyPressed) {
							if (aevent.key.code == Keyboard::Escape) {
								MENU.close();
							}
						}
					}


					//Update bg
					about.setTextureRect(sf::IntRect(1920 * frameAbout, 1080 * 0, 1920, 1080));


					if (frameAboutCounter == 200) {
						frameAbout = (frameAbout + 1) % 4;
						frameAboutCounter = 0;
					}
					frameAboutCounter++;


					MENU.draw(about);
					MENU.display();

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
	

		movieLogo.update();
		MENU.clear();
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