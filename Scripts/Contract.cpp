#include "Contract.h"

void Contract::initVariables()
{
	this->x_position = 100;
	this->y_position = 0;
	this->isMoving = true;
	this->constructionArea = 52;
	this->isMouse1 = this->isMouse2 = this->isMouse3 = this->isMouse4 = false;
	this->isMouseBack = false;
	this->is1 = this->is2 = this->is3 = this->is4 = false;
	this->isinIcon = false;
}

void Contract::initPosition(std::vector<Vector2f> v)
{
	float randValueX = 10 + (rand() % 21) * 52; //%21
	float randValueY = rand() % 2;
	this->x_position = randValueX;
	if (randValueY == 0)
		this->y_position = 400;
	if (randValueY == 1)
		this->y_position = 600;
}

void Contract::initContract()
{
	this->contractTexture.loadFromFile("images/construction.png");
	this->contract.setTexture(this->contractTexture);
	this->contract.setOrigin(512.f / 2, 512.f / 2);
	this->contract.setPosition(this->x_position, -26);
	this->contract.setScale(0.1,0.1);
}

Vector2f Contract::getConstructPos()
{
	return this->contract.getPosition();
}

void Contract::initText()
{
	this->font.loadFromFile("LCALLIG.TTF");
	this->text.setFont(this->font);
	this->text.setCharacterSize(50);
	this->text.setFillColor(Color::White);
	this->text.setOutlineThickness(1.f);
	this->text.setOutlineColor(Color::Black);
	switch (this->provinceName)
	{
	case(BARIAVUNGTAU):
		this->text.setString("Welcome to Ba Ria - Vung Tau!");
		break;
	case(BENTRE):
		this->text.setString("Welcome to Ben Tre!");
		break;
	case(BINHTHUAN):
		this->text.setString("Welcome to Binh Thuan!");
		break;
	case(CAMAU):
		this->text.setString("Welcome to Ca Mau!");
		break;
	case(CANTHO):
		this->text.setString("Welcome to Can Tho!");
		break;
	case(DANANG):
		this->text.setString("Welcome to Da Nang!");
		break;
	case(DONGTHAP):
		this->text.setString("Welcome to Dong Thap!");
		break;
	case(HAGIANG):
		this->text.setString("Welcome to Ha Giang!");
		break;
	case(HAIDUONG):
		this->text.setString("Welcome to Hai Duong!");
		break;
	case(HAIPHONG):
		this->text.setString("Welcome to Hai Phong!");
		break;
	case(HANOI):
		this->text.setString("Welcome to Ha Noi!");
		break;
	case(HCMCITY):
		this->text.setString("Welcome to Ho Chi Minh City!");
		break;
	case(KIENGIANG):
		this->text.setString("Welcome to Kien Giang!");
		break;
	case(KHANHHOA):
		this->text.setString("Welcome to Khanh Hoa!");
		break;
	case(LAMDONG):
		this->text.setString("Welcome to Lam Dong!");
		break;
	case(LAOCAI):
		this->text.setString("Welcome to Lao Cai!");
		break;
	case(NINHBINH):
		this->text.setString("Welcome to Ninh Binh!");
		break;
	case(NINHTHUAN):
		this->text.setString("Welcome to Ninh Thuan!");
		break;
	case(QUANGNAM):
		this->text.setString("Welcome to Quang Nam!");
		break;
	case(QUANGNINH):
		this->text.setString("Welcome to Quang Ninh!");
		break;
	case(THUATHIENHUE):
		this->text.setString("Welcome to Thua Thien Hue!");
		break;
	}
	this->text.setOrigin(this->text.getGlobalBounds().width / 2, this->text.getGlobalBounds().height / 2);
	this->text.setPosition(540, 50);

	this->introductionText.setFont(this->font);
	this->introductionText.setCharacterSize(30);
	this->introductionText.setFillColor(Color::Black);
	this->introductionText.setPosition(400, 660);
	this->introductionText.setString("PRESS X TO CLOSE!");
}

