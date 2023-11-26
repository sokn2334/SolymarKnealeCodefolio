// CSCI1300 Fall 2021
// Author: Solymar Kneale, Jack Snodgrass
// Recitation: 116 – Alex Ray, 112 – Maria Stull
// Project 3

#ifndef GAME_H 
#define GAME_H
#include "Player.h"
#include "Enemy.h"
#include "Shop.h"
#include "Nation.h"
#include "Map.h"
#include <string>
#include <vector>
using namespace std;

class Game
{
    public:

        // constructors
        Game();
        Game(Player p, Nation n, Shop s);

        // mutators/setters
        Player startGame(Player player, Map map, Shop shop, Nation nation, int worldNum); // contains main function implementation
        Player introGame(Player player);
        
        Map createMap(Map map, int worldNum); // Creates a random map
        void endGame(Player player); // Ends the game if player dies or wins
        void setEndGame(); // Sets game end to true
        bool getEndGame();// Checks to see if the game has ended

        Player finalBattle(Player player);

 
        // accessors/getters
        string getCurrentNation() const;

    private:
        bool GameEnd;
        Player currentplayer;
        Nation currentNation;
        Shop currentshop;
        
};

#endif