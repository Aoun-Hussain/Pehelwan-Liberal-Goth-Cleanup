#include"Queue.h"
#include<iostream>
#include"sddl.h"

using namespace std;

Queue::Queue()
{
    head = NULL;
    tail = NULL;
    length = 0;
    aliveUnits = NULL;
}

Queue::~Queue()
{
    while(head != NULL) //deallocating all the nodes
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    delete [] aliveUnits; //deleting alive units container
}

void Queue::Enqueue(Unit* unit)
{
    if(head == NULL)  //if queue is empty
    {
        head = new Node;
        head->unit = unit;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else            //if queue is filled
    {
        tail->next = new Node;
        tail->next->unit = unit;
        tail->next->next = NULL;
        tail->next->prev = tail;
        tail = tail->next;
    }
    length ++;
}

void Queue::Clean()
{
    Node* temp = head;
    while (temp!=NULL)
    {
        if (temp->unit->GetAlive() == false)
        {
            if (temp->prev == NULL)       //if node is at the start
            {
                head=head->next;
                if(head!=NULL)
                {
                    head->prev = NULL;
                }
                delete temp;
                temp = head;
                length --;
            }
            else if(temp->next == NULL)  //if node is at the end
            {
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
                length --;
                break;
            }
            else                         //if node is in between
            {
                Node* carry = temp->next;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                temp = carry;
                length --;
            }
        }
        temp = temp->next;      //move to next node
    }
}

void Queue::Render(long int& frame, SDL_Renderer* gRenderer)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        temp->unit->Render(frame, gRenderer);
        temp->unit->Move();
        temp=temp->next;
    }
}

void Queue::Move()
{
    Node* temp = head;
    while( temp!=NULL)
    {
        temp->unit->Move();
        temp=temp->next;
    }
}

void Queue::Collision(Ltexture* img, Unit* un, int& score, SDL_Renderer* gRenderer, int type)
{
    Node* temp = head;
    while( temp!=NULL)
    {
        SDL_Rect d = {288,0,90,100};

        if ((temp->unit->GetAlive() == true))
        {
            if (temp->unit->checkCollision(un, type) == true)  //if collision is detected we decrease the lives and render image
            {
                img->RenderTexture(temp->unit->GetX() - temp->unit->GetWidth()/2,
                                   temp->unit->GetY()-temp->unit->GetHeight()/2, gRenderer,&d, SDL_FLIP_NONE);
                score += 100;  //score increase by 100 when an enemy is destroyed
            }

        }
        temp=temp->next;
    }
}

Unit** Queue::returnAliveUnits()
{
    aliveUnits = new Unit*[length];
    Node* temp = head;
    int i = 0;
    while (( temp != NULL) && (i < length))
    {
        aliveUnits[i] = temp->unit;
        temp = temp->next;
        i ++;
    }
    return aliveUnits;
}

int Queue::getLength()
{
    return length;
}


