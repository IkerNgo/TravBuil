#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<iostream>
#include<string>
#include<sstream>
#include<windows.h>

using namespace sf;

class Menu
{
private:
	Texture playTexture, playTexturePress, quitTexture, quitTexturePress, continueTexture, continueTexturePress, pauseTexture, pauseTexturePress, instructionTexture, instructionTexturePress;
	Sprite playSprite, playSpritePress, quitSprite, quitSpritePress, continueSprite, continueSpritePress, pauseSprite, pauseSpritePress, instructionSprite, instructionSpritePress;

	//Instruction
	Texture pageTexture, framePageTexture, closeTexture, closeTexturePress;
	Sprite page, framePage, close, closePress;

	//Vitory Screen
	Texture fireworkTexture, gameNameTexture, authorTexture;
	Sprite firework, firework1, firework2, firework3, gameName, author;
	Font font;
	Text victoryText;

	//Private Functions
	void initVariables();
	void initButton();
	void initFirework();
	void initVictoryText();
	void initPage();

	//Variables
	bool isMousePlay, isMouseQuit, isMouseContinue, isMousePause, isMouseInstruction, isMouseClose;
	int col, row, pageLenght;

public:
	Menu();
	virtual ~Menu();

	//Functions
	const FloatRect getBoundsPlay() const;
	void checkMousePlay(Vector2i v);
	bool checkMousePlayClicked(Vector2i v);
	const FloatRect getBoundsQuit() const;
	void checkMouseQuit(Vector2i v);
	bool checkMouseQuitClicked(Vector2i v);
	const FloatRect getBoundsContinue() const;
	void checkMouseContinue(Vector2i v);
	bool checkMouseContinueClicked(Vector2i v);
	const FloatRect getBoundsPause() const;
	void checkMousePause(Vector2i v);
	bool checkMousePauseClicked(Vector2i v);
	const FloatRect getBoundsInstruction() const;
	void checkMouseIntruction(Vector2i v);
	bool checkMouseInstructionClicked(Vector2i v);
	const FloatRect getBoundsClose() const;
	void checkMouseClose(Vector2i v);
	bool checkMouseCloseClicked(Vector2i v);
	void updateFirework();
	void rollPage(Event e);

	void renderPlay(RenderTarget& target);
	void renderPause(RenderTarget& target);
	void renderContinue(RenderTarget& target);
	void renderInstruction(RenderTarget& target);
	void renderVictoryScreen(RenderTarget& target);
};

