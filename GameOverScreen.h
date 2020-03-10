#include <Screen.h>
#pragma once

class GameOverScreen : public Screen
{
private:
    Text* words;
    Ltexture* texture;   //word to be rendered on the screen
public:
    GameOverScreen(Ltexture*,Ltexture*,Ltexture*);
    void Render(long int& , long int&, SDL_Renderer*);
    virtual ~GameOverScreen();
};

