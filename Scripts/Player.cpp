#include "Player.h"

void Player::initVariables()
{
	this->moving = false;
	this->movingLeft = false;
	this->movingRight = false;
	this->characterPose = 0.f;
	this->currentFrame = IntRect(0,0, 38, 96);
}

void Player::initMainCharacter()
{
	if (!this->mainCharTexture.loadFromFile("images/character1.png"))
	{
		std::cout << "ERROR::GAME::Failed to load main character texture!" << "\n";
	}

	this->mainCharacter.setTexture(this->mainCharTexture);
	this->mainCharacter.setTextureRect(this->currentFrame);
	this->mainCharacter.setPosition(400, 400);
	this->mainCharacter.setOrigin(19, 0);
}

void Player::initAnimation()
{
	this->animationTimer.restart();
}

Player::Player()
{
	this->initVariables();
	this->initMainCharacter();
	this->initAnimation();
}

Player::~Player()
{

}

void Player::renderMainChar(RenderTarget& target)
{
	target.draw(this->mainCharacter);
}

void Player::characterMove()
{
	this->moving = false;
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->mainCharacter.move(-1.2f, 0.f);
		this->moving = true;
		this->movingLeft = true;
		this->movingRight = false;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->mainCharacter.move(1.20f, 0.f);
		this->moving = true;
		this->movingLeft = false;
		this->movingRight = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		this->moving = true;
		this->mainCharacter.move(0.f, -1.2f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		this->moving = true;
		this->mainCharacter.move(0.f, 1.20f);
	}
}

void Player::updateAnimation()
{
	if (moving)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
			this->characterPose += 1;
			if (this->characterPose >= 7)
				this->characterPose = 0;

			this->mainCharacter.setTextureRect(IntRect(this->characterPose * 38, 0, 38, 96));
			//this->mainCharacter.setOrigin(600.f / 16.f /* + this->characterPose * 600.f / 8.f*/, 290.f / 6.f);
			this->animationTimer.restart();
		}

		if (movingLeft)
		{
			this->mainCharacter.setScale(-1.f, 1.f);
		}
		if (movingRight)
		{
			this->mainCharacter.setScale(1.f, 1.f);
		}
	}
}

void Player::borderCollision()
{
	this->mainCharacter.setOrigin(0.f, 0.f);
	if (this->getBounds().left < -3)
	{
		this->mainCharacter.setPosition(0, this->getBounds().top);
	}
	else if (this->getBounds().left + this->getBounds().width > 1100)
	{
		this->mainCharacter.setPosition(1100 - this->getBounds().width, this->getBounds().top);
	}
	if (this->getBounds().top < 250)
	{
		this->mainCharacter.setPosition(this->getBounds().left, 250);
	}
	else if (this->getBounds().top + this->getBounds().height > 700)
	{
		this->mainCharacter.setPosition(this->getBounds().left, 700 - this->getBounds().height);
	}
	this->mainCharacter.setOrigin(19, 0);
}

const FloatRect Player::getBounds() const
{
	return this->mainCharacter.getGlobalBounds();
}

void Player::update()
{
	this->characterMove();
	this->updateAnimation();
	this->borderCollision();
}
