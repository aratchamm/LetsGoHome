#include "MainMenuState.h"

// Initializer funtions
void MainMenuState::initVariables()
{
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x), 
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->bgTexture.loadFromFile("img/bg/menu.png")) {
		throw"ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	
	this->background.setTexture(&this->bgTexture);
}

void MainMenuState::initBackground()
{

}


void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Pixeboy-z8XGD.ttf")) {
		throw("ERROR::MAIMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initKeybinds()
{
	this->keybinds.emplace("MOVE_LEFT", this->supportedKeys->at("A"));
	this->keybinds.emplace("MOVE_RIGHT", this->supportedKeys->at("D"));
	this->keybinds.emplace("MOVE_UP", this->supportedKeys->at("W"));
	this->keybinds.emplace("MOVE_DOWN", this->supportedKeys->at("S"));
}

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"] = new Button(
		578.f,553.f, 150.f, 50.f,
		&this->font, "START", sf::Color::White, sf::Color(79, 109, 179, 255),
		sf::Color(79, 109, 179, 255), sf::Color::White, sf::Color::White,
		sf::Color(79, 109, 179, 255), sf::Color(79, 109, 179, 255), sf::Color(79, 109, 179, 255));

	this->buttons["SCORE"] = new Button(
		798.f, 553.f, 150.f, 50.f,
		&this->font, "Score", sf::Color::White, sf::Color(79, 109, 179, 255),
		sf::Color(79, 109, 179, 255), sf::Color::White, sf::Color::White,
		sf::Color(79, 109, 179, 255), sf::Color(79, 109, 179, 255), sf::Color(79, 109, 179, 255));

	this->buttons["CREDIT"] = new Button(
		1008.f, 553.f, 200.f, 50.f,
		&this->font, "Credit", sf::Color::White, sf::Color(79, 109, 179, 255),
		sf::Color(79, 109, 179, 255), sf::Color::White, sf::Color::White,
		sf::Color(79, 109, 179, 255), sf::Color(79, 109, 179, 255), sf::Color(79, 109, 179, 255));

	this->buttons["EXIT_STATE"] = new Button(
		1258.f, 553.f, 150.f, 50.f,
		&this->font, "EXIT", sf::Color::White, sf::Color(79, 109, 179, 255),
		sf::Color(79, 109, 179, 255), sf::Color::White, sf::Color::White,
		sf::Color(79, 109, 179, 255), sf::Color(79, 109, 179, 255), sf::Color(79, 109, 179, 255));
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys, states)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();


}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		delete it->second;
	}
}


void MainMenuState::endState()
{
	std::cout << "Ending MainMenuState!" << "\n";
}


void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();


}

void MainMenuState::updateButtons()
{
	/*Updates all the buttons in the state and handles their funtionlaity*/
	for (auto &it : this->buttons) {
		it.second->update(this->mousePosView);
	}

	// New Game
	if (this->buttons["GAME_STATE"]->isPressed()) {
		this->states->push(new GameStates(this->window, this->supportedKeys, this->states));
	}

	// Quit the game
	if (this->buttons["EXIT_STATE"]->isPressed()) {
		this->quit = true;
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();
	


}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons) {
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{

	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderButtons(target);

	//REMOVE LATER!!!
	/*sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());


	target->draw(mouseText);*/
}
