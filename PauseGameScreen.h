#pragma once
#include "Screen.h"

class PauseGameScreen: public Screen
{
private:
    int x; ///position of the Pause Screen on the whole screen
    int y;
    Ltexture* texture;
public:
    PauseGameScreen(Ltexture*, Ltexture*, Ltexture*);
    virtual void Render(long int& frame, long int& frame1, SDL_Renderer*);
    virtual ~PauseGameScreen();
};
