#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<iostream>
#include<time.h>
#include<ctime>

using namespace sf;

class Player
{
private:
	Texture mainCharTexture;
	Sprite mainCharacter;

	//Variables
	bool movingLeft, movingRight, moving;
	float characterPose;
	Clock animationTimer;
	IntRect currentFrame;

	//Private functions
	void initVariables();
	void initMainCharacter();
	void initAnimation();

public:
	Player();
	virtual ~Player();

	//Functions
	void renderMainChar(RenderTarget& target);
	void characterMove();
	void updateAnimation();
	void borderCollision();
	const FloatRect getBounds() const;
	void update();
};

