#pragma once
#include "Ltexture.h"
#include "Text.h"

enum State{Normal, Hover, Clicked};                //Enumerating three states of buttons

class Button
{
    int width;                   //width of each of the three parts of the button
    int ButtonWidth;             //final width of the Button
    int height;                  //height of the Button
    std::string text;            //Text on the button
    Text* word;                  //object of word class to be rendered over the button
    SDL_Rect spriteClip[3];      //sprite clips for each state of the button
    Ltexture* textSprite;        //Texture of image consisting of Buttons
    Ltexture* buttonSprite;
    int x;                       //Position of the Button
    int y;
    int state;                   //current state of the Button

public:
    Button();
    Button(Ltexture*,Ltexture*,std::string, float, float);
    void Render(SDL_Renderer*);         //render the button using Ltexture class
    ~Button();
    int getX();                         //getters for dimensions and positions
    int getY();
    int getWidth();
    int getHeight();
    std::string getText();               //get the text of the button
    void changeState(State);             //changes the current state of the button
    void operator = (const Button& cpy); //operator overloading for assignment operator
    bool clicked();                      //tells whether button is clicked or not
};
