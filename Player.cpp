#include "Player.h"

Player* Player :: instance = NULL;


Player::Player(Ltexture* image, float x, float y)
{
    lives = 7;
    spriteSheetTexture = image;
    //Frame 0
    spriteClips[ 0 ].x =   0;
    spriteClips[ 0 ].y =   0;
    spriteClips[ 0 ].w = 128;
    spriteClips[ 0 ].h = 96;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.95f;
    speedx = 0;
    speedy = 0;
    alive  = true;
}


Player::~Player()
{
    spriteSheetTexture = NULL;
}


void Player::Move(int direction)
{
    if ((lives <= 0) || (y > 900) || (y < -50) || (x > 1100) || (x < 0))  //player cannot move out of screen, dead if tries to
        SetAlive(false);

    if(direction == LEFT)
    {
        speedx = -5;
        x+=speedx;
    }

    if(direction == RIGHT)
    {
        speedx = 5;
        x+=speedx;
    }

    if(direction == UP)
    {
        speedy = -5;
        y+=speedy;
    }

    if(direction == DOWN)
    {
        speedy = 5;
        y+=speedy;
    }
}

Player* Player::get_instance(Ltexture* image, float x, float y)
{
    if (instance == NULL)
        instance = new Player(image, x, y);
    return instance;
}

void Player::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->RenderTexture( x - width/2, y - height/2, gRenderer, &spriteClips[ 0 ], SDL_FLIP_NONE);
}

void Player::destroy_Instance()
{
    if (instance != NULL)
        delete instance;
    instance = NULL;
}







