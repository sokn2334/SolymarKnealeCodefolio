// CSCI1300 Fall 2021
// Author: Solymar Kneale, Jack Snodgrass
// Recitation: 116 – Alex Ray, 112 – Maria Stull
// Project 3

#ifndef ENEMY_H 
#define ENEMY_H

#include <string>
using namespace std;

class Enemy
{
    public:

        // constructors
        Enemy();
        Enemy(string n, int h, int c, int e);

        // mutators/setters
        void setName(string n);
        void setHp(int h);
        void setCoin(int c);
        void setElementalLevel(int e);

        void modifyHp(int num);

        // accessors/getters
        string getName() const;
        int getHp() const;
        int getCoin() const;
        int getElementalLevel() const;

    private:
        string name;
        int hp;
        int coin;
        int elementalLevel;
        
};

#endif