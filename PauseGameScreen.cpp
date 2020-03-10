#include"PauseGameScreen.h"

PauseGameScreen::PauseGameScreen(Ltexture* bgImage, Ltexture* buttonTexture, Ltexture* fontSprite) : Screen(fontSprite)
{
    this -> texture = bgImage;
    this -> x = 0;
    this -> y = 0;
    ButtonCount = 3;
    buttons = new Button[3];
    std::string ButtonText[3] = {" RESUME ","RESTART","  QUIT  "};        //text on buttons
    int posX = width/2;
    int posY = (height/2)- 115;
    for(int i=0; i<3; i++) //assigning buttons (different for every screen)
    {
        buttons[i] = Button(fontSprite,buttonTexture,ButtonText[i],posX, posY);
        posY += 100;
    }
}

void PauseGameScreen::Render(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    texture -> RenderTexture( x, y,gRenderer,NULL );
    for(int i=0; i<ButtonCount; i++)
    {
        buttons[i].Render(gRenderer);
    }
}

PauseGameScreen::~PauseGameScreen()
{}




