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

class People
{
private:
	Texture people1Tex, people2Tex, people3Tex, people4Tex, people5Tex;
	Sprite people1, people2, people3, people4, people5;

	//Variables
	Clock animationTimer;
	IntRect currentFrame1, currentFrame2, currentFrame3, currentFrame4, currentFrame5;
	float randValue_x, randValueRender;

	//Private functions
	void initVariables();
	void initTexture();
	void initPeople1();
	void initPeople2();
	void initPeople3();
	void initPeople4();
	void initPeople5();

public:
	People();
	virtual ~People();

	//Functions
	void animation();
	void setTexRect();
	void spawnPosition();
	void move();
	const FloatRect getBounds() const;
	void update();
	void render(RenderTarget& target);
};

