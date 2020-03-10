#pragma once

#include "Ltexture.h"
#include "Alphabet.h"

class Text
{
private:
    int x;                //position to be rendered
    int y;
    std::string text;     //each Text class has a string text so it can have alphabets accordingly
    int wordLen;
    int width;            //dimensions and alpha size to pass into alphabet class
    int height;
    int alphaSize;
    Ltexture* sprite;
    Alphabet* alpha;     //pointer of character class(used for creating dynamic array of alphabets)

public:
    Text();
    Text(std::string, Ltexture*, float, float,float);
    ~Text();
    void Render(SDL_Renderer*);               //to draw the word on screen
    int getLength();                          //getter function to get dimensions
    int getWidth();
    void changeText(std::string);             //changes the text of the Word
    void operator = (const Text&);            //operating overloading for assignment operator.
    std::string getText() {return text;}      //used to get text of the word
};
