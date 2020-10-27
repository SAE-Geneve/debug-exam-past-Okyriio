//
//  Characters.cpp
//  Test
//
//  Created by Elias Farhan on 14/12/16.
//  Copyright © 2016 Elias Farhan. All rights reserved.
//

#include "Characters.h"

//////////Character////////////

Character::Character(int health, int attack, int defense, float strength)
{
    this->health = health;
    this->attack = attack;
	this->defense = defense;
    this->strength = strength;
}



bool Character::isAlive()
{

	return health > 0;
	
}

void Character::takeDamage(int damage)
{
    health -= damage;
}


int Character::getAttack()
{
    return attack;
}

int Character::getDefense()
{
    return defense;
}

int Character::getHealth()
{
    return health;
}


//////////Monster////////////

Monster::Monster(int health, int attack, int defense, float strength):
Character(health, attack, defense, strength)
{
}



void Monster::fight(Hero* hero)
{
    int damage = (double)attack / hero->getDefense() * strength;

	if(damage<0)
	{
		damage = 0;
	}
    
    if(damage > strength)
    {
	    damage = strength;
    }
        
    
    std::cout << "Monster gives "<<damage<<" to Hero\n";
    ((Character*)hero)->takeDamage(damage);
}

void Monster::death()
{
    std::cout << "Yet another dead monster!\n";

}
void Monster::showstate(Monster monster)
{
    std::cout << "Health Points\n" << monster.health << "\nAttack\n"
	<< monster.attack << "\n Defense\n" << monster.defense;
}


//////////Hero////////////

Hero::Hero(int health, int attack, int defense, float strength):
Character(health, attack, defense, strength)
{

}


void Hero::fight(std::list<Monster>::iterator monsterIt)
{
int damage = (double)attack/monsterIt->getDefense()*strength;

	if(damage < 0)
    {
	         damage = 0;
    }
  
    if(damage > strength)
    {
	    damage = strength;
    }
        

    std::cout << "Hero gives "<<damage<<" to Monster\n";
    monsterIt->takeDamage(damage);
}

void Hero::death()
{
    std::cout << "The hero is dead, long live the hero!\n";
    return ;
}

