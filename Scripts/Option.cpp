#include "Option.h"

void Option::initVaribles()
{
	this->isMouse = false;
	this->isMouse2 = false;
	this->isMouse3 = false;
}

void Option::initSprite()
{
	if (this->type == TOURIST)
	{
		this->optionTexture.loadFromFile("images/option.png");
		this->optionSprite.setTexture(this->optionTexture);
		this->optionSprite.setOrigin(133.f / 2, 138.f / 2);
		this->optionSprite.setPosition(540, 350);
		this->optionSprite.setScale(2.f, 2.f);

		this->optionTexturePress.loadFromFile("images/option_press.png");
		this->optionSpritePress.setTexture(this->optionTexturePress);
		this->optionSpritePress.setOrigin(133.f / 2, 138.f / 2);
		this->optionSpritePress.setPosition(540, 350);
		this->optionSpritePress.setScale(2.f, 2.f);
	}
	else if (this->type == BUSINESSMAN)
	{
		this->optionTexture.loadFromFile("images/option2.png");
		this->optionSprite.setTexture(this->optionTexture);
		this->optionSprite.setOrigin(133.f / 2, 138.f / 2);
		this->optionSprite.setPosition(140, 350);
		this->optionSprite.setScale(2.f, 2.f);

		this->optionTexturePress.loadFromFile("images/option2_press.png");
		this->optionSpritePress.setTexture(this->optionTexturePress);
		this->optionSpritePress.setOrigin(133.f / 2, 138.f / 2);
		this->optionSpritePress.setPosition(140, 350);
		this->optionSpritePress.setScale(2.f, 2.f);

		this->optionTexture2.loadFromFile("images/option4.png");
		this->optionSprite2.setTexture(this->optionTexture2);
		this->optionSprite2.setOrigin(133.f / 2, 138.f / 2);
		this->optionSprite2.setPosition(540, 350);
		this->optionSprite2.setScale(2.f, 2.f);

		this->optionTexturePress2.loadFromFile("images/option4_press.png");
		this->optionSpritePress2.setTexture(this->optionTexturePress2);
		this->optionSpritePress2.setOrigin(133.f / 2, 138.f / 2);
		this->optionSpritePress2.setPosition(540, 350);
		this->optionSpritePress2.setScale(2.f, 2.f);

		this->optionTexture3.loadFromFile("images/option6.png");
		this->optionSprite3.setTexture(this->optionTexture3);
		this->optionSprite3.setOrigin(133.f / 2, 138.f / 2);
		this->optionSprite3.setPosition(940, 350);
		this->optionSprite3.setScale(2.f, 2.f);

		this->optionTexturePress3.loadFromFile("images/option6_press.png");
		this->optionSpritePress3.setTexture(this->optionTexturePress3);
		this->optionSpritePress3.setOrigin(133.f / 2, 138.f / 2);
		this->optionSpritePress3.setPosition(940, 350);
		this->optionSpritePress3.setScale(2.f, 2.f);
	}
	else if (this->type == THIEF)
	{
		this->optionTexture.loadFromFile("images/option3.png");
		this->optionSprite.setTexture(this->optionTexture);
		this->optionSprite.setOrigin(133.f / 2, 138.f / 2);
		this->optionSprite.setPosition(540, 350);
		this->optionSprite.setScale(2.f, 2.f);

		this->optionTexturePress.loadFromFile("images/option3_press.png");
		this->optionSpritePress.setTexture(this->optionTexturePress);
		this->optionSpritePress.setOrigin(133.f / 2, 138.f / 2);
		this->optionSpritePress.setPosition(540, 350);
		this->optionSpritePress.setScale(2.f, 2.f);
	}
	else if (this->type == LITTERER)
	{
		this->optionTexture.loadFromFile("images/option5.png");
		this->optionSprite.setTexture(this->optionTexture);
		this->optionSprite.setOrigin(133.f / 2, 138.f / 2);
		this->optionSprite.setPosition(540, 350);
		this->optionSprite.setScale(2.f, 2.f);

		this->optionTexturePress.loadFromFile("images/option5_press.png");
		this->optionSpritePress.setTexture(this->optionTexturePress);
		this->optionSpritePress.setOrigin(133.f / 2, 138.f / 2);
		this->optionSpritePress.setPosition(540, 350);
		this->optionSpritePress.setScale(2.f, 2.f);
	}
}

void Option::initText()
{
	this->font.loadFromFile("arialbd.ttf");
	this->text.setFont(this->font);
	this->text.setCharacterSize(60);
	this->text.setFillColor(Color::White);
	this->text.setOutlineThickness(2.f);
	this->text.setOutlineColor(Color::Black);
	if (this->type == TOURIST)
		this->text.setString("Tourist");
	else if (this->type == THIEF)
		this->text.setString("Thief");
	else if (this->type == BUSINESSMAN)
		this->text.setString("Businessman");
	else if (this->type == LITTERER)
		this->text.setString("Litterer");

	this->text.setOrigin(this->text.getGlobalBounds().width / 2, this->text.getGlobalBounds().height / 2);
	this->text.setPosition(540, 120);
}

