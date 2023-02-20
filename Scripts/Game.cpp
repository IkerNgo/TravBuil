#include "Game.h"


//Private functions
void Game::initVariables()
{
	this->window = nullptr;
	this->spawnPeopleTimer = 600;
	this->spawnSpecialPeopleTimer = 0;
	this->isPlay = false;
	this->isContinue = false;
	this->isPause = false;
	this->isInstruction = false;
	this->isContact = false;
	this->isContract = false;
	this->spawnContract = false;
	this->isExist = false;
	this->isInitOption = false;
	this->point = 100;
	this->grandPointTimerMax = 200.f;
	this->grantPointTimer = 0;
	this->famous = 7;
	this->garbage = 0;
	this->numberPortrait = 0;
	this->contractDisappearTimerMax = 500.f;
	this->contractDisappearTimer = this->contractDisappearTimerMax;
	this->conditions = false;
	this->additionalPoints = 0;
	this->addPoints = 10;
	this->moneyLose = 0;
	this->foodStall = 0;
	this->famousRate = 0;
	this->addFamousRate = 0;
	this->addGreenRate = 0;
	this->greenRate = 0;
	this->addBusinessmanRate = this->addThiefRate = this->addTouristRate = this-> addLittererRate =0;
	this->isIntroductionOn = false;
	this->winRate = 100;
}

void Game::initWindow()
{
	this->videoMode.height = 700;
	this->videoMode.width = 1080;
	this->window = new RenderWindow(this->videoMode, "Game 1!", Style::Close | Style::Resize | Style::Titlebar);
	this->window->setFramerateLimit(144);
}

void Game::initbackground()
{
	if (!this->backgroundTexture.loadFromFile("images/background.jpg"))
	{
		std::cout << "ERROR::GAME::Failed to load background texture!" << "\n";
	}

	this->backgound.setTexture(this->backgroundTexture);

	this->shadeBackgroundTexture.loadFromFile("images/shadeBackground.png");
	this->shadeBackground.setTexture(this->shadeBackgroundTexture);
}

