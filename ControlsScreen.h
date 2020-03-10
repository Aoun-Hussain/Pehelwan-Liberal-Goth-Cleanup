#pragma once
#include "Screen.h"
#include <SDL.h>


class ControlsScreen:public Screen
{
private:
    Ltexture* texture;
public:
    ControlsScreen(Ltexture*,Ltexture*,Ltexture*);
    virtual void Render(long int& frame, long int& frame1, SDL_Renderer*);
    virtual ~ControlsScreen();
};

