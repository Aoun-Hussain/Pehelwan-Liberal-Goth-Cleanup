#include "Boss.h"

Boss::Boss()
{}


Boss::~Boss()
{}

Boss::Boss(Ltexture* image, float x, float y, Unit* player) : Unit(image, x, y)
{
    lives = 3;
    name = "Boss";
    spriteSheetTexture = image;
    this -> player = player;

    //Frame 0
    spriteClips[ 0 ].x = 10;
    spriteClips[ 0 ].y = 28;
    spriteClips[ 0 ].w = 232;
    spriteClips[ 0 ].h = 110;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

}

void Boss::followPlayer()
{
    float p_x = player->GetX();
    float p_y = player->GetY();
    if (x != p_x)
    {
        if (x < p_x)
            x += 2;
        if (x > p_x)
            x -= 2;
    }

    if (y != p_y)
    {
        if (y < p_y)
            y += 2;

        if (y > p_y)
            y -= 2;
    }
}


void Boss::Move()
{
    followPlayer();
    if ((y > 900) || (lives <= 0) || (y < -300) || (x > 1224) || (x < -200))  //if exits the screen or dies out by colliding,
        SetAlive(false);                                                   //it is set to dead

}

void Boss::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->RenderTexture( x - width/2, y - height/2, gRenderer, &spriteClips[0], SDL_FLIP_VERTICAL);
}



