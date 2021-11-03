#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <sfeMovie/Movie.hpp>
#include <string>
#include <iostream>
#include <algorithm>
#include <SFML/OpenGL.hpp>
#include<sstream>

#include"MainMenu.h"

using namespace std;
using namespace sf;

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
	int frameMC = 0;
	int frameGO = 0;
	int row = 0;
	int frameCounter = 0;
	int frameAboutCounter = 0;
	int frameMenuCounter = 0;
	int frameScoreCounter = 0;
	int frameMCCounter = 0;
	int frameGOCounter = 0;


	// Create the main window //

	sf::Vector2i screenDimensions(1280, 720);

	sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "LET'S GO HOME");
	MainMenu mainMenu(window.getSize().x, window.getSize().y);

	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(60);

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

	// bg gameover //

	sf::Texture gameoverTexture;
	sf::Sprite gameover;

	if (!gameoverTexture.loadFromFile("img/bg/game_over.png"))
		std::cout << "Error could not load about bg" << std::endl;
	gameover.setTexture(gameoverTexture);
	gameover.setScale(2.f, 2.f);
	gameover.setPosition(30.f, 0.f);

	sf::RectangleShape bgGO(sf::Vector2f(1920.0f, 1080.0f));
	bgGO.setFillColor(Color(31, 30, 36, 255));

	sf::Texture gameoverMENUTexture;
	sf::Sprite gameoverMENU;

	if (!gameoverMENUTexture.loadFromFile("img/button/menu GO.png"))
		std::cout << "Error could not load about bg" << std::endl;
	gameoverMENU.setTexture(gameoverMENUTexture);
	gameoverMENU.setPosition(445.f, 500.f);

	sf::Texture gameoverQUITTexture;
	sf::Sprite gameoverQUIT;

	if (!gameoverQUITTexture.loadFromFile("img/button/quit GO.png"))
		std::cout << "Error could not load about bg" << std::endl;
	gameoverQUIT.setTexture(gameoverQUITTexture);
	gameoverQUIT.setPosition(707.f, 500.f);




	// Create Sprite button //

	sf::RectangleShape StartButton(sf::Vector2f(165.0f, 60.0f));
	StartButton.setPosition({ 290.f, 380.f });
	StartButton.setFillColor(sf::Color::Transparent);

	sf::RectangleShape ScoreButton(sf::Vector2f(165.0f, 60.0f));
	ScoreButton.setPosition({ 490.f, 380.f });
	ScoreButton.setFillColor(sf::Color::Transparent);

	sf::RectangleShape AboutButton(sf::Vector2f(165.0f, 60.0f));
	AboutButton.setPosition({ 690.f, 380.f });
	AboutButton.setFillColor(sf::Color::Transparent);

	sf::RectangleShape ExitButton(sf::Vector2f(145.0f, 60.0f));
	ExitButton.setPosition({ 900.f, 380.f });
	ExitButton.setFillColor(sf::Color::Transparent);


	/***************************************************** game zone ***************************************************************/

	// create mc //

	sf::Texture GrandmaTexture;
	sf::Sprite Grandma;

	if (!GrandmaTexture.loadFromFile("img/character/others/grandma.png"))
		std::cout << "Error could not load MC image" << std::endl;
	Grandma.setTexture(GrandmaTexture);
	Grandma.setScale(3.f, 3.f);


	sf::Texture AuntTexture;
	sf::Sprite Aunt;

	if (!AuntTexture.loadFromFile("img/character/others/aunt.png"))
		std::cout << "Error could not load MC image" << std::endl;
	Aunt.setTexture(AuntTexture);
	Aunt.setScale(3.f, 3.f);
	
	sf::Texture Dog_mcTexture;
	sf::Sprite Dog_mc;

	if (!Dog_mcTexture.loadFromFile("img/character/others/dog.png"))
		std::cout << "Error could not load MC image" << std::endl;
	Dog_mc.setTexture(Dog_mcTexture);
	Dog_mc.setScale(2.f, 2.f);

	sf::Texture catTexture;
	sf::Sprite cat_mc;

	if (!catTexture.loadFromFile("img/character/others/cat.png"))
		std::cout << "Error could not load MC image" << std::endl;
	cat_mc.setTexture(catTexture);
	cat_mc.setScale(4.f, 4.f);

	sf::Texture maleTexture;
	sf::Sprite male;

	if (!maleTexture.loadFromFile("img/character/others/male.png"))
		std::cout << "Error could not load MC image" << std::endl;
	male.setTexture(maleTexture);
	male.setScale(3.f, 3.f);


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

	sf::Texture Hover_exitGOTexture;
	sf::Sprite Hover_exitGOSprite;

	if (!Hover_exitGOTexture.loadFromFile("img/bg/choose.png"))
		std::cout << "Error could not load choose image" << std::endl;
	Hover_exitGOSprite.setTexture(Hover_exitGOTexture);
	Hover_exitGOSprite.setScale(0.3f, 0.3f);
	Hover_exitGOSprite.setPosition(-100, -100);

	sf::Texture Hover_menuGOTexture;
	sf::Sprite Hover_menuSprite;

	if (!Hover_menuGOTexture.loadFromFile("img/bg/choose.png"))
		std::cout << "Error could not load choose image" << std::endl;
	Hover_menuSprite.setTexture(Hover_menuGOTexture);
	Hover_menuSprite.setScale(0.3f, 0.3f);
	Hover_menuSprite.setPosition(-100, -100);

	sf::Texture ExitSpriteTexture;
	sf::Sprite ExitSprite;

	if (!ExitSpriteTexture.loadFromFile("img/bg/exit.png"))
		std::cout << "Error could not load exit button" << std::endl;
	ExitSprite.setTexture(ExitSpriteTexture);
	ExitSprite.setScale(0.7f, 0.7f);

	sf::Texture ScoreSpriteTexture;
	sf::Sprite ScoreSprite;

	if (!ScoreSpriteTexture.loadFromFile("img/button/hourglass.png"))
		std::cout << "Error could not load choose image" << std::endl;
	ScoreSprite.setTexture(ScoreSpriteTexture);
	ScoreSprite.setScale(1.5f, 1.5f);

	// create black sprite

	sf::Texture BlackTexture;
	sf::Sprite BlackSprite;

	if (!BlackTexture.loadFromFile("img/bg/black.png"))
		std::cout << "Error could not load black image" << std::endl;
	BlackSprite.setTexture(BlackTexture);
	BlackSprite.setPosition(-100000, -100000);

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

	movieLogo.fit(0, -210, 1280, 720);
	movieLogo.play();

	float dt;
	Clock dt_clock;

	const float movementSpeed = 300.f;
	Vector2f velocity;

	sf::Texture chooseBGtexture;
	sf::Sprite chooseBG;

	sf::String yourname;
	sf::Text playerName;
	sf::Font font;
	font.loadFromFile("Fonts/Pixeboy-z8XGD.ttf");


	sf::String yourPetname;
	sf::Text playerPetName;


	int player_choose = 0;
	int player_choose_pet = 0;
	int player_namecheck = 0;
	int player_Petnamecheck = 0;
	int player_Petcheck = 0;
	int player_check = 0;

	if (!chooseBGtexture.loadFromFile("img/bg/choose_character.png"))
		std::cout << "Error could not load player image" << std::endl;

	chooseBG.setTexture(chooseBGtexture);

	// Create Sprite button //

	sf::Texture character1Texture;
	sf::Sprite character1;

	if (!character1Texture.loadFromFile("img/bg/choose_character_inside.png"))
		std::cout << "Error could not load player image" << std::endl;

	character1.setTexture(character1Texture);
	character1.setPosition({ 115.f, 61.f });
	character1.setScale(5.f, 5.f);

	sf::Texture character2Texture;
	sf::Sprite character2;

	if (!character2Texture.loadFromFile("img/bg/choose_character_inside2.png"))
		std::cout << "Error could not load player image" << std::endl;

	character2.setTexture(character2Texture);
	character2.setPosition({ 363.f, 61.f });
	character2.setScale(5.f, 5.f);


	sf::Texture character3Texture;
	sf::Sprite character3;

	if (!character3Texture.loadFromFile("img/bg/choose_character_inside3.png"))
		std::cout << "Error could not load player image" << std::endl;
	character3.setTexture(character3Texture);
	character3.setPosition({ 115.f, 313.f });
	character3.setScale(5.f, 5.f);

	sf::Texture character4Texture;
	sf::Sprite character4;

	if (!character4Texture.loadFromFile("img/bg/choose_character_inside4.png"))
		std::cout << "Error could not load player image" << std::endl;
	character4.setTexture(character4Texture);
	character4.setPosition({ 364.f, 313.f });
	character4.setScale(5.f, 5.f);

	// create choose pet //

	sf::Texture characterPet1Texture;
	sf::Sprite characterPet1;

	if (!characterPet1Texture.loadFromFile("img/bg/choose_character_inside5.png"))
		std::cout << "Error could not load player image" << std::endl;
	characterPet1.setTexture(characterPet1Texture);
	characterPet1.setPosition({ 720.f, 288.f });
	characterPet1.setScale(5.f, 5.f);

	sf::Texture characterPet2Texture;
	sf::Sprite characterPet2;

	if (!characterPet2Texture.loadFromFile("img/bg/choose_character_inside6.png"))
		std::cout << "Error could not load player image" << std::endl;
	characterPet2.setTexture(characterPet2Texture);
	characterPet2.setPosition({ 967.f, 288.f });
	characterPet2.setScale(5.f, 5.f);

	sf::Texture textboxYournameTexture;
	sf::Sprite textboxYourname;

	if (!textboxYournameTexture.loadFromFile("img/button/textbox_yourname.png"))
		std::cout << "Error could not load player image" << std::endl;
	textboxYourname.setTexture(textboxYournameTexture);
	textboxYourname.setPosition({ 258.f, 570.f });

	sf::Texture textboxYourPetnameTexture;
	sf::Sprite textboxYourPetname;

	if (!textboxYourPetnameTexture.loadFromFile("img/button/textbox_yourname.png"))
		std::cout << "Error could not load player image" << std::endl;
	textboxYourPetname.setTexture(textboxYourPetnameTexture);
	textboxYourPetname.setPosition({ 848.f, 570.f });

	// create next //

	sf::Texture NextTexture;
	sf::Sprite Next;

	if (!NextTexture.loadFromFile("img/bg/next.png"))
		std::cout << "Error could not load player image" << std::endl;
	Next.setTexture(NextTexture);
	Next.setPosition({ 10000.f, 10000.f });




	// create check open door //

	sf::Texture Textbox_dialogTexture;
	sf::Sprite Textbox_dialog;

	if (!Textbox_dialogTexture.loadFromFile("img/button/textbox_dialog.png"))
		std::cout << "Error could not load player image" << std::endl;
	Textbox_dialog.setTexture(Textbox_dialogTexture);
	Textbox_dialog.setPosition({ 10000.f, 10000.f });


	// bg my house //

	sf::Texture myhouseTexture;
	sf::Sprite myhouse;

	if (!myhouseTexture.loadFromFile("img/bg/my_house.png"))
		std::cout << "Error could not load about bg" << std::endl;
	myhouse.setTexture(myhouseTexture);
	myhouse.setScale(4.f, 4.f);
	myhouse.setPosition({ 10000.f, 10000.f });

	//// bg house 5 //

	sf::Texture myhouse5Texture;
	sf::Sprite myhouse5;

	if (!myhouse5Texture.loadFromFile("img/bg/house5.png"))
		std::cout << "Error could not load about bg" << std::endl;
	myhouse5.setTexture(myhouse5Texture);
	myhouse5.setScale(4.f, 4.f);
	myhouse5.setPosition({ 10000.f, 10000.f });

	// bg house 2 //

	sf::Texture myhouse2Texture;
	sf::Sprite myhouse2;

	if (!myhouse2Texture.loadFromFile("img/bg/house2.png"))
		std::cout << "Error could not load about bg" << std::endl;
	myhouse2.setTexture(myhouse2Texture);
	myhouse2.setScale(2.f, 2.f);
	myhouse2.setPosition({ 10000.f, 10000.f });

	// bg house 3 //

	sf::Texture myhouse3Texture;
	sf::Sprite myhouse3;

	if (!myhouse3Texture.loadFromFile("img/bg/house3.png"))
		std::cout << "Error could not load about bg" << std::endl;
	myhouse3.setTexture(myhouse3Texture);
	myhouse3.setScale(4.f, 4.f);
	myhouse3.setPosition({ 10000.f, 10000.f });

	// bg house 4 //

	sf::Texture myhouse4Texture;
	sf::Sprite myhouse4;

	if (!myhouse4Texture.loadFromFile("img/bg/house4.png"))
		std::cout << "Error could not load about bg" << std::endl;
	myhouse4.setTexture(myhouse4Texture);
	myhouse4.setScale(2.2f, 2.2f);
	myhouse4.setPosition({ 10000.f, 10000.f });

	// bg house 1 //

	sf::Texture myhouse1Texture;
	sf::Sprite myhouse1;

	if (!myhouse1Texture.loadFromFile("img/bg/house.png"))
		std::cout << "Error could not load about bg" << std::endl;
	myhouse1.setTexture(myhouse1Texture);
	myhouse1.setScale(4.f, 4.f);
	myhouse1.setPosition({ 10000.f, 10000.f });

	


	sf::RectangleShape Home1(sf::Vector2f(33.0f, 38.0f));
	Home1.setPosition({ 846.f, 2971.f });
	Home1.setFillColor(sf::Color::Transparent);

	sf::RectangleShape Home2(sf::Vector2f(33.0f, 38.0f));
	Home2.setPosition({ 1168.f, 2083.f });
	Home2.setFillColor(sf::Color::Transparent);

	sf::RectangleShape Home3(sf::Vector2f(33.0f, 38.0f));
	Home3.setPosition({ 2320.f, 995.f });
	Home3.setFillColor(sf::Color::Transparent);

	sf::RectangleShape Home4(sf::Vector2f(33.0f, 38.0f));
	Home4.setPosition({ 3216.f, 865.f });
	Home4.setFillColor(sf::Color::Transparent);

	sf::RectangleShape Home5(sf::Vector2f(33.0f, 38.0f));
	Home5.setPosition({ 3280.f, 2011.f });
	Home5.setFillColor(sf::Color::Transparent);

	sf::RectangleShape Home6(sf::Vector2f(33.0f, 38.0f));
	Home6.setPosition({ 4302.f, 1563.f });
	Home6.setFillColor(sf::Color::Transparent);

	sf::RectangleShape Text1(sf::Vector2f(54.0f, 21.0f));
	Text1.setPosition({ 3046.f , 1015.f });
	Text1.setFillColor(sf::Color::Transparent);

	sf::RectangleShape Text2(sf::Vector2f(54.0f, 21.0f));
	Text2.setPosition({ 2154.f, 2163.f });
	Text2.setFillColor(sf::Color::Transparent);


	// stairs //

	sf::RectangleShape stairsHome11(sf::Vector2f(54.0f, 21.0f));
	stairsHome11.setPosition(-10000.f, -10000.f);
	stairsHome11.setFillColor(sf::Color::Transparent);

	sf::RectangleShape stairsHome12(sf::Vector2f(54.0f, 21.0f));
	stairsHome12.setPosition(-10000.f, -10000.f);
	stairsHome12.setFillColor(sf::Color::Transparent);

	sf::RectangleShape stairsHome2(sf::Vector2f(54.0f, 21.0f));
	stairsHome2.setPosition(-10000.f, -10000.f);
	stairsHome2.setFillColor(sf::Color::Transparent);

	sf::RectangleShape stairsHome3(sf::Vector2f(54.0f, 21.0f));
	stairsHome3.setPosition(-10000.f, -10000.f);
	stairsHome3.setFillColor(sf::Color::Transparent);

	sf::RectangleShape stairsHome6(sf::Vector2f(54.0f, 21.0f));
	stairsHome6.setPosition(-10000.f, -10000.f);
	stairsHome6.setFillColor(sf::Color::Transparent);

	// DOOR //

	sf::Texture door1Texture;
	sf::Sprite door1;

	if (!door1Texture.loadFromFile("img/bg/door.png"))
		std::cout << "Error could not load about bg" << std::endl;
	door1.setTexture(door1Texture);
	door1.setScale(4.f, 4.f);
	door1.setPosition({ 10000.f, 10000.f });

	sf::Texture door2Texture;
	sf::Sprite door2;

	if (!door2Texture.loadFromFile("img/bg/door.png"))
		std::cout << "Error could not load about bg" << std::endl;
	door2.setTexture(door2Texture);
	door2.setScale(4.f, 4.f);
	door2.setPosition({ 10000.f, 10000.f });

	// TEXT_STATUS //

	sf::Text textStatus;

	textStatus.setFont(font);
	textStatus.setCharacterSize(50);
	textStatus.setPosition(-10000.f, -10000.f);
	textStatus.setFillColor(Color::Black);

	sf::Text textPlayerName;

	textPlayerName.setFont(font);
	textPlayerName.setCharacterSize(50);
	textPlayerName.setPosition(-10000.f, -10000.f);
	textPlayerName.setFillColor(Color::Black);


	const float gridSize = 64.f;

	
	// create player //

	sf::Texture pTexture;
	sf::Sprite player;
	sf::Clock clock;

	//Collision
	FloatRect nextPos;


	int ExitButtonCheck = 0;
	int collision_check = 0;
	int Dialog_check = 0;

	int AppleExist = 0;
	int FishExist = 0;
	int FlowerExist = 0;

	goto MENU;

