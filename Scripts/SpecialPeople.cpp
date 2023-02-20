#include "SpecialPeople.h"

void SpecialPeople::initVariables()
{
	this->currentFrame = IntRect(0, 0, 72, 145);
	this->animationTimer.restart();
	this->randDir = rand() % 2;
}

void SpecialPeople::initSprite()
{
	this->texture.loadFromFile("images/speople.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(0.8, 0.8);
}

SpecialPeople::SpecialPeople()
{
	this->initVariables();
	this->initSprite();
	this->spawn();
}

SpecialPeople::~SpecialPeople()
{

}

void SpecialPeople::animation()
{
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
	{
		this->currentFrame.left += 72.f;
		if (this->currentFrame.left > 1152)
			this->currentFrame.left = 0;
		this->animationTimer.restart();
	}

	this->sprite.setTextureRect(this->currentFrame);
}

void SpecialPeople::spawn()
{
	float randValue_y1 = rand() % (440 - 400) + 400;
	float randValue_y2 = rand() % (395 - 355) + 355;
	this->sprite.setOrigin(0.8, 0.8);
	if (this->randDir == 0)
	{
		this->sprite.setPosition(-50, randValue_y1);
	}
	else
	{
		this->sprite.setPosition(1110, randValue_y2);
		this->sprite.setScale(-0.8, 0.8);
	}
}

void SpecialPeople::move()
{
	if (randDir == 0)
		this->sprite.move(1.f, 0.f);
	else
		this->sprite.move(-1.f, 0);
}

const FloatRect SpecialPeople::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

void SpecialPeople::update()
{
	this->animation();
	this->move();
}

void SpecialPeople::render(RenderTarget& target)
{
	target.draw(this->sprite);
}
