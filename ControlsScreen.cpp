#include "ControlsScreen.h"

ControlsScreen::ControlsScreen(Ltexture* background,Ltexture* buttonTexture, Ltexture* fontSprite) : Screen(fontSprite)
{
    this -> texture = background;
    ButtonCount = 1;
    buttons = new Button[1];
    buttons[0] = Button (fontSprite, buttonTexture,"EXIT",130,height - 670); //assigning buttons (different for every screen)
}

void ControlsScreen::Render(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    texture -> RenderTexture(0,0,gRenderer,NULL);
    buttons[0].Render(gRenderer);
}

ControlsScreen::~ControlsScreen()
{}





