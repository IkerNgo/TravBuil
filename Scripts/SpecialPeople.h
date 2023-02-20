#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<iostream>
#include<time.h>
#include<ctime>
#include<cstdlib>

using namespace sf;

class SpecialPeople
{
private:
	Texture texture;
	Sprite sprite;

	//Variables
	IntRect currentFrame;
	Clock animationTimer;
	int randDir;

	//Private functions
	void initVariables();
	void initSprite();

public:
	SpecialPeople();
	virtual ~SpecialPeople();

	//Functions
	void animation();
	void spawn();
	void move();
	const FloatRect getBounds() const;
	void update();
	void render(RenderTarget& target);
};

