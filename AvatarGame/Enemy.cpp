// CSCI1300 Fall 2021
// Author: Solymar Kneale, Jack Snodgrass
// Recitation: 116 – Alex Ray, 112 – Maria Stull
// Project 3

#include "Enemy.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
    
    // constructors
        Enemy::Enemy()
        {
            name = "";
            hp = 100;
            coin = 0;
            elementalLevel = 0;
        }
        Enemy::Enemy(string n, int h, int c, int e)
        {
            name = n;
            hp = h;
            coin = c;
            elementalLevel = e;
        }

        // mutators/setters
        void Enemy::setName(string n)
        {
            name = n;
        }
        void Enemy::setHp(int h)
        {
            hp = h;
        }
        void Enemy::setCoin(int c)
        {
            coin = c;
        }
        void Enemy::setElementalLevel(int e)
        {
            elementalLevel =e;
        }

        void Enemy::modifyHp(int num)
        {
            hp += num;
        }

        // accessors/getters
        string Enemy::getName() const
        {
            return name;
        }
        int Enemy::getHp() const
        {
            return hp;
        }
        int Enemy::getCoin() const
        {
            return coin;
        }
        int Enemy::getElementalLevel() const
        {
            return elementalLevel;
        }

    
