#pragma once
#include "Ltexture.h"
#include "Button.h"
#include <SDL_mixer.h>

class Screen
{
protected:
    Ltexture* fontSprite;      //image consisting of fonts, and buttons
    int ButtonCount = 0;       //no. of Buttons to be rendered
    Button* buttons = NULL;    //pointer of Button class(either kept null or used to create dynamic array of buttons)
    const int width =  1024;
    const int height = 700;
    int lives;                 //for game play screen to render fill rects for health bars of player and boss
    int score;                 //for player score on game play screen
public:
    virtual void Render(long int&, long int&, SDL_Renderer*) = 0;  //Render the Screen
    Screen(Ltexture* fontSprite);
    virtual ~Screen();
    virtual Button* getButtons();    //returns array of buttons
    virtual int getButtonCount();   //return the no. of buttons to be rendered
    virtual void ChangeButtonState(State, int); //changes the state of Button on the index
    virtual void mouseMotionEvents(int, int); //used to handle mouse motion events on a screen
    virtual void mouseClickEvents(int, int, Mix_Chunk*); //used to handle mouse click events on a screen
    void setLives(int);       //for game play screen and health bars
    void setScore(int);       //for player score
};