MENU:
	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{

			while (window.pollEvent(event)) {
				if (event.type == Event::Closed) {
					window.close();
				}
				if (event.type == Event::KeyPressed) {
					if (event.key.code == Keyboard::Escape) {
						window.close();
					}
				}
			}

			// Check hover

			if (StartButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				mainMenu.HoverMouse_start();	
				Hover_startSprite.setPosition(250, 395);

			}
			if (ScoreButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				mainMenu.HoverMouse_score();
				Hover_scoreSprite.setPosition(450, 395);

			}
			if (AboutButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				mainMenu.HoverMouse_about();
				Hover_aboutSprite.setPosition(650, 395);
			}
			if (ExitButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				mainMenu.HoverMouse_exit();
				Hover_exitSprite.setPosition(860, 395);
			}

			if (!StartButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				mainMenu.UnHoverMouse_start();
				Hover_startSprite.setPosition(-100, -100);
			}
			if (!ScoreButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				mainMenu.UnHoverMouse_score();
				Hover_scoreSprite.setPosition(-100, -100);

			}
			if (!AboutButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				mainMenu.UnHoverMouse_about();

				Hover_aboutSprite.setPosition(-100, -100);
			}
			if (!ExitButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				mainMenu.UnHoverMouse_exit();

				Hover_exitSprite.setPosition(-100, -100);
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (StartButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					goto CHOOSE_CHARACTER;
				}
				if (ScoreButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					goto SCORE;
				}
				if (AboutButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					goto ABOUT;
				}
				if (ExitButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					window.close();
				}
			}
			if (event.type == Event::Closed) 
			{
				window.close();
			}

			break;
		}

		//Update water
		water.setTextureRect(sf::IntRect(1280 * frameMenu, 720 * 0, 1280, 720));


		if (frameMenuCounter == 20) {
			frameMenu = (frameMenu + 1) % 5;
			frameMenuCounter = 0;
		}
		frameMenuCounter++;
	
		window.clear();
		movieLogo.update();
		window.draw(water);
		window.draw(movieLogo);
		window.draw(StartButton);
		window.draw(AboutButton);
		window.draw(ScoreButton);
		window.draw(Hover_startSprite);
		window.draw(Hover_aboutSprite);
		window.draw(Hover_scoreSprite);
		window.draw(Hover_exitSprite);
		window.draw(ExitButton);
		mainMenu.draw(window);
		window.display();


	}

