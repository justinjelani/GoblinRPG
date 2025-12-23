#include "Goblin.h"
#include <cstdlib>
#include <ctime>
using namespace std;

// Returns goblins damage, adds onto base damage with a range from 1-8 
int Goblin::getDamage(){
    damage = baseDamage + ((rand() % 8) + 1);
    return damage;
}
// Increases the base damage of the goblin by 4 every level
void Goblin::increaseDamage(){
    baseDamage += 3;
}
// Resets goblins health after death
void Goblin::resetHealth(){
    health = maxHealth;
}
// Increases the goblins health every other level
void Goblin::increaseHealth(){
    maxHealth*=1.2;
}
// Returns goblins current health
int Goblin::getHealth(){
    return health;
}
// Returns goblins maximum health
int Goblin::getMaxHealth(){
    return maxHealth;
}
// Goblin taking player damage
void Goblin::takeDmg(int dmgTaken){
    health-=dmgTaken;
}
// Resets ALL of the goblins attributes
void Goblin::reset(){
    health = 100;
    maxHealth = 100;
    baseDamage = 3;
}
