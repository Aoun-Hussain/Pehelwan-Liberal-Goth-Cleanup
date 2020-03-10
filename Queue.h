#pragma once
#include"Node.h"


class Queue
{
private:
    Node* head;         //node at the start of the queue
    Node* tail;         //node at the end of the queue
    Unit** aliveUnits;  //to store alive units of the queue
    int length;         //to keep track of the length of the queue
public:
    Queue();
    ~Queue();
    void Enqueue(Unit*);//adds the unit at the tail node
    void Clean();       //cleans all the dead units in a queue
    void Render(long int& frame, SDL_Renderer* gRenderer);  //renders every unit in the queue
    void Move();                                                 //moves the units on the screen
    void Collision(Ltexture*, Unit*, int&, SDL_Renderer*, int);  //detects collision between units of queue
    int getLength();                                             //returns the length of the queue
    Unit** returnAliveUnits();                                   //returns all alive units of queue
};
