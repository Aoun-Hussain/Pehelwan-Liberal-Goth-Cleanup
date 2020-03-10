#pragma once
#include "Screen.h"

class IntroScreen : public Screen
{
private:
    Ltexture* texture;
public:
    IntroScreen(Ltexture*,Ltexture*);
    void Render(long int&, long int&,SDL_Renderer*);
    virtual ~IntroScreen();
};