CHOOSE_CHARACTER:

	while (window.isOpen()) {
			sf::Event ev;
			while (window.pollEvent(ev)) {

				if (player_namecheck != 0)
				{
					if (ev.type == sf::Event::TextEntered) {
						if ((ev.text.unicode == '\b') && yourname.getSize() > 0) {//ถ้ากด Backspace เป็นการลบตัวอักษร				
							yourname.erase(yourname.getSize() - 1, 1);
							playerName.setFont(font);
							playerName.setString(yourname);
							if (yourname.getSize() < 1) {
								yourname.clear();
								playerName.setString(yourname);
								player_check = 0;
							}
						}
						else {
							string name;
							yourname += static_cast<char>(ev.text.unicode);
							name += static_cast<char>(ev.text.unicode);
							if ((ev.text.unicode < 128) && (yourname.getSize() < 8)) {
								playerName.setFont(font);
								playerName.setString(yourname);
								player_check = 1;
							}
							if (ev.text.unicode > 128) {
								yourname.clear();
								playerName.setString(yourname);
								player_check = 0;
							}
						}
						playerName.setCharacterSize(60);
						playerName.setPosition(325.0f, 560.0f); 
						

					}
					else if (ev.type == sf::Event::KeyPressed) {
						if (ev.key.code == sf::Keyboard::Return) {
							playerName.setString(yourname);

						}
					}

				}

				if (player_Petnamecheck != 0)
				{
					if (ev.type == sf::Event::TextEntered) {
						if ((ev.text.unicode == '\b') && yourPetname.getSize() > 0) {//ถ้ากด Backspace เป็นการลบตัวอักษร
							yourPetname.erase(yourPetname.getSize() - 1, 1);
							playerPetName.setFont(font);
							playerPetName.setString(yourPetname);
							if (yourPetname.getSize() < 1) {
								yourPetname.clear();
								playerPetName.setString(yourPetname);
								player_Petcheck = 0;
							}
						}
						else {
							string name;
							yourPetname += static_cast<char>(ev.text.unicode);
							name += static_cast<char>(ev.text.unicode);
							if ((ev.text.unicode < 128) && (yourPetname.getSize() < 8)) {
								playerPetName.setFont(font);
								playerPetName.setString(yourPetname);
								player_Petcheck = 1;

							}
							if (ev.text.unicode > 128) {
								yourPetname.clear();
								playerPetName.setString(yourPetname);
								player_Petcheck = 0;
							}
						}
						playerPetName.setCharacterSize(60);   //เซ็ตขนาดของข้อความ
						playerPetName.setPosition(920.0f, 560.0f);  //เซ็ตขนาดของข้อความ

					}
					else if (ev.type == sf::Event::KeyPressed) {
						if (ev.key.code == sf::Keyboard::Return) {
							playerPetName.setString(yourPetname);

						}
					}

				}


				if (ev.type == sf::Event::KeyPressed) {
					switch (ev.key.code) {
					case sf::Keyboard::Space: {

						if (player_choose != 0 && player_choose_pet != 0 && player_Petcheck == 1 && player_check == 1) {
							goto SHORT_SCRENE;
						}

						break;
					}

					case sf::Keyboard::Escape: {

						goto MENU;

						break;
					}

					default:
						break;
					}
				}
			}

			if (player_choose != 0 && player_choose_pet != 0 && player_Petcheck == 1 && player_check == 1) {
				Next.setPosition({ 1119.f, 668.f });
			}
			if (player_check == 0 || player_Petcheck == 0) {
				Next.setPosition({ 100000.f, 10000.f });
			}


			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (character1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					character1.setPosition({ 115.f, 41.f });
					character2.setPosition({ 363.f, 61.f });
					character3.setPosition({ 115.f, 313.f });
					character4.setPosition({ 364.f, 313.f });
					player_choose = 1;
				}
				if (character2.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					character1.setPosition({ 115.f, 61.f });
					character2.setPosition({ 363.f, 51.f });
					character3.setPosition({ 115.f, 313.f });
					character4.setPosition({ 364.f, 313.f });
					player_choose = 2;
				}
				if (character3.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					character1.setPosition({ 115.f, 61.f });
					character2.setPosition({ 363.f, 61.f });
					character3.setPosition({ 115.f, 293.f });
					character4.setPosition({ 364.f, 313.f });
					player_choose = 3;
				}
				if (character4.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					character1.setPosition({ 115.f, 61.f });
					character2.setPosition({ 363.f, 61.f });
					character3.setPosition({ 115.f, 313.f });
					character4.setPosition({ 364.f, 293.f });
					player_choose = 4;
				}

				if (characterPet1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					characterPet1.setPosition({ 720.f, 268.f });
					characterPet2.setPosition({ 967.f, 288.f });
					player_choose_pet = 1;
				}
				if (characterPet2.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					characterPet1.setPosition({ 720.f, 288.f });
					characterPet2.setPosition({ 967.f, 268.f });
					player_choose_pet = 2;
				}
				if (Next.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					goto SHORT_SCRENE;
					
				}

				if (textboxYourname.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					player_namecheck = 1;
				}

				if (!textboxYourname.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					player_namecheck = 0;
				}

				if (textboxYourPetname.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					player_Petnamecheck = 1;
				}

				if (!textboxYourPetname.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					player_Petnamecheck = 0;
				}

			}


			window.clear();
			window.draw(chooseBG);
			window.draw(textboxYourname);
			window.draw(textboxYourPetname);
			window.draw(character1);
			window.draw(character2);
			window.draw(character3);
			window.draw(character4);
			window.draw(characterPet1);
			window.draw(characterPet2);
			window.draw(playerName);
			window.draw(playerPetName);
			window.draw(Next);
			
			window.display();

		}


SHORT_SCRENE:

		movie.fit(0, 0, 1280, 720);
		movie.play();
		BlackSprite.setPosition(-100000, -100000);
		PauseButton.setPosition(-100000, -100000);
		PlayButton.setPosition(-100000, -100000);
		QuitButton.setPosition(-100000, -100000);
		MenuButton.setPosition(-100000, -100000);

		while (window.isOpen()) {
			sf::Event ev;
			while (window.pollEvent(ev)) {

				if (ev.type == sf::Event::KeyPressed) {
					switch (ev.key.code) {
					case sf::Keyboard::Space: {
						goto PLAY;
						movie.stop();
						break;
					}
					case sf::Keyboard::Escape: {
						goto MENU;
						movie.stop();
						break;
					}
					default:
						break;
					}
				}
			}

			window.clear();
			movie.update();
			window.draw(movie);

			window.display();




		}

