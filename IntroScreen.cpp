#include"IntroScreen.h"

IntroScreen::IntroScreen(Ltexture* bgImage, Ltexture* fontSprite) : Screen(fontSprite)
{
    this -> texture = bgImage;
}

void IntroScreen::Render(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    texture -> RenderTexture( 0, 0,gRenderer,NULL );
}

IntroScreen::~IntroScreen()
{}




