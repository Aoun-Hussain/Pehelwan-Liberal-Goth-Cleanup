#include "GameOverScreen.h"

GameOverScreen::GameOverScreen(Ltexture* bgImage,Ltexture* buttonTexture, Ltexture* fontSprite) : Screen(fontSprite)
{
    this->texture = bgImage;
    std::string ButtonText[3]={"MAIN MENU", "PLAY AGAIN","  EXIT  "};          ///Text on the buttons
    float posX=(float)width/2 + (float)width/4 - 250;
    float posY=((float)height/2 - 100);
    ButtonCount = 3;
    buttons = new Button[3];
    for(int i=0; i<3; i++) //assigning buttons (different for every screen)
    {
        buttons[i] = Button(fontSprite, buttonTexture, ButtonText[i],posX, posY + 100);
        posY+=100;
    }
    words = new Text[1];
    std::string text = "Game Over";
    words[0] = Text(text,fontSprite,width/2 ,height/2 - 100,1);  //through operator overloading
}

void GameOverScreen::Render(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    texture -> RenderTexture( 0, 0,gRenderer, NULL);
    for(int i = 0; i < ButtonCount; i++)
    {
        buttons[i].Render(gRenderer);
    }
    words[0].Render(gRenderer);
}

GameOverScreen::~GameOverScreen()
{
    delete[] words;
}




