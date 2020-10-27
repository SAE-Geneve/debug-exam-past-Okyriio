//
//  Characters.hpp
//  Test
//
//  Created by Elias Farhan on 14/12/16.
//  Copyright © 2016 Elias Farhan. All rights reserved.
//

#ifndef Characters_hpp
#define Characters_hpp
#include <iostream>
#include <list>

class Monster;
class Hero;

class Character
{
public:
    Character(int, int, int, float);
    void takeDamage(int damage);
    bool isAlive();
    virtual void death() = 0;
    int getHealth();
    int getDefense();
    int getAttack();
protected:
    int health;
    int attack;
    int defense;
    float strength;
};


class Monster : public Character
{
    
public:
    Monster(int,int,int,float);
    void fight(Hero*);
    void death();
    void showstate(Monster monster);
};

class Hero : public Character
{
public:
    Hero(int, int, int, float);
    void fight(Monster*);
    void fight(std::list<Monster>::iterator monsterIt);
    void death();
 
};


#endif /* Characters_hpp */
