#include "Menu.h"

void Menu::initVariables()
{
	this->isMousePlay = false;
	this->isMouseQuit = false;
	this->isMouseContinue = false;
	this->isMousePause = false;
	this->isMouseInstruction = false;
	this->isMouseClose = false;
	this->col = this->row = 0;
	this->pageLenght = 0;
}

void Menu::initButton()
{
	this->playTexture.loadFromFile("images/play_button.png");
	this->playSprite.setTexture(this->playTexture);
	this->playSprite.setOrigin(100, 36);
	this->playSprite.setPosition(540, 300);

	this->playTexturePress.loadFromFile("images/play_button_press.png");
	this->playSpritePress.setTexture(this->playTexturePress);
	this->playSpritePress.setOrigin(100, 36);
	this->playSpritePress.setPosition(540, 300);

	this->quitTexture.loadFromFile("images/quit_button.png");
	this->quitSprite.setTexture(this->quitTexture);
	this->quitSprite.setOrigin(100, 36);
	this->quitSprite.setPosition(540, 450);

	this->quitTexturePress.loadFromFile("images/quit_button_press.png");
	this->quitSpritePress.setTexture(this->quitTexturePress);
	this->quitSpritePress.setOrigin(100, 36);
	this->quitSpritePress.setPosition(540,450);

	this->continueTexture.loadFromFile("images/continue_button.png");
	this->continueSprite.setTexture(this->continueTexture);
	this->continueSprite.setOrigin(100, 36);
	this->continueSprite.setPosition(540, 300);

	this->continueTexturePress.loadFromFile("images/continue_button_press.png");
	this->continueSpritePress.setTexture(this->continueTexturePress);
	this->continueSpritePress.setOrigin(100, 36);
	this->continueSpritePress.setPosition(540, 300);

	this->pauseTexture.loadFromFile("images/pause_button.png");
	this->pauseSprite.setTexture(this->pauseTexture);
	this->pauseSprite.setScale(0.03, 0.03);
	this->pauseSprite.setPosition(1045, 4);

	this->pauseTexturePress.loadFromFile("images/pause_button_press.png");
	this->pauseSpritePress.setTexture(this->pauseTexturePress);
	this->pauseSpritePress.setScale(0.03, 0.03);
	this->pauseSpritePress.setPosition(1045, 4);

	this->instructionTexture.loadFromFile("images/instruction.png");
	this->instructionSprite.setTexture(this->instructionTexture);
	this->instructionSprite.setScale(0.03, 0.03);
	this->instructionSprite.setPosition(1005, 4);

	this->instructionTexturePress.loadFromFile("images/instruction_press.png");
	this->instructionSpritePress.setTexture(this->instructionTexturePress);
	this->instructionSpritePress.setScale(0.03, 0.03);
	this->instructionSpritePress.setPosition(1005, 4);

	this->gameNameTexture.loadFromFile("images/gamename.png");
	this->gameName.setTexture(this->gameNameTexture);
	this->gameName.setOrigin(225, 150);
	this->gameName.setPosition(540, 130);

	this->authorTexture.loadFromFile("images/author.png");
	this->author.setTexture(this->authorTexture);
	this->author.setScale(0.3, 0.3);
	this->author.setPosition(850, 670);
}

void Menu::initFirework()
{
	this->fireworkTexture.loadFromFile("images/firework.png");
	this->firework.setTexture(this->fireworkTexture);
	this->firework.setTextureRect(IntRect(this->col, this->row, 256, 256));
	this->firework.setOrigin(128, 128);
	this->firework.setPosition(500, 120);

	this->firework1.setTexture(this->fireworkTexture);
	this->firework1.setTextureRect(IntRect(this->col, this->row, 256, 256));
	this->firework1.setOrigin(128, 128);
	this->firework1.setPosition(200, 420);

	this->firework2.setTexture(this->fireworkTexture);
	this->firework2.setTextureRect(IntRect(this->col, this->row, 256, 256));
	this->firework2.setOrigin(128, 128);
	this->firework2.setPosition(800, 260);

	this->firework3.setTexture(this->fireworkTexture);
	this->firework3.setTextureRect(IntRect(this->col, this->row, 256, 256));
	this->firework3.setOrigin(128, 128);
	this->firework3.setPosition(700, 500);
}

void Menu::initVictoryText()
{
	this->font.loadFromFile("RosewoodStd-Regular.otf");
	this->victoryText.setFont(this->font);
	this->victoryText.setCharacterSize(100);
	this->victoryText.setFillColor(Color::White);
	this->victoryText.setOutlineThickness(3);
	this->victoryText.setOutlineColor(Color::Black);
	this->victoryText.setPosition(320, 200);
	this->victoryText.setString("VICTORY!");
}