void Game::initMusic()
{
	this->backgroundMusic.openFromFile("music/background_music.ogg");
	this->backgroundMusic.setVolume(10);
	this->backgroundMusic.setLoop(true);

	this->openMusic.openFromFile("music/Bay-Street-Billionaires-Squadda-B.ogg");
	this->openMusic.setVolume(30);
	this->openMusic.setLoop(true);
	this->openMusic.play();

	this->pauseMusic.openFromFile("music/Calvin-Harris-josh-pan.ogg");
	this->pauseMusic.setVolume(40);
	this->pauseMusic.setLoop(true);

	this->victoryMusic.openFromFile("music/Positive-Fuse-French-Fuse.ogg");
	this->victoryMusic.setVolume(40);
	this->victoryMusic.setLoop(true);

	this->constructionSound.openFromFile("music/mixkit-construction-place-machinery-ambience-803.ogg");
	this->constructionSound.setLoop(true);
	this->constructionSound.setVolume(35);
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initOption()
{
	this->option = new Option(this->addTouristRate,this->addBusinessmanRate, this->addThiefRate, this->addLittererRate);
	this->isInitOption = true;
}

void Game::initStat()
{
	this->stat = new Stats();
}

void Game::initContract()
{
	this->contract = new Contract(this->location);
	for (auto& a : this->location)
	{
		if (this->contract->y_position==a.y + 25 && this->contract->x_position==a.x)
		{
			this->initContract();
			std::cout << "DUPLICATE" << "\n";
		}
	}
	this->isExist = true;
}

void Game::initContractOption()
{
	this->contractOption = new Contract(this->location);
}

void Game::initMenu()
{
	this->menu = new Menu();
}

void Game::reset()
{
	this->initVariables();
	this->isPlay = true;
	this->isContinue = true;
	for (int i = 0; i < allContractOption.size(); i++)
	{
		delete this->allContractOption[i];
	}
	this->allContractOption.clear();
	for (int j = 0; j < people.size(); j++)
	{
		delete this->people[j];
	}
	this->people.clear();
	for (int h = 0; h < speople.size(); h++)
	{
		delete this->speople[h];
	}
	this->speople.clear();
	this->location.clear();
}

void Game::spawnPeople()
{
	this->spawnPeopleTimerMax = rand() % 20 + 100;
	this->spawnPeopleTimer += 0.5f;

	if (this->spawnPeopleTimer >= this->spawnPeopleTimerMax)
	{
		this->people.push_back(new People());
		this->spawnPeopleTimer = 0;
	}
}

void Game::spawnSpecialPeople()
{
	this->spawnSpecialPeopleTimerMax = rand() % 50 + 200;
	this->spawnSpecialPeopleTimer += 0.5f;

	if (this->spawnSpecialPeopleTimer >= this->spawnSpecialPeopleTimerMax)
	{
		this->speople.push_back(new SpecialPeople());
		this->spawnSpecialPeopleTimer = 0;
	}
}

void Game::deletePeople()
{
	for (int i = 0; i < this->people.size(); i++)
	{
		if (this->people[i]->getBounds().left + this->people[i]->getBounds().width < - 71)
		{
			delete this->people[i];
			this->people.erase(this->people.begin() + i);
		}

		else if (this->people[i]->getBounds().left > this->window->getSize().x + 71)
		{
			delete this->people[i];
			this->people.erase(this->people.begin() + i);
		}
	}
}

void Game::deleteSpecialPeople()
{
	for (int i = 0; i < this->speople.size(); i++)
	{
		if (this->speople[i]->getBounds().left + this->speople[i]->getBounds().width < -37)
		{
			delete this->speople[i];
			this->speople.erase(this->speople.begin() + i);
		}

		else if (this->speople[i]->getBounds().left > this->window->getSize().x + 37)
		{
			delete this->speople[i];
			this->speople.erase(this->speople.begin() + i);
		}
	}
}

void Game::checkContact()
{
	for (int i = 0; i < speople.size(); i++)
	{
		if (this->speople[i]->getBounds().intersects(this->player->getBounds()))
		{
			this->isContact = true;
			delete this->speople[i];
			this->speople.erase(this->speople.begin() + i);
		}
	}
}

void Game::contractCollision()
{
	if (this->constructionSound.getStatus() == 0 || this->constructionSound.getStatus() == 1)
		this->constructionSound.play();
	this->contractDisappearTimer += 0.5f;
	if (this->player->getBounds().intersects(this->contract->getBounds()))
	{
		this->constructionSound.stop();
		this->isContract = true;
		this->isContact = false;
		if (isExist)
		{
			delete this->contract;
		}
		this->isExist = false;
		this->initContractOption();
		this->contractDisappearTimer = 0;
	}
	else if (this->contractDisappearTimer >= this->contractDisappearTimerMax)
	{
		this->constructionSound.stop();
		this->isExist = false;
		delete this->contract;
		this->contractDisappearTimer = 0;
	}
}

Vector2i Game::getMousePosition()
{
	return Mouse::getPosition(*this->window);
}

void Game::optionClicked()
{
	if (this->option->checkClickOption(this->getMousePosition()))
	{
		this->isContact = false;
		this->isInitOption = false;

		if (this->option->getType() == TOURIST)
		{
			this->point += 20;
		}
		if (this->option->getType() == THIEF)
		{
			this->famous -= 1;
			this->stat->deleteFamousStar(this->famous);
		}
		if (this->option->getType() == BUSINESSMAN)
		{
			this->spawnContract = true;
			this->isExist = true;
			this->initContract();
		}
		if (this->option->getType() == LITTERER)
		{
			this->garbage += 1;
		}
	}

	if (this->option->checkClickOption2(this->getMousePosition()))
	{
		this->isContact = false;
		this->isInitOption = false;

		if (this->option->getType() == 2)
		{
			if (this->famous >= 7)
				this->famous = 7;
			else
				this->famous += 1;
		}
	}

	if (this->option->checkClickOption3(this->getMousePosition()))
	{
		this->isContact = false;
		this->isInitOption = false;

		if (this->option->getType() == 2)
		{
			if (this->garbage <= 0)
				this->garbage = 0;
			else
			{
				this->stat->deleteGarbage(this->garbage);
				this->garbage -= 1;
			}
		}
	}
}

void Game::contractOptionClicked()
{
	if (this->contractOption->checkClickOption1(this->getMousePosition()))
	{
		switch (this->contractOption->provinceName)
		{
		case BARIAVUNGTAU:
			if (this->point < 40)
			{
				this->conditions = false;
			}
			else if (this->point >= 40)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate += 3;
				this->addGreenRate += 3;
				this->addThiefRate -= 5;
				this->moneyLose = 40;
			}
			break;
		case BENTRE:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->additionalPoints = 2;
				this->addFamousRate += 5;
				this->addGreenRate -= 2;
				this->moneyLose = 30;
			}
			break;
		case BINHTHUAN:
			if (this->point < 40)
			{
				this->conditions = false;
			}
			else if (this->point >= 40)
			{
				this->conditions = true;
				this->additionalPoints = 6;
				this->moneyLose = 40;
			}
			break;
		case CAMAU:
			if (this->point < 35)
			{
				this->conditions = false;
			}
			else if (this->point >= 35)
			{
				this->conditions = true;
				this->additionalPoints = 2;
				this->addFamousRate += 9;
				this->addGreenRate -= 3;
				this->moneyLose = 35;
			}
			break;
		case CANTHO:
			if (this->point < 35)
			{
				this->conditions = false;
			}
			else if (this->point >= 35)
			{
				this->conditions = true;
				this->additionalPoints = 3;
				this->addFamousRate += 6;
				this->addGreenRate -= 3;
				this->addBusinessmanRate += 2;
				this->moneyLose = 35;
			}
			break;
		case DANANG:
			if (this->point < 50)
			{
				this->conditions = false;
			}
			else if (this->point >= 50)
			{
				this->conditions = true;
				this->additionalPoints = 6;
				this->addFamousRate += 5;
				this->addGreenRate -= 3;
				this->moneyLose = 50;
			}
			break;
		case DONGTHAP:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->additionalPoints = 3;
				this->addFamousRate += 5;
				this->addGreenRate -= 1;
				this->moneyLose = 30;
			}
			break;
		case HAGIANG:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->addFamousRate -= 1;
				this->addGreenRate += 15;
				this->moneyLose = 30;
			}
			break;
		case HAIDUONG:
			if (this->point < 20)
			{
				this->conditions = false;
			}
			else if (this->point >= 20)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate -= 1;
				this->addGreenRate += 4;
				this->moneyLose = 20;
			}
			break;
		case HAIPHONG:
			if (this->point < 50)
			{
				this->conditions = false;
			}
			else if (this->point >= 50)
			{
				this->conditions = true;
				this->additionalPoints = 4;
				this->addFamousRate += 5;
				this->addGreenRate -= 2;
				this->addTouristRate += 3;
				this->moneyLose = 50;
			}
			break;
		case HANOI:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->additionalPoints = 3;
				this->addFamousRate -= 1;
				this->addGreenRate += 3;
				this->moneyLose = 30;
			}
			break;
		case HCMCITY:
			if (this->point < 40)
			{
				this->conditions = false;
			}
			else if (this->point >= 40)
			{
				this->conditions = true;
				this->additionalPoints = 4;
				this->addFamousRate += 4;
				this->addGreenRate -= 1;
				this->moneyLose = 40;
			}
			break;
		case KIENGIANG:
			if (this->point < 50)
			{
				this->conditions = false;
			}
			else if (this->point >= 50)
			{
				this->conditions = true;
				this->additionalPoints = 5;
				this->addFamousRate += 6;
				this->addGreenRate -= 3;
				this->moneyLose = 50;
			}
			break;
		case KHANHHOA:
			if (this->point < 55)
			{
				this->conditions = false;
			}
			else if (this->point >= 55)
			{
				this->conditions = true;
				this->additionalPoints = 5;
				this->addFamousRate += 10;
				this->addGreenRate -= 5;
				this->addTouristRate += 1;
				this->moneyLose = 55;
			}
			break;
		case LAMDONG:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->additionalPoints = 2;
				this->addFamousRate += 6;
				this->addGreenRate -= 2;
				this->famous -= 1;
				this->moneyLose = 30;
			}
			break;
		case LAOCAI:
			if (this->point < 40)
			{
				this->conditions = false;
			}
			else if (this->point >= 40)
			{
				this->conditions = true;
				this->additionalPoints = 2;
				this->addFamousRate += 10;
				this->addGreenRate -= 2;
				this->addTouristRate += 5;
				this->moneyLose = 40;
			}
			break;
		case NINHBINH:
			if (this->point < 55)
			{
				this->conditions = false;
			}
			else if (this->point >= 55)
			{
				this->conditions = true;
				this->additionalPoints = 5;
				this->addFamousRate += 10;
				this->addGreenRate -= 2;
				this->moneyLose = 55;
			}
			break;
		case NINHTHUAN:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate -= 3;
				this->addGreenRate += 5;
				this->addTouristRate += 2;
				this->moneyLose = 25;
			}
			break;
		case QUANGNAM:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->additionalPoints = 3;
				this->addFamousRate += 3;
				this->addGreenRate -= 1;
				this->moneyLose = 30;
			}
			break;
		case QUANGNINH:
			if (this->point < 60)
			{
				this->conditions = false;
			}
			else if (this->point >= 60)
			{
				this->conditions = true;
				this->additionalPoints = 5;
				this->addFamousRate += 10;
				this->addGreenRate -= 1;
				this->addTouristRate += 3;
				this->moneyLose = 60;
			}
			break;
		case THUATHIENHUE:
			if (this->point < 50)
			{
				this->conditions = false;
			}
			else if (this->point >= 50)
			{
				this->conditions = true;
				this->additionalPoints = 4;
				this->addFamousRate += (this->famousRate / 10) * 2;
				this->addGreenRate -= 2;
				this->moneyLose = 50;
			}
			break;
		}
		if (this->conditions)
		{
			this->allContractOption.push_back(new Contract(this->location));
			this->allContractOption[this->numberPortrait]->initPort1Icon(this->contractOption->provinceName);
			this->allContractOption[this->numberPortrait]->setContractPosition(this->contractPosition);
			this->allContractOption[this->numberPortrait]->is1 = true;
			this->allContractOption[this->numberPortrait]->setChatboxIconPosition(this->contractPosition.x, this->contractPosition.y);
			this->numberPortrait++;
			//Additions
			this->addPoints += this->additionalPoints;
			this->point -= this->moneyLose;

			this->isContract = false;
			delete this->contractOption;
		}
	}
	if (this->contractOption->checkClickOption2(this->getMousePosition()))
	{
		switch (this->contractOption->provinceName)
		{
		case BARIAVUNGTAU:
			if (this->point < 20)
			{
				this->conditions = false;
			}
			else if (this->point >= 20)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate -= 3;
				this->addGreenRate += 7;
				this->moneyLose = 20;
			}
			break;
		case BENTRE:
			if (this->point < 50)
			{
				this->conditions = false;
			}
			else if (this->point >= 50)
			{
				this->conditions = true;
				this->additionalPoints = 4;
				this->addFamousRate += 4;
				this->addGreenRate -= 4;
				this->moneyLose = 50;
			}
			break;
		case BINHTHUAN:
			if (this->point < 20)
			{
				this->conditions = false;
			}
			else if (this->point >= 20)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate -= 2;
				this->addGreenRate += 5;
				this->moneyLose = 20;
			}
			break;
		case CAMAU:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate -= 5;
				this->addGreenRate += 11;
				this->moneyLose = 30;
			}
			break;
		case CANTHO:
			if (this->point < 15)
			{
				this->conditions = false;
			}
			else if (this->point >= 15)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate += 3;
				this->addGreenRate -= 1;
				this->moneyLose = 15;
			}
			break;
		case DANANG:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->additionalPoints = 2;
				this->addFamousRate += 4;
				this->addGreenRate -= 1;
				this->addTouristRate += 3;
				this->moneyLose = 30;
			}
			break;
		case DONGTHAP:
			if (this->point < 20)
			{
				this->conditions = false;
			}
			else if (this->point >= 20)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate += 3;
				this->addGreenRate += 3;
				this->moneyLose = 20;
			}
			break;
		case HAGIANG:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate += 5;
				this->addGreenRate -= 2;
				this->addThiefRate -= 2;
				this->moneyLose = 25;
			}
			break;
		case HAIDUONG:
			if (this->point < 40)
			{
				this->conditions = false;
			}
			else if (this->point >= 40)
			{
				this->conditions = true;
				if (this->famousRate > 80)
					this->addFamousRate += 20;
				this->moneyLose = 40;
			}
			break;
		case HAIPHONG:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->additionalPoints = 2;
				this->addFamousRate -= 2;
				this->addGreenRate += 6;
				this->moneyLose = 30;
			}
			break;
		case HANOI:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->additionalPoints = 2;
				this->addFamousRate += 5;
				this->addGreenRate -= 1;
				this->moneyLose = 30;
			}
			break;
		case HCMCITY:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->additionalPoints = 3;
				this->addFamousRate += 3;
				this->addGreenRate -= 3;
				this->moneyLose = 30;
			}
			break;
		case KIENGIANG:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate -= 1;
				this->addGreenRate += 8;
				this->moneyLose = 30;
			}
			break;
		case KHANHHOA:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				if (this->famousRate > 55 && this->greenRate > 55)
				{
					this->addFamousRate += 45;
					this->addGreenRate += 45;
				}
				this->moneyLose = 30;
			}
			break;
		case LAMDONG:
			if (this->point < 35)
			{
				this->conditions = false;
			}
			else if (this->point >= 35)
			{
				this->conditions = true;
				this->additionalPoints = 2;
				this->addFamousRate += 4;
				this->addGreenRate += 4;
				this->addTouristRate += 2;
				this->moneyLose = 35;
			}
			break;
		case LAOCAI:
			if (this->point < 20)
			{
				this->conditions = false;
			}
			else if (this->point >= 20)
			{
				this->conditions = true;
				this->addFamousRate += 4;
				this->addGreenRate += 4;
				this->moneyLose = 20;
			}
			break;
		case NINHBINH:
			if (this->point < 35)
			{
				this->conditions = false;
			}
			else if (this->point >= 35)
			{
				this->conditions = true;
				this->additionalPoints = 3;
				this->addFamousRate += 3;
				this->addGreenRate += 3;
				this->moneyLose = 35;
			}
			break;
		case NINHTHUAN:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->additionalPoints = 2;
				this->addFamousRate += 2;
				this->addGreenRate += 2;
				this->moneyLose = 30;
			}
			break;
		case QUANGNAM:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->additionalPoints = 2;
				this->addFamousRate += 7;
				this->addGreenRate -= 2;
				this->moneyLose = 30;
			}
			break;
		case QUANGNINH:
			if (this->point < 10)
			{
				this->conditions = false;
			}
			else if (this->point >= 10)
			{
				this->conditions = true;
				this->addFamousRate -= 3;
				this->addGreenRate += 7;
				this->moneyLose = 10;
			}
			break;
		case THUATHIENHUE:
			if (this->point < 50)
			{
				this->conditions = false;
			}
			else if (this->point >= 50)
			{
				this->conditions = true;
				this->additionalPoints = 4;
				this->addFamousRate -= 2;
				this->addGreenRate += (this->greenRate / 10) * 2;
				this->moneyLose = 50;
			}
			break;
		}
		if (this->conditions)
		{
			this->allContractOption.push_back(new Contract(this->location));
			this->allContractOption[this->numberPortrait]->initPort2Icon(this->contractOption->provinceName);
			this->allContractOption[this->numberPortrait]->setContractPosition(this->contractPosition);
			this->allContractOption[this->numberPortrait]->is2 = true;
			this->allContractOption[this->numberPortrait]->setChatboxIconPosition(this->contractPosition.x, this->contractPosition.y);
			this->numberPortrait++;
			//Additions
			this->addPoints += this->additionalPoints;
			this->point -= this->moneyLose;

			this->isContract = false;
			delete this->contractOption;
		}
	}
	if (this->contractOption->checkClickOption3(this->getMousePosition()))
	{
		switch (this->contractOption->provinceName)
		{
		case BARIAVUNGTAU:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->addFamousRate -= 1;
				this->addGreenRate += 10;
				this->moneyLose = 30;
			}
			break;
		case BENTRE:
			if (this->point < 35)
			{
				this->conditions = false;
			}
			else if (this->point >= 35)
			{
				this->conditions = true;
				this->additionalPoints = 3;
				this->addFamousRate += 2;
				this->addGreenRate -= 2;
				this->addTouristRate += 2;
				this->moneyLose = 35;
			}
			break;
		case BINHTHUAN:
			if (this->point < 10)
			{
				this->conditions = false;
			}
			else if (this->point >= 10)
			{
				this->conditions = true;
				this->addFamousRate -= 1;
				this->addGreenRate += 3;
				this->moneyLose = 10;
			}
			break;
		case CAMAU:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 2;
				this->addFamousRate += 5;
				this->addGreenRate -= 3;
				this->addBusinessmanRate += 2;
				this->moneyLose = 25;
			}
			break;
		case CANTHO:
			if (this->point < 50)
			{
				this->conditions = false;
			}
			else if (this->point >= 50)
			{
				this->conditions = true;
				this->additionalPoints = 5;
				this->addFamousRate += 10;
				this->addGreenRate -= 5;
				this->moneyLose = 50;
			}
			break;
		case DANANG:
			if (this->point < 0)
			{
				this->conditions = false;
			}
			else if (this->point >= 0)
			{
				this->conditions = true;
				this->additionalPoints = -1;
				this->addFamousRate += 1;
				this->addGreenRate += 3;
				this->moneyLose = 0;
			}
			break;
		case DONGTHAP:
			if (this->point < 15)
			{
				this->conditions = false;
			}
			else if (this->point >= 15)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate += 2;
				this->addGreenRate += 2;
				this->moneyLose = 15;
			}
			break;
		case HAGIANG:
			if (this->point < 40)
			{
				this->conditions = false;
			}
			else if (this->point >= 40)
			{
				this->conditions = true;
				this->addFamousRate += 10;
				this->addGreenRate += 10;
				this->moneyLose = 40;
			}
			break;
		case HAIDUONG:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->additionalPoints = 3;
				this->addFamousRate += 3;
				this->addGreenRate -= 2;
				this->moneyLose = 30;
			}
			break;
		case HAIPHONG:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->addFamousRate += 1;
				this->addGreenRate += 1;
				this->famous += (7 - this->famous);
				this->moneyLose = 30;
			}
			break;
		case HANOI:
			if (this->point < 40)
			{
				this->conditions = false;
			}
			else if (this->point >= 40)
			{
				this->conditions = true;
				this->addFamousRate += 8;
				this->addGreenRate -= 2;
				this->addBusinessmanRate += 5;
				this->moneyLose = 40;
			}
			break;
		case HCMCITY:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->addFamousRate += 10;
				this->addGreenRate -= 3;
				this->moneyLose = 30;
			}
			break;
		case KIENGIANG:
			if (this->point < 10)
			{
				this->conditions = false;
			}
			else if (this->point >= 10)
			{
				this->conditions = true;
				this->addFamousRate -= 2;
				this->addGreenRate += 3;
				this->addLittererRate -= 2;
				this->moneyLose = 10;
			}
			break;
		case KHANHHOA:
			if (this->point < 15)
			{
				this->conditions = false;
			}
			else if (this->point >= 15)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate += 4;
				this->addGreenRate -= 2;
				this->moneyLose = 15;
			}
			break;
		case LAMDONG:
			if (this->point < 20)
			{
				this->conditions = false;
			}
			else if (this->point >= 20)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate += 5;
				this->addGreenRate -= 2;
				this->moneyLose = 20;
			}
			break;
		case LAOCAI:
			if (this->point < 40)
			{
				this->conditions = false;
			}
			else if (this->point >= 40)
			{
				this->conditions = true;
				this->additionalPoints = 2;
				this->addFamousRate += (this->allContractOption.size() - this->foodStall);
				this->addGreenRate -= 3;
				this->moneyLose = 40;
			}
			break;
		case NINHBINH:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 2;
				this->addFamousRate += 6;
				this->addGreenRate -= 2;
				this->moneyLose = 25;
			}
			break;
		case NINHTHUAN:
			if (this->point < 5)
			{
				this->conditions = false;
			}
			else if (this->point >= 5)
			{
				this->conditions = true;
				this->addFamousRate -= 4;
				this->addGreenRate += 7;
				this->moneyLose = 5;
			}
			break;
		case QUANGNAM:
			if (this->point < 40)
			{
				this->conditions = false;
			}
			else if (this->point >= 40)
			{
				this->conditions = true;
				this->additionalPoints = 4;
				this->addFamousRate += 4;
				this->addGreenRate -= 1;
				this->moneyLose = 40;
			}
			break;
		case QUANGNINH:
			if (this->point < 15)
			{
				this->conditions = false;
			}
			else if (this->point >= 15)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate -= 1;
				this->addGreenRate += 3;
				this->moneyLose = 15;
			}
			break;
		case THUATHIENHUE:
			if (this->point < 20)
			{
				this->conditions = false;
			}
			else if (this->point >= 20)
			{
				this->conditions = true;
				this->addFamousRate += 4;
				this->addGreenRate += 4;
				this->famous -= 1;
				this->moneyLose = 20;
			}
			break;
		}
		if (this->conditions)
		{
			this->allContractOption.push_back(new Contract(this->location));
			this->allContractOption[this->numberPortrait]->initPort3Icon(this->contractOption->provinceName);
			this->allContractOption[this->numberPortrait]->setContractPosition(this->contractPosition);
			this->allContractOption[this->numberPortrait]->is3 = true;
			this->allContractOption[this->numberPortrait]->setChatboxIconPosition(this->contractPosition.x, this->contractPosition.y);
			this->numberPortrait++;
			//Additions
			this->addPoints += this->additionalPoints;
			this->point -= this->moneyLose;

			this->isContract = false;
			delete this->contractOption;
		}
	}
	if (this->contractOption->checkClickOption4(this->getMousePosition()))
	{
		switch (this->contractOption->provinceName)
		{
		case BARIAVUNGTAU:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate += 2;
				this->addGreenRate += 2;
				this->addLittererRate += 2;
				this->moneyLose = 25;
			}
			break;
		case BENTRE:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate += 2;
				this->addGreenRate += 2;
				this->addLittererRate += 2;
				this->moneyLose = 25;
			}
			break;
		case BINHTHUAN:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 2;
				this->addFamousRate += 2;
				this->addLittererRate += 2;
				this->moneyLose = 25;
			}
			break;
		case CAMAU:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 2;
				this->addFamousRate += 2;
				this->addGreenRate += 2;
				this->moneyLose = 25;
			}
			break;
		case CANTHO:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate += 2;
				this->addGreenRate += 2;
				this->addLittererRate += 2;
				this->moneyLose = 25;
			}
			break;
		case DANANG:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate += 2;
				this->addGreenRate += 2;
				this->addLittererRate += 2;
				this->moneyLose = 25;
			}
			break;
		case DONGTHAP:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate += 2;
				this->addGreenRate += 2;
				this->addLittererRate += 2;
				this->moneyLose = 25;
			}
			break;
		case HAGIANG:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 2;
				this->addFamousRate += 2;
				this->addGreenRate += 2;
				this->moneyLose = 25;
			}
			break;
		case HAIDUONG:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate += 2;
				this->addGreenRate += 2;
				this->addLittererRate += 2;
				this->moneyLose = 25;
			}
			break;
		case HAIPHONG:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate += 2;
				this->addGreenRate += 2;
				this->addLittererRate += 2;
				this->moneyLose = 25;
			}
			break;
		case HANOI:
			if (this->point < 20)
			{
				this->conditions = false;
			}
			else if (this->point >= 20)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate += 1;
				this->addGreenRate += 1;
				this->addLittererRate += 2;
				this->moneyLose = 20;
			}
			break;
		case HCMCITY:
			if (this->point < 20)
			{
				this->conditions = false;
			}
			else if (this->point >= 20)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate += 1;
				this->addGreenRate += 1;
				this->addLittererRate += 2;
				this->moneyLose = 20;
			}
			break;
		case KIENGIANG:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 2;
				this->addFamousRate += 4;
				this->addGreenRate -= 1;
				this->moneyLose = 25;
			}
			break;
		case KHANHHOA:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate += 4;
				this->addGreenRate += 4;
				this->moneyLose = 25;
			}
			break;
		case LAMDONG:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 3;
				this->moneyLose = 25;
			}
			break;

		case LAOCAI:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate += 2;
				this->addGreenRate += 2;
				this->addLittererRate += 2;
				this->moneyLose = 25;
			}
			break;
		case NINHBINH:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->additionalPoints = 3;
				this->addFamousRate += 3;
				this->addGreenRate -= 2;
				this->moneyLose = 30;
			}
			break;
		case NINHTHUAN:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 3;
				this->addLittererRate += 2;
				this->moneyLose = 25;
			}
			break;
		case QUANGNAM:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 2;
				this->addFamousRate += 2;
				this->addGreenRate -= 1;
				this->moneyLose = 25;
			}
			break;
		case QUANGNINH:
			if (this->point < 25)
			{
				this->conditions = false;
			}
			else if (this->point >= 25)
			{
				this->conditions = true;
				this->additionalPoints = 1;
				this->addFamousRate += 2;
				this->addGreenRate += 2;
				this->addLittererRate += 2;
				this->moneyLose = 25;
			}
			break;
		case THUATHIENHUE:
			if (this->point < 30)
			{
				this->conditions = false;
			}
			else if (this->point >= 30)
			{
				this->conditions = true;
				this->additionalPoints = 3;
				this->addFamousRate += 3;
				this->addGreenRate += 3;
				this->moneyLose = 30;
			}
			break;
		}
		if (this->conditions)
		{
			this->allContractOption.push_back(new Contract(this->location));
			this->allContractOption[this->numberPortrait]->initPort4Icon(this->contractOption->provinceName);
			this->allContractOption[this->numberPortrait]->setContractPosition(this->contractPosition);
			this->allContractOption[this->numberPortrait]->is4 = true;
			this->allContractOption[this->numberPortrait]->setChatboxIconPosition(this->contractPosition.x, this->contractPosition.y);
			this->numberPortrait++;
			//Additions
			this->addPoints += this->additionalPoints;
			this->point -= this->moneyLose;
			this->foodStall += 1;

			this->isContract = false;
			delete this->contractOption;
		}
	}

	if (this->contractOption->checkClickBack(this->getMousePosition()))
	{
		this->isContract = false;
		delete this->contractOption;
	}

	if(this->conditions)
		this->location.push_back(contractPosition);
	this->resetAdditions();
}

