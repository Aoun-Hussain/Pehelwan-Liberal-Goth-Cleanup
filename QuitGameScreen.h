#pragma once
#include "Screen.h"

class QuitGameScreen:public Screen
{
private:
    int x;             //position of Quit Screen on the whole screen
    int y;
    Text* word;        //word to be rendered on the screen
    Ltexture* texture;
public:
    QuitGameScreen(Ltexture*,Ltexture*,Ltexture*);
    void Render(long int& frame, long int&, SDL_Renderer*);
    virtual ~QuitGameScreen();
};
