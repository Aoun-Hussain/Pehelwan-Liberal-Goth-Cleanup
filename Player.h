#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "Unit.h"

class Player : public Unit
{
private:
    static Player* instance;                               //static unique instance of the player
    Player(Ltexture*, float, float);
public:
    static void destroy_Instance();
    static Player* get_instance(Ltexture*, float, float);  //using singleton factory design for player
    virtual ~Player();
    virtual void Move(int direction);                      //moves in the particular direction
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};





#endif // PLAYER_H
