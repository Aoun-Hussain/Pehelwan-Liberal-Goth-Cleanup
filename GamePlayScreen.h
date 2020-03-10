#pragma once
#include "Screen.h"
#include <SDL.h>
#include "Text.h"


class GamePlayScreen:public Screen
{
private:
    Ltexture* barTexture2; //health bar of the player (similar thing can be done with boss)
    Text* words;           //word to be rendered on the screen

public:
    GamePlayScreen(Ltexture*,Ltexture*,Ltexture*);
    void Render(long int&, long int&, SDL_Renderer*);
    virtual ~GamePlayScreen();
};