void Contract::initPictures()
{
	switch (this->provinceName)
	{
	case BARIAVUNGTAU:
		this->port1Tex.loadFromFile("images/bariavungtau/port1.png");
		this->port1PressTex.loadFromFile("images/bariavungtau/port1_press.png");
		this->port2Tex.loadFromFile("images/bariavungtau/port2.png");
		this->port2PressTex.loadFromFile("images/bariavungtau/port2_press.png");
		this->port3Tex.loadFromFile("images/bariavungtau/port3.png");
		this->port3PressTex.loadFromFile("images/bariavungtau/port3_press.png");
		this->port4Tex.loadFromFile("images/bariavungtau/port4.png");
		this->port4PressTex.loadFromFile("images/bariavungtau/port4_press.png");
		break;
	case BENTRE:
		this->port1Tex.loadFromFile("images/bentre/port1.png");
		this->port1PressTex.loadFromFile("images/bentre/port1_press.png");
		this->port2Tex.loadFromFile("images/bentre/port2.png");
		this->port2PressTex.loadFromFile("images/bentre/port2_press.png");
		this->port3Tex.loadFromFile("images/bentre/port3.png");
		this->port3PressTex.loadFromFile("images/bentre/port3_press.png");
		this->port4Tex.loadFromFile("images/bentre/port4.png");
		this->port4PressTex.loadFromFile("images/bentre/port4_press.png");
		break;
	case BINHTHUAN:
		this->port1Tex.loadFromFile("images/binhthuan/port1.png");
		this->port1PressTex.loadFromFile("images/binhthuan/port1_press.png");
		this->port2Tex.loadFromFile("images/binhthuan/port2.png");
		this->port2PressTex.loadFromFile("images/binhthuan/port2_press.png");
		this->port3Tex.loadFromFile("images/binhthuan/port3.png");
		this->port3PressTex.loadFromFile("images/binhthuan/port3_press.png");
		this->port4Tex.loadFromFile("images/binhthuan/port4.png");
		this->port4PressTex.loadFromFile("images/binhthuan/port4_press.png");
		break;
	case CAMAU:
		this->port1Tex.loadFromFile("images/camau/port1.png");
		this->port1PressTex.loadFromFile("images/camau/port1_press.png");
		this->port2Tex.loadFromFile("images/camau/port2.png");
		this->port2PressTex.loadFromFile("images/camau/port2_press.png");
		this->port3Tex.loadFromFile("images/camau/port3.png");
		this->port3PressTex.loadFromFile("images/camau/port3_press.png");
		this->port4Tex.loadFromFile("images/camau/port4.png");
		this->port4PressTex.loadFromFile("images/camau/port4_press.png");
		break;
	case CANTHO:
		this->port1Tex.loadFromFile("images/cantho/port1.png");
		this->port1PressTex.loadFromFile("images/cantho/port1_press.png");
		this->port2Tex.loadFromFile("images/cantho/port2.png");
		this->port2PressTex.loadFromFile("images/cantho/port2_press.png");
		this->port3Tex.loadFromFile("images/cantho/port3.png");
		this->port3PressTex.loadFromFile("images/cantho/port3_press.png");
		this->port4Tex.loadFromFile("images/cantho/port4.png");
		this->port4PressTex.loadFromFile("images/cantho/port4_press.png");
		break;
	case DANANG:
		this->port1Tex.loadFromFile("images/danang/port1.png");
		this->port1PressTex.loadFromFile("images/danang/port1_press.png");
		this->port2Tex.loadFromFile("images/danang/port2.png");
		this->port2PressTex.loadFromFile("images/danang/port2_press.png");
		this->port3Tex.loadFromFile("images/danang/port3.png");
		this->port3PressTex.loadFromFile("images/danang/port3_press.png");
		this->port4Tex.loadFromFile("images/danang/port4.png");
		this->port4PressTex.loadFromFile("images/danang/port4_press.png");
		break;
	case DONGTHAP:
		this->port1Tex.loadFromFile("images/dongthap/port1.png");
		this->port1PressTex.loadFromFile("images/dongthap/port1_press.png");
		this->port2Tex.loadFromFile("images/dongthap/port2.png");
		this->port2PressTex.loadFromFile("images/dongthap/port2_press.png");
		this->port3Tex.loadFromFile("images/dongthap/port3.png");
		this->port3PressTex.loadFromFile("images/dongthap/port3_press.png");
		this->port4Tex.loadFromFile("images/dongthap/port4.png");
		this->port4PressTex.loadFromFile("images/dongthap/port4_press.png");
		break;
	case HAGIANG:
		this->port1Tex.loadFromFile("images/hagiang/port1.png");
		this->port1PressTex.loadFromFile("images/hagiang/port1_press.png");
		this->port2Tex.loadFromFile("images/hagiang/port2.png");
		this->port2PressTex.loadFromFile("images/hagiang/port2_press.png");
		this->port3Tex.loadFromFile("images/hagiang/port3.png");
		this->port3PressTex.loadFromFile("images/hagiang/port3_press.png");
		this->port4Tex.loadFromFile("images/hagiang/port4.png");
		this->port4PressTex.loadFromFile("images/hagiang/port4_press.png");
		break;
	case HAIDUONG:
		this->port1Tex.loadFromFile("images/haiduong/port1.png");
		this->port1PressTex.loadFromFile("images/haiduong/port1_press.png");
		this->port2Tex.loadFromFile("images/haiduong/port2.png");
		this->port2PressTex.loadFromFile("images/haiduong/port2_press.png");
		this->port3Tex.loadFromFile("images/haiduong/port3.png");
		this->port3PressTex.loadFromFile("images/haiduong/port3_press.png");
		this->port4Tex.loadFromFile("images/haiduong/port4.png");
		this->port4PressTex.loadFromFile("images/haiduong/port4_press.png");
		break;
	case HAIPHONG:
		this->port1Tex.loadFromFile("images/haiphong/port1.png");
		this->port1PressTex.loadFromFile("images/haiphong/port1_press.png");
		this->port2Tex.loadFromFile("images/haiphong/port2.png");
		this->port2PressTex.loadFromFile("images/haiphong/port2_press.png");
		this->port3Tex.loadFromFile("images/haiphong/port3.png");
		this->port3PressTex.loadFromFile("images/haiphong/port3_press.png");
		this->port4Tex.loadFromFile("images/haiphong/port4.png");
		this->port4PressTex.loadFromFile("images/haiphong/port4_press.png");
		break;
	case HANOI:
		this->port1Tex.loadFromFile("images/hanoi/port1.png");
		this->port1PressTex.loadFromFile("images/hanoi/port1_press.png");
		this->port2Tex.loadFromFile("images/hanoi/port2.png");
		this->port2PressTex.loadFromFile("images/hanoi/port2_press.png");
		this->port3Tex.loadFromFile("images/hanoi/port3.png");
		this->port3PressTex.loadFromFile("images/hanoi/port3_press.png");
		this->port4Tex.loadFromFile("images/hanoi/port4.png");
		this->port4PressTex.loadFromFile("images/hanoi/port4_press.png");
		break;
	case HCMCITY:
		this->port1Tex.loadFromFile("images/hochiminhcity/port1.png");
		this->port1PressTex.loadFromFile("images/hochiminhcity/port1_press.png");
		this->port2Tex.loadFromFile("images/hochiminhcity/port2.png");
		this->port2PressTex.loadFromFile("images/hochiminhcity/port2_press.png");
		this->port3Tex.loadFromFile("images/hochiminhcity/port3.png");
		this->port3PressTex.loadFromFile("images/hochiminhcity/port3_press.png");
		this->port4Tex.loadFromFile("images/hochiminhcity/port4.png");
		this->port4PressTex.loadFromFile("images/hochiminhcity/port4_press.png");
		break;
	case KIENGIANG:
		this->port1Tex.loadFromFile("images/kiengiang/port1.png");
		this->port1PressTex.loadFromFile("images/kiengiang/port1_press.png");
		this->port2Tex.loadFromFile("images/kiengiang/port2.png");
		this->port2PressTex.loadFromFile("images/kiengiang/port2_press.png");
		this->port3Tex.loadFromFile("images/kiengiang/port3.png");
		this->port3PressTex.loadFromFile("images/kiengiang/port3_press.png");
		this->port4Tex.loadFromFile("images/kiengiang/port4.png");
		this->port4PressTex.loadFromFile("images/kiengiang/port4_press.png");
		break;
	case KHANHHOA:
		this->port1Tex.loadFromFile("images/khanhhoa/port1.png");
		this->port1PressTex.loadFromFile("images/khanhhoa/port1_press.png");
		this->port2Tex.loadFromFile("images/khanhhoa/port2.png");
		this->port2PressTex.loadFromFile("images/khanhhoa/port2_press.png");
		this->port3Tex.loadFromFile("images/khanhhoa/port3.png");
		this->port3PressTex.loadFromFile("images/khanhhoa/port3_press.png");
		this->port4Tex.loadFromFile("images/khanhhoa/port4.png");
		this->port4PressTex.loadFromFile("images/khanhhoa/port4_press.png");
		break;
	case LAMDONG:
		this->port1Tex.loadFromFile("images/lamdong/port1.png");
		this->port1PressTex.loadFromFile("images/lamdong/port1_press.png");
		this->port2Tex.loadFromFile("images/lamdong/port2.png");
		this->port2PressTex.loadFromFile("images/lamdong/port2_press.png");
		this->port3Tex.loadFromFile("images/lamdong/port3.png");
		this->port3PressTex.loadFromFile("images/lamdong/port3_press.png");
		this->port4Tex.loadFromFile("images/lamdong/port4.png");
		this->port4PressTex.loadFromFile("images/lamdong/port4_press.png");
		break;
	case LAOCAI:
		this->port1Tex.loadFromFile("images/laocai/port1.png");
		this->port1PressTex.loadFromFile("images/laocai/port1_press.png");
		this->port2Tex.loadFromFile("images/laocai/port2.png");
		this->port2PressTex.loadFromFile("images/laocai/port2_press.png");
		this->port3Tex.loadFromFile("images/laocai/port3.png");
		this->port3PressTex.loadFromFile("images/laocai/port3_press.png");
		this->port4Tex.loadFromFile("images/laocai/port4.png");
		this->port4PressTex.loadFromFile("images/laocai/port4_press.png");
		break;
	case NINHBINH:
		this->port1Tex.loadFromFile("images/ninhbinh/port1.png");
		this->port1PressTex.loadFromFile("images/ninhbinh/port1_press.png");
		this->port2Tex.loadFromFile("images/ninhbinh/port2.png");
		this->port2PressTex.loadFromFile("images/ninhbinh/port2_press.png");
		this->port3Tex.loadFromFile("images/ninhbinh/port3.png");
		this->port3PressTex.loadFromFile("images/ninhbinh/port3_press.png");
		this->port4Tex.loadFromFile("images/ninhbinh/port4.png");
		this->port4PressTex.loadFromFile("images/ninhbinh/port4_press.png");
		break;
	case NINHTHUAN:
		this->port1Tex.loadFromFile("images/ninhthuan/port1.png");
		this->port1PressTex.loadFromFile("images/ninhthuan/port1_press.png");
		this->port2Tex.loadFromFile("images/ninhthuan/port2.png");
		this->port2PressTex.loadFromFile("images/ninhthuan/port2_press.png");
		this->port3Tex.loadFromFile("images/ninhthuan/port3.png");
		this->port3PressTex.loadFromFile("images/ninhthuan/port3_press.png");
		this->port4Tex.loadFromFile("images/ninhthuan/port4.png");
		this->port4PressTex.loadFromFile("images/ninhthuan/port4_press.png");
		break;
	case QUANGNAM:
		this->port1Tex.loadFromFile("images/quangnam/port1.png");
		this->port1PressTex.loadFromFile("images/quangnam/port1_press.png");
		this->port2Tex.loadFromFile("images/quangnam/port2.png");
		this->port2PressTex.loadFromFile("images/quangnam/port2_press.png");
		this->port3Tex.loadFromFile("images/quangnam/port3.png");
		this->port3PressTex.loadFromFile("images/quangnam/port3_press.png");
		this->port4Tex.loadFromFile("images/quangnam/port4.png");
		this->port4PressTex.loadFromFile("images/quangnam/port4_press.png");
		break;
	case QUANGNINH:
		this->port1Tex.loadFromFile("images/quangninh/port1.png");
		this->port1PressTex.loadFromFile("images/quangninh/port1_press.png");
		this->port2Tex.loadFromFile("images/quangninh/port2.png");
		this->port2PressTex.loadFromFile("images/quangninh/port2_press.png");
		this->port3Tex.loadFromFile("images/quangninh/port3.png");
		this->port3PressTex.loadFromFile("images/quangninh/port3_press.png");
		this->port4Tex.loadFromFile("images/quangninh/port4.png");
		this->port4PressTex.loadFromFile("images/quangninh/port4_press.png");
		break;
	case THUATHIENHUE:
		this->port1Tex.loadFromFile("images/thuathienhue/port1.png");
		this->port1PressTex.loadFromFile("images/thuathienhue/port1_press.png");
		this->port2Tex.loadFromFile("images/thuathienhue/port2.png");
		this->port2PressTex.loadFromFile("images/thuathienhue/port2_press.png");
		this->port3Tex.loadFromFile("images/thuathienhue/port3.png");
		this->port3PressTex.loadFromFile("images/thuathienhue/port3_press.png");
		this->port4Tex.loadFromFile("images/thuathienhue/port4.png");
		this->port4PressTex.loadFromFile("images/thuathienhue/port4_press.png");
		break;
	}


	this->port1.setTexture(this->port1Tex);
	this->port1Press.setTexture(this->port1PressTex);
	this->port2.setTexture(this->port2Tex);
	this->port2Press.setTexture(this->port2PressTex);
	this->port3.setTexture(this->port3Tex);
	this->port3Press.setTexture(this->port3PressTex);
	this->port4.setTexture(this->port4Tex);
	this->port4Press.setTexture(this->port4PressTex);

	this->port1.setPosition(0, 100);
	this->port1Press.setPosition(0, 100);
	this->port2.setPosition(540, 100);
	this->port2Press.setPosition(540, 100);
	this->port3.setPosition(0, 400);
	this->port3Press.setPosition(0, 400);
	this->port4.setPosition(540, 400);
	this->port4Press.setPosition(540, 400);

	this->backTexture.loadFromFile("images/back_button.png");
	this->back.setTexture(this->backTexture);
	this->back.setOrigin(250, 250);
	this->back.setScale(0.1, 0.1);
	this->back.setPosition(40, 50);

	this->backTexturePress.loadFromFile("images/back_button_press.png");
	this->backPress.setTexture(this->backTexturePress);
	this->backPress.setOrigin(250, 250);
	this->backPress.setScale(0.1, 0.1);
	this->backPress.setPosition(40, 50);
}

