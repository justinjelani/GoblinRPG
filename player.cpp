#include "Player.h"
#include <limits>
using namespace std;

// Sets the players username
void Player::setName(string input){
    username = input;
}
// Returns the players username
string Player::getName(){
    return username;
}
// Returns the damage of the melee attack
int Player::getDamage(){
     return meleeDamage;
}
// Returns the damage of the fireball attack
int Player::getFireball(){
     return fireballDmg;
}
// Returns the amount of healing the player does
int Player::heal(){
    return healing;
}
// Heals the player when they use their heal ability
void Player::healPlayer(){
    health+=healing;
}
// Sets player health to the maximum to prevent overflow
void Player::setHealth(){
    health = maxHealth;
}
// Returns the players current health
int Player::getHealth(){
    return health;
}
// Returns the players maximum health
int Player::getMaxHealth(){
    return maxHealth;
}
// Damages the player when the goblin attacks and returns the amount of damage taken
int Player::takeDmg(int dmgTaken){
    health-= dmgTaken;
    return dmgTaken;
}
// Returns the players current stamina
int Player::getStamina(){
    return stamina;
}
// Returns the users maximum stamina
int Player::getMaxStamina(){
    return maxStamina;
}
// Sets stamina to the maximum stamina to prevent overflow
void Player::setStamina(){
    stamina = maxStamina;
}
// Increases stamina when resting
void Player::increaseStamina(){
    stamina+=staminaRegen;
}
//Removes stamina when the player attacks
void Player::updateStamina(int Stamina){
    stamina-=Stamina;
}
// Returns the users coin amount
int Player::getCoins(){
    return coins;
} 
// Adds coins when leveling up
int Player::addCoins(int addCoins){
    coins += addCoins;
    return addCoins;
}
// Removes coins when making purchases
void Player::removeCoins(int removeCoins){
    coins -= removeCoins;
}

// Text to display the users current stats
void Player::displayStats(){
    cout<< "-------------- "<< username + "'s " << "Stats!" << " --------------" << endl;
    cout<< " " << endl;
    cout<< "Coins: " << coins << endl;
    cout<< "Health: " << health << "/" << maxHealth << endl;
    cout<< "Stamina: " << stamina << "/" << maxStamina << endl;
    cout<< "Stamina Regeneration: " << staminaRegen << endl;
    cout<< "Melee Damage: " << meleeDamage << endl;
    cout<< "Fireball Damage: " << fireballDmg <<endl;
    cout<< " " << endl;
}

// Player Shop for Upgrading Attributes
void Player::shop(){
    int upgrade;
    cout<< "[!] What would you like to upgrade? Current coins: " << coins << endl;
    cout<< "1. +20 Max Health "<< "Cost: " << cost1 << endl;
    cout<< "2. +15 Healing Boost "<< "Cost: " << cost2 << endl;
    cout<< "3. +10 Melee Damage "<< "Cost: " << cost3 << endl;
    cout<< "4. +25 Fireball Damage "<< "Cost: " << cost4 << endl;
    cout<< "5. +20 Stamina Regeneration " << "Cost: " << cost5 << endl;
    cout<< "6. Back"<< endl;
    cin >> upgrade;

    while(upgrade < 1 || upgrade > 6){
        cout<< "[!] Invalid input! Must input a number between 1-6" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin>> upgrade;
    }

    switch(upgrade){
        case 1:
            if(coins < cost1){
                cout<< "[!] Not enough coins to purchase";
                return;
            }
            coins-=cost1;
            cost1+= 175;
            maxHealth+= 20;
            cout<< "[!] You're new Max Health is " << maxHealth << endl;
        break;
        case 2:
            if(coins < cost2){
                cout<< "[!] Not enough coins to purchase";
                return;
            }
            coins-=cost2;
            cost2+= 225;
            healing+=15;
            cout<< "[!] You will now heal " << healing << " health!" << endl;
        break;
        case 3:
            if(coins < cost3){
                cout<< "[!] Not enough coins to purchase";
                return;
            }
            coins-=cost3;
            cost3+= 175;
            meleeDamage+=10;
            cout<< "[!] You now do " << meleeDamage << " melee damage!" << endl;
        break;
        case 4:
            if(coins < cost4){
                cout<< "[!] Not enough coins to purchase";
                return;
            }
            coins-=cost4;
            cost4+= 225;
            fireballDmg+=25;
            cout<< "[!] You're fireball now does " << fireballDmg << " damage!" <<endl;
        break;
        case 5:
            if(coins < cost5){
                cout<< "[!] Not enough coins to purchase" << endl;
                return;
            } 
            coins-=cost5;
            cost5+=175;
            staminaRegen+=20;
            cout<< "You now regenerate " << staminaRegen << " when you rest!" << endl;
        break;
        case 6:
            cout<< "[!] Back!" << endl;
        break;
    }
}

// Resets ALL of the players attributes when replaying the game
void Player::reset(){
    // Reset Health and heal abilities
    maxHealth = startMaxHealth; health = maxHealth; healing = startHeal;
    // Reset Stamina and Abilities
     maxStamina = maxStamStart; stamina = maxStamina; staminaRegen = startStamReg;
    // Reset Attacks
    meleeDamage = startMelee; fireballDmg = startFireball;
    // Reset Coins
    coins = startCoins;
    // reset costs
    cost1 = startCost1; cost2 = startCost2; cost3 = startCost3; cost4 = startCost4; cost5 = startCost5;
}
