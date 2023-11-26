// CSCI1300 Fall 2021
// Author: Solymar Kneale, Jack Snodgrass
// Recitation: 116 – Alex Ray, 112 – Maria Stull
// Project 3

#ifndef PLAYER_H 
#define PLAYER_H

#include <string>
using namespace std;

class Player
{
    public:

        // constructors
        Player();
        Player(string n, int h, int c, int e, double l);

        // mutators/setters
        void setName(string n);
        void setHp(int h);
        void setCoin(int c);
        void setElementalLevel(int e);
        void setLuck(double l);
        void addCompleteElements(int w); // Enter world level to add a complete element
        
  
        void modifyHp(int num);
        void modifyCoin(int num);
        void modifyElementalLevel(int num);
        void modifyLuck(int num);

        void display(); // Displays the player's stats

        // accessors/getters
        string getName() const;
        int getHp() const;
        int getCoin() const;
        int getElementalLevel() const;
        double getLuck() const;
        void getCompleteElements() const;

        void inc_QuestNum(); //This increases the question number (ensures no repeated questions)
        int getQuestNum() const;// This keeps track of the question number that the player is on
       
    private:
        string name;
        int hp;
        int coin;
        int elementalLevel;
        double luck;
        string completeElements[4];
        int questNum;
        
};

#endif