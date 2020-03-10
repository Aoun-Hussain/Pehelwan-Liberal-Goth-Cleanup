#include"Bullet.h"
#include "SDL.h"


Bullet::Bullet()
{}

Bullet::~Bullet()
{}


Bullet::Bullet(Ltexture* image, float x, float y, int type):Unit(image, x, y)
{
    this -> type = type;
    lives = 1;
    name = "Bullet";
    spriteSheetTexture = image;

    //Frame 0
    spriteClips[ 0 ].x = 96;
    spriteClips[ 0 ].y = 96;
    spriteClips[ 0 ].w = 32;
    spriteClips[ 0 ].h = 32;

    //Frame 1
    spriteClips[ 1 ].x = 128;
    spriteClips[ 1 ].y = 96;
    spriteClips[ 1 ].w = 32;
    spriteClips[ 1 ].h = 32;

    //Frame 2
    spriteClips[ 2 ].x = 160;
    spriteClips[ 2 ].y = 96;
    spriteClips[ 2 ].w = 32;
    spriteClips[ 2 ].h = 32;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
}


void Bullet::Move()
{
    if (type == 0)                         //player bullet
    {
        y = y - 20;
        if ((y < -100) || (lives <= 0))    //if exits the screen or dies out by colliding, it is set to dead
        {
         SetAlive(false);
        }
     }
     else if (type == 1)                   //enemy bullet
     {
         y = y + 8;
         if ((y > 900) || (lives <= 0))
         {
             SetAlive(false);
         }
     }

     else if (type == 2)                  //boss bullet
     {
         y = y + 4;
         if ((y > 900) || (lives <= 0))
         {
             SetAlive(false);
         }
     }
}

void Bullet::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->RenderTexture( x - width/2, y - height/2, gRenderer, &spriteClips[ frame % 3 ], SDL_FLIP_NONE);
}

