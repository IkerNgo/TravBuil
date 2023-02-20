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

enum province {BARIAVUNGTAU, BENTRE, BINHTHUAN,
				CAMAU, CANTHO, DANANG,
				DONGTHAP, HAGIANG, HAIDUONG,
				HAIPHONG, HANOI, HCMCITY,
				KIENGIANG, KHANHHOA, LAMDONG,
				LAOCAI, NINHBINH, NINHTHUAN,
				QUANGNAM, QUANGNINH, THUATHIENHUE};

class Contract
{
private:
	Texture contractTexture;
	Sprite contract;
	Font font;
	Text text;

	//Contract Pictures
	Texture port1Tex, port1PressTex, port2Tex, port2PressTex, port3Tex, port3PressTex, port4Tex, port4PressTex, backTexture, backTexturePress;
	Sprite port1, port1Press, port2, port2Press, port3, port3Press, port4, port4Press, back, backPress;

	//Portrait Icon
	Texture port1IconTex, port2IconTex, port3IconTex, port4IconTex;
	Sprite port1Icon, port2Icon, port3Icon, port4Icon;

	//Chatbox
	Texture chatboxPort1Tex, chatboxPort2Tex, chatboxPort3Tex, chatboxPort4Tex;
	Sprite chatboxPort1, chatboxPort2, chatboxPort3, chatboxPort4;

	//Chatbox Icon
	Texture chatboxIcon1Tex, chatboxIcon2Tex, chatboxIcon3Tex, chatboxIcon4Tex;
	Sprite chatboxIcon1, chatboxIcon2, chatboxIcon3, chatboxIcon4;

	//Introductions
	Texture introduction1Texture, introduction2Texture, introduction3Texture, introduction4Texture;
	Sprite introduction1, introduction2, introduction3, introduction4;
	Text introductionText;

	//Variables
	bool isMoving;
	float constructionArea;
	bool isMouse1, isMouse2, isMouse3, isMouse4, isMouseBack;


	//Private Function
	void initVariables();
	//void initPosition();
	void initPosition(std::vector<Vector2f> v);
	void initContract();
	void initText();
	void initPictures();
	void getRandProvince();
	void initChatbox1();
	void initChatbox2();
	void initChatbox3();
	void initChatbox4();
	void initChatbox();


public:
	Contract(std::vector<Vector2f> v);
	virtual ~Contract();
	float x_position, y_position;
	int provinceName;
	float iconNumber;
	bool is1, is2, is3, is4, isinIcon;

	const FloatRect getBounds() const;
	void checkMoving();
	bool checkStop();
	void move();
	void initPort1Icon(int n);
	void initPort2Icon(int n);
	void initPort3Icon(int n);
	void initPort4Icon(int n);
	Vector2f getConstructPos();
	const FloatRect getBounds1() const;
	const FloatRect getBounds2() const;
	const FloatRect getBounds3() const;
	const FloatRect getBounds4() const;
	const FloatRect getBoundsIcon() const;
	const FloatRect getBoundsBack() const;
	const FloatRect getBoundsIcon1() const;
	const FloatRect getBoundsIcon2() const;
	const FloatRect getBoundsIcon3() const;
	const FloatRect getBoundsIcon4() const;
	void checkMouse1(Vector2i v);
	void checkMouse2(Vector2i v);
	void checkMouse3(Vector2i v);
	void checkMouse4(Vector2i v);
	void checkMouseIcon(Vector2i v);
	void checkMouseBack(Vector2i v);
	bool checkClickOption1(Vector2i v);
	bool checkClickOption2(Vector2i v);
	bool checkClickOption3(Vector2i v);
	bool checkClickOption4(Vector2i v);
	bool checkClickBack(Vector2i v);
	bool checkClickIcon1(Vector2i v);
	bool checkClickIcon2(Vector2i v);
	bool checkClickIcon3(Vector2i v);
	bool checkClickIcon4(Vector2i v);
	void setContractPosition(Vector2f v);
	void setChatboxIconPosition(float a, float b);
	void update();
	void render(RenderTarget& target);
	void renderContract(RenderTarget& target);
	void renderPortIcon(RenderTarget& target);
	void renderChatboxIcon(RenderTarget& target);
	void renderIntroduction(RenderTarget& target);
};