void Game::resetAdditions()
{
	this->additionalPoints = 0;
	this->moneyLose = 0;
}

void Game::checkMouse()
{
	this->option->checkMouse(this->getMousePosition());
	this->option->checkMouse2(this->getMousePosition());
	this->option->checkMouse3(this->getMousePosition());
}

void Game::checkMouseOption()
{
	this->contractOption->checkMouse1(this->getMousePosition());
	this->contractOption->checkMouse2(this->getMousePosition());
	this->contractOption->checkMouse3(this->getMousePosition());
	this->contractOption->checkMouse4(this->getMousePosition());
	this->contractOption->checkMouseBack(this->getMousePosition());
}

void Game::updatePoint()
{
	this->grantPointTimer += 1;
	if (this->grantPointTimer >= this->grandPointTimerMax * 24)
	{
		this->point += this->addPoints;
		this->grantPointTimer = 0;
	}

	this->famousRate =  this->addFamousRate - (7 - this->famous) * 4;
	if (this->famousRate <= 0)
		this->famousRate = 0;
	if (this->famousRate >= 100)
		this->famousRate = 100;

	this->greenRate = this->addGreenRate - this->garbage * 4;
	if (this->greenRate <= 0)
		this->greenRate = 0;
	if (this->greenRate >= 100)
		this->greenRate = 100;
}


