#pragma once
#include "Screen.h"

class ResumeGameScreen:public Screen
{
private:
    Ltexture* texture;
public:
    ResumeGameScreen(Ltexture*,Ltexture*,Ltexture*);
    virtual void Render(long int&, long int&, SDL_Renderer*);
    virtual ~ResumeGameScreen();
};
