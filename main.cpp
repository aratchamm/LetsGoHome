#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Audio.hpp> 
#include <SFML/Graphics.hpp> 
#include <SFML/Config.hpp> 
#include <sfeMovie/Movie.hpp> 
#include <SFML/OpenGL.hpp> 
#include <SFML/Chronometer.hpp> 
#include<sstream> 
#include<cstdlib> 
#include<stdio.h>
#include<utility>
#include <fstream>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
 
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
	srand(time(NULL)); 

	int scoreSHOW = 0;
	string tempName;
	int tempScore;
 
	// Create video logo // 

	//sftools::Chronometer;
 
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
	int frameHW = 0;
	int frameMC = 0; 
	int frameGO = 0; 
	int frameWIN = 0; 
	int row = 0; 
	int frameCounter = 0; 
	int frameAboutCounter = 0; 
	int frameMenuCounter = 0; 
	int frameScoreCounter = 0; 
	int frameMCCounter = 0; 
	int frameGOCounter = 0; 
	int frameWINCounter = 0; 
	int frameHWCounter = 0;

	int s = 0;
	int m = 0;
 
 
	// Create the main window // 
 
	sf::Vector2i screenDimensions(1280, 720); 
 
	sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "LET'S GO HOME"); 
	MainMenu mainMenu(window.getSize().x, window.getSize().y); 
 
	window.setKeyRepeatEnabled(false); 
	window.setFramerateLimit(60); 
 
	// Create the player window // 
 
	sf::RectangleShape Pbackground(sf::Vector2f(1490.f, 936.f)); 
	Texture PbackgroundTexture; 
	PbackgroundTexture.loadFromFile("img/bg/bg.png"); 
	Pbackground.setTexture(&PbackgroundTexture); 
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
	sf::Sprite scoreBG; 
 
	if (!scoreTexture.loadFromFile("img/bg/score_animation.png")) 
		std::cout << "Error could not load about bg" << std::endl; 
	scoreBG.setTexture(scoreTexture);
 
	// bg gameover // 
 
	sf::Texture gameoverTexture; 
	sf::Sprite gameover; 
 
	if (!gameoverTexture.loadFromFile("img/bg/game_over.png")) 
		std::cout << "Error could not load about bg" << std::endl; 
	gameover.setTexture(gameoverTexture); 
	gameover.setScale(2.f, 2.f); 
	gameover.setPosition(30.f, 0.f); 

	// bg how to play // 

	sf::Texture howtoplayTEXTURE;
	sf::Sprite howtoplay;

	if (!howtoplayTEXTURE.loadFromFile("img/bg/howto.png"))
		std::cout << "Error could not load about bg" << std::endl;
	howtoplay.setTexture(howtoplayTEXTURE);

 
	sf::RectangleShape bgGO(sf::Vector2f(1920.0f, 1080.0f)); 
	bgGO.setFillColor(Color(31, 30, 36, 255)); 
 
	// bg gameover // 
 
	sf::Texture mapTexture; 
	sf::Sprite map; 
 
	if (!mapTexture.loadFromFile("img/bg/map.png")) 
		std::cout << "Error could not load about bg" << std::endl; 
	map.setTexture(mapTexture); 
 
	sf::Texture gameoverMENUTexture; 
	sf::Sprite gameoverMENU; 
 
	if (!gameoverMENUTexture.loadFromFile("img/button/menu GO.png")) 
		std::cout << "Error could not load about bg" << std::endl; 
	gameoverMENU.setTexture(gameoverMENUTexture); 
	gameoverMENU.setPosition(306.f, 500.f); 
 
	sf::Texture gameoverQUITTexture; 
	sf::Sprite gameoverQUIT; 
 
	if (!gameoverQUITTexture.loadFromFile("img/button/quit GO.png")) 
		std::cout << "Error could not load about bg" << std::endl; 
	gameoverQUIT.setTexture(gameoverQUITTexture); 
	gameoverQUIT.setPosition(830.f, 500.f);

	sf::Texture gameoverSCORETexture;
	sf::Sprite gameoverSCORE;

	if (!gameoverSCORETexture.loadFromFile("img/button/score GO.png"))
		std::cout << "Error could not load about bg" << std::endl;
	gameoverSCORE.setTexture(gameoverSCORETexture);
	gameoverSCORE.setPosition(568.f, 500.f);
 
	// bg win // 
 
	sf::Texture winTexture; 
	sf::Sprite win; 
 
	if (!winTexture.loadFromFile("img/bg/win.png")) 
		std::cout << "Error could not load about bg" << std::endl; 
	win.setTexture(winTexture); 
 
	// Create Sprite button // 
 
	sf::RectangleShape winMenuButton(sf::Vector2f(97.0f, 42.0f)); 
	winMenuButton.setPosition({ 414.f, 503.f }); 
	winMenuButton.setFillColor(sf::Color::Transparent); 
 
	sf::RectangleShape winScoreButton(sf::Vector2f(97.0f, 42.0f)); 
	winScoreButton.setPosition({ 579.f, 503.f }); 
	winScoreButton.setFillColor(sf::Color::Transparent); 
 
	sf::RectangleShape winQuitButton(sf::Vector2f(97.0f, 42.0f)); 
	winQuitButton.setPosition({ 744.f, 503.f }); 
	winQuitButton.setFillColor(sf::Color::Transparent); 
 
 
 
 
 
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
 
	// create item // 
 
	sf::Texture fishTexture; 
	sf::Sprite fish; 
 
	if (!fishTexture.loadFromFile("img/tileset/fish.png")) 
		std::cout << "Error could not load fish" << std::endl; 
	fish.setTexture(fishTexture); 
	fish.setScale(2.f, 2.f); 
 
	sf::Texture cakeTexture; 
	sf::Sprite cake; 
 
	if (!cakeTexture.loadFromFile("img/tileset/cake.png")) 
		std::cout << "Error could not load cake" << std::endl; 
	cake.setTexture(cakeTexture); 
	cake.setScale(2.f, 2.f); 
 
	sf::Texture glassTexture; 
	sf::Sprite glass; 
 
	if (!glassTexture.loadFromFile("img/tileset/glass.png")) 
		std::cout << "Error could not load glass" << std::endl; 
	glass.setTexture(glassTexture); 
	glass.setScale(4.f, 4.f); 
 
	sf::Texture clockTexture; 
	sf::Sprite clockPlus; 
 
	 
 
 
	sf::Texture Key1Texture; 
	sf::Sprite key1; 
 
	if (!Key1Texture.loadFromFile("img/tileset/key1-2.png")) 
		std::cout << "Error could not load clock" << std::endl; 
	key1.setTexture(Key1Texture); 
	//key1.setScale(0.5f, 0.5f); 
 
 
	sf::Texture Key2Texture; 
	sf::Sprite key2; 
 
	if (!Key2Texture.loadFromFile("img/tileset/key2-2.png")) 
		std::cout << "Error could not load clock" << std::endl; 
	key2.setTexture(Key2Texture); 
	//key2.setScale(0.5f, 0.5f); 
 
 
	sf::Texture vaseTexture; 
	sf::Sprite vase; 
 
	if (!vaseTexture.loadFromFile("img/tileset/vase.png")) 
		std::cout << "Error could not load vase" << std::endl; 
	vase.setTexture(vaseTexture); 
	vase.setScale(4.f, 4.f); 
 
	sf::Texture bookTexture; 
	sf::Sprite book; 
 
	if (!bookTexture.loadFromFile("img/tileset/book.png")) 
		std::cout << "Error could not load book" << std::endl; 
	book.setTexture(bookTexture); 
	book.setScale(2.f, 2.f); 
 
 
	 
 
 
 
	// create mc // 
 
	sf::Texture GrandmaTexture; 
	sf::Sprite Grandma; 
 
	if (!GrandmaTexture.loadFromFile("img/character/others/grandma.png")) 
		std::cout << "Error could not load MC image" << std::endl; 
	Grandma.setTexture(GrandmaTexture); 
	Grandma.setScale(3.f, 3.f); 
 
	sf::Texture BoyTexture; 
	sf::Sprite Boy; 
 
	if (!BoyTexture.loadFromFile("img/character/others/boy.png")) 
		std::cout << "Error could not load MC image" << std::endl; 
	Boy.setTexture(BoyTexture); 
	Boy.setScale(3.f, 3.f); 
 
	sf::Texture GirlTexture; 
	sf::Sprite Girl; 
 
	if (!GirlTexture.loadFromFile("img/character/others/girl.png")) 
		std::cout << "Error could not load MC image" << std::endl; 
	Girl.setTexture(GirlTexture); 
	Girl.setScale(2.8f, 2.8f); 
 
 
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
 
	sf::Texture Hover_exitWINTexture; 
	sf::Sprite Hover_exitWINSprite; 
 
	if (!Hover_exitWINTexture.loadFromFile("img/bg/choose.png")) 
		std::cout << "Error could not load choose image" << std::endl; 
	Hover_exitWINSprite.setTexture(Hover_exitWINTexture); 
	Hover_exitWINSprite.setScale(0.3f, 0.3f); 
	Hover_exitWINSprite.setPosition(-100, -100); 

	sf::Texture Hover_scoreGOTexture;
	sf::Sprite Hover_scoreGOSprite;

	if (!Hover_scoreGOTexture.loadFromFile("img/bg/choose.png"))
		std::cout << "Error could not load choose image" << std::endl;
	Hover_scoreGOSprite.setTexture(Hover_scoreGOTexture);
	Hover_scoreGOSprite.setScale(0.3f, 0.3f);
	Hover_scoreGOSprite.setPosition(-100, -100);
 
	sf::Texture Hover_menuWINTexture; 
	sf::Sprite Hover_menuWINSprite; 
 
	if (!Hover_menuWINTexture.loadFromFile("img/bg/choose.png")) 
		std::cout << "Error could not load choose image" << std::endl; 
	Hover_menuWINSprite.setTexture(Hover_menuWINTexture); 
	Hover_menuWINSprite.setScale(0.3f, 0.3f); 
	Hover_menuWINSprite.setPosition(-100, -100); 
 
	sf::Texture Hover_scoreWINTexture; 
	sf::Sprite Hover_scoreWINSprite; 
 
	if (!Hover_scoreWINTexture.loadFromFile("img/bg/choose.png")) 
		std::cout << "Error could not load choose image" << std::endl; 
	Hover_scoreWINSprite.setTexture(Hover_scoreWINTexture); 
	Hover_scoreWINSprite.setScale(0.3f, 0.3f); 
	Hover_scoreWINSprite.setPosition(-100, -100); 
 
 
 
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
	character1.setScale(5.f, 5.f); 
 
	sf::Texture character2Texture; 
	sf::Sprite character2; 
 
	if (!character2Texture.loadFromFile("img/bg/choose_character_inside2.png")) 
		std::cout << "Error could not load player image" << std::endl; 
 
	character2.setTexture(character2Texture); 
	character2.setScale(5.f, 5.f); 
 
 
	sf::Texture character3Texture; 
	sf::Sprite character3; 
 
	if (!character3Texture.loadFromFile("img/bg/choose_character_inside3.png")) 
		std::cout << "Error could not load player image" << std::endl; 
	character3.setTexture(character3Texture); 
	character3.setScale(5.f, 5.f); 
 
	sf::Texture character4Texture; 
	sf::Sprite character4; 
 
	if (!character4Texture.loadFromFile("img/bg/choose_character_inside4.png")) 
		std::cout << "Error could not load player image" << std::endl; 
	character4.setTexture(character4Texture); 
	character4.setScale(5.f, 5.f); 
 
	// create choose pet // 
 
	sf::Texture characterPet1Texture; 
	sf::Sprite characterPet1; 
 
	if (!characterPet1Texture.loadFromFile("img/bg/choose_character_inside5.png")) 
		std::cout << "Error could not load player image" << std::endl; 
	characterPet1.setTexture(characterPet1Texture); 
	characterPet1.setScale(5.f, 5.f); 
 
	sf::Texture characterPet2Texture; 
	sf::Sprite characterPet2; 
 
	if (!characterPet2Texture.loadFromFile("img/bg/choose_character_inside6.png")) 
		std::cout << "Error could not load player image" << std::endl; 
	characterPet2.setTexture(characterPet2Texture); 
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
 
	//// bg house 5 // 
 
	sf::Texture myhouse5Texture; 
	sf::Sprite myhouse5; 
 
	if (!myhouse5Texture.loadFromFile("img/bg/house5.png")) 
		std::cout << "Error could not load about bg" << std::endl; 
	myhouse5.setTexture(myhouse5Texture); 
	myhouse5.setScale(4.f, 4.f); 
 
	// bg house 2 // 
 
	sf::Texture myhouse2Texture; 
	sf::Sprite myhouse2; 
 
	if (!myhouse2Texture.loadFromFile("img/bg/house2.png")) 
		std::cout << "Error could not load about bg" << std::endl; 
	myhouse2.setTexture(myhouse2Texture); 
	myhouse2.setScale(2.f, 2.f); 
 
		// bg house 3 // 
 
	sf::Texture myhouse3Texture; 
	sf::Sprite myhouse3; 
 
	if (!myhouse3Texture.loadFromFile("img/bg/house3.png")) 
		std::cout << "Error could not load about bg" << std::endl; 
	myhouse3.setTexture(myhouse3Texture); 
	myhouse3.setScale(4.f, 4.f); 
 
	// bg house 4 // 
 
	sf::Texture myhouse4Texture; 
	sf::Sprite myhouse4; 
 
	if (!myhouse4Texture.loadFromFile("img/bg/house4.png")) 
		std::cout << "Error could not load about bg" << std::endl; 
	myhouse4.setTexture(myhouse4Texture); 
	myhouse4.setScale(2.2f, 2.2f); 
 
	// bg house 1 // 
 
	sf::Texture myhouse1Texture; 
	sf::Sprite myhouse1; 
 
	if (!myhouse1Texture.loadFromFile("img/bg/house.png")) 
		std::cout << "Error could not load about bg" << std::endl; 
	myhouse1.setTexture(myhouse1Texture); 
	myhouse1.setScale(4.f, 4.f); 
 
	 
 
 
	sf::RectangleShape Home1(sf::Vector2f(33.0f, 38.0f)); 
	Home1.setFillColor(sf::Color::Transparent); 
 
	sf::RectangleShape Home2(sf::Vector2f(33.0f, 38.0f)); 
	Home2.setFillColor(sf::Color::Transparent); 
 
	sf::RectangleShape Home3(sf::Vector2f(33.0f, 38.0f)); 
	Home3.setFillColor(sf::Color::Transparent); 
 
	sf::RectangleShape Home4(sf::Vector2f(33.0f, 38.0f)); 
	Home4.setFillColor(sf::Color::Transparent); 
 
	sf::RectangleShape Home5(sf::Vector2f(33.0f, 38.0f)); 
	Home5.setFillColor(sf::Color::Transparent); 
 
	sf::RectangleShape Home6(sf::Vector2f(33.0f, 38.0f)); 
	Home6.setFillColor(sf::Color::Transparent); 
 
	sf::RectangleShape Text1(sf::Vector2f(54.0f, 21.0f)); 
	Text1.setFillColor(sf::Color::Red); 
 
	sf::RectangleShape Text2(sf::Vector2f(54.0f, 21.0f)); 
	Text2.setFillColor(sf::Color::Red);
 
 
	// stairs // 
 
	sf::RectangleShape stairsHome11(sf::Vector2f(24.0f, 21.0f)); 
	stairsHome11.setFillColor(sf::Color::Transparent);
 
	sf::RectangleShape stairsHome12(sf::Vector2f(24.0f, 21.0f)); 
	stairsHome12.setFillColor(sf::Color::Transparent);
 
	sf::RectangleShape stairsHome2(sf::Vector2f(24.0f, 21.0f)); 
	stairsHome2.setFillColor(sf::Color::Transparent);
 
	sf::RectangleShape stairsHome3(sf::Vector2f(24.0f, 21.0f)); 
	stairsHome3.setFillColor(sf::Color::Transparent);
 
	sf::RectangleShape stairsHome6(sf::Vector2f(24.0f, 21.0f)); 
	stairsHome6.setFillColor(sf::Color::Red);
 
	// DOOR // 
 
	sf::Texture door1Texture; 
	sf::Sprite door1; 
 
	if (!door1Texture.loadFromFile("img/bg/door.png")) 
		std::cout << "Error could not load about bg" << std::endl; 
	door1.setTexture(door1Texture); 
	door1.setScale(4.f, 4.f); 
 
	sf::Texture door2Texture; 
	sf::Sprite door2; 
 
	if (!door2Texture.loadFromFile("img/bg/door.png")) 
		std::cout << "Error could not load about bg" << std::endl; 
	door2.setTexture(door2Texture); 
	door2.setScale(4.f, 4.f); 
 
 
	sf::Texture door1afterTexture; 
	sf::Sprite door1after; 
 
	if (!door1afterTexture.loadFromFile("img/bg/door1after.png")) 
		std::cout << "Error could not load about bg" << std::endl; 
	door1after.setTexture(door1afterTexture); 
	door1after.setScale(2.f, 2.f); 
 
	sf::Texture door2afterTexture; 
	sf::Sprite door2after; 
 
	if (!door2afterTexture.loadFromFile("img/bg/door2after.png")) 
		std::cout << "Error could not load about bg" << std::endl; 
	door2after.setTexture(door2afterTexture); 
	door2after.setScale(2.f, 2.f); 
 
	sf::Texture wallhouse5afterTexture; 
	sf::Sprite wallhouse5; 
 
	if (!wallhouse5afterTexture.loadFromFile("img/bg/wallhouse5.png")) 
		std::cout << "Error could not load about bg" << std::endl; 
	wallhouse5.setTexture(wallhouse5afterTexture); 
	wallhouse5.setScale(2.f, 2.f); 
 
	// TEXT_STATUS // 
 
	sf::Text textStatus; 
 
	textStatus.setFont(font); 
	textStatus.setCharacterSize(34); 
	textStatus.setFillColor(Color::Black); 
 
	sf::Text textPlayerName; 
 
	textPlayerName.setFont(font); 
	textPlayerName.setCharacterSize(34); 
	textPlayerName.setFillColor(Color::Black); 
 
 
	const float gridSize = 64.f; 
 
	 
	// create player // 
 
	sf::Texture pTexture; 
	sf::Sprite player; 
	sf::Texture petTexture; 
	sf::Sprite pet; 
	sf::Clock clock; 
 
	//Collision 
	FloatRect nextPos; 
 
 
	int ExitButtonCheck = 0; 
	int collision_check = 0; 
	int Dialog_check = 0; 

	int TimePlus = 0;
	int secondSound = 0;
	int Timeshort = 0;

	int gamecheck = 0;
 
	Text score_show("", font); 
	score_show.setCharacterSize(50); 
	score_show.setFillColor(Color::Black); 
 
	int secondMOVIE = 0;

	sf::Music musicMENU;
	if (!musicMENU.openFromFile("sounds/MENUsound.ogg"))
		return -1; 

	sf::Music musicPLAY;
	if (!musicPLAY.openFromFile("sounds/PLAYsound.ogg"))
		return -1;

	sf::Music musicGO;
	if (!musicGO.openFromFile("sounds/GOsound.ogg"))
		return -1; 

	sf::Music musicWIN;
	if (!musicWIN.openFromFile("sounds/WINsound.ogg"))
		return -1;

	sf::SoundBuffer  popSound;
	if (!popSound.loadFromFile("sounds/popSOUND.wav"))
		return -1;

	sf::SoundBuffer  doorSound;
	if (!doorSound.loadFromFile("sounds/doorSOUND.wav"))
		return -1;

	sf::SoundBuffer selectSound;
	if (!selectSound.loadFromFile("sounds/selectSOUND.wav"))
		return -1;

	sf::SoundBuffer  clickSound;
	if (!clickSound.loadFromFile("sounds/clickSOUND.wav"))
		return -1;

	sf::SoundBuffer  hurrySound;
	if (!hurrySound.loadFromFile("sounds/hurrySOUND.wav"))
		return -1;

	sf::SoundBuffer  lockSound;
	if (!lockSound.loadFromFile("sounds/lockSOUND.wav"))
		return -1;

	sf::SoundBuffer  typingSound;
	if (!typingSound.loadFromFile("sounds/typingSOUND.wav"))
		return -1;

	sf::SoundBuffer  barkingSound;
	if (!barkingSound.loadFromFile("sounds/barkingSOUND.wav"))
		return -1;

	sf::SoundBuffer  meowSound;
	if (!meowSound.loadFromFile("sounds/meowSOUND.wav"))
		return -1;

	sf::SoundBuffer  angrySound;
	if (!angrySound.loadFromFile("sounds/angrySOUND.wav"))
		return -1;

	sf::Sound soundEffect;

	musicMENU.play();
	musicMENU.setLoop(true);
 
	vector<pair<int, string>> scoreboard;
	int score = 50;
	string name;

	ofstream myFile;
	ifstream loadFile;
	Text scoreNAME, scoreSCORE; //ประกาศ Text

	scoreSHOW = 0;
	

	Image icon;
	icon.loadFromFile("img/icon.png");
	window.setIcon(225, 225, icon.getPixelsPtr());

	int pauseCheck = 0;

	Clock clockShort;
	Time timerShort;

	goto MENU; 
 
