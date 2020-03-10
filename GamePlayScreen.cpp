#include "GamePlayScreen.h"

GamePlayScreen::GamePlayScreen(Ltexture* buttonTexture,Ltexture* fontSprite, Ltexture* StatusbarTexture2) : Screen(fontSprite)
{
    lives = 0;
    score = 0;
    ButtonCount = 1;
    buttons = new Button[1]; //assigning buttons (different for every screen)
    buttons[0] = Button (fontSprite, buttonTexture,"PAUSE",130,height - 670);
    this -> barTexture2 = StatusbarTexture2;
    words = new Text[3];
    words[0] = Text("Health", fontSprite,width/2 ,height/2 - 240,0.5);
    words[1] = Text("Score", fontSprite, width/2, height/2 - 300, 0.5);

}

void GamePlayScreen::Render(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    words[2] = Text(to_string(score), fontSprite, width/2 + 175,height/2 - 300, 1);
    buttons[0].Render(gRenderer);
    barTexture2 -> RenderTexture(600,90,gRenderer,NULL);
    words[0].Render(gRenderer);
    SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 0);
    SDL_Rect rect1 = {628,112, lives * 42,34};
    SDL_RenderFillRect(gRenderer,&rect1);
    words[1].Render(gRenderer);
    words[2].Render(gRenderer);
}

GamePlayScreen::~GamePlayScreen()
{
    delete[] words;
}










