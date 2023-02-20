#pragma once

#include"Player.h"
#include"People.h"
#include"SpecialPeople.h"
#include"Option.h"
#include"Stats.h"
#include"Contract.h"
#include"Menu.h"

class Game
{
private:
	//Window
	RenderWindow* window;
	VideoMode videoMode;
	Event e;

	//Background
	Texture backgroundTexture;
	Sprite backgound;
	Texture shadeBackgroundTexture;
	Sprite shadeBackground;

	//Music
	Music backgroundMusic, openMusic, pauseMusic, victoryMusic, constructionSound;

	//Character
	Player* player;

	//People
	std::vector<People*> people;
	float spawnPeopleTimer, spawnPeopleTimerMax;

	//Stats
	Stats* stat;
	float famousRate, greenRate, addFamousRate, addGreenRate;

	//Special People
	std::vector<SpecialPeople*> speople;
	float spawnSpecialPeopleTimer, spawnSpecialPeopleTimerMax;
	bool isContact, isContract, spawnContract, isExist;

	//Options
	Option* option;
	bool isInitOption;
	float addBusinessmanRate, addThiefRate, addTouristRate, addLittererRate;

	//Contract
	Contract* contract;
	Contract* contractOption;
	std::vector<Contract*> allContractOption;
	Vector2f contractPosition;
	int numberPortrait;
	float contractDisappearTimer, contractDisappearTimerMax;
	bool conditions;
	int additionalPoints, addPoints, moneyLose, foodStall;

	//Menu
	Menu* menu;
	bool isPlay, isPause, isContinue, isInstruction, isIntroductionOn;
	int iconNumber, winRate;

	//Functions
	void initVariables();
	void initWindow();
	void initbackground();
	void initMusic();
	void initPlayer();
	void initOption();
	void initStat();
	void initContract();
	void initContractOption();
	void initMenu();
	void reset();

public:
	//Contructors & Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;
	int point;
	float grantPointTimer, grandPointTimerMax;
	int famous, garbage;
	std::vector<Vector2f> location;

	//Functions
	void pollEvent();
	void renderbackground();
	void renderShadeBackground();
	void checkMouseMenu();
	void checkPlay();
	void checkContinue();
	void checkPause();
	void checkCloseInstruction();
	void checkOpenIntroduction();
	void checkCloseIntroduction();
	void spawnPeople();
	void spawnSpecialPeople();
	void deletePeople();
	void deleteSpecialPeople();
	void checkContact();
	void contractCollision();
	Vector2i getMousePosition();
	void optionClicked();
	void contractOptionClicked();
	void resetAdditions();
	void checkMouse();
	void checkMouseOption();
	void updatePoint();
	void update();
	void render();
};

