// CSCI1300 Fall 2021
// Author: Solymar Kneale, Jack Snodgrass
// Recitation: 116 – Alex Ray, 112 – Maria Stull
// Project 3

#ifndef SHOP_H 
#define SHOP_H

#include <string>
using namespace std;

class Shop
{
    public:

        // constructors
        Shop();
        Shop(int s_arr[], int p_arr[]); //will take in the the shops inventory array

        // mutators/setters
        void setPlayerInventory(string i, int num); //player inventory will have three spaces for the scrolls, slaves, and tokens
        void setShopInventory(string i, int num); //shop inventory will have three spaces for the scrolls, slaves, and tokens will have random amount of each from 1-3

        // accessors/getters
        void getPlayerInventory() const; //input name of item you wanted counted will then get the number of that item
        void getShopInventory() const; //input name of item you wanted counted will then get the number of that item

        int getPlayerInventoryAt(string i); // Prints inventory at a specific location
        int getShopInventoryAt(string i); // Prints inventory at a specific location
       
    private:
        int playerInventory[3]; // elementalScroll[0], healingSalve[1], luckyToken[2]
        int shopInventory[3]; // elementalScroll[0], healingSalve[1], luckyToken[2]
        
};

#endif