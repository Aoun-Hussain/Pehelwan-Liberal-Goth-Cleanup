#include "Button.h"
#include<sstream>
#include "Ltexture.h"

using namespace std;

Button::Button()
{
    width = 0;                   //initializing width, height, state and word of the button.
    height = 0;
    ButtonWidth = 0;
    state = 0;
    word = NULL;
}

Button::Button(Ltexture* textSprite, Ltexture* buttonSprite, string text, float x, float y)
{
    state = Normal;             //initial state of button is always Normal
    this -> x = x;
    this -> y = y;

    this -> textSprite = textSprite;
    this -> buttonSprite = buttonSprite;
    this -> text = text;

    spriteClip[Normal].x = 4;                   //hardcoding enumeration states for screen's mouse motion events
    spriteClip[Normal].y = 271;
    spriteClip[Normal].w = 25;
    spriteClip[Normal].h = 48;
    spriteClip[Hover].x = 4;
    spriteClip[Hover].y = 332;
    spriteClip[Hover].w = 25;
    spriteClip[Hover].h = 48;
    spriteClip[Clicked].x = 2;
    spriteClip[Clicked].y = 393;
    spriteClip[Clicked].w = 25;
    spriteClip[Clicked].h = 48;

    this -> width = spriteClip[0].w;
    this -> height = spriteClip[0].h;
    int textLength = text.size();             //size of the text
    if(textLength % 2 == 0)                   //Button Width is decided on whether text size is even or odd
        textLength = textLength - 1;
    ButtonWidth = width * (textLength + 2);
    word = new Text(text,textSprite,x,y + 8,1);
}

void Button::Render(SDL_Renderer* gRenderer)
{
    int textLength = word -> getLength();
    float posX = x - (25 * ((textLength - 1) / 2) + 13) - 40; //Position for the left part of the button
    spriteClip[state].x = 0;                                  //selects the spriteClip according to Button State
    buttonSprite -> RenderTexture( posX - width / 2, y - height / 2, gRenderer, &spriteClip[state]);

    spriteClip[state].x = 31;        //Middle part of the Button
    int limit;                       //limit of the for loop (below) decided according to text size
    if(textLength % 2 == 0)
    {
        limit = textLength + 1;
    }
    else
    {
        limit = textLength + 2;
    }

    //rendering middle part of the button as a background for each character in the Word
    for(int i = 0; i < limit; i++)
    {
        posX += 25;
        buttonSprite -> RenderTexture( posX - width / 2, y - height / 2, gRenderer, &spriteClip[state]);
    }

    spriteClip[state].x = 71;       //Right part of the Button
    posX = x + (25 * ((textLength - 1) / 2) + 13) + 30;          //position for the right most part of the button
    buttonSprite -> RenderTexture( posX - width / 2, y - height / 2, gRenderer, &spriteClip[state]);
    word -> Render(gRenderer);
}

int Button::getX()
{
    return x;
}

int Button::getY()
{
    return y;
}

int Button::getWidth()
{
    return ButtonWidth;
}

int Button::getHeight()
{
    return height;
}

string Button::getText()
{
    return text;
}

void Button::changeState(State val)
{
    state = val;
}
bool Button::clicked()
{
    return (state == Clicked);
}
Button::~Button()
{
    if (word != NULL)
    {
        delete word;
        word = NULL;
    }
}

void Button::operator = (const Button& cpy)   //operator overloading to make a deep copy of button
{
    state = cpy.state;
    this -> x = cpy.x;
    this -> y = cpy.y;
    buttonSprite = cpy.buttonSprite;
    textSprite = cpy.textSprite;
    text = cpy.text;
    spriteClip[Normal] = cpy.spriteClip[Normal];
    spriteClip[Hover] = cpy.spriteClip[Hover];
    spriteClip[Clicked] = cpy.spriteClip[Clicked];
    width = cpy.width;
    height = cpy.height;
    ButtonWidth = cpy.ButtonWidth;
    this -> word = new Text(text,textSprite,x,y+8,1);
}