Option::Option(float touristRate, float businessmanRate, float thiefRate, float littererRate)
{
	this->randPeopleStyle(touristRate,businessmanRate,thiefRate, littererRate);
	this->initVaribles();
	this->initSprite();
	this->initText();
}

Option::~Option()
{

}

void Option::randPeopleStyle(float touristRate, float businessmanRate, float thiefRate, float littererRate)
{
	int randValue = rand() % 101 + 1;
	if (randValue > 0 && randValue <= (20 + touristRate - businessmanRate/2 - thiefRate - littererRate/2))
	{
		this->type = peopleStyle::TOURIST;
	}
	if (randValue > (20 + touristRate - businessmanRate/2 - thiefRate - littererRate/2) && randValue <= (80 + touristRate + businessmanRate/2 - littererRate/2 - thiefRate))
	{
		this->type = peopleStyle::BUSINESSMAN;
	}
	if (randValue > (80 + touristRate + businessmanRate / 2 - littererRate/2 - thiefRate) && randValue < (90 + touristRate + businessmanRate/2 - littererRate/2 - thiefRate))
	{
		this->type = peopleStyle::LITTERER;
	}
	if (randValue > (90 + touristRate + businessmanRate/2 + littererRate/2 - thiefRate) && randValue <= (100 + touristRate))
	{
		this->type = peopleStyle::THIEF;
	}
}

float Option::getBoundsLeft()
{
	return this->optionSprite.getGlobalBounds().left;
}

float Option::getBoundsTop()
{
	return this->optionSprite.getGlobalBounds().top;
}

float Option::getBoundsWidth()
{
	return this->optionSprite.getGlobalBounds().width;
}

float Option::getBoundsHeight()
{
	return this->optionSprite.getGlobalBounds().height;
}

float Option::getBoundsLeft2()
{
	return this->optionSprite2.getGlobalBounds().left;
}

float Option::getBoundsTop2()
{
	return this->optionSprite2.getGlobalBounds().top;
}

float Option::getBoundsWidth2()
{
	return this->optionSprite2.getGlobalBounds().width;
}

float Option::getBoundsHeight2()
{
	return this->optionSprite2.getGlobalBounds().height;
}

float Option::getBoundsLeft3()
{
	return this->optionSprite3.getGlobalBounds().left;
}

float Option::getBoundsTop3()
{
	return this->optionSprite3.getGlobalBounds().top;
}

float Option::getBoundsWidth3()
{
	return this->optionSprite3.getGlobalBounds().width;
}

float Option::getBoundsHeight3()
{
	return this->optionSprite3.getGlobalBounds().height;
}

bool Option::checkClickOption(Vector2i v)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (v.x > this->getBoundsLeft() && v.x<this->getBoundsLeft() + this->getBoundsWidth() && v.y>this->getBoundsTop() && v.y < this->getBoundsTop() + this->getBoundsHeight())
		{
			return true;
		}
	}
	return false;
}

bool Option::checkClickOption2(Vector2i v)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (v.x > this->getBoundsLeft2() && v.x<this->getBoundsLeft2() + this->getBoundsWidth2() && v.y>this->getBoundsTop2() && v.y < this->getBoundsTop2() + this->getBoundsHeight2())
		{
			return true;
		}
	}
	return false;
}

bool Option::checkClickOption3(Vector2i v)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (v.x > this->getBoundsLeft3() && v.x<this->getBoundsLeft3() + this->getBoundsWidth3() && v.y>this->getBoundsTop3() && v.y < this->getBoundsTop3() + this->getBoundsHeight3())
		{
			return true;
		}
	}
	return false;
}

int Option::getType()
{
	return this->type;
}

bool Option::checkMouse(Vector2i v)
{
	if (v.x > this->getBoundsLeft() && v.x<this->getBoundsLeft() + this->getBoundsWidth() && v.y>this->getBoundsTop() && v.y < this->getBoundsTop() + this->getBoundsHeight())
	{
		return this->isMouse = true;
	}
	return this->isMouse = false;
}

bool Option::checkMouse2(Vector2i v)
{
	if (v.x > this->getBoundsLeft2() && v.x<this->getBoundsLeft2() + this->getBoundsWidth2() && v.y>this->getBoundsTop2() && v.y < this->getBoundsTop2() + this->getBoundsHeight2())
	{
		return this->isMouse2 = true;
	}
	return this->isMouse2 = false;
}

bool Option::checkMouse3(Vector2i v)
{
	if (v.x > this->getBoundsLeft3() && v.x<this->getBoundsLeft3() + this->getBoundsWidth3() && v.y>this->getBoundsTop3() && v.y < this->getBoundsTop3() + this->getBoundsHeight3())
	{
		return this->isMouse3 = true;
	}
	return this->isMouse3 = false;
}

void Option::update()
{
}

void Option::render(RenderTarget& target)
{
	if(!this->isMouse)
		target.draw(this->optionSprite);
	if(this->isMouse)
		target.draw(this->optionSpritePress);
	
	if (!this->isMouse2)
		target.draw(this->optionSprite2);
	if (this->isMouse2)
		target.draw(this->optionSpritePress2);

	if (!this->isMouse3)
		target.draw(this->optionSprite3);
	if (this->isMouse3)
		target.draw(this->optionSpritePress3);

	target.draw(this->text);
}
