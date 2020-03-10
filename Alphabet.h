#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"Ltexture.h"


class Alphabet
{
private:
    int x;                    //position of the alphabet
    int y;
    int character_value = 0;  //ascii value of the character to read from the sprite sheet
    int width;                //dimensions of sprite
    int height;
    SDL_Rect spriteClip;      //clip to cut the sprite sheet
    Ltexture* sprite;
    float alphaSize;          //size of sprite
public:
    Alphabet();
    Alphabet(Ltexture* , float , float , int ,float );
    ~Alphabet();
    void Render(SDL_Renderer*);
    void operator = (const Alphabet&); //operator overloading for assignment operatot
};

