#include "Stats.h"

void Stats::initVariables()
{
	this->currentPosition = Vector2f(190,15);
	this->currentPosition2 = Vector2f(190, 50);
	this->timerTimerMax = 200.f;
	this->timerTimer = 0;
	this->dayCounter = 1;
	this->hourCounter = 0;
}

void Stats::initCoin()
{
	this->coinTexture.loadFromFile("images/coin.png");
	this->coin.setTexture(this->coinTexture);
	this->coin.setScale(0.07, 0.07);
	this->coin.setPosition(this->text.getGlobalBounds().left + this->text.getGlobalBounds().width, 95);

	this->starTexture.loadFromFile("images/star.png");

	this->fadedStarTexture.loadFromFile("images/faded_star.png");

	this->garbageTexture.loadFromFile("images/garbage.png");

	this->fadedGarbageTexture.loadFromFile("images/garbage_faded.png");

	this->coin2.setTexture(this->coinTexture);
	this->coin2.setScale(0.07, 0.07);
	this->coin2.setPosition(304, 85);
}

void Stats::initText()
{
	this->font.loadFromFile("arialbd.ttf");
	this->text.setFont(this->font);
	this->text.setCharacterSize(25);
	this->text.setFillColor(Color::White);
	this->text.setOutlineThickness(1.f);
	this->text.setOutlineColor(Color::Black);
	this->text.setString("$1 ");
	this->text.setPosition(30, 85);

	this->famousText.setFont(this->font);
	this->famousText.setCharacterSize(25);
	this->famousText.setFillColor(Color::White);
	this->famousText.setOutlineThickness(1.f);
	this->famousText.setOutlineColor(Color::Black);
	this->famousText.setString("Security: 7/7 ");
	this->famousText.setPosition(30, 15);

	this->garbageText.setFont(this->font);
	this->garbageText.setCharacterSize(25);
	this->garbageText.setFillColor(Color::White);
	this->garbageText.setOutlineThickness(1.f);
	this->garbageText.setOutlineColor(Color::Black);
	this->garbageText.setString("Garbage: 0/7 ");
	this->garbageText.setPosition(30, 50);

	this->GUIText.setFont(this->font);
	this->GUIText.setCharacterSize(25);
	this->GUIText.setFillColor(Color::White);
	this->GUIText.setOutlineThickness(1.f);
	this->GUIText.setOutlineColor(Color::Black);
	this->GUIText.setString("Famous 100%");
	this->GUIText.setPosition(625, 15);

	this->GUIText2.setFont(this->font);
	this->GUIText2.setCharacterSize(25);
	this->GUIText2.setFillColor(Color::White);
	this->GUIText2.setOutlineThickness(1.f);
	this->GUIText2.setOutlineColor(Color::Black);
	this->GUIText2.setString("Green 100%");
	this->GUIText2.setPosition(625, 55);

	this->incomeText.setFont(this->font);
	this->incomeText.setCharacterSize(25);
	this->incomeText.setFillColor(Color::White);
	this->incomeText.setOutlineThickness(1.f);
	this->incomeText.setOutlineColor(Color::Black);
	this->incomeText.setString("Income: ");
	this->incomeText.setPosition(150, 85);
}

void Stats::initFadedStar()
{
	for (int i = 0; i < 7; i++)
	{
		this->fadedStar[i].setTexture(this->fadedStarTexture);
		this->fadedStar[i].setScale(0.03, 0.03);
		this->fadedStar[i].setPosition(this->currentPosition);
		this->currentPosition.x += 35;
	}
	this->currentPosition = Vector2f(190, 15);

	for (int i = 0; i < 7; i++)
	{
		this->fadedGarbage[i].setTexture(this->fadedGarbageTexture);
		this->fadedGarbage[i].setScale(0.1, 0.1);
		this->fadedGarbage[i].setPosition(this->currentPosition2);
		this->currentPosition2.x += 35;
	}
	this->currentPosition2 = Vector2f(190, 50);
}

void Stats::initTimer()
{
	this->timer.setFont(this->font);
	this->timer.setCharacterSize(25);
	this->timer.setFillColor(Color::White);
	this->timer.setOutlineThickness(1.f);
	this->timer.setOutlineColor(Color::Black);
	this->timer.setString("Day: ");
	this->timer.setPosition(30, 120);
}

