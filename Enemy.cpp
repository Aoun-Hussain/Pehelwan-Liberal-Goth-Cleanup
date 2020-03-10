#include"Enemy.h"

Enemy::Enemy()
{}

Enemy::~Enemy()
{}

Enemy::Enemy(Ltexture* image, float x, float y):Unit(image, x, y)
{
    name = "Enemy";
    lives = 1;
    spriteSheetTexture = image;


    //Frame 0
    spriteClips[ 0 ].x = 259;
    spriteClips[ 0 ].y =   3;
    spriteClips[ 0 ].w = 110;
    spriteClips[ 0 ].h = 98;

    //Frame 1
    spriteClips[ 1 ].x = 390;
    spriteClips[ 1 ].y =  3;
    spriteClips[ 1 ].w = 110;
    spriteClips[ 1 ].h = 98;

    //Frame 2
    spriteClips[ 2 ].x = 510;
    spriteClips[ 2 ].y = 3;
    spriteClips[ 2 ].w = 110;
    spriteClips[ 2 ].h = 98;

    spriteClips[ 3 ].x = 649;
    spriteClips[ 3 ].y = 3;
    spriteClips[ 3 ].w = 110;
    spriteClips[ 3 ].h = 98;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
}


void Enemy::Move()
{
     y = y + 2; //speedy;
     if((y > 900) || (lives <= 0))  //if exits the screen or dies out by colliding, it is set to dead
     {
         SetAlive(false);
     }
}



void Enemy::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->RenderTexture( x - width/2 , y - height/2, gRenderer, &spriteClips[ 2 ], SDL_FLIP_VERTICAL);
}
