#include "Unit.h"

Unit::Unit()
{}


Unit::Unit(Ltexture* image, float x, float y)
{
    spriteSheetTexture = image;
    this->x = x;
    this->y = y;
    friction = 0.95f;
    speedx = 0;
    speedy = 0;
    alive  = true;
}


Unit::~Unit()
{
    spriteSheetTexture = NULL;
}

void Unit::SetAlive(bool alive)
{
    this->alive = alive;
}

bool Unit::GetAlive()
{
    return alive;
}

void Unit::Move(int direction)
{}


void Unit::Move()
{
    speedx = speedx * friction;
    speedy = speedy * friction;

    x = x + speedx;
    y = y + speedy;
}


int Unit::GetWidth()
{
    return width;
}

int Unit::GetHeight()
{
    return height;
}

float Unit::GetX()
{
    return x;
}
float Unit::GetY()
{
    return y;
}

bool Unit::checkCollision(Unit* e, int type)
{
    if (type == 1)     //type 1 is collision between player and other units of queue
    {
        if ((this -> x > (e -> GetX() - (float)(e -> width / 2))) &&
                (this -> x < (e -> GetX() + (float)(e -> width / 2)))
                && (this != e) && (this -> y > (e -> GetY() - (float)(e -> height / 2))) &&
                (this -> y < (e -> GetY() + (float)(e -> height / 2))) )
        {
            this->decrementLives();
            e->decrementLives();
            return true;
        }

    }
    else if (type == 0) //type 0 is collision between player bullets with other units of the queue
    {
        if ((this -> x > (e -> GetX() - (float)(e -> width / 2))) &&
                (this -> x < (e -> GetX() + (float)(e -> width / 2)))
                && (this != e))
        {
            this->decrementLives();
            e->decrementLives();
            return true;
        }
    }
    return false;
}

void Unit::SetY(float a)
{
    y = a;
}

void Unit::SetX(float a)
{
    x = a;
}

void Unit::decrementLives()
{
    if (lives > 0)
        lives --;
}

int Unit :: getLives()
{
    return lives;
}

void Unit :: setLives(int a)
{
    lives = a;
}

string Unit::getName()
{
    return name;
}


void Unit::Render(long int& frame, SDL_Renderer* gRenderer)  //virtual function not defined
{}

void Unit::setName(std::string name)
{
    this->name = name;
}












