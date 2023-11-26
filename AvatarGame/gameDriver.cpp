// CSCI1300 Fall 2021
// Author: Solymar Kneale, Jack Snodgrass
// Recitation: 116 – Alex Ray, 112 – Maria Stull
// Project 3

#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Shop.h"
#include "Nation.h"
#include "Map.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    srand(time(NULL));
    //Game Constructor
    Game game1 = Game(); //makes a game object
    Player player = Player(); //makes a player object
    Shop shop= Shop(); //makes a shop object
    Enemy enemy = Enemy(); //makes an enemy object


    shop.setShopInventory("elementalScroll", 1);//initializes shop inventory
    shop.setShopInventory("healingSalve", 1);//initializes shop inventory
    shop.setShopInventory("luckyToken", 1);//initializes shop inventory


    Map map = Map();//creates a map object
    map = game1.createMap(map, 0); //initalizes a map
    Nation water = Nation(); //creates a nation object
    water.setEnemy(0);//initializes the enemies of each nation
    player = game1.introGame(player); //runs the intro to the game
    player = game1.startGame(player, map, shop, water, 0);//runs the main part of the game
    if (game1.getEndGame() == true)//checks to see if the player died or quit
    {
        return 0;
    }
    
    shop.setShopInventory("elementalScroll", 2);//initializes shop inventory
    shop.setShopInventory("healingSalve", 2);//initializes shop inventory
    shop.setShopInventory("luckyToken", 1);//initializes shop inventory
    Map map1 = Map();//creates a map object
    map1 = game1.createMap(map, 1);//initalizes a map
    Nation earth = Nation();//creates a nation object
    earth.setEnemy(5);//initializes the enemies of each nation
    player = game1.startGame(player, map1, shop, earth, 1); //runs the main part of the game
    if (game1.getEndGame() == true) //checks to see if the player died or quit
    {
        return 0;
    }

    shop.setShopInventory("elementalScroll", 2);//initializes shop inventory
    shop.setShopInventory("healingSalve", 3);//initializes shop inventory
    shop.setShopInventory("luckyToken", 0);//initializes shop inventory
    Map map2 = Map();//creates a map object
    map2 = game1.createMap(map, 2);//initalizes a map
    Nation fire = Nation();//creates a nation object
    fire.setEnemy(10);//initializes the enemies of each nation
    player= game1.startGame(player, map2, shop, fire, 2);//runs the main part of the game

    return 0;
}
    
    