void Menu::initPage()
{
	this->pageTexture.loadFromFile("images/page.png");
	this->page.setTexture(this->pageTexture);
	this->page.setTextureRect(IntRect(0, this->pageLenght, 700, 600));
	this->page.setOrigin(350, 0);
	this->page.setPosition(540, 50);

	this->framePageTexture.loadFromFile("images/frame_page.png");
	this->framePage.setTexture(this->framePageTexture);
	this->framePage.setOrigin(368, 0);
	this->framePage.setPosition(540, 30);

	this->closeTexture.loadFromFile("images/close_button.png");
	this->close.setTexture(this->closeTexture);
	this->close.setOrigin(221, 221);
	this->close.setPosition(890, 40);
	this->close.setScale(0.1, 0.1);

	this->closeTexturePress.loadFromFile("images/close_button_press.png");
	this->closePress.setTexture(this->closeTexturePress);
	this->closePress.setOrigin(221, 221);
	this->closePress.setPosition(890, 40);
	this->closePress.setScale(0.1, 0.1);
}

Menu::Menu()
{
	this->initVariables();
	this->initButton();
	this->initFirework();
	this->initVictoryText();
	this->initPage();
}

Menu::~Menu()
{
}

const FloatRect Menu::getBoundsPlay() const
{
	return this->playSprite.getGlobalBounds();
}

void Menu::checkMousePlay(Vector2i v)
{
	if (v.x > this->getBoundsPlay().left && v.x <this->getBoundsPlay().left + this->getBoundsPlay().width && v.y > this->getBoundsPlay().top && v.y < this->getBoundsPlay().top + this->getBoundsPlay().height)
		this->isMousePlay = true;
	else this->isMousePlay = false;
}

bool Menu::checkMousePlayClicked(Vector2i v)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (v.x > this->getBoundsPlay().left && v.x <this->getBoundsPlay().left + this->getBoundsPlay().width && v.y > this->getBoundsPlay().top && v.y < this->getBoundsPlay().top + this->getBoundsPlay().height)
		{
			return true;
		}
	}
	return false;
}

const FloatRect Menu::getBoundsQuit() const
{
	return this->quitSprite.getGlobalBounds();
}

void Menu::checkMouseQuit(Vector2i v)
{
	if (v.x > this->getBoundsQuit().left && v.x <this->getBoundsQuit().left + this->getBoundsQuit().width && v.y > this->getBoundsQuit().top && v.y < this->getBoundsQuit().top + this->getBoundsQuit().height)
		this->isMouseQuit = true;
	else this->isMouseQuit = false;
}

bool Menu::checkMouseQuitClicked(Vector2i v)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (v.x > this->getBoundsQuit().left && v.x <this->getBoundsQuit().left + this->getBoundsQuit().width && v.y > this->getBoundsQuit().top && v.y < this->getBoundsQuit().top + this->getBoundsQuit().height)
			return true;
	}
	return false;
}

const FloatRect Menu::getBoundsContinue() const
{
	return this->continueSprite.getGlobalBounds();
}

void Menu::checkMouseContinue(Vector2i v)
{
	if (v.x > this->getBoundsContinue().left && v.x <this->getBoundsContinue().left + this->getBoundsContinue().width && v.y > this->getBoundsContinue().top && v.y < this->getBoundsContinue().top + this->getBoundsContinue().height)
		this->isMouseContinue = true;
	else this->isMouseContinue = false;
}

bool Menu::checkMouseContinueClicked(Vector2i v)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (v.x > this->getBoundsContinue().left && v.x <this->getBoundsContinue().left + this->getBoundsContinue().width && v.y > this->getBoundsContinue().top && v.y < this->getBoundsContinue().top + this->getBoundsContinue().height)
			return true;
	}
	return false;
}

const FloatRect Menu::getBoundsPause() const
{
	return this->pauseSprite.getGlobalBounds();
}

void Menu::checkMousePause(Vector2i v)
{
	if (v.x > this->getBoundsPause().left && v.x <this->getBoundsPause().left + this->getBoundsPause().width && v.y > this->getBoundsPause().top && v.y < this->getBoundsPause().top + this->getBoundsPause().height)
		this->isMousePause = true;
	else this->isMousePause = false;
}