//Contructors & Destructors
Game::Game() 
{
	this->initVariables();
	this->initWindow();
	this->initbackground();
	this->initMusic();
	this->initPlayer();
	this->initStat();
	this->initContract();
	this->initMenu();
}
Game::~Game()
{
	delete this->window;
	delete this->player;
	for (auto* i : this->people)
	{
		delete i;
	}
	for (auto* i : this->speople)
	{
		delete i;
	}
	delete this->option;
	delete this->stat;
	delete this->contractOption;
	for (auto *i : this->allContractOption)
	{
		delete i;
	}
}


//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}


void Game::pollEvent()
{
	while (this->window->pollEvent(this->e))
	{
		switch (this-> e.type)
		{
		case Event::Closed:
			this-> window->close();
			break;
		case Event::KeyPressed:
			if (this->e.key.code == Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::renderbackground()
{
	this->window->draw(this->backgound);
}

void Game::renderShadeBackground()
{
	this->window->draw(this->shadeBackground);
}

void Game::checkMouseMenu()
{
	this->menu->checkMousePlay(this->getMousePosition());
	this->menu->checkMouseQuit(this->getMousePosition());
	this->menu->checkMouseContinue(this->getMousePosition());
}

void Game::checkPlay()
{
	if (this->menu->checkMousePlayClicked(this->getMousePosition()))
	{
		this->isPlay = true;
		this->isContinue = true;
	}
	if (this->menu->checkMouseQuitClicked(this->getMousePosition()))
	{
		this->window->close();
	}
}

void Game::checkContinue()
{
	if (this->menu->checkMouseContinueClicked(this->getMousePosition()))
	{
		this->isContinue = true;
		this->isPause = false;
	}
	if (this->menu->checkMouseQuitClicked(this->getMousePosition()))
	{
		this->window->close();
	}
}

void Game::checkPause()
{
	if (Keyboard::isKeyPressed(Keyboard::P))
	{
		this->isPause = true;
		this->isContinue = false;
	}
	if(this->menu->checkMousePauseClicked(this->getMousePosition()))
	{
		this->isPause = true;
		this->isContinue = false;
	}
	if (this->menu->checkMouseInstructionClicked(this->getMousePosition()))
	{
		this->isInstruction = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::I))
	{
		this->isInstruction = true;
	}
}

void Game::checkCloseInstruction()
{
	if (Keyboard::isKeyPressed(Keyboard::C))
	{
		this->isInstruction = false;
	}
	if (this->menu->checkMouseCloseClicked(this->getMousePosition()))
	{
		this->isInstruction = false;
	}
	this->menu->rollPage(this->e);
	this->menu->checkMouseClose(this->getMousePosition());
}

void Game::checkOpenIntroduction()
{
	for (int i = 0; i < this->allContractOption.size(); i++)
	{
		if (this->allContractOption[i]->checkClickIcon1(this->getMousePosition()))
		{
			this->iconNumber = i;
			this->isIntroductionOn = true;
		}
		if (this->allContractOption[i]->checkClickIcon2(this->getMousePosition()))
		{
			this->iconNumber = i;
			this->isIntroductionOn = true;
		}
		if (this->allContractOption[i]->checkClickIcon3(this->getMousePosition()))
		{
			this->iconNumber = i;
			this->isIntroductionOn = true;
		}
		if (this->allContractOption[i]->checkClickIcon4(this->getMousePosition()))
		{
			this->iconNumber = i;
			this->isIntroductionOn = true;
		}
	}
}

void Game::checkCloseIntroduction()
{
	if (Keyboard::isKeyPressed(Keyboard::X))
	{
		this->isIntroductionOn = false;
	}
}


//Functions
void Game::update()
{
	this->pollEvent();
	if (!this->isPlay)
	{
		this->checkMouseMenu();
		this->checkPlay();
	}
	if (this->isPlay)
	{
		if(this->backgroundMusic.getStatus()==0 || this->backgroundMusic.getStatus() == 1)
			this->backgroundMusic.play();
		this->openMusic.stop();
		this->stat->famousStar(this->famous, this->garbage);
		this->updatePoint();
		this->stat->update(this->famousRate, this->greenRate, this->addPoints);

		if (this->famousRate <= this->winRate)
		{
			this->checkPause();
			if (!this->isContinue)
			{
				this->backgroundMusic.pause();
				if (this->pauseMusic.getStatus() == 0 || this->pauseMusic.getStatus() == 1)
					this->pauseMusic.play();
				this->checkMouseMenu();
				this->checkContinue();
			}

			if (isInstruction)
			{
				this->checkCloseInstruction();
			}

			if (!isContact && !isContract && isContinue && !isInstruction)
			{
				this->pauseMusic.stop();
				this->player->update();
				this->spawnPeople();
				for (auto* i : people)
				{
					i->update();
				}
				this->deletePeople();
				this->spawnSpecialPeople();
				for (auto* i : speople)
				{
					i->update();
				}
				this->stat->updateText(this->point, this->famous);
				this->checkContact();
				this->menu->checkMousePause(this->getMousePosition());
				this->menu->checkMouseIntruction(this->getMousePosition());
				for (auto* a : allContractOption)
				{
					a->checkMouseIcon(this->getMousePosition());
				}
				this->checkOpenIntroduction();
			}

			if (this->isIntroductionOn)
			{
				this->checkCloseIntroduction();
			}

			if (isContact)
			{
				if (!isInitOption)
					this->initOption();

				this->checkMouse();
				this->optionClicked();
			}

			if (spawnContract)
			{
				this->contract->update();
				this->contractPosition = this->contract->getConstructPos();
				this->spawnContract = this->contract->checkStop();
			}
			if (!spawnContract && isExist)
			{
				this->contractCollision();
			}

			if (isContract)
			{
				this->checkMouseOption();
				this->contractOptionClicked();
			}

			this->deleteSpecialPeople();
		}
	}
	if (this->famousRate > this->winRate)
	{
		this->backgroundMusic.stop();
		if (this->victoryMusic.getStatus() == 0 || this->victoryMusic.getStatus() == 1)
		this->victoryMusic.play();
		this->menu->updateFirework();
	}
}


void Game::render()
{
	this->window->clear(Color::Blue);

	this->renderbackground();

	if (!this->isPlay)
	{
		this->renderShadeBackground();
		this->menu->renderPlay(*this->window);
	}

	if (this->isPlay)
	{
		this->menu->renderPause(*this->window);

		for (auto* i : this->allContractOption)
		{
			i->renderPortIcon(*this->window);
		}

		if (isExist)
		{
			this->contract->render(*this->window);
		}

		this->stat->render(*this->window);

		for (auto* i : people)
		{
			i->render(*this->window);
		}

		for (auto* i : speople)
		{
			i->render(*this->window);
		}

		this->player->renderMainChar(*this->window);

		for (auto* a : allContractOption)
		{
			a->renderChatboxIcon(*this->window);
		}

		if (isContact)
		{
			this->renderShadeBackground();
			this->option->render(*this->window);
		}

		if (isContract)
		{
			this->renderShadeBackground();
			this->contractOption->renderContract(*this->window);
		}

		if (this->isPause)
		{
			this->renderShadeBackground();
			this->menu->renderContinue(*this->window);
		}

		if (this->isInstruction)
		{
			this->renderShadeBackground();
			this->menu->renderInstruction(*this->window);
		}

		if (this->isIntroductionOn)
		{
			this->allContractOption[this->iconNumber]->renderIntroduction(*this->window);
		}
	}

	if (this->famousRate > this->winRate)
	{
		this->renderShadeBackground();
		this->menu->renderVictoryScreen(*this->window);
	}

	this->window->display();
}