void Contract::getRandProvince()
{
	int randValue = rand() % 22;
	switch (randValue)
	{
	case 0:
		this->provinceName = province::BARIAVUNGTAU;
		break;
	case 1:
		this->provinceName = province::BENTRE;
		break;
	case 2:
		this->provinceName = province::BINHTHUAN;
		break;
	case 3:
		this->provinceName = province::CAMAU;
		break;
	case 4:
		this->provinceName = province::CANTHO;
		break;
	case 5:
		this->provinceName = province::DANANG;
		break;
	case 6:
		this->provinceName = province::DONGTHAP;
		break;
	case 7:
		this->provinceName = province::HAGIANG;
		break;
	case 8:
		this->provinceName = province::HAIDUONG;
		break;
	case 9:
		this->provinceName = province::HAIPHONG;
		break;
	case 10:
		this->provinceName = province::HANOI;
		break;
	case 11:
		this->provinceName = province::HCMCITY;
		break;
	case 12:
		this->provinceName = province::KIENGIANG;
		break;
	case 13:
		this->provinceName = province::KHANHHOA;
		break;
	case 14:
		this->provinceName = province::LAMDONG;
		break;
	case 15:
		this->provinceName = province::LAOCAI;
		break;
	case 16:
		this->provinceName = province::NINHBINH;
		break;
	case 17:
		this->provinceName = province::NINHTHUAN;
		break;
	case 18:
		this->provinceName = province::QUANGNAM;
		break;
	case 19:
		this->provinceName = province::QUANGNINH;
		break;
	case 20:
		this->provinceName = province::THUATHIENHUE;
		break;
	}
}

void Contract::initChatbox1()
{
	switch (this->provinceName)
	{
	case BARIAVUNGTAU:
		this->chatboxPort1Tex.loadFromFile("images/bariavungtau/chatbox_port1.png");
		break;
	case BENTRE:
		this->chatboxPort1Tex.loadFromFile("images/bentre/chatbox_port1.png");
		break;
	case BINHTHUAN:
		this->chatboxPort1Tex.loadFromFile("images/binhthuan/chatbox_port1.png");
		break;
	case CAMAU:
		this->chatboxPort1Tex.loadFromFile("images/camau/chatbox_port1.png");
		break;
	case CANTHO:
		this->chatboxPort1Tex.loadFromFile("images/cantho/chatbox_port1.png");
		break;
	case DANANG:
		this->chatboxPort1Tex.loadFromFile("images/danang/chatbox_port1.png");
		break;
	case DONGTHAP:
		this->chatboxPort1Tex.loadFromFile("images/dongthap/chatbox_port1.png");
		break;
	case HAGIANG:
		this->chatboxPort1Tex.loadFromFile("images/hagiang/chatbox_port1.png");
		break;
	case HAIDUONG:
		this->chatboxPort1Tex.loadFromFile("images/haiduong/chatbox_port1.png");
		break;
	case HAIPHONG:
		this->chatboxPort1Tex.loadFromFile("images/haiphong/chatbox_port1.png");
		break;
	case HANOI:
		this->chatboxPort1Tex.loadFromFile("images/hanoi/chatbox_port1.png");
		break;
	case HCMCITY:
		this->chatboxPort1Tex.loadFromFile("images/hochiminhcity/chatbox_port1.png");
		break;
	case KIENGIANG:
		this->chatboxPort1Tex.loadFromFile("images/kiengiang/chatbox_port1.png");
		break;
	case KHANHHOA:
		this->chatboxPort1Tex.loadFromFile("images/khanhhoa/chatbox_port1.png");
		break;
	case LAMDONG:
		this->chatboxPort1Tex.loadFromFile("images/lamdong/chatbox_port1.png");
		break;
	case LAOCAI:
		this->chatboxPort1Tex.loadFromFile("images/laocai/chatbox_port1.png");
		break;
	case NINHBINH:
		this->chatboxPort1Tex.loadFromFile("images/ninhbinh/chatbox_port1.png");
		break;
	case NINHTHUAN:
		this->chatboxPort1Tex.loadFromFile("images/ninhthuan/chatbox_port1.png");
		break;
	case QUANGNAM:
		this->chatboxPort1Tex.loadFromFile("images/quangnam/chatbox_port1.png");
		break;
	case QUANGNINH:
		this->chatboxPort1Tex.loadFromFile("images/quangninh/chatbox_port1.png");
		break;
	case THUATHIENHUE:
		this->chatboxPort1Tex.loadFromFile("images/thuathienhue/chatbox_port1.png");
		break;
	}

	this->chatboxPort1.setTexture(this->chatboxPort1Tex);
	this->chatboxPort1.setOrigin(200, 75);
	this->chatboxPort1.setPosition(270, 305);
}

