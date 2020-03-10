#include "ResumeGameScreen.h"

ResumeGameScreen::ResumeGameScreen(Ltexture* bgImage, Ltexture* fontSprite, Ltexture* buttonTexture) : Screen(fontSprite)
{
    this -> texture = bgImage;
    std::string ButtonText[2]={"RESUME GAME", " EXIT GAME "}; //Text on the buttons
    float posX = (float) (width / 2);
    float posY = (float) (height / 2);
    ButtonCount = 2;
    buttons = new Button[4];
    for(int i = 0; i < 2; i++) //assigning buttons (different for every screen)
    {
        buttons[i] = Button(fontSprite, buttonTexture, ButtonText[i],posX, posY - 100 );
        posY += 100;
    }
}

void ResumeGameScreen::Render(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    texture -> RenderTexture( 0, 0, gRenderer, NULL);
    for(int i = 0; i < ButtonCount; i++) //rendering buttons
    {
        buttons[i].Render(gRenderer);
    }
}

ResumeGameScreen::~ResumeGameScreen()
{}





