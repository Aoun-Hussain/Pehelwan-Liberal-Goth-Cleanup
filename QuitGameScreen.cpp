#include "QuitGameScreen.h"

QuitGameScreen::QuitGameScreen(Ltexture* bgImage,Ltexture* buttonTexture,Ltexture* fontSprite) : Screen(fontSprite)
{
    this -> texture = bgImage;
    x = 0;
    y = 0;
    ButtonCount = 3;
    buttons = new Button[3];
    std::string ButtonText[3] = {" YES ","  NO  ","CANCEL"}; //text on buttons
    int posX = width / 2 ;
    int posY = y + 120;
    for(int i = 0; i < 3; i++) //assigning buttons (different for every screen)
    {
        buttons[i] = Button(fontSprite,buttonTexture,ButtonText[i],posX, posY + 145);
        posY += 80;
    }
    word = new Text("Save Game?",fontSprite, posX , y + 150 ,1);

}

void QuitGameScreen::Render(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    texture -> RenderTexture( 0, 0,gRenderer,NULL );
    for(int i = 0; i < ButtonCount; i++)
    {
        buttons[i].Render(gRenderer);
    }
    word->Render(gRenderer);
}

QuitGameScreen::~QuitGameScreen()
{}