void Contract::initChatbox2()
{
	switch (this->provinceName)
	{
	case BARIAVUNGTAU:
		this->chatboxPort2Tex.loadFromFile("images/bariavungtau/chatbox_port2.png");
		break;
	case BENTRE:
		this->chatboxPort2Tex.loadFromFile("images/bentre/chatbox_port2.png");
		break;
	case BINHTHUAN:
		this->chatboxPort2Tex.loadFromFile("images/binhthuan/chatbox_port2.png");
		break;
	case CAMAU:
		this->chatboxPort2Tex.loadFromFile("images/camau/chatbox_port2.png");
		break;
	case CANTHO:
		this->chatboxPort2Tex.loadFromFile("images/cantho/chatbox_port2.png");
		break;
	case DANANG:
		this->chatboxPort2Tex.loadFromFile("images/danang/chatbox_port2.png");
		break;
	case DONGTHAP:
		this->chatboxPort2Tex.loadFromFile("images/dongthap/chatbox_port2.png");
		break;
	case HAGIANG:
		this->chatboxPort2Tex.loadFromFile("images/hagiang/chatbox_port2.png");
		break;
	case HAIDUONG:
		this->chatboxPort2Tex.loadFromFile("images/haiduong/chatbox_port2.png");
		break;
	case HAIPHONG:
		this->chatboxPort2Tex.loadFromFile("images/haiphong/chatbox_port2.png");
		break;
	case HANOI:
		this->chatboxPort2Tex.loadFromFile("images/hanoi/chatbox_port2.png");
		break;
	case HCMCITY:
		this->chatboxPort2Tex.loadFromFile("images/hochiminhcity/chatbox_port2.png");
		break;
	case KIENGIANG:
		this->chatboxPort2Tex.loadFromFile("images/kiengiang/chatbox_port2.png");
		break;
	case KHANHHOA:
		this->chatboxPort2Tex.loadFromFile("images/khanhhoa/chatbox_port2.png");
		break;
	case LAMDONG:
		this->chatboxPort2Tex.loadFromFile("images/lamdong/chatbox_port2.png");
		break;
	case LAOCAI:
		this->chatboxPort2Tex.loadFromFile("images/laocai/chatbox_port2.png");
		break;
	case NINHBINH:
		this->chatboxPort2Tex.loadFromFile("images/ninhbinh/chatbox_port2.png");
		break;
	case NINHTHUAN:
		this->chatboxPort2Tex.loadFromFile("images/ninhthuan/chatbox_port2.png");
		break;
	case QUANGNAM:
		this->chatboxPort2Tex.loadFromFile("images/quangnam/chatbox_port2.png");
		break;
	case QUANGNINH:
		this->chatboxPort2Tex.loadFromFile("images/quangninh/chatbox_port2.png");
		break;
	case THUATHIENHUE:
		this->chatboxPort2Tex.loadFromFile("images/thuathienhue/chatbox_port2.png");
		break;
	}

	this->chatboxPort2.setTexture(this->chatboxPort2Tex);
	this->chatboxPort2.setOrigin(200, 75);
	this->chatboxPort2.setPosition(810, 305);
}

void Contract::initChatbox3()
{
	switch (this->provinceName)
	{
	case BARIAVUNGTAU:
		this->chatboxPort3Tex.loadFromFile("images/bariavungtau/chatbox_port3.png");
		break;
	case BENTRE:
		this->chatboxPort3Tex.loadFromFile("images/bentre/chatbox_port3.png");
		break;
	case BINHTHUAN:
		this->chatboxPort3Tex.loadFromFile("images/binhthuan/chatbox_port3.png");
		break;
	case CAMAU:
		this->chatboxPort3Tex.loadFromFile("images/camau/chatbox_port3.png");
		break;
	case CANTHO:
		this->chatboxPort3Tex.loadFromFile("images/cantho/chatbox_port3.png");
		break;
	case DANANG:
		this->chatboxPort3Tex.loadFromFile("images/danang/chatbox_port3.png");
		break;
	case DONGTHAP:
		this->chatboxPort3Tex.loadFromFile("images/dongthap/chatbox_port3.png");
		break;
	case HAGIANG:
		this->chatboxPort3Tex.loadFromFile("images/hagiang/chatbox_port3.png");
		break;
	case HAIDUONG:
		this->chatboxPort3Tex.loadFromFile("images/haiduong/chatbox_port3.png");
		break;
	case HAIPHONG:
		this->chatboxPort3Tex.loadFromFile("images/haiphong/chatbox_port3.png");
		break;
	case HANOI:
		this->chatboxPort3Tex.loadFromFile("images/hanoi/chatbox_port3.png");
		break;
	case HCMCITY:
		this->chatboxPort3Tex.loadFromFile("images/hochiminhcity/chatbox_port3.png");
		break;
	case KIENGIANG:
		this->chatboxPort3Tex.loadFromFile("images/kiengiang/chatbox_port3.png");
		break;
	case KHANHHOA:
		this->chatboxPort3Tex.loadFromFile("images/khanhhoa/chatbox_port3.png");
		break;
	case LAMDONG:
		this->chatboxPort3Tex.loadFromFile("images/lamdong/chatbox_port3.png");
		break;
	case LAOCAI:
		this->chatboxPort3Tex.loadFromFile("images/laocai/chatbox_port3.png");
		break;
	case NINHBINH:
		this->chatboxPort3Tex.loadFromFile("images/ninhbinh/chatbox_port3.png");
		break;
	case NINHTHUAN:
		this->chatboxPort3Tex.loadFromFile("images/ninhthuan/chatbox_port3.png");
		break;
	case QUANGNAM:
		this->chatboxPort3Tex.loadFromFile("images/quangnam/chatbox_port3.png");
		break;
	case QUANGNINH:
		this->chatboxPort3Tex.loadFromFile("images/quangninh/chatbox_port3.png");
		break;
	case THUATHIENHUE:
		this->chatboxPort3Tex.loadFromFile("images/thuathienhue/chatbox_port3.png");
		break;
	}

	this->chatboxPort3.setTexture(this->chatboxPort3Tex);
	this->chatboxPort3.setOrigin(200, 75);
	this->chatboxPort3.setPosition(270, 605);
}

