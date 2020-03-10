#include "TransitionScreen.h"

TransitionScreen::TransitionScreen(Ltexture* bgImage1, Ltexture* bgImage2, Ltexture* bgImage3,
                                    Ltexture* fontSprite) : Screen(fontSprite)
{
    this -> texture1 = bgImage1;
    this -> texture2 = bgImage2;
    this -> texture3 = bgImage3;
    this -> x = 0;
    this -> y = 0;
    word = new Text("Loading",fontSprite,x + 800, y + 50,1);
}

void TransitionScreen::Render(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    //frame and frame1 adding the delays in rendering
    if ((frame - frame1 > 0) && (frame - frame1 < 250))
        texture1 -> RenderTexture( x, y,gRenderer,NULL );

    if ((frame - frame1 > 250) && (frame - frame1 < 500))
        texture2 -> RenderTexture( x, y,gRenderer,NULL );

    if ((frame - frame1 > 500) && (frame - frame1 < 750))
        texture3 -> RenderTexture( x, y,gRenderer,NULL );

    word -> Render(gRenderer);
}

TransitionScreen::~TransitionScreen()
{}


