// CSCI1300 Fall 2021
// Author: Solymar Kneale, Jack Snodgrass
// Recitation: 116 – Alex Ray, 112 – Maria Stull
// Project 3

#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <iostream>
#include <ctype.h>
#include <vector>

using namespace std; 

class Map
{
     private:
          static const int num_rows = 5;
          static const int num_cols = 9;
          static const int num_enemy = 5;

          int playerPosition[2];
          int shopPosition[2];
          int disasterPosition[2];

          int enemyPositions[num_enemy][2];
          char mapData[num_rows][num_cols];

          int npc_count;
          int enemy_count;
          bool shop_on_map;
          bool disaster_on_map;

     public :
          Map();

          void resetMap();

          // getters
          int getPlayerRowPosition();
          int getPlayerColPosition();
          int getEnemyCount();

          // setters
          void setPlayerRowPosition(int);
          void setPlayerColPosition(int);
          void setEnemyCount(int);

          void setMapData(int i, int j);
          char getMapData(int i, int j);
         
          bool spawnShop(int, int);
          bool spawnEnemy(int, int);
          bool spawnNaturalDisaster(int, int);

          void displayMap();
          void displayMoves();  
          bool executeMove(char);

          bool isShopLocation();
          bool isDisasterLocation();
          bool isEnemyLocation();

          bool isShopOnMap();
          bool isDisasterOnMap();

};
 
#endif