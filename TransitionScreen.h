#ifndef TRANSITIONSCREEN_H
#define TRANSITIONSCREEN_H


#include "Screen.h"
#include "Text.h"
#include "Alphabet.h"

class TransitionScreen: public Screen
{
private:
    int x;               //position of the Pause Screen on the whole screen
    int y;
    Ltexture* texture1;
    Ltexture* texture2;
    Ltexture* texture3;
    Text* word;          //word to be rendered on the screen
public:
    TransitionScreen(Ltexture*, Ltexture*, Ltexture*, Ltexture*);
    void Render(long int&, long int&, SDL_Renderer*);
    virtual ~TransitionScreen();
};


#endif // TRANSITIONSCREEN_H
