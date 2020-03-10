#include "Text.h"

using namespace std;

Text::Text()
{
    width = 0;      //initializing member variables of text class
    height = 0;
    text = "\0";    //assigning null terminator string
    wordLen = 0;
    alpha = NULL;
}

Text::Text(string text, Ltexture* image, float x, float y, float alphaSize)
{
    this -> alphaSize = alphaSize;
    this -> sprite = image;
    width = 0;
    height = 40;
    wordLen = text.size();
    this -> text = text;
    alpha = new Alphabet[wordLen]; //create a dynamic array of characters
    this -> x = x;
    this -> y = y;
    float posX = x - 16 * (wordLen - 1);
    for(int i = 0; i < wordLen; i++)
    {
        alpha[i] = Alphabet(sprite, posX + width, y, (int)text[i],alphaSize); //make charaters and store that in dynamic array
        width += 32;
    }
}
void Text::Render(SDL_Renderer* gRenderer)
{
    for(int i = 0; i < wordLen; i++)
    {
        alpha[i].Render(gRenderer);
    }
}

int Text::getLength()
{
    return wordLen;
}

Text::~Text()
{
    if ( alpha != NULL)
    {
        delete[] alpha; //deallocating dynamic array
        alpha = NULL;
    }
}

int Text::getWidth()
{
    return width;
}

void Text::changeText(std::string text)
{
    this -> text = text;
    width = 0;
    height = 40;
    wordLen = text.size();
    delete alpha;                   //to deallocate the previous character array
    alpha = new Alphabet[wordLen]; //create new now
    float posX = x - 16 * (wordLen - 1);
    for(int i = 0; i < wordLen; i++)
    {
        alpha[i] = Alphabet(sprite,posX + width, y, (int)text[i],alphaSize); //make charaters and store that in dynamic array
        width += 32;
    }
}
void Text::operator = (const Text& cpy)
{
    this -> x = cpy.x;
    this -> y = cpy.y;
    this -> sprite = cpy.sprite;
    this -> text = cpy.text;
    this -> wordLen = cpy.wordLen;
    this -> alphaSize = cpy.alphaSize;
    delete alpha;                       //delete previous character array
    alpha = new Alphabet[wordLen];      //make new
    for(int i = 0;i < wordLen; i++)
    {
        alpha[i] = cpy.alpha[i];
    }
    this->width = cpy.width;
    this->height = cpy.height;
}


