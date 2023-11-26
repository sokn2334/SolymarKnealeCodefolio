// CSCI1300 Fall 2021
// Author: Solymar Kneale, Jack Snodgrass
// Recitation: 116 – Alex Ray, 112 – Maria Stull
// Project 3

#include "Shop.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
    
    Shop::Shop() //Constructor sets both inventories to 0
    {
        shopInventory[0]= 0;
        shopInventory[1]= 0;
        shopInventory[2]= 0;
        playerInventory[0]= 0;
        playerInventory[1]= 0;
        playerInventory[2]= 0;
    }
    Shop::Shop(int s_arr[], int p_arr[]) //Constructor that takes in an array to input for the shop and the player
    {
        shopInventory[0]= s_arr[0];
        shopInventory[1]= s_arr[1];
        shopInventory[2]= s_arr[2];
        playerInventory[0]= p_arr[0];
        playerInventory[1]= p_arr[1];
        playerInventory[2]= p_arr[2];
    }

    // mutators/setters
    void Shop::setPlayerInventory(string i, int num) //Input the name of the item and the number to change the amount of that item
    {
        if (i == "elementalScroll")
        {
            playerInventory[0] += num;
        }
        else if(i == "healingSalve")
        {
            playerInventory[1] += num;
        }
        else if(i == "luckyToken")
        {
            playerInventory[2] += num;
        }
    }
    void Shop::setShopInventory(string i, int num)//Input the name of the item and the number to change the amount of that item
    {
        if (i == "elementalScroll")
        {
            shopInventory[0] += num;
        }
        else if(i == "healingSalve")
        {
            shopInventory[1] += num;
        }
        else if(i == "luckyToken")
        {
            shopInventory[2] += num;
        }
    }

    // accessors/getters
    void Shop::getPlayerInventory() const // Prints inventory
    {
        cout << "Elemental Scroll: " << playerInventory[0] << endl;
        cout << "Healing Salve: " << playerInventory[1] << endl;
        cout << "Lucky Token: " << playerInventory[2] << endl;
    } 
    void Shop::getShopInventory() const // Prints inventory
    {
        cout << "Elemental Scroll: " << shopInventory[0] << " (Price 20)"<< endl;
        cout << "Healing Salve: " << shopInventory[1] << " (Price 10)" << endl;
        cout << "Lucky Token: " << shopInventory[2] << " (Price 30)" << endl;
    } 


   int Shop::getPlayerInventoryAt(string i) // Prints inventory at a specific location
   {
       if (i == "elementalScroll")
        {
            return playerInventory[0];
        }
        else if(i == "healingSalve")
        {
            return playerInventory[1];
        }
        else if(i == "luckyToken")
        {
            return playerInventory[2];
        }
        return -10;
   }
   
    
    int Shop::getShopInventoryAt(string i) // Prints inventory at a specific location
    {
        if (i == "elementalScroll")
        {
            return shopInventory[0];
        }
        else if(i == "healingSalve")
        {
            return shopInventory[1];
        }
        else if(i == "luckyToken")
        {
            return shopInventory[2];
        }
        return -10;
    }
         