bool Menu::checkMousePauseClicked(Vector2i v)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (v.x > this->getBoundsPause().left && v.x <this->getBoundsPause().left + this->getBoundsPause().width && v.y > this->getBoundsPause().top && v.y < this->getBoundsPause().top + this->getBoundsPause().height)
			return true;
	}
	return false;
}

const FloatRect Menu::getBoundsInstruction() const
{
	return this->instructionSprite.getGlobalBounds();
}

void Menu::checkMouseIntruction(Vector2i v)
{
	if (v.x > this->getBoundsInstruction().left && v.x <this->getBoundsInstruction().left + this->getBoundsInstruction().width && v.y > this->getBoundsInstruction().top && v.y < this->getBoundsInstruction().top + this->getBoundsInstruction().height)
		this->isMouseInstruction = true;
	else this->isMouseInstruction = false;
}

bool Menu::checkMouseInstructionClicked(Vector2i v)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (v.x > this->getBoundsInstruction().left && v.x <this->getBoundsInstruction().left + this->getBoundsInstruction().width && v.y > this->getBoundsInstruction().top && v.y < this->getBoundsInstruction().top + this->getBoundsInstruction().height)
			return true;
	}
	return false;
}

const FloatRect Menu::getBoundsClose() const
{
	return this->close.getGlobalBounds();
}

void Menu::checkMouseClose(Vector2i v)
{
	if (v.x > this->getBoundsClose().left && v.x <this->getBoundsClose().left + this->getBoundsClose().width && v.y > this->getBoundsClose().top && v.y < this->getBoundsClose().top + this->getBoundsClose().height)
		this->isMouseClose = true;
	else this->isMouseClose = false;
}

bool Menu::checkMouseCloseClicked(Vector2i v)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (v.x > this->getBoundsClose().left && v.x <this->getBoundsClose().left + this->getBoundsClose().width && v.y > this->getBoundsClose().top && v.y < this->getBoundsClose().top + this->getBoundsClose().height)
			return true;
	}
	return false;
}

void Menu::updateFirework()
{
	this->col += 256;
	if (this->col>256*5)
	{
		this->col = 0;
		this->row += 256;
		if (this->row > 256 * 4)
		{
			this->row = 0;
		}
	}
	Sleep(100);
	this->firework.setTextureRect(IntRect(this->col, this->row, 256, 256));
	this->firework1.setTextureRect(IntRect(this->col, this->row, 256, 256));
	this->firework2.setTextureRect(IntRect(this->col, this->row, 256, 256));
	this->firework3.setTextureRect(IntRect(this->col, this->row, 256, 256));
}

void Menu::rollPage(Event e)
{
	if (e.type == Event::MouseWheelScrolled)
	{
		this->pageLenght -= e.mouseWheelScroll.delta*3;
		if (this->pageLenght <= 0)
			this->pageLenght = 0;
		if (this->pageLenght >= 900)
			this->pageLenght = 900;
		this->page.setTextureRect(IntRect(0, this->pageLenght, 700, 600));
	}

}

void Menu::renderPlay(RenderTarget& target)
{
	if (isMousePlay)
		target.draw(this->playSpritePress);
	if (!isMousePlay)
		target.draw(this->playSprite);

	if (isMouseQuit)
		target.draw(this->quitSpritePress);
	if (!isMouseQuit)
		target.draw(this->quitSprite);

	target.draw(this->author);
	target.draw(this->gameName);
}

void Menu::renderPause(RenderTarget& target)
{
	if (isMousePause)
		target.draw(this->pauseSpritePress);
	if (!isMousePause)
		target.draw(this->pauseSprite);

	if (isMouseInstruction)
		target.draw(this->instructionSpritePress);
	if (!isMouseInstruction)
		target.draw(this->instructionSprite);
}

void Menu::renderContinue(RenderTarget& target)
{
	if (isMouseContinue)
		target.draw(this->continueSpritePress);
	if (!isMouseContinue)
		target.draw(this->continueSprite);

	if (isMouseQuit)
		target.draw(this->quitSpritePress);
	if (!isMouseQuit)
		target.draw(this->quitSprite);
}

void Menu::renderInstruction(RenderTarget& target)
{
	target.draw(this->page);
	target.draw(this->framePage);
	if (isMouseClose)
		target.draw(this->closePress);
	if (!isMouseClose)
		target.draw(this->close);
}

void Menu::renderVictoryScreen(RenderTarget& target)
{
	target.draw(this->firework);
	target.draw(this->firework1);
	target.draw(this->firework2);
	target.draw(this->firework3);
	target.draw(this->victoryText);
}

