// CSCI1300 Fall 2021
// Author: Solymar Kneale, Jack Snodgrass
// Recitation: 116 – Alex Ray, 112 – Maria Stull
// Project 3

#include "Nation.h"
#include "Enemy.h"
#include "Player.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int split(string split, char sep_char, string store[], int size) // Split function
{
    int num_slice= 0;
    int start =0;
    int length =0;
    int string_length= split.length();
    if (split == "")
    {
        return 0;
    }
    for (int i=0; i <= string_length; i++)
    {
        if (split[i]==sep_char || i == string_length)
        {
            string sub = split.substr(start, length);
            store[num_slice]= sub;
            num_slice++;
            start += length+1;
            length = -1; 
        }
        length ++;
    }
    if (size<num_slice)
    {
        return -1;
    }

return num_slice;   
}
    
    Nation::Nation()
    {
        name = "";

        for (int i=0; i< 5; i++)
        {
            enemy[i] = Enemy();
        } 
    }
    Nation::Nation(string n, Enemy inenemy[5])
    {
        name = n;

        for (int i=0; i< 5; i++)
        {
            enemy[i] = inenemy[i];
        } 
        
    }


    // mutators/setters
    void Nation::setName(string n)
    {
        name = n;
    }
    void Nation::setEnemy(int i) // Reads enemies from a file and puts them in an array
    {
        ifstream file;
        file.open("enemy.txt");
        string line;
        string arr[5];
        for(int j = 0; j < i; j++) // Loops differently depending on the world number inputed
        {
            getline(file,line); //Moves curser to the correct enemies in the file
        }
        
        for(int k = 0; k < 5; k++)
        {
            getline(file,line);
            split(line, '/', arr, 5); //Splits the line in the file
            Enemy enemyThis = Enemy(arr[0], stoi(arr[1]), stoi(arr[2]), stoi(arr[3])); //Creates and enemy based on the data from the file
            enemy[k] = enemyThis; // Stores the enemies in an array
        }

    }

    Player createNaturalDisaster(int i , Player player) //Disaster changes depending on the world
    {
        if (i == 0)
        {
            cout << "OH NO! You have run into a heavy rainstorm! You lose 10 health." << endl;
            player.modifyHp(-10);
        }
        else if (i == 1)
        {
            cout << "OH NO! You have run into a sandstorm! You lose 15 health." << endl;
            player.modifyHp(-15);
        }
        else if (i == 2)
        {
            cout << "OH NO! You have run into a geyser! You lose 20 health." << endl;
            player.modifyHp(-20);
        }
        return player;
    }

    // accessors/getters
    string Nation::getName() const
    {
        return name;
    }
    Enemy Nation::getEnemyat(int i) const
    {
        return enemy[i];
    }
 

    
