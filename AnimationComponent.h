#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

#include<iostream>
#include<string>
#include<map>

#include"SFML/Graphics.hpp"
#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Network.hpp"
#include"SFML/Audio.hpp"

class AnimationComponent
{
private:
	class Animation {
	public:
		// Variables
		sf::Sprite& sprite;
		sf::Texture& textureSheet;
		float animationTimer;
		float timer;
		int width;
		int height;
		sf::IntRect Startrect;
		sf::IntRect currentRect;
		sf::IntRect Endrect;

		Animation(sf::Sprite&sprite,sf::Texture& texture_sheet, 
			float animation_timer,
			int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height)
		 : sprite(sprite), textureSheet(texture_sheet), 
			animationTimer(animation_timer),width(width), height(height)
		{
			this->timer = 0.f;
			this->Startrect = sf::IntRect(start_frame_x * width, start_frame_y * height, width, height);
			this->currentRect = this->Startrect;
			this->Endrect = sf::IntRect(frames_x * width, frames_y * height, width, height);

			this->sprite.setTexture(this->textureSheet, true);
			this->sprite.setTextureRect(this->Startrect);
			
		}

		//Funtions
		void play(const float& dt) {

			//Update timer
			this->timer += 40.0f * dt;
			if (this->timer >= this->animationTimer) { 
				// reset timer
				this->timer = 0.f;

				// Animate
				if (this->currentRect != this->Endrect) {
					this->currentRect.left += this->width;
				}
				else // Reset 
				{
					this->currentRect.left = this->Startrect.left;
				}

				this->sprite.setTextureRect(this->currentRect);
			}
		}

		void reset() {
			this->timer = 0.f;
			this->currentRect = this->Startrect;
		
		}
	};

	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	std::map<std::string, Animation* > animations;
	Animation* lastAnimation;

public:
	AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet);
	virtual ~AnimationComponent();

	//Funtions
	void addAnimation(const std::string key,
		float animation_timer,
		int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height);


	void play(const std::string key, const float& dt);

};

#endif // !ANIMATIONCOMPONENT_H
