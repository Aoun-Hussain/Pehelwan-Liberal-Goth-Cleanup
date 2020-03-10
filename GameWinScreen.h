#pragma once

#include <Screen.h>

class GameWinScreen : public Screen
{
private:
    Text* words;         //word to be rendered on the screen
    Ltexture* texture;
public:
    GameWinScreen(Ltexture*,Ltexture*,Ltexture*);
    void Render(long int& , long int&, SDL_Renderer*);
    virtual ~GameWinScreen();
};


