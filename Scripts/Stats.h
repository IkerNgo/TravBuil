#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<iostream>
#include<time.h>
#include<cstdlib>
#include<string>
#include<sstream>
#include<vector>

using namespace sf;

class Stats
{
private:
	Texture coinTexture, starTexture, fadedStarTexture, garbageTexture, fadedGarbageTexture;
	Sprite coin, coin2,star;
	Sprite fadedStar[7], goldStar[7], garbage[7], fadedGarbage[7];

	Font font;
	Text text, famousText, timer, GUIText, GUIText2, incomeText, garbageText;

	//Variables
	Vector2f currentPosition, currentPosition2;
	float timerTimer, timerTimerMax, dayCounter, hourCounter;

	//GUI
	RectangleShape famousBar, famousBarBack, greenBar, greenBarBack;

	//Private functions
	void initVariables();
	void initCoin();
	void initText();
	void initFadedStar();
	void initTimer();
	void initGUI();

public:
	Stats();
	virtual ~Stats();

	//Functions
	void updateText(int point, int famous);
	void famousStar(int famous, int garbage);
	void deleteFamousStar(int famous);
	void deleteGarbage(int garbage);
	void timerRunning();
	void updateTimer();
	void updateGUI(float famous, float green);
	void updateIncome(float a);
	void update(float famous,float green, float income);
	void render(RenderTarget& target);
};

