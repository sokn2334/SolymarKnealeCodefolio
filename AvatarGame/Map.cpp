// CSCI1300 Fall 2021
// Author: Solymar Kneale, Jack Snodgrass
// Recitation: 116 – Alex Ray, 112 – Maria Stull
// Project 3

#include "Map.h"
#include <vector>

using namespace std; 

Map::Map()
{
    resetMap();
}

// resets player position, count values, and initializes values in position arrays to -1
void Map::resetMap() {
    playerPosition[0] = 0; 
    playerPosition[1] = 0;

    shopPosition[0] = -1;
    shopPosition[1] = -1;

    disasterPosition[0] = -2;
    disasterPosition[1] = -2;
    
    enemy_count = 0;
    shop_on_map = false;
    disaster_on_map = false;


    for (int i = 0; i < num_enemy; i++) {
        enemyPositions[i][0] = -1;
        enemyPositions[i][1] = -1;
    }

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            mapData[i][j] = '-';
        }
    }
}

// return player's row position
int Map::getPlayerRowPosition() {
    return playerPosition[0];
}

// return player's column position
int Map::getPlayerColPosition() {
    return playerPosition[1];
}

int Map::getEnemyCount() {
    return enemy_count;
}

// set player's row position to parameter row
void Map::setPlayerRowPosition(int row) {
    playerPosition[0] = row;
}

// set player's column position to parameter row
void Map::setPlayerColPosition(int col) {
    playerPosition[1] = col;
}


void Map::setEnemyCount(int count) {
    enemy_count += count;
}

/* add Hacker to map
 * Parameters: where to spawn Hacker -- row (int), col (int)
 * Return: (bool) false if no more space in hackerPositions array
 *                      or if (row, col) is an invalid position
 *                      or if (row, col) is already populated; else true
 */
bool Map::spawnEnemy(int row, int col) {
    // out of map bounds
    if (!(row >= 0 && row < num_rows && col >= 0 && col < num_cols)) {
        return false;
    }

    if (enemy_count >= num_enemy) {
        return false;
    }

    // location must be blank to spawn
    if (mapData[row][col] != '-') {
        return false;
    }

    if (enemyPositions[enemy_count][0] == -1 && enemyPositions[enemy_count][1] == -1) {
        enemyPositions[enemy_count][0] = row;
        enemyPositions[enemy_count][1] = col;
        mapData[row][col] = 'E';
        enemy_count++;
        return true;
    }

    return false;
}


bool Map::spawnNaturalDisaster(int row, int col) {
    // out of map bounds
    if (!(row >= 0 && row < num_rows && col >= 0 && col < num_cols)) {
        return false;
    }

    // location must be blank to spawn
    if (mapData[row][col] != '-') {
        return false;
    }

    if (disaster_on_map) {
        return false;
    }

    if (disasterPosition[0] == -2 && disasterPosition[1] == -2) {
        disasterPosition[0] = row;
        disasterPosition[1] = col;
        mapData[row][col] = '-';
        disaster_on_map = true;
        return true;
    }

    return false;
}



/* add Best Buy to map
 * Parameters: where to spawn Best Buy -- row (int), col (int)
 * Return: (bool) false if (row, col) is an invalid location
 *                      or if (row, col) is already populated
 *                      or if there is a best buy already on the map; else true
 */
bool Map::spawnShop(int row, int col) {
    // out of map bounds
    if (!(row >= 0 && row < num_rows && col >= 0 && col < num_cols)) {
        return false;
    }

    // location must be blank to spawn
    if (mapData[row][col] != '-') {
        return false;
    }

    if (shop_on_map) {
        return false;
    }

    if (shopPosition[0] == -1 && shopPosition[1] == -1) {
        shopPosition[0] = row;
        shopPosition[1] = col;
        mapData[row][col] = 'S';
        shop_on_map = true;
        return true;
    }

    return false;
}

// return true if x, y position has a best buy there
bool Map::isShopLocation(){
    return shopPosition[0] == playerPosition[0] && shopPosition[1] == playerPosition[1];
}

bool Map::isDisasterLocation(){
    return disasterPosition[0] == playerPosition[0] && disasterPosition[1] == playerPosition[1];
}


// return true if x, y position has a hacker there
bool Map::isEnemyLocation() {
    for(int i = 0; i < num_enemy; i++){
        if(enemyPositions[i][0] == playerPosition[0] && enemyPositions[i][1] == playerPosition[1]){
            return true; 
        }
    }
    return false; 
}

/*
 * This function prints a menu of valid moves based on playerPosition
 * Parameters: none
 * Return: nothing (void)
 */
void Map::displayMoves(){
    if(!(playerPosition[0] == 0)){
        cout << "w (Up)" << endl;
    }
    if(!(playerPosition[0] == (num_rows - 1))){
        cout << "s (Down)" << endl; 
    }
    if(!(playerPosition[1] == 0)){
        cout << "a (Left)" << endl; 
    }
    if(!(playerPosition[1] == (num_cols - 1))){
        cout << "d (Right)" << endl; 
    }
}

/*
 * This function takes in user input
 * and updates playerPosition on the map.
 * Parameters: move (char) -- 'w' (up), 'a' (left), 's' (down), 'd' (right)
 * Return: (bool) if move is valid, then true, else false
 */
bool Map::executeMove(char move){
    // if user inputs w, move up if it is an allowed move
    if(!(playerPosition[0] == 0) && (tolower(move) == 'w')){
        playerPosition[0] -= 1;
        return true; 
    }
    // if user inputs s, move down if it is an allowed move
    else if(!(playerPosition[0] == (num_rows - 1))&& (tolower(move) == 's')){
        playerPosition[0] += 1;
        return true; 
    }
    // if user inputs a, move left if it is an allowed move
    else if(!(playerPosition[1] == 0)&& (tolower(move) == 'a')){
        playerPosition[1] -= 1;
        return true; 
    }
    // if user inputs d, move right if it is an allowed move
    else if(!(playerPosition[1] == (num_cols - 1))&& (tolower(move) == 'd')){
        playerPosition[1] += 1;
        return true; 
    }
    else{
        cout << "Invalid Move" << endl; 
        return false; 
    }
}

/*
 * This function prints a 2D map in the terminal.
 * Parameters: none
 * Return: nothing (void)
 */
void Map::displayMap() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (playerPosition[0] == i && playerPosition[1] == j) {
                cout << "x";
            }
            else {
                cout << mapData[i][j];
            }
        }
        cout << endl;
    }
}

// returns true if there is already a Best Buy on the map
bool Map::isShopOnMap() {
    return shop_on_map;
}

bool Map::isDisasterOnMap() {
    return disaster_on_map;
}

void Map::setMapData(int i, int j)
{
    mapData[i][j] = '-';
}

char Map::getMapData(int i, int j)
{
    return mapData[i][j];
}