void Contract::initChatbox4()
{
	switch (this->provinceName)
	{
	case BARIAVUNGTAU:
		this->chatboxPort4Tex.loadFromFile("images/bariavungtau/chatbox_port4.png");
		break;
	case BENTRE:
		this->chatboxPort4Tex.loadFromFile("images/bentre/chatbox_port4.png");
		break;
	case BINHTHUAN:
		this->chatboxPort4Tex.loadFromFile("images/binhthuan/chatbox_port4.png");
		break;
	case CAMAU:
		this->chatboxPort4Tex.loadFromFile("images/camau/chatbox_port4.png");
		break;
	case CANTHO:
		this->chatboxPort4Tex.loadFromFile("images/cantho/chatbox_port4.png");
		break;
	case DANANG:
		this->chatboxPort4Tex.loadFromFile("images/danang/chatbox_port4.png");
		break;
	case DONGTHAP:
		this->chatboxPort4Tex.loadFromFile("images/dongthap/chatbox_port4.png");
		break;
	case HAGIANG:
		this->chatboxPort4Tex.loadFromFile("images/hagiang/chatbox_port4.png");
		break;
	case HAIDUONG:
		this->chatboxPort4Tex.loadFromFile("images/haiduong/chatbox_port4.png");
		break;
	case HAIPHONG:
		this->chatboxPort4Tex.loadFromFile("images/haiphong/chatbox_port4.png");
		break;
	case HANOI:
		this->chatboxPort4Tex.loadFromFile("images/hanoi/chatbox_port4.png");
		break;
	case HCMCITY:
		this->chatboxPort4Tex.loadFromFile("images/hochiminhcity/chatbox_port4.png");
		break;
	case KIENGIANG:
		this->chatboxPort4Tex.loadFromFile("images/kiengiang/chatbox_port4.png");
		break;
	case KHANHHOA:
		this->chatboxPort4Tex.loadFromFile("images/khanhhoa/chatbox_port4.png");
		break;
	case LAMDONG:
		this->chatboxPort4Tex.loadFromFile("images/lamdong/chatbox_port4.png");
		break;
	case LAOCAI:
		this->chatboxPort4Tex.loadFromFile("images/laocai/chatbox_port4.png");
		break;
	case NINHBINH:
		this->chatboxPort4Tex.loadFromFile("images/ninhbinh/chatbox_port4.png");
		break;
	case NINHTHUAN:
		this->chatboxPort4Tex.loadFromFile("images/ninhthuan/chatbox_port4.png");
		break;
	case QUANGNAM:
		this->chatboxPort4Tex.loadFromFile("images/quangnam/chatbox_port4.png");
		break;
	case QUANGNINH:
		this->chatboxPort4Tex.loadFromFile("images/quangninh/chatbox_port4.png");
		break;
	case THUATHIENHUE:
		this->chatboxPort4Tex.loadFromFile("images/thuathienhue/chatbox_port4.png");
		break;
	}

	this->chatboxPort4.setTexture(this->chatboxPort4Tex);
	this->chatboxPort4.setOrigin(200, 75);
	this->chatboxPort4.setPosition(810, 605);
}

void Contract::initChatbox()
{
	this->initChatbox1();
	this->initChatbox2();
	this->initChatbox3();
	this->initChatbox4();
}


Contract::Contract(std::vector<Vector2f> v)
{
	this->initVariables();
	this->initPosition(v);
	this->initContract();
	this->getRandProvince();
	this->initText();
	this->initPictures();
	this->initChatbox();
}

Contract::~Contract()
{
}

const FloatRect Contract::getBounds() const
{
	return this->contract.getGlobalBounds();
}

void Contract::checkMoving()
{
	if (this->getBounds().top +this->getBounds().height >= this->y_position)
		this->isMoving = false;
}

bool Contract::checkStop()
{
	return this->isMoving;
}

void Contract::move()
{
	this->contract.move(0.f, 1.f);
}

void Contract::initPort1Icon(int n)
{
	switch (n)
	{
	case(BARIAVUNGTAU):
		this->port1IconTex.loadFromFile("images/bariavungtau/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/bariavungtau/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/bariavungtau/introduce1.png");
		break;
	case(BENTRE):
		this->port1IconTex.loadFromFile("images/bentre/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/bentre/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/bentre/introduce1.png");
		break;
	case(BINHTHUAN):
		this->port1IconTex.loadFromFile("images/binhthuan/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/binhthuan/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/binhthuan/introduce1.png");
		break;
	case(CAMAU):
		this->port1IconTex.loadFromFile("images/camau/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/camau/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/camau/introduce1.png");
		break;
	case(CANTHO):
		this->port1IconTex.loadFromFile("images/cantho/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/cantho/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/cantho/introduce1.png");
		break;
	case(DANANG):
		this->port1IconTex.loadFromFile("images/danang/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/danang/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/danang/introduce1.png");
		break;
	case(DONGTHAP):
		this->port1IconTex.loadFromFile("images/dongthap/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/dongthap/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/dongthap/introduce1.png");
		break;
	case(HAGIANG):
		this->port1IconTex.loadFromFile("images/hagiang/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/hagiang/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/hagiang/introduce1.png");
		break;
	case(HAIDUONG):
		this->port1IconTex.loadFromFile("images/haiduong/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/haiduong/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/haiduong/introduce1.png");
		break;
	case(HAIPHONG):
		this->port1IconTex.loadFromFile("images/haiphong/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/haiphong/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/haiphong/introduce1.png");
		break;
	case(HANOI):
		this->port1IconTex.loadFromFile("images/hanoi/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/hanoi/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/hanoi/introduce1.png");
		break;
	case(HCMCITY):
		this->port1IconTex.loadFromFile("images/hochiminhcity/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/hochiminhcity/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/hochiminhcity/introduce1.png");
		break;
	case(KIENGIANG):
		this->port1IconTex.loadFromFile("images/kiengiang/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/kiengiang/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/kiengiang/introduce1.png");
		break;
	case(KHANHHOA):
		this->port1IconTex.loadFromFile("images/khanhhoa/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/khanhhoa/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/khanhhoa/introduce1.png");
		break;
	case(LAMDONG):
		this->port1IconTex.loadFromFile("images/lamdong/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/lamdong/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/lamdong/introduce1.png");
		break;
	case(LAOCAI):
		this->port1IconTex.loadFromFile("images/laocai/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/laocai/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/laocai/introduce1.png");
		break;
	case(NINHBINH):
		this->port1IconTex.loadFromFile("images/ninhbinh/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/ninhbinh/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/ninhbinh/introduce1.png");
		break;
	case(NINHTHUAN):
		this->port1IconTex.loadFromFile("images/ninhthuan/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/ninhthuan/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/ninhthuan/introduce1.png");
		break;
	case(QUANGNAM):
		this->port1IconTex.loadFromFile("images/quangnam/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/quangnam/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/quangnam/introduce1.png");
		break;
	case(QUANGNINH):
		this->port1IconTex.loadFromFile("images/quangninh/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/quangninh/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/quangninh/introduce1.png");
		break;
	case(THUATHIENHUE):
		this->port1IconTex.loadFromFile("images/thuathienhue/port1_icon.png");
		this->chatboxIcon1Tex.loadFromFile("images/thuathienhue/chatbox_icon1.png");
		this->introduction1Texture.loadFromFile("images/thuathienhue/introduce1.png");
		break;
	}

	this->port1Icon.setTexture(this->port1IconTex);
	this->port1Icon.setOrigin(512.f / 2, 512.f / 2);
	this->port1Icon.setScale(0.1, 0.1);

	this->chatboxIcon1.setTexture(this->chatboxIcon1Tex);
	this->chatboxIcon1.setOrigin(1250, 1000);
	this->chatboxIcon1.setScale(0.05, 0.05);

	this->introduction1.setTexture(this->introduction1Texture);
	this->introduction1.setOrigin(3630.f / 2, 4928.f / 2);
	this->introduction1.setScale(0.2, 0.15);
	this->introduction1.setPosition(540, 350);
}

