#pragma once
#include "SDL.h"

#include "Unit.h"


class Bullet : public Unit
{
private:
    int type = 0;  //default type is player bullet
public:
    Bullet(Ltexture* image, float x, float y, int type);
    Bullet();
    virtual ~Bullet();
    virtual void Move();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);

};