MENU: 
	ExitButtonCheck = 0;
	Dialog_check = 0;
	pauseCheck = 0;
	Textbox_dialog.setPosition(10000.f, 10000.f);
	textStatus.setPosition(-10000.f, -10000.f);
	map.setPosition(-10000.f, -10000.f);
	
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
				if (StartButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) ||
					AboutButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) ||
					ScoreButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
					soundEffect.setBuffer(selectSound);
					soundEffect.play();
				}

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
 
	yourname.clear();
	playerName.setString(yourname);
	yourPetname.clear();
	playerPetName.setString(yourPetname);
	character1.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
	character2.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
	character3.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
	character4.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
	characterPet1.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
	characterPet2.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
	character1.setPosition({ 115.f, 61.f });
	character2.setPosition({ 363.f, 61.f });
	character3.setPosition({ 115.f, 313.f });
	character4.setPosition({ 364.f, 313.f });
	characterPet1.setPosition({ 720.f, 288.f });
	characterPet2.setPosition({ 967.f, 288.f });
	player_check = 0;
	yourPetname.clear();
	playerPetName.setString(yourPetname);
	player_Petcheck = 0;
	player_choose = 0;
	player_choose_pet = 0;
	Next.setPosition({ 100000.f, 10000.f });

	while (window.isOpen()) { 
			sf::Event ev; 
			while (window.pollEvent(ev)) { 
 
				if (player_namecheck != 0) 
				{ 
					if (ev.type == sf::Event::TextEntered) { 
						if ((ev.text.unicode == '\b') && yourname.getSize() > 0) {
							soundEffect.setBuffer(typingSound);
							soundEffect.play();
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
								soundEffect.setBuffer(typingSound);
								soundEffect.play();
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
						if ((ev.text.unicode == '\b') && yourPetname.getSize() > 0) {
							soundEffect.setBuffer(typingSound);
							soundEffect.play();
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
							soundEffect.setBuffer(typingSound);
							soundEffect.play();
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
						playerPetName.setCharacterSize(60); 
						playerPetName.setPosition(920.0f, 560.0f);  
 
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
							soundEffect.setBuffer(selectSound);
							soundEffect.play();
							goto HOWTO; 
							soundEffect.stop();
						} 
 
						break; 
					} 
 
					case sf::Keyboard::Escape: { 
						soundEffect.setBuffer(selectSound);
						soundEffect.play();
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
					character1.setTextureRect(sf::IntRect(42 * 1, 42 * 0, 42, 42));
					character2.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
					character3.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
					character4.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
					player_choose = 1;
				}
				if (character2.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					character1.setPosition({ 115.f, 61.f });
					character2.setPosition({ 363.f, 41.f });
					character3.setPosition({ 115.f, 313.f });
					character4.setPosition({ 364.f, 313.f });
					character2.setTextureRect(sf::IntRect(42 * 1, 42 * 0, 42, 42));
					character1.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
					character3.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
					character4.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
					player_choose = 2;
				}
				if (character3.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					character1.setPosition({ 115.f, 61.f });
					character2.setPosition({ 363.f, 61.f });
					character3.setPosition({ 115.f, 293.f });
					character4.setPosition({ 364.f, 313.f });
					character3.setTextureRect(sf::IntRect(42 * 1, 42 * 0, 42, 42));
					character2.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
					character1.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
					character4.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
					player_choose = 3;
				}
				if (character4.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					character1.setPosition({ 115.f, 61.f });
					character2.setPosition({ 363.f, 61.f });
					character3.setPosition({ 115.f, 313.f });
					character4.setPosition({ 364.f, 293.f });
					character4.setTextureRect(sf::IntRect(42 * 1, 42 * 0, 42, 42));
					character2.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
					character3.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
					character1.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
					player_choose = 4;
				}

				if (characterPet1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					characterPet1.setPosition({ 720.f, 268.f });
					characterPet2.setPosition({ 967.f, 288.f });
					characterPet1.setTextureRect(sf::IntRect(42 * 1, 42 * 0, 42, 42));
					characterPet2.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
					player_choose_pet = 1;
				}
				if (characterPet2.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					characterPet1.setPosition({ 720.f, 288.f });
					characterPet2.setPosition({ 967.f, 268.f });
					characterPet2.setTextureRect(sf::IntRect(42 * 1, 42 * 0, 42, 42));
					characterPet1.setTextureRect(sf::IntRect(42 * 0, 42 * 0, 42, 42));
					player_choose_pet = 2;
				}
				if (Next.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					soundEffect.setBuffer(clickSound);
					soundEffect.play();
					goto HOWTO;
					soundEffect.stop();

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

				if (character1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) ||
					character2.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) ||
					character3.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) ||
					character4.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) ||
					characterPet1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) ||
					characterPet2.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) ||
					textboxYourname.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) ||
					textboxYourPetname.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
					soundEffect.setBuffer(clickSound);
					soundEffect.play();
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
 
