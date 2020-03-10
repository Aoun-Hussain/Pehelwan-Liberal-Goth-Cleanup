#pragma once
#include "Screen.h"

class GameMenuScreen:public Screen
{
private:
    Ltexture* buttonScreen; //the small screen over which buttons are drawn
    Ltexture* menuPic1;
    Ltexture* menuPic2;
    Ltexture* menuPic3;
    Ltexture* texture;
public:
    GameMenuScreen(Ltexture*,Ltexture*,Ltexture*,Ltexture*,Ltexture*,Ltexture*,Ltexture*);
    void Render(long int&, long int&, SDL_Renderer*);
    virtual ~GameMenuScreen();
};