void Contract::initPort2Icon(int n)
{
	switch (n)
	{
	case(BARIAVUNGTAU):
		this->port2IconTex.loadFromFile("images/bariavungtau/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/bariavungtau/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/bariavungtau/introduce2.png");
		break;
	case(BENTRE):
		this->port2IconTex.loadFromFile("images/bentre/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/bentre/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/bentre/introduce2.png");
		break;
	case(BINHTHUAN):
		this->port2IconTex.loadFromFile("images/binhthuan/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/binhthuan/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/binhthuan/introduce2.png");
		break;
	case(CAMAU):
		this->port2IconTex.loadFromFile("images/camau/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/camau/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/camau/introduce2.png");
		break;
	case(CANTHO):
		this->port2IconTex.loadFromFile("images/cantho/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/cantho/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/cantho/introduce2.png");
		break;
	case(DANANG):
		this->port2IconTex.loadFromFile("images/danang/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/danang/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/danang/introduce2.png");
		break;
	case(DONGTHAP):
		this->port2IconTex.loadFromFile("images/dongthap/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/dongthap/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/dongthap/introduce2.png");
		break;
	case(HAGIANG):
		this->port2IconTex.loadFromFile("images/hagiang/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/hagiang/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/hagiang/introduce2.png");
		break;
	case(HAIDUONG):
		this->port2IconTex.loadFromFile("images/haiduong/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/haiduong/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/haiduong/introduce2.png");
		break;
	case(HAIPHONG):
		this->port2IconTex.loadFromFile("images/haiphong/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/haiphong/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/haiphong/introduce2.png");
		break;
	case(HANOI):
		this->port2IconTex.loadFromFile("images/hanoi/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/hanoi/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/hanoi/introduce2.png");
		break;
	case(HCMCITY):
		this->port2IconTex.loadFromFile("images/hochiminhcity/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/hochiminhcity/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/hochiminhcity/introduce2.png");
		break;
	case(KIENGIANG):
		this->port2IconTex.loadFromFile("images/kiengiang/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/kiengiang/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/kiengiang/introduce2.png");
		break;
	case(KHANHHOA):
		this->port2IconTex.loadFromFile("images/khanhhoa/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/khanhhoa/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/khanhhoa/introduce2.png");
		break;
	case(LAMDONG):
		this->port2IconTex.loadFromFile("images/lamdong/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/lamdong/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/lamdong/introduce2.png");
		break;
	case(LAOCAI):
		this->port2IconTex.loadFromFile("images/laocai/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/laocai/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/laocai/introduce2.png");
		break;
	case(NINHBINH):
		this->port2IconTex.loadFromFile("images/ninhbinh/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/ninhbinh/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/ninhbinh/introduce2.png");
		break;
	case(NINHTHUAN):
		this->port2IconTex.loadFromFile("images/ninhthuan/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/ninhthuan/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/ninhthuan/introduce2.png");
		break;
	case(QUANGNAM):
		this->port2IconTex.loadFromFile("images/quangnam/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/quangnam/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/quangnam/introduce2.png");
		break;
	case(QUANGNINH):
		this->port2IconTex.loadFromFile("images/quangninh/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/quangninh/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/quangninh/introduce2.png");
		break;
	case(THUATHIENHUE):
		this->port2IconTex.loadFromFile("images/thuathienhue/port2_icon.png");
		this->chatboxIcon2Tex.loadFromFile("images/thuathienhue/chatbox_icon2.png");
		this->introduction2Texture.loadFromFile("images/thuathienhue/introduce2.png");
		break;
	}
	this->port2Icon.setTexture(this->port2IconTex);
	this->port2Icon.setOrigin(512.f / 2, 512.f / 2);
	this->port2Icon.setScale(0.1, 0.1);

	this->chatboxIcon2.setTexture(this->chatboxIcon2Tex);
	this->chatboxIcon2.setOrigin(1250, 1000);
	this->chatboxIcon2.setScale(0.05, 0.05);

	this->introduction2.setTexture(this->introduction2Texture);
	this->introduction2.setOrigin(3630.f / 2, 4928.f / 2);
	this->introduction2.setScale(0.2, 0.15);
	this->introduction2.setPosition(540, 350);
}

void Contract::initPort3Icon(int n)
{
	switch (n)
	{
	case(BARIAVUNGTAU):
		this->port3IconTex.loadFromFile("images/bariavungtau/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/bariavungtau/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/bariavungtau/introduce3.png");
		break;
	case(BENTRE):
		this->port3IconTex.loadFromFile("images/bentre/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/bentre/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/bentre/introduce3.png");
		break;
	case(BINHTHUAN):
		this->port3IconTex.loadFromFile("images/binhthuan/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/binhthuan/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/binhthuan/introduce3.png");
		break;
	case(CAMAU):
		this->port3IconTex.loadFromFile("images/camau/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/camau/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/camau/introduce3.png");
		break;
	case(CANTHO):
		this->port3IconTex.loadFromFile("images/cantho/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/cantho/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/cantho/introduce3.png");
		break;
	case(DANANG):
		this->port3IconTex.loadFromFile("images/danang/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/danang/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/danang/introduce3.png");
		break;
	case(DONGTHAP):
		this->port3IconTex.loadFromFile("images/dongthap/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/dongthap/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/dongthap/introduce3.png");
		break;
	case(HAGIANG):
		this->port3IconTex.loadFromFile("images/hagiang/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/hagiang/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/hagiang/introduce3.png");
		break;
	case(HAIDUONG):
		this->port3IconTex.loadFromFile("images/haiduong/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/haiduong/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/haiduong/introduce3.png");
		break;
	case(HAIPHONG):
		this->port3IconTex.loadFromFile("images/haiphong/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/haiphong/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/haiphong/introduce3.png");
		break;
	case(HANOI):
		this->port3IconTex.loadFromFile("images/hanoi/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/hanoi/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/hanoi/introduce3.png");
		break;
	case(HCMCITY):
		this->port3IconTex.loadFromFile("images/hochiminhcity/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/hochiminhcity/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/hochiminhcity/introduce3.png");
		break;
	case(KIENGIANG):
		this->port3IconTex.loadFromFile("images/kiengiang/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/kiengiang/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/kiengiang/introduce3.png");
		break;
	case(KHANHHOA):
		this->port3IconTex.loadFromFile("images/khanhhoa/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/khanhhoa/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/khanhhoa/introduce3.png");
		break;
	case(LAMDONG):
		this->port3IconTex.loadFromFile("images/lamdong/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/lamdong/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/lamdong/introduce3.png");
		break;
	case(LAOCAI):
		this->port3IconTex.loadFromFile("images/laocai/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/laocai/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/laocai/introduce3.png");
		break;
	case(NINHBINH):
		this->port3IconTex.loadFromFile("images/ninhbinh/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/ninhbinh/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/ninhbinh/introduce3.png");
		break;
	case(NINHTHUAN):
		this->port3IconTex.loadFromFile("images/ninhthuan/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/ninhthuan/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/ninhthuan/introduce3.png");
		break;
	case(QUANGNAM):
		this->port3IconTex.loadFromFile("images/quangnam/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/quangnam/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/quangnam/introduce3.png");
		break;
	case(QUANGNINH):
		this->port3IconTex.loadFromFile("images/quangninh/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/quangninh/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/quangninh/introduce3.png");
		break;
	case(THUATHIENHUE):
		this->port3IconTex.loadFromFile("images/thuathienhue/port3_icon.png");
		this->chatboxIcon3Tex.loadFromFile("images/thuathienhue/chatbox_icon3.png");
		this->introduction3Texture.loadFromFile("images/thuathienhue/introduce3.png");
		break;
	}
	this->port3Icon.setTexture(this->port3IconTex);
	this->port3Icon.setOrigin(512.f / 2, 512.f / 2);
	this->port3Icon.setScale(0.1, 0.1);

	this->chatboxIcon3.setTexture(this->chatboxIcon3Tex);
	this->chatboxIcon3.setOrigin(1250, 1000);
	this->chatboxIcon3.setScale(0.05, 0.05);

	this->introduction3.setTexture(this->introduction3Texture);
	this->introduction3.setOrigin(3630.f / 2, 4928.f / 2);
	this->introduction3.setScale(0.2, 0.15);
	this->introduction3.setPosition(540, 350);
}

