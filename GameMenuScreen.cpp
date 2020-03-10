#include "GameMenuScreen.h"

GameMenuScreen::GameMenuScreen(Ltexture* bgImage, Ltexture* buttonTexture, Ltexture* fontSprite,
                               Ltexture* buttonScreen, Ltexture* menu1, Ltexture* menu2, Ltexture* menu3) : Screen(fontSprite)
{
    this -> texture = bgImage;
    this -> buttonScreen = buttonScreen;
    this -> menuPic1 = menu1;
    this -> menuPic2 = menu2;
    this -> menuPic3 = menu3;
    std::string ButtonText[4]={" NEW GAME ", "LOAD GAME"," CONTROLS ","   EXIT   "}; //Text on the buttons
    float posX = (float) (width / 2);
    float posY = (float) (height / 2);
    ButtonCount = 4;
    buttons = new Button[4];
    for(int i = 0; i < 4; i++) //assigning buttons (different for every screen)
    {
        buttons[i] = Button(fontSprite, buttonTexture, ButtonText[i],posX, posY - 55 );
        posY += 100;
    }
}

void GameMenuScreen::Render(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    texture -> RenderTexture( 0, 0, gRenderer, NULL);
    buttonScreen -> RenderTexture(width / 2 - 200, height / 2 - 95, gRenderer, NULL);
    for(int i = 0; i < ButtonCount; i++)
    {
        buttons[i].Render(gRenderer);
    }
    menuPic1 -> RenderTexture(width / 2 - 370, height / 2 - 345, gRenderer, NULL);//for rendering 3 menu pics on the menu screen
    menuPic2 -> RenderTexture(width / 2 - 120, height / 2 - 345, gRenderer, NULL);
    menuPic3 -> RenderTexture(width / 2 + 130, height / 2 - 345, gRenderer, NULL);
}

GameMenuScreen::~GameMenuScreen()
{}


