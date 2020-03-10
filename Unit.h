#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "Ltexture.h"
//#include "Bullet.h"

using namespace std;


enum MOTION {RIGHT, LEFT, UP, DOWN};

class Unit
{
protected:
    int lives = 0;     //life of every unit
    std::string name;  //name of every unit
    bool alive;        //true if unit is alive
    float x;           //positions of units
    float y;
    float speedx;      //speed in x direction
    float speedy;      //speed in y direction
    int width;         //dimensions of units
    int height;
    float friction; //lower speed means more friction
    Ltexture* spriteSheetTexture;
    SDL_Rect spriteClips[ 4 ];

public:
    Unit(Ltexture* image, float x, float y);
    Unit();
    virtual ~Unit();
    void SetAlive(bool);                //set the unit alive or dead
    virtual bool GetAlive();
    virtual int GetWidth();
    virtual int GetHeight();
    virtual float GetX();
    virtual float GetY();
    virtual void Move(int direction);   //move the unit in a direction
    virtual void Move();
    virtual void decrementLives();     //for a single collision, live is decremented by 1
    virtual void Render(long int& frame, SDL_Renderer* gRenderer) = 0; //pure virtual function makes the unit abstract
    bool checkCollision(Unit*, int);   //checks collision of two units by using x,y co-ordinates
    void SetY(float);        //sets unit position co-ordinates
    void SetX(float);
    int getLives();          //sets and gets unit lives
    void setLives(int);
    std::string getName();   //sets and gets unit name
    void setName(std::string);
};



