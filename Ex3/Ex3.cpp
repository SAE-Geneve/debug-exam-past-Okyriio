//
//  SUPER HERO VERSUS HORDE OF MONSTERS
//
//  Created by Elias Farhan on 14/12/16.
//  Copyright © 2016 Elias Farhan. All rights reserved.
//

#include <list>
#include <vector>
#include "Characters.h"



int main()
{
    Hero* hero = new Hero(10,10,10,0.5f);
    std::list<Monster> monsters = {
        Monster(10, 1,1,5),
		Monster(20,5, 5,5),
         Monster(30,10,10,5)
    };
    
    for(std::list<Monster>::iterator monsterIt = monsters.begin();
        monsterIt != monsters.end(); monsterIt++)
    {
        while (hero->isAlive() || monsterIt->isAlive());
        {
            hero->fight(monsterIt);
            monsterIt->fight(hero);
        }
        //If the monster is dead, meaning not alive, he dies!
        if(!monsterIt->isAlive()){
            monsterIt->death();
        }
        //Windows specific
        if(!hero->isAlive())
{
            hero->death();
            break;
        }
    }
    
    system("pause");
}
