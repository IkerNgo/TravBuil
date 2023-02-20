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

using namespace sf;

enum peopleStyle {TOURIST, THIEF, BUSINESSMAN, LITTERER};

class Option
{
private:
	Texture optionTexture,optionTexturePress, optionTexture2, optionTexturePress2, optionTexture3, optionTexturePress3;
	Sprite optionSprite,optionSpritePress, optionSprite2, optionSpritePress2, optionSprite3, optionSpritePress3;
	Font font;
	Text text;
	bool isMouse, isMouse2, isMouse3;
	int type;

	//Private function
	void initVaribles();
	void initSprite();
	void initText();
public:
	Option(float touristRate, float businessmanRate, float thiefRate, float littererRate);
	virtual ~Option();

	//Functions
	void randPeopleStyle(float touristRate, float businessmanRate, float thiefRate, float littererRate);
	float getBoundsLeft();
	float getBoundsTop();
	float getBoundsWidth();
	float getBoundsHeight();
	float getBoundsLeft2();
	float getBoundsTop2();
	float getBoundsWidth2();
	float getBoundsHeight2();
	float getBoundsLeft3();
	float getBoundsTop3();
	float getBoundsWidth3();
	float getBoundsHeight3();
	bool checkClickOption(Vector2i v);
	bool checkClickOption2(Vector2i v);
	bool checkClickOption3(Vector2i v);
	int getType();
	bool checkMouse(Vector2i v);
	bool checkMouse2(Vector2i v);
	bool checkMouse3(Vector2i v);
	void  update();
	void render(RenderTarget& target);
};

