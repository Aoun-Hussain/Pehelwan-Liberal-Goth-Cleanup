#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "Enemy.h"
#include "Boss.h"
#include "Unit.h"
#include "Ltexture.h"


class EnemyFactory
{
private:
    Unit* enemy;
public:
    EnemyFactory();
    virtual ~EnemyFactory();
    Unit* GetEnemies(Ltexture*, int, int, int, float, Unit*);
};

#endif // ENEMYFACTORY_H