void Contract::initPort4Icon(int n)
{
	switch (n)
	{
	case(BARIAVUNGTAU):
		this->port4IconTex.loadFromFile("images/bariavungtau/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/bariavungtau/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/bariavungtau/introduce4.png");
		break;
	case(BENTRE):
		this->port4IconTex.loadFromFile("images/bentre/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/bentre/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/bentre/introduce4.png");
		break;
	case(BINHTHUAN):
		this->port4IconTex.loadFromFile("images/binhthuan/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/binhthuan/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/binhthuan/introduce4.png");
		break;
	case(CAMAU):
		this->port4IconTex.loadFromFile("images/camau/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/camau/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/camau/introduce4.png");
		break;
	case(CANTHO):
		this->port4IconTex.loadFromFile("images/cantho/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/cantho/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/cantho/introduce4.png");
		break;
	case(DANANG):
		this->port4IconTex.loadFromFile("images/danang/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/danang/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/danang/introduce4.png");
		break;
	case(DONGTHAP):
		this->port4IconTex.loadFromFile("images/dongthap/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/dongthap/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/dongthap/introduce4.png");
		break;
	case(HAGIANG):
		this->port4IconTex.loadFromFile("images/hagiang/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/hagiang/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/hagiang/introduce4.png");
		break;
	case(HAIDUONG):
		this->port4IconTex.loadFromFile("images/haiduong/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/haiduong/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/haiduong/introduce4.png");
		break;
	case(HAIPHONG):
		this->port4IconTex.loadFromFile("images/haiphong/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/haiphong/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/haiphong/introduce4.png");
		break;
	case(HANOI):
		this->port4IconTex.loadFromFile("images/hanoi/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/hanoi/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/hanoi/introduce4.png");
		break;
	case(HCMCITY):
		this->port4IconTex.loadFromFile("images/hochiminhcity/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/hochiminhcity/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/hochiminhcity/introduce4.png");
		break;
	case(KIENGIANG):
		this->port4IconTex.loadFromFile("images/kiengiang/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/kiengiang/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/kiengiang/introduce4.png");
		break;
	case(KHANHHOA):
		this->port4IconTex.loadFromFile("images/khanhhoa/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/khanhhoa/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/khanhhoa/introduce4.png");
		break;
	case(LAMDONG):
		this->port4IconTex.loadFromFile("images/lamdong/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/lamdong/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/lamdong/introduce4.png");
		break;
	case(LAOCAI):
		this->port4IconTex.loadFromFile("images/laocai/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/laocai/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/laocai/introduce4.png");
		break;
	case(NINHBINH):
		this->port4IconTex.loadFromFile("images/ninhbinh/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/ninhbinh/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/ninhbinh/introduce4.png");
		break;
	case(NINHTHUAN):
		this->port4IconTex.loadFromFile("images/ninhthuan/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/ninhthuan/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/ninhthuan/introduce4.png");
		break;
	case(QUANGNAM):
		this->port4IconTex.loadFromFile("images/quangnam/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/quangnam/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/quangnam/introduce4.png");
		break;
	case(QUANGNINH):
		this->port4IconTex.loadFromFile("images/quangninh/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/quangninh/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/quangninh/introduce4.png");
		break;
	case(THUATHIENHUE):
		this->port4IconTex.loadFromFile("images/thuathienhue/port4_icon.png");
		this->chatboxIcon4Tex.loadFromFile("images/thuathienhue/chatbox_icon4.png");
		this->introduction4Texture.loadFromFile("images/thuathienhue/introduce4.png");
		break;
	}
	this->port4Icon.setTexture(this->port4IconTex);
	this->port4Icon.setOrigin(512.f / 2, 512.f / 2);
	this->port4Icon.setScale(0.1, 0.1);

	this->chatboxIcon4.setTexture(this->chatboxIcon4Tex);
	this->chatboxIcon4.setOrigin(1250, 1000);
	this->chatboxIcon4.setScale(0.05, 0.05);

	this->introduction4.setTexture(this->introduction4Texture);
	this->introduction4.setOrigin(3630.f / 2, 4928.f / 2);
	this->introduction4.setScale(0.2, 0.15);
	this->introduction4.setPosition(540, 350);
}

const FloatRect Contract::getBounds1() const
{
	return this->port1.getGlobalBounds();
}

const FloatRect Contract::getBounds2() const
{
	return this->port2.getGlobalBounds();
}

const FloatRect Contract::getBounds3() const
{
	return this->port3.getGlobalBounds();
}

const FloatRect Contract::getBounds4() const
{
	return this->port4.getGlobalBounds();
}

const FloatRect Contract::getBoundsIcon() const
{
	if (is1)
	{
		return this->port1Icon.getGlobalBounds();
	}
if (is2)
	{
		return this->port2Icon.getGlobalBounds();
	}
	if (is3)
	{
		return this->port3Icon.getGlobalBounds();
	}
	if (is4)
	{
		return this->port4Icon.getGlobalBounds();
	}
}

const FloatRect Contract::getBoundsBack() const
{
	return this->back.getGlobalBounds();
}

const FloatRect Contract::getBoundsIcon1() const
{
	return this->port1Icon.getGlobalBounds();
}

const FloatRect Contract::getBoundsIcon2() const
{
	return this->port2Icon.getGlobalBounds();
}

const FloatRect Contract::getBoundsIcon3() const
{
	return this->port3Icon.getGlobalBounds();
}

const FloatRect Contract::getBoundsIcon4() const
{
	return this->port4Icon.getGlobalBounds();
}