ABOUT:
		ExitSprite.setPosition(0, 0);
		while (window.isOpen()) {

			Event aevent;
			while (window.pollEvent(aevent)) {
				if (aevent.type == Event::Closed) {
					window.close();
				}
				if (aevent.type == Event::KeyPressed) {
					if (aevent.key.code == Keyboard::Escape) {
						goto MENU;
					}
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (ExitSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					goto MENU;
				}

			}


			//Update bg
			about.setTextureRect(sf::IntRect(1280 * frameAbout, 720 * 0, 1280, 720));


			if (frameAboutCounter == 50) {
				frameAbout = (frameAbout + 1) % 4;
				frameAboutCounter = 0;
			}
			frameAboutCounter++;

			window.clear();
			window.draw(about);
			window.draw(ExitSprite);
			window.display();

		}

SCORE:
		ExitSprite.setPosition(0, 0);
		while (window.isOpen()) {

				Event aevent;
				while (window.pollEvent(aevent)) {
					if (aevent.type == Event::Closed) {
						window.close();
					}
					if (aevent.type == Event::KeyPressed) {
						if (aevent.key.code == Keyboard::Escape) {
							goto MENU;
						}
					}
				}

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (ExitSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					{
						goto MENU;
					}

				}

				//Update score bg
				score.setTextureRect(sf::IntRect(1280 * frameScore, 720 * 0, 1280, 720));


				if (frameScoreCounter == 20) {
					frameScore = (frameScore + 1) % 8;
					frameScoreCounter = 0;
				}
				frameScoreCounter++;


				window.clear();
				window.draw(score);
				window.draw(ExitSprite);
				window.display();
			}

PLAY:

		Clock clock_count;
		Time timer;
		stringstream ss;
		int s = 0;
		int m = 0;
		int house_check = 0;
		int textCheckDialogGrandma = 0;
		int textCheckDialogAunt = 0;
		int textCheckDialogMale = 0;

		// walls zone //

		std::vector<RectangleShape> walls;

		RectangleShape wall;
		wall.setFillColor(Color::Transparent);
		wall.setSize(Vector2f(gridSize, gridSize));

		if (house_check == 0) {
			wall.setPosition(gridSize * 9, gridSize * 40); walls.push_back(wall); wall.setPosition(gridSize * 9, gridSize * 41); walls.push_back(wall); wall.setPosition(gridSize * 9, gridSize * 42); walls.push_back(wall); wall.setPosition(gridSize * 9, gridSize * 43); walls.push_back(wall); wall.setPosition(gridSize * 9, gridSize * 44); walls.push_back(wall); wall.setPosition(gridSize * 9, gridSize * 45); walls.push_back(wall); wall.setPosition(gridSize * 9, gridSize * 46); walls.push_back(wall);
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
			wall.setPosition(gridSize * 18, gridSize * 33);
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
			wall.setPosition(gridSize * 45, gridSize * 30);
			walls.push_back(wall);
			wall.setPosition(gridSize * 48, gridSize * 30);
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
			wall.setPosition(gridSize * 55, gridSize * 14);
			walls.push_back(wall);
			wall.setPosition(gridSize * 57, gridSize * 14);
			walls.push_back(wall);
			wall.setPosition(gridSize * 59, gridSize * 14);
			walls.push_back(wall);
			wall.setPosition(gridSize * 61, gridSize * 14);
			walls.push_back(wall);
			wall.setPosition(gridSize * 63, gridSize * 14);
			walls.push_back(wall);
			wall.setPosition(gridSize * 65, gridSize * 14);
			walls.push_back(wall);
			wall.setPosition(gridSize * 66, gridSize * 15);
			walls.push_back(wall);
			wall.setPosition(gridSize * 66, gridSize * 17);
			walls.push_back(wall);
			wall.setPosition(gridSize * 66, gridSize * 19);
			walls.push_back(wall);
			wall.setPosition(gridSize * 66, gridSize * 21);
			walls.push_back(wall);
			wall.setPosition(gridSize * 66, gridSize * 23);
			walls.push_back(wall);
			wall.setPosition(gridSize * 66, gridSize * 24);
			walls.push_back(wall);
			wall.setPosition(gridSize * 68, gridSize * 24);
			walls.push_back(wall);
			wall.setPosition(gridSize * 69, gridSize * 25);
			walls.push_back(wall);
			wall.setPosition(gridSize * 69, gridSize * 27);
			walls.push_back(wall);
			wall.setPosition(gridSize * 68, gridSize * 28);
			walls.push_back(wall);
			wall.setPosition(gridSize * 66, gridSize * 28);
			walls.push_back(wall);
			wall.setPosition(gridSize * 66, gridSize * 30);
			walls.push_back(wall);
			wall.setPosition(gridSize * 72, gridSize * 30);
			walls.push_back(wall);
			wall.setPosition(gridSize * 73, gridSize * 31);
			walls.push_back(wall);
			wall.setPosition(gridSize * 74, gridSize * 31);
			walls.push_back(wall);
			wall.setPosition(gridSize * 50, gridSize * 25);
			walls.push_back(wall);
			wall.setPosition(gridSize * 51, gridSize * 24);
			walls.push_back(wall);
			wall.setPosition(gridSize * 53, gridSize * 23);
			walls.push_back(wall);
			wall.setPosition(gridSize * 53, gridSize * 21);
			walls.push_back(wall);
			wall.setPosition(gridSize * 53, gridSize * 19);
			walls.push_back(wall);
			wall.setPosition(gridSize * 55, gridSize * 19);
			walls.push_back(wall);
			wall.setPosition(gridSize * 57, gridSize * 19);
			walls.push_back(wall);
			wall.setPosition(gridSize * 59, gridSize * 19);
			walls.push_back(wall);
			wall.setPosition(gridSize * 61, gridSize * 19);
			walls.push_back(wall);
			wall.setPosition(gridSize * 61, gridSize * 21);
			walls.push_back(wall);
			wall.setPosition(gridSize * 62, gridSize * 23);
			walls.push_back(wall);
			wall.setPosition(gridSize * 62, gridSize * 25);
			walls.push_back(wall);
			wall.setPosition(gridSize * 62, gridSize * 27);
			walls.push_back(wall);
			wall.setPosition(gridSize * 62, gridSize * 29);
			walls.push_back(wall);
			wall.setPosition(gridSize * 71, gridSize * 31);
			walls.push_back(wall);

			wall.setPosition(gridSize * 34, gridSize * 19);
			walls.push_back(wall);
			wall.setPosition(gridSize * 54, gridSize * 14);
			walls.push_back(wall);
			wall.setPosition(gridSize * 32, gridSize * 40);
			walls.push_back(wall);
		}

		Text time_show("", font);
		Text playername_show("", font);

		time_show.setCharacterSize(50);
		time_show.setFillColor(Color::Black);
		time_show.setOutlineColor(Color::White);
		time_show.setOutlineThickness(3);
		time_show.setLetterSpacing(2);



		if (player_choose == 1) {

			if (!pTexture.loadFromFile("img/character/playersheet_1.png"))
				std::cout << "Error could not load player image" << std::endl;
		}
		if (player_choose == 2) {

			if (!pTexture.loadFromFile("img/character/playersheet_2.png"))
				std::cout << "Error could not load player image" << std::endl;
		}
		if (player_choose == 3) {

			if (!pTexture.loadFromFile("img/character/playersheet_3.png"))
				std::cout << "Error could not load player image" << std::endl;
		}
		if (player_choose == 4) {

			if (!pTexture.loadFromFile("img/character/playersheet_4.png"))
				std::cout << "Error could not load player image" << std::endl;
		}
		

		player.setTexture(pTexture);
		player.setScale(3.f, 3.f);

		myhouse.setPosition(-10000.f, -10000.f);
		player.setPosition(1050.f, 3000.f);
		Grandma.setPosition(3424.f, 878.f);
		Dog_mc.setPosition(3443.f, 939.f);
		cat_mc.setPosition(1122.f, 2088.f);
		Aunt.setPosition(2163.f, 1224.f);
		male.setPosition(2037.f, 2576.f);

		//Start the game loop
		while (window.isOpen()) {

			dt = dt_clock.restart().asSeconds();
			clock.restart();

			sf::Event aevent;
			while (window.pollEvent(aevent)) {

				if (aevent.type == Event::KeyPressed) {
					if (aevent.key.code == Keyboard::Escape) {
						if (ExitButtonCheck == 0) {
							ExitButtonCheck = 1;
							BlackSprite.setPosition(0, 0);
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

					else if (aevent.key.code == Keyboard::Space) {

						if (player.getGlobalBounds().intersects(stairsHome11.getGlobalBounds()) || player.getGlobalBounds().intersects(stairsHome2.getGlobalBounds()) 
							|| player.getGlobalBounds().intersects(stairsHome3.getGlobalBounds()) || player.getGlobalBounds().intersects(stairsHome6.getGlobalBounds())) {
							if (Dialog_check == 0) {
								Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182);
								textStatus.setString("you can't go upstairs");
								textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 220);
								Dialog_check = 1;
							}
							else if (Dialog_check == 1) {
								Textbox_dialog.setPosition(10000.f, 10000.f);
								textStatus.setPosition(-10000.f, -10000.f);
								Dialog_check = 0;
							}
						}
						if (player.getGlobalBounds().intersects(stairsHome12.getGlobalBounds())) {
							if (Dialog_check == 0) {
								Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182);
								textStatus.setString("you can't go downstairs");
								textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 220);
								Dialog_check = 1;
							}
							else if (Dialog_check == 1) {
								Textbox_dialog.setPosition(10000.f, 10000.f);
								textStatus.setPosition(-10000.f, -10000.f);
								Dialog_check = 0;
							}
						}
						if (player.getGlobalBounds().intersects(door1.getGlobalBounds()) || player.getGlobalBounds().intersects(door2.getGlobalBounds())) {
							if (Dialog_check == 0) {
								Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182);
								textStatus.setString("you can not enter this room");
								textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 220);
								Dialog_check = 1;
							}
							else if (Dialog_check == 1) {
								Textbox_dialog.setPosition(10000.f, 10000.f);
								textStatus.setPosition(-10000.f, -10000.f);
								Dialog_check = 0;
							}
						}
						if (player.getGlobalBounds().intersects(Home1.getGlobalBounds())) {
							if (house_check == 0) {

								stairsHome12.setPosition({ 1001.f, 3266.f });
								stairsHome11.setPosition({ 1455.f, 2768.f });
								myhouse.setPosition(-14.f, 2191.f);
								player.setPosition(1553.f, 2883.f);
								row = 1;
								walls.clear();
								Home1.setPosition(1553.f, 2883.f);
								male.setPosition(-10000.f, -10000.f);
								house_check = 1;

								wall.setPosition(gridSize * 11, gridSize * 43);
								walls.push_back(wall);
								wall.setPosition(gridSize * 11, gridSize * 44);
								walls.push_back(wall);
								wall.setPosition(gridSize * 11, gridSize * 46);
								walls.push_back(wall);
								wall.setPosition(gridSize * 11, gridSize * 48);
								walls.push_back(wall);
								wall.setPosition(gridSize * 12, gridSize * 42);
								walls.push_back(wall);
								wall.setPosition(gridSize * 12, gridSize * 50);
								walls.push_back(wall);
								wall.setPosition(gridSize * 13, gridSize * 50);
								walls.push_back(wall);
								wall.setPosition(gridSize * 14, gridSize * 47);
								walls.push_back(wall);
								wall.setPosition(gridSize * 14, gridSize * 48);
								walls.push_back(wall);
								wall.setPosition(gridSize * 14, gridSize * 42);
								walls.push_back(wall);
								wall.setPosition(gridSize * 15, gridSize * 43);
								walls.push_back(wall);
								wall.setPosition(gridSize * 15, gridSize * 44);
								walls.push_back(wall);
								wall.setPosition(gridSize * 15, gridSize * 51);
								walls.push_back(wall);
								wall.setPosition(gridSize * 15, gridSize * 52);
								walls.push_back(wall);
								wall.setPosition(gridSize * 17, gridSize * 44);
								walls.push_back(wall);
								wall.setPosition(gridSize * 17, gridSize * 53);
								walls.push_back(wall);
								wall.setPosition(gridSize * 19, gridSize * 53);
								walls.push_back(wall);
								wall.setPosition(gridSize * 21, gridSize * 53);
								walls.push_back(wall);
								wall.setPosition(gridSize * 21, gridSize * 45);
								walls.push_back(wall);
								wall.setPosition(gridSize * 21, gridSize * 44);
								walls.push_back(wall);
								wall.setPosition(gridSize * 21, gridSize * 49);
								walls.push_back(wall);
								wall.setPosition(gridSize * 22, gridSize * 43);
								walls.push_back(wall);
								wall.setPosition(gridSize * 22, gridSize * 51);
								walls.push_back(wall);
								wall.setPosition(gridSize * 22, gridSize * 52);
								walls.push_back(wall);
								wall.setPosition(gridSize * 23, gridSize * 42);
								walls.push_back(wall);
								wall.setPosition(gridSize * 24, gridSize * 42);
								walls.push_back(wall);
								wall.setPosition(gridSize * 25, gridSize * 43);
								walls.push_back(wall);
								wall.setPosition(gridSize * 25, gridSize * 47);
								walls.push_back(wall);
								wall.setPosition(gridSize * 26, gridSize * 46);
								walls.push_back(wall);
								wall.setPosition(gridSize * 26, gridSize * 45);
								walls.push_back(wall);
								wall.setPosition(gridSize * 26, gridSize * 44);
								walls.push_back(wall);
								wall.setPosition(gridSize * 25, gridSize * 49);
								walls.push_back(wall);
								wall.setPosition(gridSize * 23, gridSize * 49);
								walls.push_back(wall);
								wall.setPosition(gridSize * 18, gridSize * 45);
								walls.push_back(wall);
								wall.setPosition(gridSize * 18, gridSize * 46);
								walls.push_back(wall);
								wall.setPosition(gridSize * 19, gridSize * 46);
								walls.push_back(wall);
								wall.setPosition(gridSize * 20, gridSize * 46);
								walls.push_back(wall);
								wall.setPosition(gridSize * 12, gridSize * 47);
								walls.push_back(wall);
							}
							else {
								house_check = 0;
								Home1.setPosition(846.f, 2971.f);
								myhouse.setPosition(-10000.f, -10000.f);
								player.setPosition(805.f, 2995.f);
								male.setPosition(2037.f, 2576.f);
								stairsHome12.setPosition(-10000.f, -10000.f);
								stairsHome11.setPosition(-10000.f, -10000.f);

								row = 0;
								walls.clear();
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
								wall.setPosition(gridSize * 17, gridSize * 33);
								walls.push_back(wall);
								wall.setPosition(gridSize * 18, gridSize * 33);
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
								wall.setPosition(gridSize * 45, gridSize * 30);
								walls.push_back(wall);
								wall.setPosition(gridSize * 48, gridSize * 30);
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
								wall.setPosition(gridSize * 55, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 57, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 59, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 61, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 63, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 65, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 15);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 17);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 21);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 23);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 24);
								walls.push_back(wall);
								wall.setPosition(gridSize * 68, gridSize * 24);
								walls.push_back(wall);
								wall.setPosition(gridSize * 69, gridSize * 25);
								walls.push_back(wall);
								wall.setPosition(gridSize * 69, gridSize * 27);
								walls.push_back(wall);
								wall.setPosition(gridSize * 68, gridSize * 28);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 28);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 30);
								walls.push_back(wall);
								wall.setPosition(gridSize * 72, gridSize * 30);
								walls.push_back(wall);
								wall.setPosition(gridSize * 73, gridSize * 31);
								walls.push_back(wall);
								wall.setPosition(gridSize * 74, gridSize * 31);
								walls.push_back(wall);
								wall.setPosition(gridSize * 50, gridSize * 25);
								walls.push_back(wall);
								wall.setPosition(gridSize * 51, gridSize * 24);
								walls.push_back(wall);
								wall.setPosition(gridSize * 53, gridSize * 23);
								walls.push_back(wall);
								wall.setPosition(gridSize * 53, gridSize * 21);
								walls.push_back(wall);
								wall.setPosition(gridSize * 53, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 55, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 57, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 59, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 61, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 61, gridSize * 21);
								walls.push_back(wall);
								wall.setPosition(gridSize * 62, gridSize * 23);
								walls.push_back(wall);
								wall.setPosition(gridSize * 62, gridSize * 25);
								walls.push_back(wall);
								wall.setPosition(gridSize * 62, gridSize * 27);
								walls.push_back(wall);
								wall.setPosition(gridSize * 62, gridSize * 29);
								walls.push_back(wall);
								wall.setPosition(gridSize * 71, gridSize * 31);
								walls.push_back(wall);
								wall.setPosition(gridSize * 34, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 54, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 32, gridSize * 40);
								walls.push_back(wall);
							}
						}
						else if (player.getGlobalBounds().intersects(Home2.getGlobalBounds())) {
							if (house_check == 0) {
								myhouse5.setPosition({ 130.f, 1290.f });
								player.setPosition(1295.f, 2189.f);
								row = 3;
								walls.clear();
								Home2.setPosition(1295.f, 2189.f);
								stairsHome2.setPosition(1045.f, 1870.f);
								house_check = 1;
								wall.setPosition(gridSize * 14, gridSize * 31);
								walls.push_back(wall);
								wall.setPosition(gridSize * 15, gridSize * 29);
								walls.push_back(wall);
								wall.setPosition(gridSize * 15, gridSize * 32);
								walls.push_back(wall);
								wall.setPosition(gridSize * 16, gridSize * 27);
								walls.push_back(wall);
								wall.setPosition(gridSize * 16, gridSize * 33);
								walls.push_back(wall);
								wall.setPosition(gridSize * 16, gridSize * 34);
								walls.push_back(wall);
								wall.setPosition(gridSize * 17, gridSize * 35);
								walls.push_back(wall);
								wall.setPosition(gridSize * 17, gridSize * 27);
								walls.push_back(wall);
								wall.setPosition(gridSize * 18, gridSize * 27);
								walls.push_back(wall);
								wall.setPosition(gridSize * 19, gridSize * 28);
								walls.push_back(wall);
								wall.setPosition(gridSize * 19, gridSize * 35);
								walls.push_back(wall);
								wall.setPosition(gridSize * 22, gridSize * 35);
								walls.push_back(wall);
								wall.setPosition(gridSize * 20, gridSize * 36);
								walls.push_back(wall);
								wall.setPosition(gridSize * 21, gridSize * 28);
								walls.push_back(wall);
								wall.setPosition(gridSize * 23, gridSize * 28);
								walls.push_back(wall);
								wall.setPosition(gridSize * 22, gridSize * 31);
								walls.push_back(wall);
								wall.setPosition(gridSize * 22, gridSize * 32);
								walls.push_back(wall);
								wall.setPosition(gridSize * 23, gridSize * 29);
								walls.push_back(wall);
								wall.setPosition(gridSize * 23, gridSize * 30);
								walls.push_back(wall);
								wall.setPosition(gridSize * 23, gridSize * 33);
								walls.push_back(wall);
								wall.setPosition(gridSize * 23, gridSize * 34);
								walls.push_back(wall);

							}
							else {
								house_check = 0;
								Home2.setPosition({ 1168.f, 2083.f });
								myhouse5.setPosition(-10000.f, -10000.f);
								player.setPosition(1132.f, 2108.f);
								stairsHome2.setPosition(-10000.f, -10000.f);
								row = 0;
								walls.clear();
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
								wall.setPosition(gridSize * 18, gridSize * 33);
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
								wall.setPosition(gridSize * 45, gridSize * 30);
								walls.push_back(wall);
								wall.setPosition(gridSize * 48, gridSize * 30);
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
								wall.setPosition(gridSize * 55, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 57, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 59, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 61, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 63, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 65, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 15);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 17);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 21);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 23);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 24);
								walls.push_back(wall);
								wall.setPosition(gridSize * 68, gridSize * 24);
								walls.push_back(wall);
								wall.setPosition(gridSize * 69, gridSize * 25);
								walls.push_back(wall);
								wall.setPosition(gridSize * 69, gridSize * 27);
								walls.push_back(wall);
								wall.setPosition(gridSize * 68, gridSize * 28);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 28);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 30);
								walls.push_back(wall);
								wall.setPosition(gridSize * 72, gridSize * 30);
								walls.push_back(wall);
								wall.setPosition(gridSize * 73, gridSize * 31);
								walls.push_back(wall);
								wall.setPosition(gridSize * 74, gridSize * 31);
								walls.push_back(wall);
								wall.setPosition(gridSize * 50, gridSize * 25);
								walls.push_back(wall);
								wall.setPosition(gridSize * 51, gridSize * 24);
								walls.push_back(wall);
								wall.setPosition(gridSize * 53, gridSize * 23);
								walls.push_back(wall);
								wall.setPosition(gridSize * 53, gridSize * 21);
								walls.push_back(wall);
								wall.setPosition(gridSize * 53, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 55, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 57, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 59, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 61, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 61, gridSize * 21);
								walls.push_back(wall);
								wall.setPosition(gridSize * 62, gridSize * 23);
								walls.push_back(wall);
								wall.setPosition(gridSize * 62, gridSize * 25);
								walls.push_back(wall);
								wall.setPosition(gridSize * 62, gridSize * 27);
								walls.push_back(wall);
								wall.setPosition(gridSize * 62, gridSize * 29);
								walls.push_back(wall);
								wall.setPosition(gridSize * 71, gridSize * 31);
								walls.push_back(wall);
								wall.setPosition(gridSize * 34, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 54, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 32, gridSize * 40);
								walls.push_back(wall);
							}
						}
						else if (player.getGlobalBounds().intersects(Home3.getGlobalBounds())) {
						if (house_check == 0) {
							myhouse1.setPosition({ 1247.f, 260.f });
							player.setPosition(2097.f, 1074.f);
							stairsHome3.setPosition(2032.f, 882.f);
							row = 3;
							walls.clear();
							Home3.setPosition(2097.f, 1074.f);
							Aunt.setPosition(-10000.f, -10000.f);
							house_check = 1;
							wall.setPosition(gridSize * 29, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 30, gridSize * 13);
							walls.push_back(wall);
							wall.setPosition(gridSize * 39, gridSize * 12);
							walls.push_back(wall);
							wall.setPosition(gridSize * 30, gridSize * 16);
							walls.push_back(wall);
							wall.setPosition(gridSize * 31, gridSize * 18);
							walls.push_back(wall);
							wall.setPosition(gridSize * 31, gridSize * 18);
							walls.push_back(wall);
							wall.setPosition(gridSize * 33, gridSize * 18);
							walls.push_back(wall);
							wall.setPosition(gridSize * 35, gridSize * 18);
							walls.push_back(wall);
							wall.setPosition(gridSize * 37, gridSize * 18);
							walls.push_back(wall);
							wall.setPosition(gridSize * 39, gridSize * 18);
							walls.push_back(wall);
							wall.setPosition(gridSize * 41, gridSize * 17);
							walls.push_back(wall);
							wall.setPosition(gridSize * 41, gridSize * 15);
							walls.push_back(wall);
							wall.setPosition(gridSize * 39, gridSize * 11);
							walls.push_back(wall);
							wall.setPosition(gridSize * 32, gridSize * 11);
							walls.push_back(wall);
							wall.setPosition(gridSize * 31, gridSize * 12);
							walls.push_back(wall);
							wall.setPosition(gridSize * 31, gridSize * 13);
							walls.push_back(wall);
							wall.setPosition(gridSize * 33, gridSize * 10);
							walls.push_back(wall);
							wall.setPosition(gridSize * 34, gridSize * 10);
							walls.push_back(wall);
							wall.setPosition(gridSize * 36, gridSize * 10);
							walls.push_back(wall);
							wall.setPosition(gridSize * 38, gridSize * 10);
							walls.push_back(wall);
							wall.setPosition(gridSize * 40, gridSize * 14);
							walls.push_back(wall);
						}
						else {
							house_check = 0;
							Home3.setPosition(2291.f, 1026.f);
							myhouse1.setPosition(-10000.f, -10000.f);
							stairsHome3.setPosition(-10000.f, -10000.f);
							player.setPosition(2291.f, 1030.f);
							Aunt.setPosition(2163.f, 1224.f);

							row = 0;
							walls.clear();
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
							wall.setPosition(gridSize * 18, gridSize * 33);
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
							wall.setPosition(gridSize * 45, gridSize * 30);
							walls.push_back(wall);
							wall.setPosition(gridSize * 48, gridSize * 30);
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
							wall.setPosition(gridSize * 55, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 57, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 59, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 61, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 63, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 65, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 15);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 17);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 21);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 23);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 24);
							walls.push_back(wall);
							wall.setPosition(gridSize * 68, gridSize * 24);
							walls.push_back(wall);
							wall.setPosition(gridSize * 69, gridSize * 25);
							walls.push_back(wall);
							wall.setPosition(gridSize * 69, gridSize * 27);
							walls.push_back(wall);
							wall.setPosition(gridSize * 68, gridSize * 28);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 28);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 30);
							walls.push_back(wall);
							wall.setPosition(gridSize * 72, gridSize * 30);
							walls.push_back(wall);
							wall.setPosition(gridSize * 73, gridSize * 31);
							walls.push_back(wall);
							wall.setPosition(gridSize * 74, gridSize * 31);
							walls.push_back(wall);
							wall.setPosition(gridSize * 50, gridSize * 25);
							walls.push_back(wall);
							wall.setPosition(gridSize * 51, gridSize * 24);
							walls.push_back(wall);
							wall.setPosition(gridSize * 53, gridSize * 23);
							walls.push_back(wall);
							wall.setPosition(gridSize * 53, gridSize * 21);
							walls.push_back(wall);
							wall.setPosition(gridSize * 53, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 55, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 57, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 59, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 61, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 61, gridSize * 21);
							walls.push_back(wall);
							wall.setPosition(gridSize * 62, gridSize * 23);
							walls.push_back(wall);
							wall.setPosition(gridSize * 62, gridSize * 25);
							walls.push_back(wall);
							wall.setPosition(gridSize * 62, gridSize * 27);
							walls.push_back(wall);
							wall.setPosition(gridSize * 62, gridSize * 29);
							walls.push_back(wall);
							wall.setPosition(gridSize * 71, gridSize * 31);
							walls.push_back(wall);
							wall.setPosition(gridSize * 34, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 54, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 32, gridSize * 40);
							walls.push_back(wall);
						}
						}
						else if (player.getGlobalBounds().intersects(Home4.getGlobalBounds())) {
						if (house_check == 0) {
							myhouse4.setPosition({ 1700.f, 22.f });
							player.setPosition(3120.f, 1526.f);
							row = 3;
							walls.clear();
							Home4.setPosition(3120.f, 1526.f);
							Grandma.setPosition(-10000.f, -10000.f);
							Dog_mc.setPosition(-10000.f, -10000.f);
							cat_mc.setPosition(-10000.f, -10000.f);
							Aunt.setPosition(-10000.f, -10000.f);
							house_check = 1;
							wall.setPosition(gridSize * 37, gridSize * 6);
							walls.push_back(wall);
							wall.setPosition(gridSize * 39, gridSize * 6);
							walls.push_back(wall);
							wall.setPosition(gridSize * 43, gridSize * 5);
							walls.push_back(wall);
							wall.setPosition(gridSize * 41, gridSize * 6);
							walls.push_back(wall);
							wall.setPosition(gridSize * 44, gridSize * 6);
							walls.push_back(wall);
							wall.setPosition(gridSize * 36, gridSize * 8);
							walls.push_back(wall);
							wall.setPosition(gridSize * 36, gridSize * 10);
							walls.push_back(wall);
							wall.setPosition(gridSize * 36, gridSize * 12);
							walls.push_back(wall);
							wall.setPosition(gridSize * 37, gridSize * 12);
							walls.push_back(wall);
							wall.setPosition(gridSize * 44, gridSize * 12);
							walls.push_back(wall);
							wall.setPosition(gridSize * 45, gridSize * 12);
							walls.push_back(wall);
							wall.setPosition(gridSize * 47, gridSize * 12);
							walls.push_back(wall);
							wall.setPosition(gridSize * 49, gridSize * 12);
							walls.push_back(wall);
							wall.setPosition(gridSize * 54, gridSize * 11);
							walls.push_back(wall);
							wall.setPosition(gridSize * 54, gridSize * 12);
							walls.push_back(wall);
							wall.setPosition(gridSize * 49, gridSize * 11);
							walls.push_back(wall);
							wall.setPosition(gridSize * 47, gridSize * 10);
							walls.push_back(wall);
							wall.setPosition(gridSize * 45, gridSize * 10);
							walls.push_back(wall);
							wall.setPosition(gridSize * 45, gridSize * 8);
							walls.push_back(wall);
							wall.setPosition(gridSize * 63, gridSize * 9);
							walls.push_back(wall);
							wall.setPosition(gridSize * 63, gridSize * 11);
							walls.push_back(wall);
							wall.setPosition(gridSize * 63, gridSize * 13);
							walls.push_back(wall);
							wall.setPosition(gridSize * 55, gridSize * 12);
							walls.push_back(wall);
							wall.setPosition(gridSize * 57, gridSize * 12);
							walls.push_back(wall);
							wall.setPosition(gridSize * 59, gridSize * 12);
							walls.push_back(wall);
							wall.setPosition(gridSize * 36, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 38, gridSize * 15);
							walls.push_back(wall);
							wall.setPosition(gridSize * 42, gridSize * 15);
							walls.push_back(wall);
							wall.setPosition(gridSize * 44, gridSize * 15);
							walls.push_back(wall);
							wall.setPosition(gridSize * 46, gridSize * 15);
							walls.push_back(wall);
							wall.setPosition(gridSize * 47, gridSize * 15);
							walls.push_back(wall);
							wall.setPosition(gridSize * 49, gridSize * 15);
							walls.push_back(wall);
							wall.setPosition(gridSize * 53, gridSize * 15);
							walls.push_back(wall);
							wall.setPosition(gridSize * 55, gridSize * 15);
							walls.push_back(wall);
							wall.setPosition(gridSize * 57, gridSize * 15);
							walls.push_back(wall);
							wall.setPosition(gridSize * 59, gridSize * 15);
							walls.push_back(wall);
							wall.setPosition(gridSize * 61, gridSize * 15);
							walls.push_back(wall);
							wall.setPosition(gridSize * 46, gridSize * 7);
							walls.push_back(wall);
							wall.setPosition(gridSize * 48, gridSize * 7);
							walls.push_back(wall);
							wall.setPosition(gridSize * 50, gridSize * 7);
							walls.push_back(wall);
							wall.setPosition(gridSize * 52, gridSize * 8);
							walls.push_back(wall);
							wall.setPosition(gridSize * 54, gridSize * 9);
							walls.push_back(wall);
							wall.setPosition(gridSize * 56, gridSize * 8);
							walls.push_back(wall);
							wall.setPosition(gridSize * 56, gridSize * 10);
							walls.push_back(wall);
							wall.setPosition(gridSize * 58, gridSize * 7);
							walls.push_back(wall);
							wall.setPosition(gridSize * 60, gridSize * 7);
							walls.push_back(wall);
							wall.setPosition(gridSize * 62, gridSize * 7);
							walls.push_back(wall);
							wall.setPosition(gridSize * 57, gridSize * 11);
							walls.push_back(wall);
							wall.setPosition(gridSize * 59, gridSize * 11);
							walls.push_back(wall);
							wall.setPosition(gridSize * 38, gridSize * 18);
							walls.push_back(wall);
							wall.setPosition(gridSize * 38, gridSize * 20);
							walls.push_back(wall);
							wall.setPosition(gridSize * 38, gridSize * 22);
							walls.push_back(wall);
							wall.setPosition(gridSize * 37, gridSize * 23);
							walls.push_back(wall);
							wall.setPosition(gridSize * 39, gridSize * 25);
							walls.push_back(wall);
							wall.setPosition(gridSize * 41, gridSize * 25);
							walls.push_back(wall);
							wall.setPosition(gridSize * 43, gridSize * 25);
							walls.push_back(wall);
							wall.setPosition(gridSize * 45, gridSize * 25);
							walls.push_back(wall);
							wall.setPosition(gridSize * 47, gridSize * 25);
							walls.push_back(wall);
							wall.setPosition(gridSize * 49, gridSize * 25);
							walls.push_back(wall);
							wall.setPosition(gridSize * 47, gridSize * 23);
							walls.push_back(wall);
							wall.setPosition(gridSize * 51, gridSize * 23);
							walls.push_back(wall);
							wall.setPosition(gridSize * 53, gridSize * 23);
							walls.push_back(wall);
							wall.setPosition(gridSize * 55, gridSize * 23);
							walls.push_back(wall);
							wall.setPosition(gridSize * 43, gridSize * 21);
							walls.push_back(wall);
							wall.setPosition(gridSize * 43, gridSize * 20);
							walls.push_back(wall);
							wall.setPosition(gridSize * 46, gridSize * 21);
							walls.push_back(wall);
							wall.setPosition(gridSize * 46, gridSize * 20);
							walls.push_back(wall);
							wall.setPosition(gridSize * 42, gridSize * 18);
							walls.push_back(wall);
							wall.setPosition(gridSize * 47, gridSize * 18);
							walls.push_back(wall);
							wall.setPosition(gridSize * 49, gridSize * 18);
							walls.push_back(wall);
							wall.setPosition(gridSize * 53, gridSize * 18);
							walls.push_back(wall);
							wall.setPosition(gridSize * 54, gridSize * 18);
							walls.push_back(wall);
							wall.setPosition(gridSize * 56, gridSize * 18);
							walls.push_back(wall);
							wall.setPosition(gridSize * 56, gridSize * 20);
							walls.push_back(wall);
							wall.setPosition(gridSize * 56, gridSize * 21);
							walls.push_back(wall);
							wall.setPosition(gridSize *38, gridSize * 16);
							walls.push_back(wall);
						}
						else {
							house_check = 0;
							Home4.setPosition({ 3216.f, 865.f });
							myhouse4.setPosition(-10000.f, -10000.f);
							player.setPosition(3189.f,898.f);
							Grandma.setPosition(3424.f, 878.f);
							Dog_mc.setPosition(3443.f, 939.f);
							cat_mc.setPosition(1122.f, 2088.f);
							Aunt.setPosition(2163.f, 1224.f);
							row = 0;
							walls.clear();
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
							wall.setPosition(gridSize * 18, gridSize * 33);
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
							wall.setPosition(gridSize * 45, gridSize * 30);
							walls.push_back(wall);
							wall.setPosition(gridSize * 48, gridSize * 30);
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
							wall.setPosition(gridSize * 55, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 57, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 59, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 61, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 63, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 65, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 15);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 17);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 21);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 23);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 24);
							walls.push_back(wall);
							wall.setPosition(gridSize * 68, gridSize * 24);
							walls.push_back(wall);
							wall.setPosition(gridSize * 69, gridSize * 25);
							walls.push_back(wall);
							wall.setPosition(gridSize * 69, gridSize * 27);
							walls.push_back(wall);
							wall.setPosition(gridSize * 68, gridSize * 28);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 28);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 30);
							walls.push_back(wall);
							wall.setPosition(gridSize * 72, gridSize * 30);
							walls.push_back(wall);
							wall.setPosition(gridSize * 73, gridSize * 31);
							walls.push_back(wall);
							wall.setPosition(gridSize * 74, gridSize * 31);
							walls.push_back(wall);
							wall.setPosition(gridSize * 50, gridSize * 25);
							walls.push_back(wall);
							wall.setPosition(gridSize * 51, gridSize * 24);
							walls.push_back(wall);
							wall.setPosition(gridSize * 53, gridSize * 23);
							walls.push_back(wall);
							wall.setPosition(gridSize * 53, gridSize * 21);
							walls.push_back(wall);
							wall.setPosition(gridSize * 53, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 55, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 57, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 59, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 61, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 61, gridSize * 21);
							walls.push_back(wall);
							wall.setPosition(gridSize * 62, gridSize * 23);
							walls.push_back(wall);
							wall.setPosition(gridSize * 62, gridSize * 25);
							walls.push_back(wall);
							wall.setPosition(gridSize * 62, gridSize * 27);
							walls.push_back(wall);
							wall.setPosition(gridSize * 62, gridSize * 29);
							walls.push_back(wall);
							wall.setPosition(gridSize * 71, gridSize * 31);
							walls.push_back(wall);
							wall.setPosition(gridSize * 34, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 54, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 32, gridSize * 40);
							walls.push_back(wall);
						}
						}
						else if (player.getGlobalBounds().intersects(Home5.getGlobalBounds())) {
						if (house_check == 0) {
							myhouse2.setPosition({ 2207.f, 1268.f });
							player.setPosition(2950.f, 2260.f);
							door1.setPosition(3352.f, 1882.f);
							door2.setPosition(3672.f, 1882.f);
							row = 3;
							walls.clear();
							Home5.setPosition(2950.f, 2260.f);
							Grandma.setPosition(-10000.f, -10000.f);
							Dog_mc.setPosition(-10000.f, -10000.f);
							cat_mc.setPosition(-10000.f, -10000.f);
							Aunt.setPosition(-10000.f, -10000.f);
							house_check = 1;
							wall.setPosition(gridSize * 44, gridSize * 28);
							walls.push_back(wall);
							wall.setPosition(gridSize * 44, gridSize * 30);
							walls.push_back(wall);
							wall.setPosition(gridSize * 44, gridSize * 32);
							walls.push_back(wall);
							wall.setPosition(gridSize * 44, gridSize * 34);
							walls.push_back(wall);
							wall.setPosition(gridSize * 44, gridSize * 36);
							walls.push_back(wall);
							wall.setPosition(gridSize * 44, gridSize * 26);
							walls.push_back(wall);
							wall.setPosition(gridSize * 45, gridSize * 25);
							walls.push_back(wall);
							wall.setPosition(gridSize * 45, gridSize * 37);
							walls.push_back(wall);
							wall.setPosition(gridSize * 47, gridSize * 37);
							walls.push_back(wall);
							wall.setPosition(gridSize * 48, gridSize * 36);
							walls.push_back(wall);
							wall.setPosition(gridSize * 57, gridSize * 36);
							walls.push_back(wall);
							wall.setPosition(gridSize * 59, gridSize * 36);
							walls.push_back(wall);
							wall.setPosition(gridSize * 50, gridSize * 35);
							walls.push_back(wall);
							wall.setPosition(gridSize * 50, gridSize * 34);
							walls.push_back(wall);
							wall.setPosition(gridSize * 56, gridSize * 34);
							walls.push_back(wall);
							wall.setPosition(gridSize * 60, gridSize * 34);
							walls.push_back(wall);
							wall.setPosition(gridSize * 54, gridSize * 33);
							walls.push_back(wall);
							wall.setPosition(gridSize * 52, gridSize * 33);
							walls.push_back(wall);
							wall.setPosition(gridSize * 60, gridSize * 32);
							walls.push_back(wall);
							wall.setPosition(gridSize * 60, gridSize * 31);
							walls.push_back(wall);
							wall.setPosition(gridSize * 50, gridSize * 29);
							walls.push_back(wall);
							wall.setPosition(gridSize * 52, gridSize * 29);
							walls.push_back(wall);
							wall.setPosition(gridSize * 54, gridSize * 29);
							walls.push_back(wall);
							wall.setPosition(gridSize * 56, gridSize * 29);
							walls.push_back(wall);
							wall.setPosition(gridSize * 55, gridSize * 30);
							walls.push_back(wall);
							wall.setPosition(gridSize * 58, gridSize * 29);
							walls.push_back(wall);
							wall.setPosition(gridSize * 48, gridSize * 28);
							walls.push_back(wall);
							wall.setPosition(gridSize * 49, gridSize * 28);
							walls.push_back(wall);
							wall.setPosition(gridSize * 50, gridSize * 26);
							walls.push_back(wall);
							wall.setPosition(gridSize * 49, gridSize * 25);
							walls.push_back(wall);
							wall.setPosition(gridSize * 47, gridSize * 25);
							walls.push_back(wall);
						}
						else {
							house_check = 0;
							Home5.setPosition({ 3280.f, 2011.f });
							myhouse2.setPosition(-10000.f, -10000.f);
							player.setPosition(3246.f, 2048.f);
							Grandma.setPosition(3424.f, 878.f);
							Dog_mc.setPosition(3443.f, 939.f);
							cat_mc.setPosition(1122.f, 2088.f);
							Aunt.setPosition(2163.f, 1224.f);
							door1.setPosition(-10000.f, -10000.f);
							door2.setPosition(-10000.f, -10000.f);
							row = 0;
							walls.clear();
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
							wall.setPosition(gridSize * 18, gridSize * 33);
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
							wall.setPosition(gridSize * 45, gridSize * 30);
							walls.push_back(wall);
							wall.setPosition(gridSize * 48, gridSize * 30);
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
							wall.setPosition(gridSize * 55, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 57, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 59, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 61, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 63, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 65, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 15);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 17);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 21);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 23);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 24);
							walls.push_back(wall);
							wall.setPosition(gridSize * 68, gridSize * 24);
							walls.push_back(wall);
							wall.setPosition(gridSize * 69, gridSize * 25);
							walls.push_back(wall);
							wall.setPosition(gridSize * 69, gridSize * 27);
							walls.push_back(wall);
							wall.setPosition(gridSize * 68, gridSize * 28);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 28);
							walls.push_back(wall);
							wall.setPosition(gridSize * 66, gridSize * 30);
							walls.push_back(wall);
							wall.setPosition(gridSize * 72, gridSize * 30);
							walls.push_back(wall);
							wall.setPosition(gridSize * 73, gridSize * 31);
							walls.push_back(wall);
							wall.setPosition(gridSize * 74, gridSize * 31);
							walls.push_back(wall);
							wall.setPosition(gridSize * 50, gridSize * 25);
							walls.push_back(wall);
							wall.setPosition(gridSize * 51, gridSize * 24);
							walls.push_back(wall);
							wall.setPosition(gridSize * 53, gridSize * 23);
							walls.push_back(wall);
							wall.setPosition(gridSize * 53, gridSize * 21);
							walls.push_back(wall);
							wall.setPosition(gridSize * 53, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 55, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 57, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 59, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 61, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 61, gridSize * 21);
							walls.push_back(wall);
							wall.setPosition(gridSize * 62, gridSize * 23);
							walls.push_back(wall);
							wall.setPosition(gridSize * 62, gridSize * 25);
							walls.push_back(wall);
							wall.setPosition(gridSize * 62, gridSize * 27);
							walls.push_back(wall);
							wall.setPosition(gridSize * 62, gridSize * 29);
							walls.push_back(wall);
							wall.setPosition(gridSize * 71, gridSize * 31);
							walls.push_back(wall);
							wall.setPosition(gridSize * 34, gridSize * 19);
							walls.push_back(wall);
							wall.setPosition(gridSize * 54, gridSize * 14);
							walls.push_back(wall);
							wall.setPosition(gridSize * 32, gridSize * 40);
							walls.push_back(wall);
						}
						}
						else if (player.getGlobalBounds().intersects(Home6.getGlobalBounds())) {
							if (house_check == 0) {
								myhouse3.setPosition({ 3088.f, 606.f });
								player.setPosition(4271.f, 1889.f);
								stairsHome6.setPosition(4704.0f, 1359.0f);
								row = 3;
								walls.clear();
								Home6.setPosition(4271.f, 1889.f);
								Grandma.setPosition(-10000.f, -10000.f);
								Dog_mc.setPosition(-10000.f, -10000.f);
								cat_mc.setPosition(-10000.f, -10000.f);
								house_check = 1;
								wall.setPosition(gridSize * 59, gridSize * 20);
								walls.push_back(wall);
								wall.setPosition(gridSize * 61, gridSize * 20);
								walls.push_back(wall);
								wall.setPosition(gridSize * 59, gridSize * 30);
								walls.push_back(wall);
								wall.setPosition(gridSize * 61, gridSize * 30);
								walls.push_back(wall);
								wall.setPosition(gridSize * 62, gridSize * 31);
								walls.push_back(wall);
								wall.setPosition(gridSize * 64, gridSize * 31);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 31);
								walls.push_back(wall);
								wall.setPosition(gridSize * 68, gridSize * 31);
								walls.push_back(wall);
								wall.setPosition(gridSize * 70, gridSize * 31);
								walls.push_back(wall);
								wall.setPosition(gridSize * 72, gridSize * 30);
								walls.push_back(wall);
								wall.setPosition(gridSize * 73, gridSize * 30);
								walls.push_back(wall);
								wall.setPosition(gridSize * 75, gridSize * 30);
								walls.push_back(wall);
								wall.setPosition(gridSize * 76, gridSize * 28);
								walls.push_back(wall);
								wall.setPosition(gridSize * 58, gridSize * 22);
								walls.push_back(wall);
								wall.setPosition(gridSize * 76, gridSize * 26);
								walls.push_back(wall);
								wall.setPosition(gridSize * 75, gridSize * 25);
								walls.push_back(wall);
								wall.setPosition(gridSize * 73, gridSize * 25);
								walls.push_back(wall);
								wall.setPosition(gridSize * 71, gridSize * 25);
								walls.push_back(wall);
								wall.setPosition(gridSize * 75, gridSize * 24);
								walls.push_back(wall);
								wall.setPosition(gridSize * 73, gridSize * 24);
								walls.push_back(wall);
								wall.setPosition(gridSize * 71, gridSize * 24);
								walls.push_back(wall);
								wall.setPosition(gridSize * 75, gridSize * 22);
								walls.push_back(wall);
								wall.setPosition(gridSize * 74, gridSize * 20);
								walls.push_back(wall);
								wall.setPosition(gridSize * 73, gridSize * 18);
								walls.push_back(wall);
								wall.setPosition(gridSize * 71, gridSize * 18);
								walls.push_back(wall);
								wall.setPosition(gridSize * 71, gridSize * 18);
								walls.push_back(wall);
								wall.setPosition(gridSize * 70, gridSize * 17);
								walls.push_back(wall);
								wall.setPosition(gridSize * 69, gridSize * 17);
								walls.push_back(wall);
								wall.setPosition(gridSize * 68, gridSize * 17);
								walls.push_back(wall);
								wall.setPosition(gridSize * 67, gridSize * 17);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 15);
								walls.push_back(wall);
								wall.setPosition(gridSize * 64, gridSize * 15);
								walls.push_back(wall);
								wall.setPosition(gridSize * 63, gridSize * 15);
								walls.push_back(wall);
								wall.setPosition(gridSize * 61, gridSize * 16);
								walls.push_back(wall);
								wall.setPosition(gridSize * 61, gridSize * 18);
								walls.push_back(wall);
								wall.setPosition(gridSize * 62, gridSize * 18);
								walls.push_back(wall);
								wall.setPosition(gridSize * 64, gridSize * 18);
								walls.push_back(wall);
								wall.setPosition(gridSize * 58, gridSize * 23);
								walls.push_back(wall);
								wall.setPosition(gridSize * 58, gridSize * 25);
								walls.push_back(wall);
								wall.setPosition(gridSize * 58, gridSize * 27);
								walls.push_back(wall);
								wall.setPosition(gridSize * 58, gridSize * 29);
								walls.push_back(wall);
								wall.setPosition(gridSize * 71, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 72, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 75, gridSize * 29);
								walls.push_back(wall);
							}
							else {
								house_check = 0;
								Home6.setPosition({ 4302.f, 1563.f });
								myhouse3.setPosition(-10000.f, -10000.f);
								player.setPosition(4274.f, 1606.f);
								Grandma.setPosition(3424.f, 878.f);
								Dog_mc.setPosition(3443.f, 939.f);
								cat_mc.setPosition(1122.f, 2088.f);
								stairsHome6.setPosition(-10000.f, -10000.f);
								row = 0;
								walls.clear();
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
								wall.setPosition(gridSize * 18, gridSize * 33);
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
								wall.setPosition(gridSize * 45, gridSize * 30);
								walls.push_back(wall);
								wall.setPosition(gridSize * 48, gridSize * 30);
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
								wall.setPosition(gridSize * 55, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 57, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 59, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 61, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 63, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 65, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 15);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 17);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 21);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 23);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 24);
								walls.push_back(wall);
								wall.setPosition(gridSize * 68, gridSize * 24);
								walls.push_back(wall);
								wall.setPosition(gridSize * 69, gridSize * 25);
								walls.push_back(wall);
								wall.setPosition(gridSize * 69, gridSize * 27);
								walls.push_back(wall);
								wall.setPosition(gridSize * 68, gridSize * 28);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 28);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 30);
								walls.push_back(wall);
								wall.setPosition(gridSize * 72, gridSize * 30);
								walls.push_back(wall);
								wall.setPosition(gridSize * 73, gridSize * 31);
								walls.push_back(wall);
								wall.setPosition(gridSize * 74, gridSize * 31);
								walls.push_back(wall);
								wall.setPosition(gridSize * 50, gridSize * 25);
								walls.push_back(wall);
								wall.setPosition(gridSize * 51, gridSize * 24);
								walls.push_back(wall);
								wall.setPosition(gridSize * 53, gridSize * 23);
								walls.push_back(wall);
								wall.setPosition(gridSize * 53, gridSize * 21);
								walls.push_back(wall);
								wall.setPosition(gridSize * 53, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 55, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 57, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 59, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 61, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 61, gridSize * 21);
								walls.push_back(wall);
								wall.setPosition(gridSize * 62, gridSize * 23);
								walls.push_back(wall);
								wall.setPosition(gridSize * 62, gridSize * 25);
								walls.push_back(wall);
								wall.setPosition(gridSize * 62, gridSize * 27);
								walls.push_back(wall);
								wall.setPosition(gridSize * 62, gridSize * 29);
								walls.push_back(wall);
								wall.setPosition(gridSize * 71, gridSize * 31);
								walls.push_back(wall);
								wall.setPosition(gridSize * 34, gridSize * 19);
								walls.push_back(wall);
								wall.setPosition(gridSize * 54, gridSize * 14);
								walls.push_back(wall);
								wall.setPosition(gridSize * 32, gridSize * 40);
								walls.push_back(wall);
							}
						}
						else if (player.getGlobalBounds().intersects(Grandma.getGlobalBounds())) {
						if (Dialog_check == 0) {
							if (textCheckDialogGrandma == 0) {
								textStatus.setString("Hello");
								textPlayerName.setString(yourname);
								textPlayerName.setPosition(player.getPosition().x - 150, player.getPosition().y + 220);
								textCheckDialogGrandma = 1;
							}
							else if (textCheckDialogGrandma == 1) {
								textStatus.setString("Hope you find your pet soon");
								textPlayerName.setPosition(-10000.f, -10000.f);
							}
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182);
							textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 220);
							
							Dialog_check = 1;
						}
						else if (Dialog_check == 1) {
							Textbox_dialog.setPosition(10000.f, 10000.f);
							textStatus.setPosition(-10000.f, -10000.f);
							textPlayerName.setPosition(-10000.f, -10000.f);
							Dialog_check = 0;
						}
						}

						else if (player.getGlobalBounds().intersects(Aunt.getGlobalBounds())) {
						if (Dialog_check == 0) {
							if (textCheckDialogAunt == 0 && FlowerExist == 0) {
								textStatus.setString("How do you do?");
								textCheckDialogAunt = 1;
							}
							else if (textCheckDialogAunt == 1 && FlowerExist == 0) {
								textStatus.setString("i find flower to put in vase .. ");
							}
							else if (FlowerExist == 1) {
								textStatus.setString("Thanks. your flower is so pretty");
							}
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182);
							textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 220);
							Dialog_check = 1;
						}
						else if (Dialog_check == 1) {
							Textbox_dialog.setPosition(10000.f, 10000.f);
							textStatus.setPosition(-10000.f, -10000.f);
							Dialog_check = 0;
						}
						}

						else if (player.getGlobalBounds().intersects(Dog_mc.getGlobalBounds())) {
						if (Dialog_check == 0) {
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182);
							textStatus.setString("Bark Bark Bark Bark Bark");
							textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 220);
							Dialog_check = 1;
						}
						else if (Dialog_check == 1) {
							Textbox_dialog.setPosition(10000.f, 10000.f);
							textStatus.setPosition(-10000.f, -10000.f);
							Dialog_check = 0;
						}
						}

						else if (player.getGlobalBounds().intersects(cat_mc.getGlobalBounds())) {
						if (Dialog_check == 0) {
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182);
							textStatus.setString("Meoww~");
							textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 220);
							Dialog_check = 1;
						}
						else if (Dialog_check == 1) {
							Textbox_dialog.setPosition(10000.f, 10000.f);
							textStatus.setPosition(-10000.f, -10000.f);
							Dialog_check = 0;
						}
						}

						else if (player.getGlobalBounds().intersects(male.getGlobalBounds())) {
						if (Dialog_check == 0) {
							if (textCheckDialogMale == 0 && AppleExist == 0) {
								textStatus.setString("Have a nice day!");
								textCheckDialogMale = 1;
							}
							else if (textCheckDialogMale == 1 && AppleExist == 0) {
								textStatus.setString("can you have some fruit?");
							}
							else if (AppleExist == 1) {
								textStatus.setString("thank you so much!");
							}
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182);
							textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 220);
							Dialog_check = 1;
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182);
							textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 220);
							Dialog_check = 1;
						}
						else if (Dialog_check == 1) {
							Textbox_dialog.setPosition(10000.f, 10000.f);
							textStatus.setPosition(-10000.f, -10000.f);
							Dialog_check = 0;
						}
						}

						else if (player.getGlobalBounds().intersects(Text1.getGlobalBounds())) {
						if (Dialog_check == 0) {
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182);
							textStatus.setString("Grandma's house");
							textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 220);
							Dialog_check = 1;
						}
						else if (Dialog_check == 1) {
							Textbox_dialog.setPosition(10000.f, 10000.f);
							textStatus.setPosition(-10000.f, -10000.f);
							Dialog_check = 0;
						}
						}

						else if (player.getGlobalBounds().intersects(Text2.getGlobalBounds())) {
						if (Dialog_check == 0) {
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182);
							textStatus.setString("welcome to the village");
							textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 220);
							Dialog_check = 1;
						}
						else if (Dialog_check == 1) {
							Textbox_dialog.setPosition(10000.f, 10000.f);
							textStatus.setPosition(-10000.f, -10000.f);
							Dialog_check = 0;
						}
						}

					}
				}

			}

			


			ss.str("");

			timer = clock_count.getElapsedTime();
			s = timer.asSeconds();
			m = s / 60;
			s = s - (m * 60);

			if (m < 10)
			{
				ss << "0" << m;
			}
			if (s < 10)
			{
				ss << " : " << "0" << s;
			}
			else
			{
				ss << " : " << s;
			}

			if (m == 4 && s >= 50) {
				time_show.setFillColor(Color::Red);
			}

			if (m == 5) {
				view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
				sf::Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);
				view.setCenter(position);
				window.setView(view);
				ExitButtonCheck = 0;
				yourname.clear();
				playerName.setString(yourname);
				player_check = 0;
				yourPetname.clear();
				playerPetName.setString(yourPetname);
				player_Petcheck = 0;
				character1.setPosition({ 115.f, 61.f });
				character2.setPosition({ 363.f, 61.f });
				character3.setPosition({ 115.f, 313.f });
				character4.setPosition({ 364.f, 313.f });
				characterPet1.setPosition({ 720.f, 288.f });
				characterPet2.setPosition({ 967.f, 288.f });
				player_choose = 0;
				player_choose_pet = 0;
				goto GAMEOVER;
			}


			time_show.setString(ss.str());


			//Player movement
			velocity.y = 0.f;
			velocity.x = 0.f;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && ExitButtonCheck == 0 && Dialog_check == 0) {
				velocity.y += movementSpeed * dt;
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && ExitButtonCheck == 0 && Dialog_check == 0) {
				velocity.x += -movementSpeed * dt;
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && ExitButtonCheck == 0 && Dialog_check == 0) {
				velocity.x += movementSpeed * dt;
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ExitButtonCheck == 0 && Dialog_check == 0) {
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

			if (row == 2 && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) && ExitButtonCheck == 0)row = 6;
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

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (QuitButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					window.close();

				}

				if (MenuButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
					sf::Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);
					view.setCenter(position);
					window.setView(view);
					ExitButtonCheck = 0;
					yourname.clear();
					playerName.setString(yourname);
					player_check = 0;
					yourPetname.clear();
					playerPetName.setString(yourPetname);
					player_Petcheck = 0;
					character1.setPosition({ 115.f, 61.f });
					character2.setPosition({ 363.f, 61.f });
					character3.setPosition({ 115.f, 313.f });
					character4.setPosition({ 364.f, 313.f });
					characterPet1.setPosition({ 720.f, 288.f });
					characterPet2.setPosition({ 967.f, 288.f });
					player_choose = 0;
					player_choose_pet = 0;
					goto MENU;
				}


				if (PlayButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
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

				if (frameCounter == 20) {
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


			if (position.x == player.getPosition().x + 25) {

				if (ExitButtonCheck == 1) {
					PauseButton.setPosition(player.getPosition().x - 170, player.getPosition().y - 200);
					PlayButton.setPosition(player.getPosition().x - 105, player.getPosition().y - 50);
					MenuButton.setPosition(player.getPosition().x - 105, player.getPosition().y + 30);
					QuitButton.setPosition(player.getPosition().x - 105, player.getPosition().y + 110);
				}
				ScoreSprite.setPosition(player.getPosition().x - 575, player.getPosition().y - 310);
				time_show.setPosition(player.getPosition().x - 505, player.getPosition().y - 322);
			}

			//Update MC
			Dog_mc.setTextureRect(sf::IntRect(32 * frameMC, 32 * 0, 32, 32));
			cat_mc.setTextureRect(sf::IntRect(32 * frameMC, 32 * 0, 32, 32));
			Aunt.setTextureRect(sf::IntRect(32 * frameMC, 32 * 0, 32, 32));
			male.setTextureRect(sf::IntRect(32 * frameMC, 32 * 0, 32, 32));
			Grandma.setTextureRect(sf::IntRect(32 * frameMC, 32 * 0, 32, 32));

			if (frameMCCounter == 50) {
				frameMC = (frameMC + 1) % 3;
				frameMCCounter = 0;
			}
			frameMCCounter++;

			window.clear();
			player.move(velocity);
			view.setCenter(position); //ตั้งศูนย์กลางของมุมมองตามตำแหน่งของ position
			window.setView(view); //ใช้งานมุมมอง
			window.draw(Pbackground); //วาด background
			window.draw(myhouse);
			window.draw(myhouse1);
			window.draw(myhouse2);
			window.draw(myhouse3);
			window.draw(myhouse4);
			window.draw(myhouse5);
			window.draw(Home1);
			window.draw(Home2);
			window.draw(Home3);
			window.draw(Home4);
			window.draw(Home5);
			window.draw(Home6);
			window.draw(Text1);
			window.draw(Text2);
			window.draw(door1);
			window.draw(door2);
			window.draw(Grandma);
			window.draw(Dog_mc);
			window.draw(cat_mc);
			window.draw(Aunt);
			window.draw(male);
			window.draw(player);
			window.draw(stairsHome11);
			window.draw(stairsHome12);
			window.draw(stairsHome2);
			window.draw(stairsHome3);
			window.draw(stairsHome6);
			window.draw(Textbox_dialog);
			window.draw(textStatus);
			window.draw(textPlayerName);
			for (auto& i : walls)
			{
				window.draw(i);
			}
			window.draw(time_show);
			window.draw(ScoreSprite);
			window.draw(BlackSprite);
			window.draw(PauseButton);
			window.draw(PlayButton);
			window.draw(QuitButton);
			window.draw(MenuButton);
			window.display();

		}

	GAMEOVER:

		while (window.isOpen()) {

			Event aevent;
			while (window.pollEvent(aevent)) {
				if (aevent.type == Event::Closed) {
					window.close();
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (gameoverMENU.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					goto MENU;
				}
				if (gameoverQUIT.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					window.close();
				}

			}

			if (gameoverQUIT.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				Hover_exitGOSprite.setPosition(687.f, 505.f);
			}

			if (gameoverMENU.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				Hover_menuSprite.setPosition(425.f, 505.f);
			}

			if (!gameoverMENU.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				Hover_menuSprite.setPosition(10000.f, 10000.f);
			}
			if (!gameoverQUIT.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				Hover_exitGOSprite.setPosition(10000.f, 10000.f);
			}



			//Update bg
			gameover.setTextureRect(sf::IntRect(600 * frameGO, 300 * 0, 600, 300));


			if (frameGOCounter == 10) {
				frameGO = (frameGO + 1) % 23;
				frameGOCounter = 0;
			}
			frameGOCounter++;

			window.clear();
			window.draw(bgGO);
			window.draw(gameover);
			window.draw(gameoverMENU);
			window.draw(gameoverQUIT);
			window.draw(Hover_menuSprite);
			window.draw(Hover_exitGOSprite);
			window.display();

		}

		return 0;

}

