#include"Alphabet.h"
#include<iostream>
#include"Ltexture.h"

Alphabet::Alphabet()                  //empty default constructor for composition of Alphabet in other classes
{}

Alphabet::~Alphabet()                 //no need of deleting dynamic memory here
{}

Alphabet::Alphabet(Ltexture* sprite, float x, float y, int ascii, float alphaSize)
{
    this -> alphaSize = alphaSize;
    this -> sprite = sprite;
    spriteClip.w = 42;
    spriteClip.h = 28;

    int diff = 0;

    //selects the Character image according to its ascii value
    if (ascii == 32)
    {
        spriteClip.x=168;
        spriteClip.y=256;
        spriteClip.w=10;
    }
    else if( ascii == 33)
    {
        spriteClip.x=294;
        spriteClip.y=224;
    }
    else if(ascii >= 48 && ascii <= 57)
    {
        character_value = 48;
        spriteClip.x = 168;
        spriteClip.y = 192;

        diff = ascii - character_value;
        if (diff > 3)
        {
            spriteClip.x = 0;
            spriteClip.y += 33;
            character_value += 4;
            diff = ascii - character_value;
        }
        spriteClip.x += 42 * diff;
    }
    else if(ascii == 63)
    {
        spriteClip.x=252;
        spriteClip.y=224;
    }
    else if(( ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122))
    {
        if((ascii >= 97) && (ascii <= 122))
            ascii -= 32;
        character_value = 65;
        spriteClip.x = 0;
        spriteClip.y = 0;
        diff = ascii - character_value;
        spriteClip.y += 32 * (diff / 8);
        character_value += 8 * (diff / 8);
        diff = ascii - character_value;
        spriteClip.x += 42 * diff;
    }

    character_value = ascii;

    this -> x = x;
    this -> y = y;

    this -> width = spriteClip.w;
    this -> height = spriteClip.h;
}

void Alphabet::Render( SDL_Renderer* gRenderer)
{
    sprite -> RenderTexture(x - width/2, y - height/2, gRenderer, &spriteClip,SDL_FLIP_NONE,0,NULL,alphaSize);
}

void Alphabet::operator = (const Alphabet& alph)
{
    this -> x = alph.x;                          //this is the same as c++'s default assignment operator does.
    this -> y = alph.y;
    this -> spriteClip = alph.spriteClip;
    this -> alphaSize = alph.alphaSize;
    this -> sprite = alph.sprite;
    this -> character_value = alph.character_value;
    this -> width = alph.width;
    this -> height = alph.height;
}
