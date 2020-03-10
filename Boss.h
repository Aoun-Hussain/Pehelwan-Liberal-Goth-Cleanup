#ifndef BOSS_H
#define BOSS_H
#include "Unit.h"
#include "Player.h"


class Boss : public Unit
{
private:
    Unit* player;   //to follow player position
public:
    Boss(Ltexture* image, float x, float y,Unit*);
    Boss();
    virtual ~Boss();
    virtual void Move();
    void followPlayer();   //follows x,y pos of player
    virtual void Render(long int&, SDL_Renderer*);

};

#endif // BOSS_H
