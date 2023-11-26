// CSCI1300 Fall 2021
// Author: Solymar Kneale, Jack Snodgrass
// Recitation: 116 – Alex Ray, 112 – Maria Stull
// Project 3

#include "Player.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

        // constructors
        Player::Player()
        {
            name = "";
            hp = 100;
            coin = 20;
            elementalLevel = 1;
            luck = 1;
            completeElements[0] = "Air";
            completeElements[1] = "";
            completeElements[2] = "";
            completeElements[3] = "";
            questNum = 0;
        }
        Player::Player(string n, int h, int c, int e, double l)
        {
            name = n;
            hp = h;
            coin = c;
            elementalLevel = e;
            luck = l;
        }

        // mutators/setters
        void Player::setName(string n)
        {
            name = n;
        }
        void Player::setHp(int h)
        {
            hp = h;
        }
        void Player::setCoin(int c)
        {
            coin = c;
        }
        void Player::setElementalLevel(int e)
        {
            elementalLevel = e;
        }
        void Player::setLuck(double l)
        {
            luck = l;
        }
        void Player::addCompleteElements(int w) // Enter world level to add a complete element
        {
            if (w == 0)
            {
                completeElements[1] = "Water";
            }
            else if(w ==1)
            {
                completeElements[2] = "Earth";
            }
            else if(w == 2)
            {
                completeElements[3] = "Fire";
            }
        }
        

        void Player::modifyHp(int num)
        {
            hp+=num;
        }
        void Player::modifyCoin(int num)
        {
           coin += num;
        }
        void Player::modifyElementalLevel(int num)
        {
            elementalLevel += num;        
        }
        void Player::modifyLuck(int num)
        {
            luck += num;
        }
        
        void Player::display()
        {
            cout << "Avatar " << name << ":" << endl;
            cout << "HP: " << hp << endl;
            cout << "Elemental Level: " << elementalLevel << endl;
            cout << "Coins: " << coin << endl;
            cout << "Complete Elements: ";
            for (int i =0; i < 4; i++)
            {
                if (completeElements[i] != "")
                {
                    cout << completeElements[i] << " ";
                }
            }
            cout << endl;
        }

        // accessors/getters
        string Player::getName() const
        {
            return name;
        }
        int Player::getHp() const
        {
            return hp;
        }
        int Player::getCoin() const
        {
            return coin;
        }
        int Player::getElementalLevel() const
        {
            return elementalLevel;
        }
        double Player::getLuck() const
        {
            return luck;
        }
        void Player::getCompleteElements() const
        {
            for (int i =0; i < 4; i++)
            {
                if (completeElements[i] != "")
                {
                    cout << completeElements[i] << ", ";
                }
            }
        }

        void Player::inc_QuestNum()
        {
            questNum++;
        }

        int Player::getQuestNum() const
        {
            return questNum;
        }