HOWTO: 
		
	while (window.isOpen()) {
			sf::Event ev;
			while (window.pollEvent(ev)) {

				if (ev.type == sf::Event::KeyPressed) {
					switch (ev.key.code) {
					case sf::Keyboard::Space: {
						soundEffect.setBuffer(selectSound);
						soundEffect.play();
						musicMENU.stop();
						goto SHORT_SCRENE;
						break;
					}
					default:
						break;
					}
				}
			}

			//Update bg 
			howtoplay.setTextureRect(sf::IntRect(1280 * frameHW, 720 * 0, 1280, 720));


			if (frameHWCounter == 50) {
				frameHW = (frameHW + 1) % 3;
				frameHWCounter = 0;
			}
			frameHWCounter++;

			window.clear();
			window.draw(howtoplay);
			window.display();
		}
 
SHORT_SCRENE: 

	
		secondMOVIE = 0;
		movie.fit(0, 0, 1280, 720); 
		movie.play(); 
		clockShort.restart();

		while (window.isOpen()) { 
			sf::Event ev; 
			while (window.pollEvent(ev)) { 
 
				if (ev.type == sf::Event::KeyPressed) { 
					switch (ev.key.code) { 
					case sf::Keyboard::Space: { 
						goto PLAY;
						if (Timeshort >= 10) {
							
						}
						break; 
					} 
					default: 
						break; 
					} 
				} 
			} 

			clockShort.getElapsedTime();
			timerShort = clockShort.getElapsedTime();
			Timeshort = timerShort.asSeconds();

			secondMOVIE++;

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
						soundEffect.setBuffer(clickSound);
						soundEffect.play();
						goto MENU; 
					} 
				} 
			} 
 
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
			{ 
				if (ExitSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
				{ 
					soundEffect.setBuffer(clickSound);
					soundEffect.play();
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
		name = yourname;
		score = (m * 1200) + (s * 20);
		scoreSHOW = (TimePlus * 20) + (12000 - score);
		scoreboard.clear();
		if (gamecheck == 1) {
			myFile.open("score/score.txt", ios::out | ios::app);
			myFile << "\n" << name << " " << scoreSHOW;
			myFile.close();
			gamecheck = 0;
		}
		loadFile.open("score/score.txt");

		while (!loadFile.eof()) {
			loadFile >> tempName >> tempScore;
			cout << ">> \"" << tempName << "\" " << tempScore << endl;
			scoreboard.push_back({ tempScore,tempName });
		}
		sort(scoreboard.begin(), scoreboard.end(), greater<pair<int, string>>());
		loadFile.close();

		ExitSprite.setPosition(0, 0);
		while (window.isOpen()) {
			Event aevent;
			while (window.pollEvent(aevent)) {
				if (aevent.type == Event::Closed) {
					window.close();
				}
				if (aevent.type == Event::KeyPressed) {
					if (aevent.key.code == Keyboard::Escape) {
						soundEffect.setBuffer(clickSound);
						soundEffect.play();
						goto MENU;
					}
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (ExitSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					soundEffect.setBuffer(clickSound);
					soundEffect.play();
					goto MENU;
				}

			}

			//Update score bg 
			scoreBG.setTextureRect(sf::IntRect(1280 * frameScore, 720 * 0, 1280, 720));


			if (frameScoreCounter == 20) {
				frameScore = (frameScore + 1) % 8;
				frameScoreCounter = 0;
			}
			frameScoreCounter++;

			int cnt = 0;


			
			
			window.clear();
			window.draw(scoreBG);

			for (vector<pair<int, string>>::iterator i = scoreboard.begin(); i != scoreboard.end(); ++i) {
				++cnt;
				if (cnt > 5) break;

				scoreSCORE.setString(to_string(i->first));
				scoreSCORE.setFont(font);
				scoreSCORE.setFillColor(sf::Color::White);
				scoreNAME.setFillColor(sf::Color::White);
				scoreSCORE.setCharacterSize(40); 
				scoreSCORE.setPosition(1010, 320 + (60 * cnt)); 
				scoreNAME.setString(i->second); 
				scoreNAME.setFont(font); 
				scoreNAME.setCharacterSize(40); 
				scoreNAME.setPosition(645, 320 + (60 * cnt));
				window.draw(scoreSCORE); 
				window.draw(scoreNAME); 
				
			}
			window.draw(ExitSprite);
			window.display();
		}
		
PLAY: 
		
	    Time timer; 
		stringstream ss; 
		stringstream TimeSS; 

		sftools::Chronometer clockPLAY;
		//float t = clockPLAY.getElapsedTime().asSeconds();
		clockPLAY.isRunning();

		int house_check = 0; 
		int textCheckDialogGrandma = 0; 
		int textCheckDialogAunt = 0; 
		int textCheckDialogBoy = 0; 
		int textCheckDialogGirl = 0; 
		int textCheckDialogMale = 0; 

		TimePlus = 0;

		
		musicPLAY.play();
		musicPLAY.setLoop(true);
 
		// collision item // 
 
		sf::RectangleShape FishCheck1(sf::Vector2f(27.0f, 12.0f));
		FishCheck1.setPosition(2461.f, 1342.f); 
		FishCheck1.setFillColor(sf::Color::Blue); 
 
		sf::RectangleShape FishCheck2(sf::Vector2f(27.0f, 12.0f));
		FishCheck2.setPosition(2695.f, 1352.f); 
		FishCheck2.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape FishCheck3(sf::Vector2f(27.0f, 12.0f));
		FishCheck3.setPosition(2461.f, 429.f); 
		FishCheck3.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape FishCheck4(sf::Vector2f(27.0f, 12.0f));
		FishCheck4.setPosition(3023.f, 457.f); 
		FishCheck4.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape FishCheck5(sf::Vector2f(27.0f, 12.0f));
		FishCheck5.setPosition(3931.f, 457.f); 
		FishCheck5.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape FishCheck6(sf::Vector2f(27.0f, 12.0f));
		FishCheck6.setPosition(1061.f, 2886.f); 
		FishCheck6.setFillColor(sf::Color::Transparent);
 
		sf::RectangleShape FishCheck7(sf::Vector2f(27.0f, 12.0f));
		FishCheck7.setPosition(798.f, 2754.f); 
		FishCheck7.setFillColor(sf::Color::Transparent);
 
		sf::RectangleShape GlassCheck2(sf::Vector2f(81.0f, 77.0f));
		GlassCheck2.setPosition(1381.f, 2044.f); 
		GlassCheck2.setFillColor(sf::Color::Transparent);
 
		sf::RectangleShape GlassCheck3(sf::Vector2f(27.0f, 22.0f));
		GlassCheck3.setPosition(1395.f, 1843.f); 
		GlassCheck3.setFillColor(sf::Color::Transparent);
 
		sf::RectangleShape GlassCheck4(sf::Vector2f(27.0f, 22.0f));
		GlassCheck4.setPosition(1239.f, 1843.f); 
		GlassCheck4.setFillColor(sf::Color::Transparent);
		 
		sf::RectangleShape CakeCheck(sf::Vector2f(27.0f, 32.0f));
		CakeCheck.setPosition(2484.f, 807.f);
		CakeCheck.setFillColor(sf::Color::Transparent);
 
		sf::RectangleShape CakeCheck3(sf::Vector2f(27.0f, 32.0f));
		CakeCheck3.setPosition(2322.f, 683.f); 
		CakeCheck3.setFillColor(sf::Color::Transparent);
 
		sf::RectangleShape CakeCheck4(sf::Vector2f(27.0f, 32.0f));
		CakeCheck4.setPosition(2546.f, 948.f);
		CakeCheck4.setFillColor(sf::Color::Transparent);
 
		sf::RectangleShape VaseCheck(sf::Vector2f(27.0f, 12.0f));
		VaseCheck.setPosition(4532.f, 1234.f);
		VaseCheck.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape VaseCheck2(sf::Vector2f(27.0f, 12.0f));
		VaseCheck2.setPosition(4265.f, 1119.f);
		VaseCheck2.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape VaseCheck3(sf::Vector2f(27.0f, 12.0f));
		VaseCheck3.setPosition(3965.f, 1151.f);
		VaseCheck3.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape VaseCheck4(sf::Vector2f(27.0f, 12.0f));
		VaseCheck4.setPosition(4089.f, 1151.f);
		VaseCheck4.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape BookCheck2(sf::Vector2f(27.0f, 12.0f));
		BookCheck2.setPosition(3437.f, 558.f); 
		BookCheck2.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape BookCheck3(sf::Vector2f(27.0f, 12.0f));
		BookCheck3.setPosition(3102.f, 1189.f); 
		BookCheck3.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape BookCheck5(sf::Vector2f(27.0f, 12.0f));
		BookCheck5.setPosition(1394.f, 3338.f); 
		BookCheck5.setFillColor(sf::Color::Transparent);
 
		sf::RectangleShape BookCheck4(sf::Vector2f(27.0f, 12.0f));
		BookCheck4.setPosition(1146.f, 1798.f); 
		BookCheck4.setFillColor(sf::Color::Transparent);
 
		sf::RectangleShape BookCheck6(sf::Vector2f(27.0f, 12.0f));
		BookCheck6.setPosition(3633.f, 1339.f); 
		BookCheck6.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape ClockCheck(sf::Vector2f(27.0f, 12.0f));
		ClockCheck.setPosition(1029.f, 2179.f); 
		ClockCheck.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape ClockCheck3(sf::Vector2f(27.0f, 12.0f));
		ClockCheck3.setPosition(3712.f, 739.f); 
		ClockCheck3.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape ClockCheck4(sf::Vector2f(27.0f, 12.0f));
		ClockCheck4.setPosition(4520.f, 1599.f);
		ClockCheck4.setFillColor(sf::Color::Transparent);
 
		sf::RectangleShape PetCheck(sf::Vector2f(27.0f, 12.0f));
		PetCheck.setPosition(3310.f, 1658.f);
		PetCheck.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape PetCheck2(sf::Vector2f(27.0f, 12.0f));
		PetCheck2.setPosition(3757.f, 1658.f); 
		PetCheck2.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape KeyCheck(sf::Vector2f(27.0f, 12.0f));
		KeyCheck.setPosition(2890.f, 1658.f); 
		KeyCheck.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape KeyCheck2(sf::Vector2f(27.0f, 12.0f));
		KeyCheck2.setPosition(3051.f, 1607.f);
		KeyCheck2.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape KeyCheck3(sf::Vector2f(27.0f, 12.0f));
		KeyCheck3.setPosition(3167.f, 1606.f);
		KeyCheck3.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape KeyCheck4(sf::Vector2f(27.0f, 12.0f));
		KeyCheck4.setPosition(3119.f, 1841.f); 
		KeyCheck4.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape KeyCheck5(sf::Vector2f(27.0f, 12.0f));
		KeyCheck5.setPosition(3224.f, 1918.f);
		KeyCheck5.setFillColor(sf::Color::Blue);
 
		sf::RectangleShape KeyCheck6(sf::Vector2f(27.0f, 12.0f));
		KeyCheck6.setPosition(3396.f, 1708.f);
		KeyCheck6.setFillColor(sf::Color::Blue);

		sf::RectangleShape otherCheck(sf::Vector2f(27.0f, 12.0f));
		otherCheck.setPosition(4774.f, 2049.f);
		otherCheck.setFillColor(sf::Color::Blue);
 
 
		// walls zone // 
 
		std::vector<RectangleShape> walls; 
 
		RectangleShape wall; 
		wall.setFillColor(Color::Transparent); 
		wall.setSize(Vector2f(gridSize, gridSize)); 
 
		// cat check // 
 
		std::vector<RectangleShape> catMC; 
 
		RectangleShape catMCcheck; 
		catMCcheck.setFillColor(Color::Transparent); 
		catMCcheck.setSize(Vector2f(gridSize, gridSize)); 
 
		// door check // 
 
		std::vector<RectangleShape> door1Wall; 
 
		RectangleShape door1WallCheck; 
		door1WallCheck.setFillColor(Color::Transparent); 
		door1WallCheck.setSize(Vector2f(gridSize, gridSize)); 
 
		std::vector<RectangleShape> door2Wall; 
 
		RectangleShape door2WallCheck; 
		door2WallCheck.setFillColor(Color::Transparent); 
		door2WallCheck.setSize(Vector2f(gridSize, gridSize)); 
 
		if (house_check == 0) { 
 
			wall.setPosition(gridSize * 9, gridSize * 40);  
			walls.push_back(wall); wall.setPosition(gridSize * 9, gridSize * 41); walls.push_back(wall); wall.setPosition(gridSize * 9, gridSize * 42); walls.push_back(wall); wall.setPosition(gridSize * 9, gridSize * 43); walls.push_back(wall); wall.setPosition(gridSize * 9, gridSize * 44); walls.push_back(wall); wall.setPosition(gridSize * 9, gridSize * 45); walls.push_back(wall); wall.setPosition(gridSize * 9, gridSize * 46); walls.push_back(wall); 
			wall.setPosition(gridSize * 9, gridSize * 47); 
			walls.push_back(wall); 
			wall.setPosition(gridSize * 57, gridSize * 34); 
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
 
		catMCcheck.setPosition(gridSize * 18, gridSize * 33); 
		catMC.push_back(catMCcheck); 
 
		Text time_show("", font); 
		Text playername_show("", font); 
		 
 
		time_show.setCharacterSize(50); 
		time_show.setFillColor(Color::Black); 
		time_show.setOutlineColor(Color::White); 
		time_show.setOutlineThickness(3); 
		time_show.setLetterSpacing(2); 
 
		Text TimePlus_show; 
		TimePlus_show.setFont(font); 
		TimePlus_show.setCharacterSize(34); 
		TimePlus_show.setFillColor(Color::Black); 
 
		 
		 
 
 
 
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
 
		if (player_choose_pet == 1) { 
 
			if (!petTexture.loadFromFile("img/animal/dog.png")) 
				std::cout << "Error could not load player image" << std::endl; 
		} 
		if (player_choose_pet == 2) { 
 
			if (!petTexture.loadFromFile("img/animal/cat.png")) 
				std::cout << "Error could not load player image" << std::endl; 
		} 
		 
		 
 
		player.setTexture(pTexture); 
		player.setScale(3.f, 3.f); 
 
		pet.setTexture(petTexture); 
		pet.setScale(3.f, 3.f); 


 
		int cat_check = 0; 
		int fish_check = 0; 
 
		int glass_check = 0; 
		int cake_check = 0; 
		int vase_check = 0; 
		int book_check = 0; 
		int clock_check = 0; 
 
		int keyleft_check = 0; 
		int keyright_check = 0; 
 
		int glass_aunt = 0; 
 
 
		int home3check = 0; 
		int home5check = 0; 
		int home6check = 0; 
 
		int roomleft = 0; 
		int roomight = 0; 
 
		int randXFish[7] = { 2462.f,3027.f,2753.f,3943.f, 2465.f, 1052.f,783.f };  
		int randYFish[7] = { 400.f,435.f,1323.f,433.f, 1343.f, 2838.f,2722.f };  
 
		int randXPet[2] = { 3767.f,3256.f};  
		int randYPet[2] = { 1609.f,1609.f};  
 
		int randXGlass[3] = { 1188.f,1376.f,1346.f}; 
		int randYGlass[3] = { 1759.f,1989.f,1759.f }; 
 
		int randXCake[3] = { 2495.f,2562.f,2298.f }; 
		int randYCake[3] = { 781.f,915.f,663.f };  
 
		int randXVase[4] = { 4546.f,4291.f,3967.f,4091.f };  
		int randYVase[4] = { 1299.f,1101.f,1167.f ,1165.f };  
 
		int randXBook[5] = { 3347.f,3107.f,3590.f, 1391.f , 1098.f }; 
		int randYBook[5] = { 516.f,1167.f,1345.f,3298.f , 1763.f }; 
 
		int randXClock[3] = { 1008.f,4558.f,3729.f };
		int randYClock[3] = { 2169.f,1582.f ,778.f };
 
		int randXKey1[3] = { 2926,3176.f,3235.f }; 
		int randYKey1[3] = { 1660.f,1596.f ,1908.f }; 
 
		int randXKey2[3] = { 3060.f,3142.f,3427.f };
		int randYKey2[3] = { 1597.f,1857.f,1706.f };
 
		int randClock[4] = { 0,1,2,3 }; 
		int randTime[4] = { 30,60,90,120 }; 
		 
		int chooseClock = 0; 
		int timeScoreSet = 0; 
 
		
 
		TimeSS.str(""); 
 
		int i = 5, a = 10, b = 1, c = 0, d = 10, e = 4, f = 0, g = 10, h = 10, j = 10, k = 10;
		while (i != 2 && i != 1 && i != 0 && i != 3 && i != 4 && i != 5 && i != 6)i = rand();
		while (a != 1 && a != 0)a = rand();
		while (b != 2 && b != 1 && b != 0)b = rand();
		while (c != 2 && c != 1 && c != 0)c = rand();
		while (d != 2 && d != 1 && d != 0 && d != 3)d = rand();
		while (e != 2 && e != 1 && e != 0 && e != 3 && e != 4)e = rand();
		while (f != 2 && f != 1 && f != 0)f = rand();
		while (g != 2 && g != 1 && g != 0)g = rand();
		while (h != 2 && h != 1 && h != 0)h = rand();
		while (j != 2 && j != 1 && j != 0 && j != 3)j = rand();
		while (k != 2 && k != 1 && k != 0 && k != 3)k = rand();
		 
		chooseClock = randClock[j]; 

		m = 0;
		s = 0;

	
 
		if (chooseClock == 0) { 
			if (!clockTexture.loadFromFile("img/tileset/clock1.png")) 
				std::cout << "Error could not load clock" << std::endl; 
		} 
		if (chooseClock == 1) { 
			if (!clockTexture.loadFromFile("img/tileset/clock2.png")) 
				std::cout << "Error could not load clock" << std::endl; 
		} 
		if (chooseClock == 2) { 
			if (!clockTexture.loadFromFile("img/tileset/clock3.png")) 
				std::cout << "Error could not load clock" << std::endl; 
		} 
		if (chooseClock == 3) { 
			if (!clockTexture.loadFromFile("img/tileset/clock4.png")) 
				std::cout << "Error could not load clock" << std::endl; 
		} 
		clockPlus.setTexture(clockTexture); 
 

		fish.setPosition(-10000.f, -10000.f);
		cake.setPosition(-10000.f, -10000.f);
		glass.setPosition(-10000.f, -10000.f);
		vase.setPosition(-10000.f, -10000.f);
		clockPlus.setPosition(-10000.f, -10000.f);
		book.setPosition(-10000.f, -10000.f);
		house_check = 0;
		Home1.setPosition(846.f, 2971.f);
		Home2.setPosition({ 1168.f, 2083.f });
		Home3.setPosition({ 2320.f, 995.f });
		Home4.setPosition({ 3216.f, 865.f });
		Home5.setPosition({ 3280.f, 2011.f });
		Home6.setPosition({ 4302.f, 1563.f });
		myhouse1.setPosition(-10000.f, -10000.f);
		myhouse.setPosition(-10000.f, -10000.f);
		myhouse2.setPosition(-10000.f, -10000.f);
		myhouse3.setPosition(-10000.f, -10000.f);
		myhouse4.setPosition(-10000.f, -10000.f);
		myhouse5.setPosition(-10000.f, -10000.f);
		stairsHome3.setPosition(-10000.f, -10000.f);
		stairsHome11.setPosition(-10000.f, -10000.f);
		stairsHome12.setPosition(-10000.f, -10000.f);
		stairsHome2.setPosition(-10000.f, -10000.f);
		pet.setPosition(-10000.f, -10000.f);
		wallhouse5.setPosition(-10000.f, -10000.f);
		Text1.setPosition({ 3046.f , 1015.f });
		Text2.setPosition({ 2154.f, 2163.f });
		book.setPosition(-10000.f, -10000.f);
		myhouse.setPosition(-10000.f, -10000.f);
		door1.setPosition(-10000.f, -10000.f);
		door2.setPosition(-10000.f, -10000.f);
		door1after.setPosition(-10000.f, -10000.f);
		door2after.setPosition(-10000.f, -10000.f);
		key1.setPosition(-10000.f, -10000.f);
		key2.setPosition(-10000.f, -10000.f);
		Grandma.setPosition(3424.f, 878.f);
		Dog_mc.setPosition(3443.f, 939.f);
		cat_mc.setPosition(1122.f, 2088.f);
		Aunt.setPosition(2163.f, 1224.f);
		Boy.setPosition(3608.f, 2175.f);
		male.setPosition(2037.f, 2576.f);
		BlackSprite.setPosition(-100000, -100000);
		PauseButton.setPosition(-100000, -100000);
		PlayButton.setPosition(-100000, -100000);
		QuitButton.setPosition(-100000, -100000);
		MenuButton.setPosition(-100000, -100000);


		// player.setPosition(1050.f, 3000.f);
		player.setPosition(2163.f, 1224.f);


		//Start the game loop 
		while (window.isOpen()) { 
 
			dt = dt_clock.restart().asSeconds(); 
			clock.restart(); 
			
			sf::Event aevent; 
			while (window.pollEvent(aevent)) { 
 
				if (aevent.type == Event::KeyPressed) { 
					if (aevent.key.code == Keyboard::Escape) { 
						if (ExitButtonCheck == 0) { 
							soundEffect.setBuffer(clickSound);
							soundEffect.play();
							ExitButtonCheck = 1; 
							BlackSprite.setPosition(0, 0); 
							pauseCheck = 1;
						} 
						else if (ExitButtonCheck == 1) { 
							ExitButtonCheck = 0; 
							BlackSprite.setPosition(-100000, -100000); 
							PauseButton.setPosition(-100000, -100000); 
							PlayButton.setPosition(-100000, -100000); 
							QuitButton.setPosition(-100000, -100000); 
							MenuButton.setPosition(-100000, -100000); 
							pauseCheck = 0;
						} 
					} 
 
					else if (aevent.key.code == Keyboard::Space) { 
 
						if (player.getGlobalBounds().intersects(stairsHome11.getGlobalBounds()) || player.getGlobalBounds().intersects(stairsHome2.getGlobalBounds())  
							|| player.getGlobalBounds().intersects(stairsHome3.getGlobalBounds()) || player.getGlobalBounds().intersects(stairsHome6.getGlobalBounds())) { 
							if (Dialog_check == 0) { 
								soundEffect.setBuffer(lockSound);
								soundEffect.play();
								Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
								textStatus.setString("you can't go upstairs."); 
								textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
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
								soundEffect.setBuffer(lockSound);
								soundEffect.play();
								Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
								textStatus.setString("you can't go downstairs."); 
								textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
								Dialog_check = 1; 
							} 
							else if (Dialog_check == 1) { 
								Textbox_dialog.setPosition(10000.f, 10000.f); 
								textStatus.setPosition(-10000.f, -10000.f); 
								Dialog_check = 0; 
	
							} 
						} 
						if (player.getGlobalBounds().intersects(door1.getGlobalBounds())) { 
							if (keyleft_check == 0) { 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(lockSound);
									soundEffect.play();
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
									textStatus.setString("The room is locked."); 
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
									Dialog_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
		
									 
								} 
							} 
							else { 
								soundEffect.setBuffer(doorSound);
								soundEffect.play();
								door1.setPosition(10000.f, 100000.f); 
								door1after.setPosition(3349.f, 1909.f); 
								wallhouse5.setPosition(3301.f, 1787.f); 
								door1Wall.clear(); 
							} 
						} 
						if (player.getGlobalBounds().intersects(door2.getGlobalBounds())) { 
							if (keyright_check == 0) { 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(lockSound);
									soundEffect.play();
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
									textStatus.setString("The room is locked."); 
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
									Dialog_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
		
									 
								} 
							} 
							else { 
								soundEffect.setBuffer(doorSound);
								soundEffect.play();
								door2.setPosition(10000.f, 100000.f); 
								door2after.setPosition(3674.f, 1909.f); 
								wallhouse5.setPosition(3301.f, 1787.f); 
								door2Wall.clear(); 
							} 
						} 
						if (player.getGlobalBounds().intersects(Home1.getGlobalBounds())) { 
							if (house_check == 0) { 
								soundEffect.setBuffer(doorSound);
								soundEffect.play();
								stairsHome12.setPosition({ 1001.f, 3266.f }); 
								stairsHome11.setPosition({ 1455.f, 2768.f }); 
								myhouse.setPosition(-14.f, 2191.f); 
								player.setPosition(1553.f, 2883.f); 
								row = 1; 
								catMC.clear(); 
								walls.clear(); 
								Home1.setPosition(1553.f, 2883.f); 
								male.setPosition(-10000.f, -10000.f); 
								if(fish_check == 0)fish.setPosition(Vector2f(randXFish[i], randYFish[i])); 
								if (book_check == 0)book.setPosition(Vector2f(randXBook[e], randYBook[e])); 
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
								soundEffect.setBuffer(doorSound);
								soundEffect.play();
								house_check = 0; 
								Home1.setPosition(846.f, 2971.f); 
								myhouse.setPosition(-10000.f, -10000.f); 
								fish.setPosition(-10000.f, -10000.f); 
								book.setPosition(-10000.f, -10000.f); 
								player.setPosition(805.f, 2995.f); 
								male.setPosition(2037.f, 2576.f); 
								stairsHome12.setPosition(-10000.f, -10000.f); 
								stairsHome11.setPosition(-10000.f, -10000.f); 
 
								row = 0; 
 
								if (cat_check == 0) { 
									catMCcheck.setPosition(gridSize * 18, gridSize * 33); 
									catMC.push_back(catMCcheck); 
								} 
								 
								walls.clear(); 
								wall.setPosition(gridSize * 9, gridSize * 40); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 57, gridSize * 34); 
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
								soundEffect.setBuffer(doorSound);
								soundEffect.play();
								myhouse5.setPosition({ 130.f, 1290.f }); 
								player.setPosition(1295.f, 2189.f); 
								row = 3; 
								walls.clear(); 
								catMC.clear(); 
								if (glass_check == 0)glass.setPosition(Vector2f(randXGlass[b], randYGlass[b])); 
								if (book_check == 0)book.setPosition(Vector2f(randXBook[e], randYBook[e])); 
								if (clock_check == 0)clockPlus.setPosition(Vector2f(randXClock[f], randYClock[f])); 
								Home2.setPosition(1295.f, 2189.f); 
								stairsHome2.setPosition(1025.f, 1885.f); 
								house_check = 1; 
 
								wall.setPosition(gridSize * 14, gridSize * 31); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 15, gridSize * 29); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 15, gridSize * 32); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 16, gridSize * 27); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 14, gridSize * 33); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 15, gridSize * 34); 
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
								wall.setPosition(gridSize * 23, gridSize * 29); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 23, gridSize * 30); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 23, gridSize * 32); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 23, gridSize * 34); 
								walls.push_back(wall); 
 
							} 
							else { 
								soundEffect.setBuffer(doorSound);
								soundEffect.play();
								glass.setPosition(-10000.f, -10000.f); 
								book.setPosition(-10000.f, -10000.f); 
								clockPlus.setPosition(-10000.f, -10000.f); 
 
								house_check = 0; 
								Home2.setPosition({ 1168.f, 2083.f }); 
								myhouse5.setPosition(-10000.f, -10000.f); 
								player.setPosition(1132.f, 2108.f); 
								stairsHome2.setPosition(-10000.f, -10000.f); 
								row = 0; 
								if (cat_check == 0) { 
									catMCcheck.setPosition(gridSize * 18, gridSize * 33); 
									catMC.push_back(catMCcheck); 
								} 
								walls.clear(); 
								wall.setPosition(gridSize * 9, gridSize * 40); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 57, gridSize * 34); 
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
						if (home3check == 0) { 
							if (house_check == 0) { 
								soundEffect.setBuffer(doorSound);
								soundEffect.play();

								if (cake_check == 0)cake.setPosition(Vector2f(randXCake[c], randYCake[c])); 
								if (clock_check == 0)clockPlus.setPosition(Vector2f(randXClock[f], randYClock[f])); 
 
								myhouse1.setPosition({ 1247.f, 260.f }); 
								player.setPosition(2097.f, 1074.f); 
								stairsHome3.setPosition(2032.f, 882.f); 
								row = 3; 
								walls.clear(); 
								catMC.clear(); 
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
								soundEffect.setBuffer(doorSound);
								soundEffect.play();
								house_check = 0; 
								Home3.setPosition(2291.f, 1026.f); 
								myhouse1.setPosition(-10000.f, -10000.f); 
								stairsHome3.setPosition(-10000.f, -10000.f); 
								cake.setPosition(-10000.f, -10000.f); 
								clockPlus.setPosition(-10000.f, -10000.f); 
								player.setPosition(2291.f, 1030.f); 
								Aunt.setPosition(2163.f, 1224.f); 
 
								row = 0; 
								walls.clear(); 
								wall.setPosition(gridSize * 9, gridSize * 40); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 57, gridSize * 34); 
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
						else { 
						if (Dialog_check == 0) { 
							soundEffect.setBuffer(lockSound);
							soundEffect.play();
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
							textStatus.setString("you can't enter this house."); 
							textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
							Dialog_check = 1; 
						} 
						else if (Dialog_check == 1) { 
							Textbox_dialog.setPosition(10000.f, 10000.f); 
							textStatus.setPosition(-10000.f, -10000.f); 
							Dialog_check = 0; 

						} 
						} 
						} 
						else if (player.getGlobalBounds().intersects(Home4.getGlobalBounds())) { 
						if (house_check == 0) { 
							soundEffect.setBuffer(doorSound);
							soundEffect.play();
							myhouse4.setPosition({ 1700.f, 22.f }); 
							player.setPosition(3120.f, 1526.f); 
							row = 3; 
							walls.clear(); 
							Home4.setPosition(3120.f, 1526.f); 
							if (fish_check == 0)fish.setPosition(Vector2f(randXFish[i], randYFish[i])); 
							if (book_check == 0)book.setPosition(Vector2f(randXBook[e], randYBook[e])); 
							if (clock_check == 0)clockPlus.setPosition(Vector2f(randXClock[f], randYClock[f])); 
							Grandma.setPosition(-10000.f, -10000.f); 
							Dog_mc.setPosition(-10000.f, -10000.f); 
							cat_mc.setPosition(-10000.f, -10000.f); 
							Boy.setPosition(10000.f, 10000.f); 
							Girl.setPosition(10000.f, 10000.f); 
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
						soundEffect.setBuffer(doorSound);
						soundEffect.play();
							house_check = 0; 
							Home4.setPosition({ 3216.f, 865.f }); 
							myhouse4.setPosition(-10000.f, -10000.f); 
							fish.setPosition(-10000.f, -10000.f); 
							clockPlus.setPosition(-10000.f, -10000.f); 
							book.setPosition(-10000.f, -10000.f); 
							player.setPosition(3189.f,898.f); 
							Grandma.setPosition(3424.f, 878.f); 
							Dog_mc.setPosition(3443.f, 939.f); 
							Boy.setPosition(3608.f, 2175.f); 
							if (cat_check == 0) { 
								catMCcheck.setPosition(gridSize * 18, gridSize * 33); 
								catMC.push_back(catMCcheck); 
								cat_mc.setPosition(1122.f, 2088.f); 
							} 
 
							Aunt.setPosition(2163.f, 1224.f); 
							row = 0; 
							walls.clear(); 
							wall.setPosition(gridSize * 9, gridSize * 40); 
							walls.push_back(wall); 
							wall.setPosition(gridSize * 57, gridSize * 34); 
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
						if (home5check == 1) { 
							if (house_check == 0) { 
								if (player_choose_pet == 2) {
										soundEffect.setBuffer(meowSound);
										soundEffect.play();
								}
								if (player_choose_pet == 1) {
										soundEffect.setBuffer(barkingSound);
										soundEffect.play();
								}
								Boy.setPosition(-100000.f, -100000.f); 
								Girl.setPosition(10000.f, 10000.f); 
								myhouse2.setPosition({ 2207.f, 1263.f }); 
								player.setPosition(2950.f, 2245.f); 
								if(keyleft_check == 0)door1.setPosition(3321.f, 1877.f); 
								if (keyright_check == 0)door2.setPosition(3646.f, 1877.f); 
								if (clock_check == 0)clockPlus.setPosition(Vector2f(randXClock[f], randYClock[f]));
								if (keyleft_check == 1) { 
									door1after.setPosition(3349.f, 1914.f); 
									wallhouse5.setPosition(3301.f, 1792.f); 
								} 
								if (keyright_check == 1) { 
									door2after.setPosition(3674.f, 1914.f); 
									wallhouse5.setPosition(3301.f, 1787.f); 
								} 
								row = 3; 
								catMC.clear(); 
								walls.clear(); 
								Home5.setPosition(2950.f, 2260.f); 
								Grandma.setPosition(-10000.f, -10000.f); 
								Dog_mc.setPosition(-10000.f, -10000.f); 
								cat_mc.setPosition(-10000.f, -10000.f); 
								Aunt.setPosition(-10000.f, -10000.f); 
								clockPlus.setPosition(-10000.f, -10000.f);
								house_check = 1; 

								pet.setPosition(Vector2f(randXPet[a], randYPet[a])); 
 
								if (keyleft_check == 0) { 
									key1.setPosition(Vector2f(randXKey1[g], randYKey1[g])); 
									door1WallCheck.setPosition(gridSize * 53, gridSize * 29); 
									door1Wall.push_back(door1WallCheck); 
								} 
								if (keyright_check == 0) { 
									key2.setPosition(Vector2f(randXKey2[h], randYKey2[h])); 
									door2WallCheck.setPosition(gridSize * 58, gridSize * 29); 
									door2Wall.push_back(door2WallCheck); 
								} 
 
								wall.setPosition(gridSize * 51, gridSize * 26); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 54, gridSize * 26); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 51, gridSize * 28); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 54, gridSize * 28); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 51, gridSize * 29); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 54, gridSize * 29); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 52, gridSize * 24); 
								walls.push_back(wall); 
 
								wall.setPosition(gridSize * 56, gridSize * 26); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 59, gridSize * 26); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 56, gridSize * 28); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 59, gridSize * 28); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 56, gridSize * 29); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 59, gridSize * 29); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 57, gridSize * 24); 
								walls.push_back(wall); 
								 
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
								wall.setPosition(gridSize * 51, gridSize * 29); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 54, gridSize * 29); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 56, gridSize * 29); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 55, gridSize * 30); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 59, gridSize * 29); 
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
								wall.setPosition(gridSize * 50, gridSize * 30); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 50, gridSize * 30); 
								walls.push_back(wall); 
							} 
							else { 
							soundEffect.setBuffer(doorSound);
							soundEffect.play();
							
								house_check = 0; 
								Boy.setPosition(3608.f, 2175.f); 
								Home5.setPosition({ 3280.f, 2011.f }); 
								myhouse2.setPosition(-10000.f, -10000.f); 
								player.setPosition(3246.f, 2048.f); 
								Grandma.setPosition(3424.f, 878.f); 
								Dog_mc.setPosition(3443.f, 939.f); 
								Aunt.setPosition(2163.f, 1224.f); 
								door1.setPosition(-10000.f, -10000.f); 
								door2.setPosition(-10000.f, -10000.f); 
								door1after.setPosition(-10000.f, -10000.f); 
								wallhouse5.setPosition(-10000.f, -10000.f); 
								door2after.setPosition(-10000.f, -10000.f); 
								key1.setPosition(-10000.f, -10000.f); 
								key2.setPosition(-10000.f, -10000.f); 
								pet.setPosition(-10000.f, -10000.f); 
								row = 0; 
 
								door1Wall.clear(); 
								door2Wall.clear(); 
								walls.clear(); 
								wall.setPosition(gridSize * 9, gridSize * 40); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 57, gridSize * 34); 
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
						else { 
						if (Dialog_check == 0) { 
							soundEffect.setBuffer(lockSound);
							soundEffect.play();
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
							textStatus.setString("you can't enter this house."); 
							textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
							Dialog_check = 1; 
						} 
						else if (Dialog_check == 1) { 
							Textbox_dialog.setPosition(10000.f, 10000.f); 
							textStatus.setPosition(-10000.f, -10000.f); 
							Dialog_check = 0; 

						} 
						} 
						} 
						else if (player.getGlobalBounds().intersects(Home6.getGlobalBounds())) { 
						if (home6check == 1) { 
							if (house_check == 0) { 
								soundEffect.setBuffer(doorSound);
								soundEffect.play();
								if (vase_check == 0)vase.setPosition(Vector2f(randXVase[d], randYVase[d])); 
								if (clock_check == 0)clockPlus.setPosition(Vector2f(randXClock[f], randYClock[f])); 
 
 
								myhouse3.setPosition({ 3088.f, 606.f }); 
								Girl.setPosition(3896.f, 1360.f); 
								player.setPosition(4271.f, 1889.f); 
								stairsHome6.setPosition(4704.0f, 1359.0f); 
								row = 3; 
								walls.clear(); 
								Home6.setPosition(4271.f, 1889.f); 
								Grandma.setPosition(-10000.f, -10000.f); 
								Dog_mc.setPosition(-10000.f, -10000.f); 
								cat_mc.setPosition(-10000.f, -10000.f); 
								Boy.setPosition(-10000.f, -10000.f); 
								door1.setPosition(-10000.f, -10000.f); 
								door2.setPosition(-10000.f, -10000.f); 
								house_check = 1; 
								wall.setPosition(gridSize * 59, gridSize * 20); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 61, gridSize * 21); 
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
								wall.setPosition(gridSize * 67, gridSize * 15);
								walls.push_back(wall);
								wall.setPosition(gridSize * 66, gridSize * 14);
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
								wall.setPosition(gridSize * 61, gridSize * 20);
								walls.push_back(wall);
							} 
							else { 
							soundEffect.setBuffer(doorSound);
							soundEffect.play();
								house_check = 0; 
								Home6.setPosition({ 4302.f, 1563.f }); 
								myhouse3.setPosition(-10000.f, -10000.f); 
								vase.setPosition(-10000.f, -10000.f); 
								clockPlus.setPosition(-10000.f, -10000.f); 
								Girl.setPosition(-10000.f, -10000.f); 
								player.setPosition(4274.f, 1606.f); 
								Grandma.setPosition(3424.f, 878.f); 
								Dog_mc.setPosition(3443.f, 939.f); 
								Boy.setPosition(3608.f, 2175.f); 
								stairsHome6.setPosition(-10000.f, -10000.f); 
								row = 0; 
								walls.clear(); 
								wall.setPosition(gridSize * 9, gridSize * 40); 
								walls.push_back(wall); 
								wall.setPosition(gridSize * 57, gridSize * 34); 
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
						 else { 
						 soundEffect.setBuffer(lockSound);
						 soundEffect.play();
							if (Dialog_check == 0) { 
								Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
								textStatus.setString("you can't enter this house."); 
								textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
								Dialog_check = 1; 
							} 
							else if (Dialog_check == 1) { 
								Textbox_dialog.setPosition(10000.f, 10000.f); 
								textStatus.setPosition(-10000.f, -10000.f); 
								Dialog_check = 0; 
	
							} 
						} 
						} 
						else if (player.getGlobalBounds().intersects(Grandma.getGlobalBounds())) { 
						if (Dialog_check == 0) { 
							soundEffect.setBuffer(popSound);
							soundEffect.play();
							if (textCheckDialogGrandma == 0) { 
								textStatus.setString("Hello"); 
								textPlayerName.setString(yourname); 
								textPlayerName.setPosition(player.getPosition().x - 200, player.getPosition().y + 233); 
								textCheckDialogGrandma = 1; 
							} 
							else if (textCheckDialogGrandma == 1) { 
								textStatus.setString("Hope you find your pet soon."); 
								textPlayerName.setPosition(-10000.f, -10000.f); 
							} 
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
							textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
							 
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
							soundEffect.setBuffer(popSound);
							soundEffect.play();
							if (textCheckDialogAunt == 0 && glass_check == 0) { 
								textStatus.setString("How do you do?"); 
								textCheckDialogAunt = 1; 
							} 
							else if (textCheckDialogAunt == 1 && glass_check == 0) { 
								textStatus.setString("Have you seen my glasses?"); 
							} 
							else if (glass_check == 1) { 
							textStatus.setString("Ohh Thanks!"); 
							glass_aunt = 1; 
							home3check = 1; 
							} 
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
							textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
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
							soundEffect.setBuffer(barkingSound);
							soundEffect.play();
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
							textStatus.setString("Bark Bark Bark Bark Bark"); 
							textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
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
							
							if (fish_check == 0) { 
								soundEffect.setBuffer(angrySound);
								soundEffect.play();
								textStatus.setString("EEEEEEAAAAAAAAAAAAAAARRRRRRRRRRRRRREIR!"); 
							} 
							else { 
								soundEffect.setBuffer(meowSound);
								soundEffect.play();
								textStatus.setString("Meowww~"); 
							} 
							textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
							Dialog_check = 1; 
						} 
						else if (Dialog_check == 1) { 
							Textbox_dialog.setPosition(10000.f, 10000.f); 
							textStatus.setCharacterSize(34); 
							textStatus.setPosition(-10000.f, -10000.f); 
							Dialog_check = 0; 

							if (fish_check == 1) { 
								cat_mc.setPosition(-10000.f, -10000.f); 
								cat_check = 1; 
								catMC.clear(); 
							} 
								 
						} 
						} 
						else if (player.getGlobalBounds().intersects(male.getGlobalBounds())) { 
						if (Dialog_check == 0) { 
							soundEffect.setBuffer(popSound);
							soundEffect.play();
							if (textCheckDialogMale == 0 && vase_check == 0) { 
								textStatus.setCharacterSize(34);
								textStatus.setString("Have a nice day!"); 
								textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
								textCheckDialogMale = 1; 
							} 
							else if (textCheckDialogMale == 1 && vase_check == 0) { 
								textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
								textStatus.setString("My vase is gone. do you think it in the pool?"); 
							} 
							else if (vase_check == 1) { 
								textStatus.setCharacterSize(30);
								textStatus.setPosition(player.getPosition().x - 315, player.getPosition().y + 235);
								textStatus.setString("OMG! Thanks a lot. This vase very important for me.");
								home5check = 1; 
							} 
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
							Dialog_check = 1; 
						} 
						else if (Dialog_check == 1) { 
							Textbox_dialog.setPosition(10000.f, 10000.f); 
							textStatus.setPosition(-10000.f, -10000.f); 
							textStatus.setCharacterSize(34); 
							Dialog_check = 0; 

						} 
						} 
						else if (player.getGlobalBounds().intersects(Boy.getGlobalBounds())) { 
						if (Dialog_check == 0) { 
							soundEffect.setBuffer(popSound);
							soundEffect.play();
							if (textCheckDialogBoy == 0 && cake_check == 0) { 
								textStatus.setString("the sky looks beautiful."); 
								textCheckDialogBoy = 1; 
							} 
							else if (textCheckDialogBoy == 1 && cake_check == 0) { 
								textStatus.setString("today is my wife's birthday!"); 
							} 
							else if (cake_check == 1) { 
								textStatus.setString("WOW, what lovely cake. You shouldn't have!"); 
								home6check = 1; 
							} 
							textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
							Dialog_check = 1; 
						} 
						else if (Dialog_check == 1) { 
							Textbox_dialog.setPosition(10000.f, 10000.f); 
							textStatus.setPosition(-10000.f, -10000.f); 
							textStatus.setCharacterSize(34); 
							Dialog_check = 0; 

						} 
						} 
						else if (player.getGlobalBounds().intersects(Girl.getGlobalBounds())) { 
						if (Dialog_check == 0) { 
							soundEffect.setBuffer(popSound);
							soundEffect.play();
							if (textCheckDialogGirl == 0) { 
								textStatus.setString("Thanks for cake! it's so sweet."); 
								textStatus.setCharacterSize(34); 
								textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
								textCheckDialogGirl = 1; 
							} 
							else if (textCheckDialogGirl == 1) { 
								textStatus.setCharacterSize(30); 
								textStatus.setPosition(player.getPosition().x - 315, player.getPosition().y + 235); 
								textStatus.setString("your pet's missing? I think i saw her in Peter's home."); 
							} 
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
							Dialog_check = 1; 
						} 
						else if (Dialog_check == 1) { 
							Textbox_dialog.setPosition(10000.f, 10000.f); 
							textStatus.setPosition(-10000.f, -10000.f); 
							textStatus.setCharacterSize(34); 
							Dialog_check = 0; 

						} 
						} 
						else if (player.getGlobalBounds().intersects(pet.getGlobalBounds())) { 
						view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y)); 
						sf::Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2); 
						view.setCenter(position); 
						window.setView(view); 
						musicPLAY.stop();
						goto WIN; 
						} 
 
 
						else if (player.getGlobalBounds().intersects(Text1.getGlobalBounds())) { 
						if (Dialog_check == 0) { 
							soundEffect.setBuffer(popSound);
							soundEffect.play();
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
							textStatus.setString("Grandma's house"); 
							textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
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
							soundEffect.setBuffer(popSound);
							soundEffect.play();
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
							textStatus.setString("welcome to the village."); 
							textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
							Dialog_check = 1; 
						} 
						else if (Dialog_check == 1) { 
							Textbox_dialog.setPosition(10000.f, 10000.f); 
							textStatus.setPosition(-10000.f, -10000.f); 
							Dialog_check = 0; 

						} 
						} 
						
						if (glass.getGlobalBounds().intersects(GlassCheck2.getGlobalBounds())) { 
 
							if (player.getGlobalBounds().intersects(GlassCheck2.getGlobalBounds())) { 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
									textStatus.setString("You got glass."); 
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
									Dialog_check = 1; 
									glass_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
		
									glass.setPosition(-10000.f, -10000.f); 
								} 
 
							} 
						} 
						else if (glass.getGlobalBounds().intersects(GlassCheck3.getGlobalBounds())) { 
 
							if (player.getGlobalBounds().intersects(GlassCheck3.getGlobalBounds())) { 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									textStatus.setString("You got glass."); 
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
									Dialog_check = 1; 
									glass_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
		
									glass.setPosition(-10000.f, -10000.f); 
								} 
 
							} 
						} 
						else if (glass.getGlobalBounds().intersects(GlassCheck4.getGlobalBounds())) { 
							if (player.getGlobalBounds().intersects(GlassCheck4.getGlobalBounds())) { 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									textStatus.setString("You got glass."); 
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
									Dialog_check = 1; 
									glass_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
		
									glass.setPosition(-10000.f, -10000.f); 
								} 
 
							} 
						} 
 
						if (fish.getGlobalBounds().intersects(FishCheck1.getGlobalBounds())) { 
						if (player.getGlobalBounds().intersects(FishCheck1.getGlobalBounds())) { 
 
							if (Dialog_check == 0) { 
								soundEffect.setBuffer(popSound);
								soundEffect.play();
								textStatus.setString("You got fish."); 
								Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
								textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
								Dialog_check = 1; 
								fish_check = 1; 
							} 
							else if (Dialog_check == 1) { 
								Textbox_dialog.setPosition(10000.f, 10000.f); 
								textStatus.setPosition(-10000.f, -10000.f); 
								Dialog_check = 0; 
	
								fish.setPosition(-10000.f, -10000.f); 
							} 
 
						} 
						} 
						else if (fish.getGlobalBounds().intersects(FishCheck2.getGlobalBounds())) { 
							if (player.getGlobalBounds().intersects(FishCheck2.getGlobalBounds())) { 
 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									textStatus.setString("You got fish."); 
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
									Dialog_check = 1; 
									fish_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
		
									fish.setPosition(-10000.f, -10000.f); 
								} 
 
							} 
						} 
						else if (fish.getGlobalBounds().intersects(FishCheck3.getGlobalBounds())) { 
							if (player.getGlobalBounds().intersects(FishCheck3.getGlobalBounds())) { 
 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									textStatus.setString("You got fish."); 
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
									Dialog_check = 1; 
									fish_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
		
									fish.setPosition(-10000.f, -10000.f); 
								} 
 
							} 
						} 
						else if (fish.getGlobalBounds().intersects(FishCheck4.getGlobalBounds())) { 
							if (player.getGlobalBounds().intersects(FishCheck4.getGlobalBounds())) { 
 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									textStatus.setString("You got fish."); 
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
									Dialog_check = 1; 
									fish_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
		
									fish.setPosition(-10000.f, -10000.f); 
								} 
 
							} 
						} 
						else if (fish.getGlobalBounds().intersects(FishCheck5.getGlobalBounds())) { 
							if (player.getGlobalBounds().intersects(FishCheck5.getGlobalBounds())) { 
 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									textStatus.setString("You got fish."); 
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
									Dialog_check = 1; 
									fish_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
		
									fish.setPosition(-10000.f, -10000.f); 
								} 
 
							} 
						} 
						else if (fish.getGlobalBounds().intersects(FishCheck6.getGlobalBounds())) { 
							if (player.getGlobalBounds().intersects(FishCheck6.getGlobalBounds())) { 
 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									textStatus.setString("You got fish."); 
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
									Dialog_check = 1; 
									fish_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
		
									fish.setPosition(-10000.f, -10000.f); 
								} 
 
							} 
						} 
						else if (fish.getGlobalBounds().intersects(FishCheck7.getGlobalBounds())) { 
							if (player.getGlobalBounds().intersects(FishCheck7.getGlobalBounds())) { 
 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									textStatus.setString("You got fish."); 
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
									Dialog_check = 1; 
									fish_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
		
									fish.setPosition(-10000.f, -10000.f); 
								} 
 
							} 
						} 
 
						if (cake.getGlobalBounds().intersects(CakeCheck.getGlobalBounds())) { 
 
						if (player.getGlobalBounds().intersects(CakeCheck.getGlobalBounds())) { 
							if (Dialog_check == 0) { 
								soundEffect.setBuffer(popSound);
								soundEffect.play();
								textStatus.setString("You got cake."); 
								Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
								textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
								Dialog_check = 1; 
								cake_check = 1; 
							} 
							else if (Dialog_check == 1) { 
								Textbox_dialog.setPosition(10000.f, 10000.f); 
								textStatus.setPosition(-10000.f, -10000.f); 
								Dialog_check = 0; 
	
								cake.setPosition(-10000.f, -10000.f); 
							} 
 
						} 
						} 
					
						else if (cake.getGlobalBounds().intersects(CakeCheck3.getGlobalBounds())) { 
 
							if (player.getGlobalBounds().intersects(CakeCheck3.getGlobalBounds())) { 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									textStatus.setString("You got cake."); 
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
									Dialog_check = 1; 
									cake_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
		
									cake.setPosition(-10000.f, -10000.f); 
								} 
 
							} 
						} 
						else if (cake.getGlobalBounds().intersects(CakeCheck4.getGlobalBounds())) { 
 
							if (player.getGlobalBounds().intersects(CakeCheck4.getGlobalBounds())) { 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
									textStatus.setString("You got cake."); 
									Dialog_check = 1; 
									cake_check = 1;
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
		
									cake.setPosition(-10000.f, -10000.f);
								} 
 
							} 
						} 
 
						if (vase.getGlobalBounds().intersects(VaseCheck.getGlobalBounds())) { 
 
						if (player.getGlobalBounds().intersects(VaseCheck.getGlobalBounds())) { 
							if (Dialog_check == 0) { 
								soundEffect.setBuffer(popSound);
								soundEffect.play();

								Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
								textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
								textStatus.setString("You got vase."); 
								Dialog_check = 1; 
								vase_check = 1; 
							} 
							else if (Dialog_check == 1) { 
								Textbox_dialog.setPosition(10000.f, 10000.f); 
								textStatus.setPosition(-10000.f, -10000.f); 
								Dialog_check = 0; 
	
								vase.setPosition(-10000.f, -10000.f); 
							} 
 
						} 
						} 
						else if (vase.getGlobalBounds().intersects(VaseCheck2.getGlobalBounds())) { 
 
							if (player.getGlobalBounds().intersects(VaseCheck2.getGlobalBounds())) { 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									textStatus.setString("You got vase."); 
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
									Dialog_check = 1; 
									vase_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
		
									vase.setPosition(-10000.f, -10000.f); 
								} 
 
							} 
						} 
						else if (vase.getGlobalBounds().intersects(VaseCheck3.getGlobalBounds())) { 
 
							if (player.getGlobalBounds().intersects(VaseCheck3.getGlobalBounds())) { 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
									textStatus.setString("You got vase."); 
									Dialog_check = 1; 
									vase_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
		
									vase.setPosition(-10000.f, -10000.f); 
								} 
 
							} 
						} 
						else if (vase.getGlobalBounds().intersects(VaseCheck4.getGlobalBounds())) { 
 
							if (player.getGlobalBounds().intersects(VaseCheck4.getGlobalBounds())) { 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									textStatus.setString("You got vase."); 
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
									Dialog_check = 1; 
									vase_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
									vase.setPosition(-10000.f, -10000.f); 
								} 
 
							} 
						} 
 
						if (book.getGlobalBounds().intersects(BookCheck2.getGlobalBounds())) { 
 
							if (player.getGlobalBounds().intersects(BookCheck2.getGlobalBounds())) { 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									map.setPosition(player.getPosition().x - 490, player.getPosition().y - 320); 
									Dialog_check = 1; 
									pauseCheck = 1;
						 
								} 
								else if (Dialog_check == 1) { 
									Dialog_check = 0; 
									pauseCheck = 0;
									map.setPosition(-10000.f, -10000.f); 
									 
								} 
							} 
						} 
						else if (book.getGlobalBounds().intersects(BookCheck3.getGlobalBounds())) { 
 
							if (player.getGlobalBounds().intersects(BookCheck3.getGlobalBounds())) { 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									map.setPosition(player.getPosition().x - 490, player.getPosition().y - 320); 
									Dialog_check = 1; 
									pauseCheck = 1;
								} 
								else if (Dialog_check == 1) { 
									Dialog_check = 0; 
									pauseCheck = 0;
									map.setPosition(-10000.f, -10000.f); 
									 
								} 
 
							} 
						} 
						else if (book.getGlobalBounds().intersects(BookCheck4.getGlobalBounds())) { 
 
							if (player.getGlobalBounds().intersects(BookCheck4.getGlobalBounds())) { 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									map.setPosition(player.getPosition().x - 490, player.getPosition().y - 320); 
									Dialog_check = 1; 
									pauseCheck = 1;
								} 
								else if (Dialog_check == 1) { 
									Dialog_check = 0; 
									pauseCheck = 0;
									map.setPosition(-10000.f, -10000.f); 
								} 
 
							} 
						} 
						else if (book.getGlobalBounds().intersects(BookCheck5.getGlobalBounds())) { 
 
							if (player.getGlobalBounds().intersects(BookCheck5.getGlobalBounds())) { 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									map.setPosition(player.getPosition().x - 490, player.getPosition().y - 320); 
									Dialog_check = 1; 
									pauseCheck = 1;
								} 
								else if (Dialog_check == 1) { 
									Dialog_check = 0; 
									pauseCheck = 0;
									map.setPosition(-10000.f, -10000.f); 
									 
								} 
 
							} 
						} 
						else if (book.getGlobalBounds().intersects(BookCheck6.getGlobalBounds())) { 
 
							if (player.getGlobalBounds().intersects(BookCheck6.getGlobalBounds())) { 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									map.setPosition(player.getPosition().x - 490, player.getPosition().y - 320); 
									Dialog_check = 1; 
									pauseCheck = 1;
								} 
								else if (Dialog_check == 1) { 
									Dialog_check = 0; 
									pauseCheck = 0;
									map.setPosition(-10000.f, -10000.f); 
									 
								} 
 
							} 
						} 
 
						if (clockPlus.getGlobalBounds().intersects(ClockCheck.getGlobalBounds())) { 
						if (player.getGlobalBounds().intersects(ClockCheck.getGlobalBounds())) { 
							TimePlus = randTime[k];
							TimeSS << TimePlus << " seconds!"; 
							TimePlus_show.setPosition(player.getPosition().x - 210, player.getPosition().y + 233); 
							Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
							textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
							if (Dialog_check == 0) { 
								soundEffect.setBuffer(popSound);
								soundEffect.play();
								textStatus.setString("Time +"); 
 
									Dialog_check = 1; 
									clock_check = 1; 
							} 
							else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									TimePlus_show.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
									clockPlus.setPosition(-10000.f, -10000.f); 
							} 
						} 
						} 
						
						else if (clockPlus.getGlobalBounds().intersects(ClockCheck3.getGlobalBounds())) { 
							 
							if (player.getGlobalBounds().intersects(ClockCheck3.getGlobalBounds())) { 
								TimePlus = randTime[k];
								TimeSS << TimePlus << " seconds!"; 
								TimePlus_show.setPosition(player.getPosition().x - 210, player.getPosition().y + 233); 
								Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
								textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
								 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									textStatus.setString("Time +"); 
									Dialog_check = 1; 
									clock_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									TimePlus_show.setPosition(10000.f, 10000.f); 
									Dialog_check = 0; 
									
									clockPlus.setPosition(-10000.f, -10000.f); 
								} 
							} 
						} 
						else if (clockPlus.getGlobalBounds().intersects(ClockCheck4.getGlobalBounds())) { 
							 
							if (player.getGlobalBounds().intersects(ClockCheck4.getGlobalBounds())) { 
								TimePlus = randTime[k];
								TimeSS << TimePlus << " seconds!"; 
								TimePlus_show.setPosition(player.getPosition().x - 210, player.getPosition().y + 233); 
								Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
								textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									textStatus.setString("Time +"); 
									Dialog_check = 1; 
									clock_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
									
									clockPlus.setPosition(-10000.f, -10000.f); 
									TimePlus_show.setPosition(10000.f, 10000.f); 
								} 
							} 
						} 
 
						if (key1.getGlobalBounds().intersects(KeyCheck.getGlobalBounds())) { 
 
						if (player.getGlobalBounds().intersects(KeyCheck.getGlobalBounds())) { 
 
							if (Dialog_check == 0) { 
								soundEffect.setBuffer(popSound);
								soundEffect.play();
								textStatus.setString("You got key."); 
								Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
								textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
								Dialog_check = 1; 
								keyleft_check = 1; 
							} 
							else if (Dialog_check == 1) { 
								Textbox_dialog.setPosition(10000.f, 10000.f); 
								textStatus.setPosition(-10000.f, -10000.f); 
								Dialog_check = 0; 
								
								key1.setPosition(-10000.f, -10000.f); 
							} 
 
						} 
						} 
						else if (key1.getGlobalBounds().intersects(KeyCheck3.getGlobalBounds())) { 
 
							if (player.getGlobalBounds().intersects(KeyCheck3.getGlobalBounds())) { 
 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									textStatus.setString("You got key."); 
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
									Dialog_check = 1; 
									keyleft_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
									pauseCheck = 0;
									key1.setPosition(-10000.f, -10000.f); 
								} 
 
							} 
						} 
						else if (key1.getGlobalBounds().intersects(KeyCheck5.getGlobalBounds())) { 
 
							if (player.getGlobalBounds().intersects(KeyCheck5.getGlobalBounds())) { 
 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									textStatus.setString("You got key."); 
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
									Dialog_check = 1; 
									keyleft_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
									
									key1.setPosition(-10000.f, -10000.f); 
								} 
 
							} 
						} 
 
						if (key2.getGlobalBounds().intersects(KeyCheck2.getGlobalBounds())) { 
 
						if (player.getGlobalBounds().intersects(KeyCheck2.getGlobalBounds())) { 
 
							if (Dialog_check == 0) { 
								soundEffect.setBuffer(popSound);
								soundEffect.play();
								textStatus.setString("You got key."); 
								Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
								textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
								Dialog_check = 1; 
								keyright_check = 1; 
							} 
							else if (Dialog_check == 1) { 
								Textbox_dialog.setPosition(10000.f, 10000.f); 
								textStatus.setPosition(-10000.f, -10000.f); 
								Dialog_check = 0; 
	
								key2.setPosition(-10000.f, -10000.f); 
							} 
 
						} 
						} 
						else  if (key2.getGlobalBounds().intersects(KeyCheck4.getGlobalBounds())) { 
 
							if (player.getGlobalBounds().intersects(KeyCheck4.getGlobalBounds())) { 
 
								if (Dialog_check == 0) { 
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									textStatus.setString("You got key."); 
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182); 
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233); 
									Dialog_check = 1; 
									keyright_check = 1; 
								} 
								else if (Dialog_check == 1) { 
									Textbox_dialog.setPosition(10000.f, 10000.f); 
									textStatus.setPosition(-10000.f, -10000.f); 
									Dialog_check = 0; 
		
									key2.setPosition(-10000.f, -10000.f); 
								} 
 
							} 
						} 
						else  if (key2.getGlobalBounds().intersects(KeyCheck6.getGlobalBounds())) { 
 
							if (player.getGlobalBounds().intersects(KeyCheck6.getGlobalBounds())) { 
 
								if (Dialog_check == 0) {
									soundEffect.setBuffer(popSound);
									soundEffect.play();
									textStatus.setString("You got key");
									Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182);
									textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233);
									Dialog_check = 1;
									keyright_check = 1;
								}
								else if (Dialog_check == 1) {
									Textbox_dialog.setPosition(10000.f, 10000.f);
									textStatus.setPosition(-10000.f, -10000.f);
									Dialog_check = 0;
		
									key2.setPosition(-10000.f, -10000.f);
								}
 
							} 
						} 

						if (player.getGlobalBounds().intersects(otherCheck.getGlobalBounds())) {

							if (Dialog_check == 0) {
								soundEffect.setBuffer(lockSound);
								soundEffect.play();
								textStatus.setString("You can't go the outside.");
								Textbox_dialog.setPosition(player.getPosition().x - 400, player.getPosition().y + 182);
								textStatus.setPosition(player.getPosition().x - 300, player.getPosition().y + 233);
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
 
			if(glass_aunt == 1 && Dialog_check == 0)Aunt.setTextureRect(sf::IntRect(32 * frameMC, 32 * 1, 32, 32)); 

			ss.str("");
			timer = clockPLAY.getElapsedTime();

			//clockPLAY.isRunning();
			clockPLAY.resume();

			s = timer.asSeconds();
			m = s / 60;
			s = s - (m * 60);
			
			if (pauseCheck == 0)clockPLAY.isRunning();
			else clockPLAY.pause();

			if (s == 60) {
				s = 0;
				ss << " : " << s;
			}
			if (m < 10)
			{
				ss << "0" << m;
			}
			if (s < 10)
			{
				ss << " : " << "0" << s;
			}
			else if (s >= 10 && s != 60)
			{
				ss << " : " << s;
			}


			

			
 
			if (TimePlus == 0) { 
				if (m == 9 && s == 50) { 
					soundEffect.setBuffer(hurrySound);
					soundEffect.play();
					time_show.setFillColor(Color::Red); 
				} 
				if (m == 10) {
					view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
					sf::Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);
					view.setCenter(position);
					window.setView(view);
					ExitButtonCheck = 0;
					musicPLAY.stop();
					goto GAMEOVER; 
				} 
			} 
			else if (TimePlus == 30) { 
				if (m == 10 && s == 20) {
					soundEffect.setBuffer(hurrySound);
					soundEffect.play();
					time_show.setFillColor(Color::Red); 
				} 
				if (m == 10 && s == 30 ) {
					view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
					sf::Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);
					view.setCenter(position);
					window.setView(view);
					ExitButtonCheck = 0;
					musicPLAY.stop();
					goto GAMEOVER; 
				} 
			} 
			else if (TimePlus == 60) { 
				if (m == 10 && s == 50) {
					soundEffect.setBuffer(hurrySound);
					soundEffect.play();
					time_show.setFillColor(Color::Red); 
				} 
				if (m == 11) {
					view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
					sf::Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);
					view.setCenter(position);
					window.setView(view);
					ExitButtonCheck = 0;
					musicPLAY.stop();
					goto GAMEOVER; 
				} 
			} 
			else  if (TimePlus == 90) { 
				if (m == 11 && s == 20) {
					soundEffect.setBuffer(hurrySound);
					soundEffect.play();
					time_show.setFillColor(Color::Red); 
				} 
				if (m == 11 && s == 30) {
					view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
					sf::Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);
					view.setCenter(position);
					window.setView(view);
					ExitButtonCheck = 0;
					musicPLAY.stop();
					goto GAMEOVER; 
				} 
			} 
			else if (TimePlus == 120) { 
				if (m == 11 && s == 50) {
					soundEffect.setBuffer(hurrySound);
					soundEffect.play();
					time_show.setFillColor(Color::Red); 
				} 
				if (m == 12) { 
					view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
					sf::Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);
					view.setCenter(position);
					window.setView(view);
					ExitButtonCheck = 0;
					musicPLAY.stop();
					goto GAMEOVER; 
				} 
			} 
 
			time_show.setString(ss.str()); 
			TimePlus_show.setString(TimeSS.str()); 


			//Update model 

			if (ExitButtonCheck == 0) {
				player.setTextureRect(sf::IntRect(32 * frame, 32 * row, 32, 32));
				if (frameCounter == 20) {
					frame = (frame + 1) % 3;
					frameCounter = 0;
				}
				frameCounter++;
			}
 
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
			for (auto& wall : catMC) 
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
			for (auto& wall : door1Wall) 
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
			for (auto& wall : door2Wall) 
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
					musicMENU.play();
					musicPLAY.stop();
					

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
			if(glass_aunt == 0)Aunt.setTextureRect(sf::IntRect(32 * frameMC, 32 * 0, 32, 32)); 
			male.setTextureRect(sf::IntRect(32 * frameMC, 32 * 0, 32, 32)); 
			Grandma.setTextureRect(sf::IntRect(32 * frameMC, 32 * 0, 32, 32)); 
			Boy.setTextureRect(sf::IntRect(32 * frameMC, 32 * 0, 32, 32)); 
			Girl.setTextureRect(sf::IntRect(32 * frameMC, 32 * 0, 32, 32)); 
			pet.setTextureRect(sf::IntRect(32 * frameMC, 32 * 0, 32, 32)); 
 
			if (frameMCCounter == 50) { 
				frameMC = (frameMC + 1) % 3; 
				frameMCCounter = 0; 
			} 
			frameMCCounter++; 
 
			window.clear(); 
			player.move(velocity); 
			view.setCenter(position); 
			window.setView(view);  
			window.draw(Pbackground); 
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
			window.draw(door1after); 
			window.draw(door2after); 
			window.draw(FishCheck1); 
			window.draw(FishCheck2); 
			window.draw(FishCheck3); 
			window.draw(FishCheck4); 
			window.draw(FishCheck5); 
			window.draw(FishCheck6); 
			window.draw(FishCheck7); 
			window.draw(CakeCheck); 
			window.draw(CakeCheck3); 
			window.draw(CakeCheck4); 
			window.draw(GlassCheck2); 
			window.draw(GlassCheck3); 
			window.draw(GlassCheck4); 
			window.draw(VaseCheck); 
			window.draw(VaseCheck2); 
			window.draw(VaseCheck3); 
			window.draw(VaseCheck4); 
			window.draw(BookCheck2); 
			window.draw(BookCheck3); 
			window.draw(BookCheck4); 
			window.draw(BookCheck5); 
			window.draw(BookCheck6); 
			window.draw(ClockCheck); 
			window.draw(ClockCheck3); 
			window.draw(ClockCheck4); 
			window.draw(KeyCheck); 
			window.draw(KeyCheck2); 
			window.draw(KeyCheck3); 
			window.draw(KeyCheck4); 
			window.draw(KeyCheck5); 
			window.draw(KeyCheck6); 
 
 
 
			for (auto& i : catMC) 
			{ 
				window.draw(i); 
			} 
			for (auto& i : door1Wall) 
			{ 
				window.draw(i); 
			} 
			for (auto& i : door2Wall) 
			{ 
				window.draw(i); 
			} 
			for (auto& i : walls) 
			{ 
				window.draw(i); 
			} 
 
			window.draw(Grandma); 
			window.draw(Dog_mc); 
			window.draw(cat_mc); 
			window.draw(Aunt); 
			window.draw(male); 
			window.draw(Boy); 
			window.draw(Girl); 
			window.draw(pet); 
 
			window.draw(fish); 
			window.draw(cake); 
			window.draw(glass); 
			window.draw(vase); 
			window.draw(book); 
			window.draw(key1); 
			window.draw(key2); 
			window.draw(player); 
			window.draw(wallhouse5); 
			window.draw(clockPlus);
			window.draw(stairsHome11); 
			window.draw(stairsHome12); 
			window.draw(stairsHome2); 
			window.draw(stairsHome3); 
			window.draw(stairsHome6); 
			window.draw(Textbox_dialog); 
			window.draw(textStatus); 
			window.draw(TimePlus_show); 
			window.draw(textPlayerName); 
			window.draw(map); 
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
		gamecheck = 1;
		musicGO.play();
		musicGO.setLoop(true);

		while (window.isOpen()) { 
 
			Event aevent; 
			while (window.pollEvent(aevent)) { 
				if (aevent.type == Event::Closed) { 
					window.close(); 
				} 
			} 
 
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
			{ 
				if (gameoverMENU.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) ||
					gameoverSCORE.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
					soundEffect.setBuffer(selectSound);
					soundEffect.play();
				}

				if (gameoverMENU.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
				{ 
						 
					view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
					sf::Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);
					view.setCenter(position);
					window.setView(view);
					ExitButtonCheck = 0;
					musicMENU.play();
					musicGO.stop();

					goto MENU; 
				} 
				if (gameoverQUIT.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
				{ 
					window.close(); 
				} 
				if (gameoverSCORE.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
					sf::Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);
					view.setCenter(position);
					window.setView(view);
					ExitButtonCheck = 0;
					musicGO.stop();
					musicMENU.play();
					goto SCORE;
				}
			} 
 
			if (gameoverQUIT.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
			{ 
				Hover_exitGOSprite.setPosition(810.f, 505.f); 
			} 
			if (gameoverMENU.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
			{ 
				Hover_menuSprite.setPosition(286.f, 505.f); 
			} 
			if (!gameoverMENU.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
			{ 
				Hover_menuSprite.setPosition(10000.f, 10000.f); 
			} 
			if (!gameoverQUIT.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
			{ 
				Hover_exitGOSprite.setPosition(10000.f, 10000.f); 
			} 
			if (gameoverSCORE.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				Hover_scoreGOSprite.setPosition(548.f, 505.f);
			}
			if (!gameoverSCORE.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				Hover_scoreGOSprite.setPosition(10000.f, 10000.f);
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
			window.draw(gameoverSCORE);
			window.draw(Hover_menuSprite); 
			window.draw(Hover_exitGOSprite); 
			window.draw(Hover_scoreGOSprite);
			window.display(); 
 
		} 
 
 
	WIN: 
		gamecheck = 1;
		musicWIN.play();
		musicWIN.setLoop(true);
		while (window.isOpen()) { 
 
			Event aevent; 
			while (window.pollEvent(aevent)) { 
				if (aevent.type == Event::Closed) { 
					window.close(); 
				} 
			} 
 
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
			{ 
				if (winScoreButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) ||
					winMenuButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
					soundEffect.setBuffer(selectSound);
					soundEffect.play();
				}

				if (winScoreButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
				{ 
					view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
					sf::Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);
					view.setCenter(position);
					window.setView(view);
					ExitButtonCheck = 0;
					musicWIN.stop();
					musicMENU.play();
					goto SCORE; 
				} 
				if (winMenuButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
				{ 
					view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
					sf::Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);
					view.setCenter(position);
					window.setView(view);
					ExitButtonCheck = 0;
					musicMENU.play();
					musicWIN.stop();

					goto MENU; 
				} 
				if (winQuitButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
				{ 
					window.close(); 
				} 
 
 
			} 
 
			if (winScoreButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
			{ 
				Hover_scoreWINSprite.setPosition(539.f, 505.f); 
			} 
			if (winMenuButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
			{ 
				Hover_menuWINSprite.setPosition({ 385.f, 505.f }); 
			} 
			if (!winMenuButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
			{ 
				Hover_menuWINSprite.setPosition(10000.f, 10000.f); 
			} 
			if (!winScoreButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
			{ 
				Hover_scoreWINSprite.setPosition(10000.f, 10000.f); 
			} 
			if (winQuitButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
			{ 
				Hover_exitWINSprite.setPosition(714.f, 505.f); 
			} 
			if (!winQuitButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
			{ 
				Hover_exitWINSprite.setPosition(10000.f, 10000.f); 
			} 
 
			//Update score bg 
			win.setTextureRect(sf::IntRect(1280 * frameWIN, 720 * 0, 1280, 720)); 
 
 
			if (frameWINCounter == 20) { 
				frameWIN = (frameWIN + 1) % 5; 
				frameWINCounter = 0; 
			} 
			frameWINCounter++; 
 
 
			window.clear(); 
			window.draw(win); 
			window.draw(winScoreButton); 
			window.draw(winMenuButton); 
			window.draw(winQuitButton); 
			window.draw(Hover_exitWINSprite); 
			window.draw(Hover_scoreWINSprite); 
			window.draw(Hover_menuWINSprite); 
			window.display(); 
		} 

	return 0; 
} 