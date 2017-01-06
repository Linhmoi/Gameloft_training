#include "MenuScene.h"

MenuScene::MenuScene()
{
	this->_background = new Sprite;
	this->_secondBackground = new Sprite;
	this->_gameTitle = new UIElement;
	this->_btnPlay = new UIElement;
	this->_btnHelp = new UIElement;
	this->_btnAbout = new UIElement;
	this->_btnExit = new UIElement;
	this->_index = 2;
}

MenuScene::MenuScene(int w, int h) : Scene(w, h)
{
	this->_background = new Sprite;
	this->_secondBackground = new Sprite;
	this->_gameTitle = new UIElement;
	this->_btnPlay = new UIElement;
	this->_btnHelp = new UIElement;
	this->_btnAbout = new UIElement;
	this->_btnExit = new UIElement;
	this->_index = 2;
}

MenuScene::~MenuScene()
{
	this->Destroy();
}

void MenuScene::Init()
{
	this->_background->LoadTextureFromFile("Resources/Background/SpaceBackground-1.jpg");
	this->_secondBackground->LoadTextureFromFile("Resources/Background/SpaceBackground-1.jpg");
	this->_gameTitle->LoadFont(GAME_TITLE_FONT, GAME_TITLE_FONT_SIZE);
	this->_btnPlay->LoadFont(BTN_TEXT_FONT, BTN_TEXT_FONT_SIZE);
	this->_btnHelp->LoadFont(BTN_TEXT_FONT, BTN_TEXT_FONT_SIZE);
	this->_btnAbout->LoadFont(BTN_TEXT_FONT, BTN_TEXT_FONT_SIZE);
	this->_btnExit->LoadFont(BTN_TEXT_FONT, BTN_TEXT_FONT_SIZE);

	this->_gameTitle->setColor(GAME_TITLE_COLOR);
	this->_btnPlay->setColor(BTN_TEXT_COLOR);
	this->_btnExit->setColor(BTN_TEXT_COLOR);
	this->_btnHelp->setColor(BTN_TEXT_COLOR);
	this->_btnAbout->setColor(BTN_TEXT_COLOR);

	this->_gameTitle->setText("Star Figter");
	this->_btnPlay->setText("Play");
	this->_btnAbout->setText("About");
	this->_btnHelp->setText("Help");
	this->_btnExit->setText("Exit");

	this->_gameTitle->LoadTextureFromFont(UIElement::TextType::Solid);
	this->_btnPlay->LoadTextureFromFont(UIElement::TextType::Solid);
	this->_btnAbout->LoadTextureFromFont(UIElement::TextType::Solid);
	this->_btnHelp->LoadTextureFromFont(UIElement::TextType::Solid);
	this->_btnExit->LoadTextureFromFont(UIElement::TextType::Solid);

	int posX = (this->_screenW / 2) - (GAME_TITLE_W / 2);
	int posY = MARGIN_TOP;

	this->_gameTitle->setPosition(posX, posY);
	this->_btnPlay->setPosition(posX + (GAME_TITLE_W / 2) - (BTN_TEXT_W / 2), posY + GAME_TITLE_H + OFFSET);
	this->_btnHelp->setPosition(posX + (GAME_TITLE_W / 2) - (BTN_TEXT_W / 2), this->_btnPlay->getPosition().y + BTN_TEXT_H + OFFSET);
	this->_btnAbout->setPosition(posX + (GAME_TITLE_W / 2) - (BTN_TEXT_W / 2), this->_btnHelp->getPosition().y + BTN_TEXT_H + OFFSET);
	this->_btnExit->setPosition(posX + (GAME_TITLE_W / 2) - (BTN_TEXT_W / 2), this->_btnAbout->getPosition().y + BTN_TEXT_H + OFFSET);
	this->_background->setPosition(0, 0);
	this->_secondBackground->setPosition(0, -this->_screenH);
}

void MenuScene::Update()
{
	this->ScrollBackground();
}

void MenuScene::Render()
{
	this->_background->Render(this->_screenW, this->_screenH);
	this->_secondBackground->Render(this->_screenW, this->_screenH);
	if (this->isFirstRun)
	{
		this->_secondBackground->Rotate(180);
	}
	this->_gameTitle->Render(GAME_TITLE_W, GAME_TITLE_H);
	this->_btnPlay->Render(BTN_TEXT_W, BTN_TEXT_H);
	this->_btnHelp->Render(BTN_TEXT_W, BTN_TEXT_H);
	this->_btnAbout->Render(BTN_TEXT_W, BTN_TEXT_H);
	this->_btnExit->Render(BTN_TEXT_W, BTN_TEXT_H);
}

void MenuScene::Destroy()
{
	delete this->_background;
	delete this->_secondBackground;
	delete this->_gameTitle;
	delete this->_btnPlay;
	delete this->_btnAbout;
	delete this->_btnExit;
	delete this->_btnHelp;
	delete this->_btnExit;
}

void MenuScene::ScrollBackground()
{
	this->_background->MoveTo(0, this->_screenH, 1);
	this->_secondBackground->MoveTo(0, this->_screenH, 1);

	if (this->_background->getPosition().y >= this->_screenH)
	{
		this->_background->setPosition(0, -this->_screenH);
	}

	if (this->_secondBackground->getPosition().y >= this->_screenH)
	{
		this->_secondBackground->setPosition(0, -this->_screenH);
	}
}

void MenuScene::OnMouseDown()
{

}

void MenuScene::OnMouseOver()
{

}

void MenuScene::OnKeyDown(int key)
{

}