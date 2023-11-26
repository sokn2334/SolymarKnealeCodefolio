// CSCI1300 Fall 2021
// Author: Solymar Kneale, Jack Snodgrass
// Recitation: 116 – Alex Ray, 112 – Maria Stull
// Project 3

#ifndef NATION_H 
#define NATION_H
#include "Enemy.h"
#include "Player.h"
#include <string>
using namespace std;

class Nation
{
    public:

        // constructors
        Nation();
        Nation(string n, Enemy inenemy[5]);
    
        // mutators/setters
        void setName(string n);
        void setEnemy(int i); // Takes in world number and sets the array of enemys
    
        Player createNaturalDisaster(int i, Player player); //Takes in the world number and creates a certain disaster and a player to edit

        // accessors/getters
        string getName() const;
        Enemy getEnemyat(int i) const; // Gets enemy at index i
        
    private:
        string name;
        Enemy enemy[5];
        
};

#endif