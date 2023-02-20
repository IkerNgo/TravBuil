#include "People.h"

void People::initVariables()
{
	this->animationTimer.restart();
	this->currentFrame1 = IntRect(0, 0, 75, 140);
	this->currentFrame2 = IntRect(852 , 0, 72, 150);
	this->currentFrame3 = IntRect(1199 , 0, 109, 150);
	this->currentFrame4 = IntRect(0, 0, 84, 120);
	this->currentFrame5 = IntRect(0, 0, 142, 200);
	this->randValue_x = rand() % 2;
	this->randValueRender = rand() % 5;
}

void People::initTexture()
{
	this->people1Tex.loadFromFile("images/people1.png");
	this->people2Tex.loadFromFile("images/people2.png");
	this->people3Tex.loadFromFile("images/people3.png");
	this->people4Tex.loadFromFile("images/people4.png");
	this->people5Tex.loadFromFile("images/people5.png");
}

void People::initPeople1()
{
	this->people1.setTexture(this->people1Tex);
	this->people1.setTextureRect(this->currentFrame1);
	this->people1.setPosition(-75, 440);
	this->people1.setOrigin(75.f / 2.f, 0);
	this->people1.setScale(0.8f, 0.8f); 
}

void People::initPeople2()
{
	this->people2.setTexture(this->people2Tex);
	this->people2.setTextureRect(this->currentFrame2);
	this->people2.setPosition(1080, 390);
	this->people2.setOrigin(36, 0);
	this->people2.setScale(0.7f, 0.7f);
}

void People::initPeople3()
{
	this->people3.setTexture(this->people3Tex);
	this->people3.setTextureRect(this->currentFrame3);
	this->people3.setPosition(1080, 440);
	this->people3.setOrigin(109.f / 2.f, 0);
	this->people3.setScale(0.7f, 0.7f);
}

void People::initPeople4()
{
	this->people4.setTexture(this->people4Tex);
	this->people4.setTextureRect(this->currentFrame4);
	this->people4.setPosition(-84, 390);
	this->people4.setOrigin(42, 0);
	this->people4.setScale(0.7f, 0.7f);
}

void People::initPeople5()
{
	this->people5.setTexture(this->people5Tex);
	this->people5.setTextureRect(this->currentFrame5);
	this->people5.setPosition(-142, 390);
	this->people5.setOrigin(71, 0);
	this->people5.setScale(0.5f, 0.5f);
}


People::People()
{
	this->initVariables();
	this->initTexture();
	this->initPeople1();
	this->initPeople2();
	this->initPeople3();
	this->initPeople4();
	this->initPeople5();
	this->spawnPosition();
}

People::~People()
{
}

void People::animation()
{
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
	{
		this->currentFrame1.left += 75;
		if (this->currentFrame1.left > 375)
			this->currentFrame1.left = 0;
		this->currentFrame2.left -= 72;
		if (this->currentFrame2.left < 0)
			this->currentFrame2.left = 852;
		this->currentFrame3.left -= 109;
		if (this->currentFrame3.left < 0)
			this->currentFrame3.left = 1199;
		this->currentFrame4.left += 84;
		if (this->currentFrame4.left > 1344)
			this->currentFrame4.left = 0;
		this->currentFrame5.left += 142;
		if (this->currentFrame5.left > 1136)
			this->currentFrame5.left = 0;

		this->setTexRect();

		this->animationTimer.restart();
	}
}

void People::setTexRect()
{
	this->people1.setTextureRect(this->currentFrame1);
	this->people2.setTextureRect(this->currentFrame2);
	this->people3.setTextureRect(this->currentFrame3);
	this->people4.setTextureRect(this->currentFrame4);
	this->people5.setTextureRect(this->currentFrame5);

}


void People::spawnPosition()
{
	float randValue_y1 = rand() % (460-415) + 425;
	float randValue_y2 = rand() % (410-360) + 360;
	if (this->randValue_x == 0)
	{
		this->people1.setPosition(-75, randValue_y1);
		this->people2.setPosition(-72, randValue_y1);
		this->people3.setPosition(-109, randValue_y1);
		this->people4.setPosition(-84, randValue_y1);
		this->people5.setPosition(-142, randValue_y1);
		this->people2.setScale(-0.7f, 0.7f);
		this->people3.setScale(-0.7f, 0.7f);
		std::cout << "SPAWN 0!" << "\n";
	}
	//if (randValue_x == 1)
	else
	{
		this->people1.setPosition(1080, randValue_y2);
		this->people2.setPosition(1080, randValue_y2);
		this->people3.setPosition(1080, randValue_y2);
		this->people4.setPosition(1080, randValue_y2);
		this->people5.setPosition(1080, randValue_y2);
		this->people1.setScale(-0.8f, 0.8f);
		this->people4.setScale(-0.7f, 0.7f);
		this->people5.setScale(-0.5f, 0.5f);
	}
}

void People::move()
{
	if (this->randValue_x == 0)
	{
		this->people1.move(1.f, 0.f);
		this->people2.move(1.f, 0.f);
		this->people3.move(1.f, 0.f);
		this->people4.move(1.f, 0.f);
		this->people5.move(1.f, 0.f);
	}
	else
	{
		this->people1.move(-1.f, 0.f);
		this->people2.move(-1.f, 0.f);
		this->people3.move(-1.f, 0.f);
		this->people4.move(-1.f, 0.f);
		this->people5.move(-1.f, 0.f);
	}
}

const FloatRect People::getBounds() const
{
	if (this->randValueRender == 0)
		return this->people1.getGlobalBounds();
	if (this->randValueRender == 1)
		return this->people2.getGlobalBounds();
	if (this->randValueRender == 2)
		return this->people3.getGlobalBounds();
	if (this->randValueRender == 3)
		return this->people4.getGlobalBounds();
	if (this->randValueRender == 4)
		return this->people5.getGlobalBounds();
}

void People::update()
{
	this->animation();
	this->move();
}

void People::render(RenderTarget& target)
{
	if(this->randValueRender==0)
		target.draw(this->people1);
	if(this->randValueRender==1)
		target.draw(this->people2);
	if(this->randValueRender==2)
		target.draw(this->people3);
	if(this->randValueRender==3)
		target.draw(this->people4);
	if (this->randValueRender == 4)
		target.draw(this->people5);
}
