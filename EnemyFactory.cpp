#include "EnemyFactory.h"

EnemyFactory::EnemyFactory()
{
    enemy = NULL;
}

EnemyFactory::~EnemyFactory()
{}

Unit* EnemyFactory::GetEnemies(Ltexture* enemysheet, int x, int y, int type, float objectSize, Unit* p)
{
    if (type == 0) //regular enemy
    {
        enemy = new Enemy(enemysheet,x,y);
    }
    else if (type == 1) //boss enemy
    {
        enemy = new Boss(enemysheet,x,y,p);
    }
    return enemy;
}