void Contract::checkMouse1(Vector2i v)
{
	if (v.x > this->getBounds1().left && v.x<this->getBounds1().left + this->getBounds1().width && v.y > this->getBounds1().top && v.y < this->getBounds1().top + this->getBounds1().height)
	{
		this->isMouse1 = true;
	}
	else
		this->isMouse1 = false;
}

void Contract::checkMouse2(Vector2i v)
{
	if (v.x > this->getBounds2().left && v.x<this->getBounds2().left + this->getBounds2().width && v.y > this->getBounds2().top && v.y < this->getBounds2().top + this->getBounds2().height)
		this->isMouse2 = true;
	else
		this->isMouse2 = false;
}

void Contract::checkMouse3(Vector2i v)
{
	if (v.x > this->getBounds3().left && v.x<this->getBounds3().left + this->getBounds3().width && v.y > this->getBounds3().top && v.y < this->getBounds3().top + this->getBounds3().height)
		this->isMouse3 = true;
	else
		this->isMouse3 = false;
}

void Contract::checkMouse4(Vector2i v)
{
	if (v.x > this->getBounds4().left && v.x<this->getBounds4().left + this->getBounds4().width && v.y > this->getBounds4().top && v.y < this->getBounds4().top + this->getBounds4().height)
		this->isMouse4 = true;
	else
		this->isMouse4 = false;
}

void Contract::checkMouseIcon(Vector2i v)
{
	if (v.x > this->getBoundsIcon().left && v.x<this->getBoundsIcon().left + this->getBoundsIcon().width && v.y > this->getBoundsIcon().top && v.y < this->getBoundsIcon().top + this->getBoundsIcon().height)
		this->isinIcon = true;
	else
		this->isinIcon = false;
}

void Contract::checkMouseBack(Vector2i v)
{
	if (v.x > this->getBoundsBack().left && v.x<this->getBoundsBack().left + this->getBoundsBack().width && v.y > this->getBoundsBack().top && v.y < this->getBoundsBack().top + this->getBoundsBack().height)
		this->isMouseBack = true;
	else
		this->isMouseBack = false;
}

bool Contract::checkClickOption1(Vector2i v)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (v.x > this->getBounds1().left && v.x<this->getBounds1().left + this->getBounds1().width && v.y > this->getBounds1().top && v.y < this->getBounds1().top + this->getBounds1().height)
		{
			return true;
		}
	}
	return false;
}

bool Contract::checkClickOption2(Vector2i v)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (v.x > this->getBounds2().left && v.x<this->getBounds2().left + this->getBounds2().width && v.y > this->getBounds2().top && v.y < this->getBounds2().top + this->getBounds2().height)
		{
			return true;
		}
	}
	return false;
}

bool Contract::checkClickOption3(Vector2i v)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (v.x > this->getBounds3().left && v.x<this->getBounds3().left + this->getBounds3().width && v.y > this->getBounds3().top && v.y < this->getBounds3().top + this->getBounds3().height)
		{
			return true;
		}
	}
	return false;
}

bool Contract::checkClickOption4(Vector2i v)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (v.x > this->getBounds4().left && v.x<this->getBounds4().left + this->getBounds4().width && v.y > this->getBounds4().top && v.y < this->getBounds4().top + this->getBounds4().height)
		{
			return true;
		}
	}
	return false;
}

bool Contract::checkClickBack(Vector2i v)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (v.x > this->getBoundsBack().left && v.x<this->getBoundsBack().left + this->getBoundsBack().width && v.y > this->getBoundsBack().top && v.y < this->getBoundsBack().top + this->getBoundsBack().height)
		{
			return true;
		}
	}
	return false;
}

bool Contract::checkClickIcon1(Vector2i v)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (v.x > this->getBoundsIcon1().left && v.x<this->getBoundsIcon1().left + this->getBoundsIcon1().width && v.y > this->getBoundsIcon1().top && v.y < this->getBoundsIcon1().top + this->getBoundsIcon1().height)
		{
			return true;
		}
	}
	return false;
}

bool Contract::checkClickIcon2(Vector2i v)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (v.x > this->getBoundsIcon2().left && v.x<this->getBoundsIcon2().left + this->getBoundsIcon2().width && v.y > this->getBoundsIcon2().top && v.y < this->getBoundsIcon2().top + this->getBoundsIcon2().height)
		{
			return true;
		}
	}
	return false;

}

bool Contract::checkClickIcon3(Vector2i v)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (v.x > this->getBoundsIcon3().left && v.x<this->getBoundsIcon3().left + this->getBoundsIcon3().width && v.y > this->getBoundsIcon3().top && v.y < this->getBoundsIcon3().top + this->getBoundsIcon3().height)
		{
			return true;
		}
	}
	return false;
}

bool Contract::checkClickIcon4(Vector2i v)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (v.x > this->getBoundsIcon4().left && v.x<this->getBoundsIcon4().left + this->getBoundsIcon4().width && v.y > this->getBoundsIcon4().top && v.y < this->getBoundsIcon4().top + this->getBoundsIcon4().height)
		{
			return true;
		}
	}
	return false;
}

void Contract::setContractPosition(Vector2f v)
{
	this->port1Icon.setPosition(v);
	this->port2Icon.setPosition(v);
	this->port3Icon.setPosition(v);
	this->port4Icon.setPosition(v);
}

void Contract::setChatboxIconPosition(float a, float b)
{
	this->chatboxIcon1.setPosition(a, b);
	this->chatboxIcon2.setPosition(a, b);
	this->chatboxIcon3.setPosition(a, b);
	this->chatboxIcon4.setPosition(a, b);
}

void Contract::update()
{
	this->checkMoving();
	if(isMoving)
		this->move();
}

void Contract::render(RenderTarget& target)
{
	target.draw(this->contract);
}

void Contract::renderContract(RenderTarget& target)
{
	target.draw(this->text);

	if (!this->isMouse1)
		target.draw(this->port1);
	if (this->isMouse1)
	{
		target.draw(this->port1Press);
		target.draw(this->chatboxPort1);
	}

	if (!this->isMouse2)
		target.draw(this->port2);
	if (this->isMouse2)
	{
		target.draw(this->port2Press);
		target.draw(this->chatboxPort2);
	}

	if (!this->isMouse3)
		target.draw(this->port3);
	if (this->isMouse3)
	{
		target.draw(this->port3Press);
		target.draw(this->chatboxPort3);
	}

	if (!this->isMouse4)
		target.draw(this->port4);
	if (this->isMouse4)
	{
		target.draw(this->port4Press);
		target.draw(this->chatboxPort4);
	}

	if (this->isMouseBack)
	{
		target.draw(this->backPress);
	}
	if (!this->isMouseBack)
	{
		target.draw(this->back);
	}
}

void Contract::renderPortIcon(RenderTarget& target)
{
	target.draw(this->port1Icon);
	target.draw(this->port2Icon);
	target.draw(this->port3Icon);
	target.draw(this->port4Icon);
}

void Contract::renderChatboxIcon(RenderTarget& target)
{
	if (isinIcon)
	{
		if (is1)
			target.draw(this->chatboxIcon1);
		if(is2)
			target.draw(this->chatboxIcon2);
		if(is3)
			target.draw(this->chatboxIcon3);
		if(is4)
			target.draw(this->chatboxIcon4);
	}
}

void Contract::renderIntroduction(RenderTarget& target)
{

	target.draw(this->introduction1);
	target.draw(this->introduction2);
	target.draw(this->introduction3);
	target.draw(this->introduction4);
	target.draw(this->introductionText);
}