void Stats::initGUI()
{
	this->famousBar.setSize(Vector2f(400, 30));
	this->famousBar.setFillColor(Color::Yellow);
	this->famousBar.setOutlineThickness(2);
	this->famousBar.setOutlineColor(Color::Black);
	this->famousBar.setPosition(500, 15);

	this->famousBarBack = this->famousBar;
	this->famousBarBack.setFillColor(Color(155, 157, 165));

	this->greenBar.setSize(Vector2f(400, 30));
	this->greenBar.setFillColor(Color::Green);
	this->greenBar.setOutlineThickness(2);
	this->greenBar.setOutlineColor(Color::Black);
	this->greenBar.setPosition(500, 55);

	this->greenBarBack = this->greenBar;
	this->greenBarBack.setFillColor(Color(155, 157, 165));
}

Stats::Stats()
{
	this->initVariables();
	this->initText();
	this->initCoin();
	this->initFadedStar();
	this->initTimer();
	this->initGUI();
}

Stats::~Stats()
{
}

void Stats::updateText(int point, int famous)
{
	std::stringstream ss, ss1;
	ss << "$" << point;
	this->text.setString(ss.str());
	this->coin.setPosition(this->text.getGlobalBounds().left + this->text.getGlobalBounds().width + 3, 80);

	ss1 << "Security: " << famous << "/7";
	this->famousText.setString(ss1.str());
}

void Stats::famousStar(int famous, int garbage)
{
	for (int i = 0; i < famous; i++)
	{
		this->goldStar[i].setTexture(this->starTexture);
		this->goldStar[i].setScale(0.03, 0.03);
		this->goldStar[i].setPosition(this->currentPosition);
		this->currentPosition.x += 35;
	}
	this->currentPosition = Vector2f(190, 15);

	for (int j = 0; j < garbage; j++)
	{
		this->garbage[j].setTexture(this->garbageTexture);
		this->garbage[j].setScale(0.11, 0.11);
		this->garbage[j].setPosition(this->currentPosition2);
		this->currentPosition2.x += 35;
	}
	this->currentPosition2 = Vector2f(190, 50);
}

void Stats::deleteFamousStar(int famous)
{
	this->goldStar[famous].setScale(0, 0);
}

void Stats::deleteGarbage(int garbage)
{
	this->garbage[garbage - 1].setScale(0, 0);
}

void Stats::timerRunning()
{
	this->timerTimer += 1.f;
	if (this->timerTimer >= this->timerTimerMax)
	{
		this->hourCounter += 1;
		this->timerTimer = 0;
		if (this->hourCounter >= 24)
		{
			this->dayCounter += 1;
			this->hourCounter = 0;
		}
	}
}

void Stats::updateTimer()
{
	std::stringstream ss;
	ss << this->hourCounter << "h  " << "Day " << this->dayCounter;
	this->timer.setString(ss.str());
}

void Stats::updateGUI(float famous, float green)
{
	std::stringstream ss, ss2;
	ss << "Famous " << famous << "%";
	this->GUIText.setString(ss.str());

	this->famousBar.setSize(Vector2f(famous * 400 / 100, this->famousBar.getSize().y));

	ss2 << "Green " << green << "%";
	this->GUIText2.setString(ss2.str());

	this->greenBar.setSize(Vector2f(green * 400 / 100, this->greenBar.getSize().y));
}

void Stats::updateIncome(float a)
{
	std::stringstream ss;
	ss << "Income: +" << a << "      /day";
	this->incomeText.setString(ss.str());
}

void Stats::update(float famous, float green, float income)
{
	this->timerRunning();
	this->updateTimer();
	this->updateGUI(famous, green);
	this->updateIncome(income);
}

void Stats::render(RenderTarget& target)
{
	target.draw(this->coin);
	target.draw(this->coin2);
	target.draw(this->text);
	target.draw(this->famousText);
	target.draw(this->garbageText);
	for (auto& s : fadedStar)
	{
		target.draw(s);
	}
	for (auto& s : goldStar)
	{
		target.draw(s);
	}
	for (auto& s : fadedGarbage)
	{
		target.draw(s);
	}
	for (auto& s : garbage)
	{
		target.draw(s);
	}
	target.draw(this->timer);
	target.draw(this->famousBarBack);
	target.draw(this->famousBar);
	target.draw(this->GUIText);
	target.draw(this->greenBarBack);
	target.draw(this->greenBar);
	target.draw(this->GUIText2);
	target.draw(this->incomeText);
}

