#ifndef STORYSCREEN_H
#define STORYSCREEN_H

#include "Text.h"
#include "Alphabet.h"
#include "Screen.h"

class StoryScreen: public Screen
{
private:
    int x;               //position of the Pause Screen on the whole screen
    int y;
    Ltexture* texture1;
    Ltexture* texture2;
    Ltexture* texture3;
    Ltexture* texture4;
    Ltexture* texture5;
    Text* word;         //word to be rendered on the screen
public:
    StoryScreen(Ltexture*, Ltexture*, Ltexture*, Ltexture*, Ltexture*, Ltexture*);
    void Render(long int&,long int&, SDL_Renderer*);
    virtual ~StoryScreen();
};

#endif // STORYSCREEN_H
