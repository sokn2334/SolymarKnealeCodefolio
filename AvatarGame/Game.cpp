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
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
    
int split1(string split, char sep_char, string store[], int size) // Split function
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
    
Game::Game()
{
    Player player1 = Player();
    Nation nation1 = Nation();
    Shop shop1 = Shop();
    GameEnd = false;
}
Game::Game(Player p, Nation n, Shop s)
{
    Player player1 = p;
    Nation nation1 = n;
    Shop shop1 = s;
}

// mutators/setters

Player Game::introGame(Player player)
{
    cout << "            \x1B[34m✯✯✯✯✯✯✯✯✯✯✯✯✯✯GAME START✯✯✯✯✯✯✯✯✯✯✯✯✯✯\033[0m" << endl << endl;
    string input;
    cout << "    Long ago, the four nations lived together in harmony." << endl;
    cout << "   Then, everything changed when the \x1B[31mFire Nation\033[0m attacked." << endl;
    cout << "        Only the Avatar, master of all four elements, " << endl;
    cout << "     could stop them, but when the world needed him most," << endl; 
    cout << "                        he vanished." << endl << endl;
    cout << "            Please enter your name young Avatar: " << endl;
    getline(cin, input);
    player.setName(input);

    cout << "Avatar " << player.getName() << " we need your help!"<< endl;
    return player;
}


Player Game::startGame(Player player, Map map, Shop shop, Nation nation, int worldNum) //This function will contain the entire game implementation
{
   

    int UpE = 0;
    int E = 0;
    string input1;
 

    do{
    string input1;
    string chars;
    char chars1;

    do{
    cout << endl;
    map.displayMap();
    cout << endl;
    cout << "Choose an option:" << endl; // Begining menu
    cout << "1. Move" << endl;
    cout << "2. Battle Enemy" << endl;
    cout << "3. Enter Shop" << endl;
    cout << "4. Use Items" << endl;
    cout << "5. Check Stats" << endl;
    cout << "6. Quit" << endl;
    getline(cin, input1);

    //Check to see if the player has inputed an invalid option
    if (input1 != "1" && input1 != "2" && input1 != "3" && input1 != "4" && input1 != "5" && input1 != "6")
    {
        cout << "Please enter a number" << endl;
    }
    //Gives the player the menu again if they put and invalid character
    }while(input1 != "1" && input1 != "2" && input1 != "3"&& input1 != "4" && input1 != "5" && input1 != "6");
    
    switch(stoi(input1))
    {
        case 1: // Move
            map.displayMoves();
            getline(cin, chars);
            chars1 = chars[0];
            map.executeMove(chars1);
            if (map.isDisasterLocation()== true)
            {
                if (worldNum == 0)
                {
                    cout << "OH NO! You have run into a heavy rainstorm! You lose 10 health." << endl;
                    player.modifyHp(-10);
                }
                else if (worldNum == 1)
                {
                    cout << "OH NO! You have run into a sandstorm! You lose 15 health." << endl;
                    player.modifyHp(-15);
                }
                else if (worldNum == 2)
                {
                    cout << "OH NO! You have run into a geyser! You lose 20 health." << endl;
                    player.modifyHp(-20);
                }
            }
            break;
        case 2: //Battle
            if (map.isEnemyLocation() == true && map.getMapData(map.getPlayerRowPosition(), map.getPlayerColPosition()) == 'E') // Checks if the player is truly on an enemy
            {
                Enemy enemyGuy = nation.getEnemyat(UpE);
                do{
                cout << endl;
                cout << "You have encountered " << enemyGuy.getName() << "!"<< endl;
                cout << "What will you do?" << endl;
                cout << "1. Answer a Question" << endl;
                cout << "2. Take a Chance" << endl;
                cout << "3. Run Away!" << endl;

                getline(cin, input1);
                //Check to see if the player has inputed an invalid option
                if (input1 != "1" && input1 != "2" && input1 != "3" && input1 != "4")
                {
                    cout << "Please enter a number" << endl;
                }
                //Gives the player the menu again if they put and invalid character
                }while(input1 != "1" && input1 != "2" && input1 != "3" && input1 != "4");

                ifstream file1;
                string line1;
                string arr1[4];
                int rand1 =rand() %(3)+ 1; //Random numbers for chance
                int rand2 =rand() %(3)+ 1;
                int chance = 0;

                switch (stoi(input1))
                {
                    case 1: // If the player chooses to answer a question
                        do{
                        
                        file1.open("Questions.txt");
                        for(int h = 0 ; h < player.getQuestNum(); h++) //Loops to the next unanswered question (ensures no repeated questions)
                        {
                            getline(file1,line1); 
                        }

                        do{
                            getline(file1,line1);
                            split1(line1, '/', arr1, 4);
                            cout << arr1[0] << endl;
                            cout << arr1[1] << endl;
                            cout << arr1[2] << endl;

                            getline(cin, input1);
                            //Check to see if the player has inputed an invalid option
                            if (input1 != "1" && input1 != "2")
                            {
                                cout << "Please enter a number" << endl;
                            }
                        }while(input1 != "1" && input1 != "2"); //Gives the player the menu again if they put and invalid character
                        
                        file1.close();
                        player.inc_QuestNum(); // Increases the question number
                        
                        if(stoi(input1) == stoi(arr1[3])) // If the player answers correct
                        {
                            cout << "Correct!" << endl;
                            enemyGuy.modifyHp(-10); 
                        }
                        else // If the player answers incorrect
                        {
                            cout << "Incorrect" << endl;
                            player.modifyHp(-10);
                        }
                            cout << endl;
                            cout << "The enemy has "<< enemyGuy.getHp() << " hp." << endl;
                            cout << "You have " << player.getHp() << " hp." << endl;

                        } while(enemyGuy.getHp() > 0 && player.getHp() > 0);

                        if (enemyGuy.getHp() == 0) // If the enemy has been beaten
                        {
                            cout << "Congratulation! You have beaten " << enemyGuy.getName() << "!" << endl;
                            cout << "You have gained " << enemyGuy.getCoin() << " coins, and 20 elemental points!" << endl;
                            player.modifyCoin(enemyGuy.getCoin());
                            player.modifyElementalLevel(20);
                            UpE++; // Makes sure that the next enemy is not repeated
                            map.setMapData(map.getPlayerRowPosition(), map.getPlayerColPosition()); // Deletes the enemy off of the map

                        }
                        else if (player.getHp() == 0) // If the player dies
                        {
                            cout << "You have died" << endl;
                            return player; // Exists the function
                        }
                

                        break;
                    case 2: // If the player chooses to take a chance
                    
                        chance = (rand1 * player.getElementalLevel()) - (rand2 * enemyGuy.getElementalLevel() * (1/player.getLuck()));
                        cout << chance << endl;
                        if (chance < 0) // If the player loses 
                        {
                            cout << "Too Bad! Luck was not on you side. You have lost 10 health." << endl;
                            player.modifyHp(-10);
                        }
                        else if (chance > 0) // If the player wins
                        {
                            cout << "Luck was on your side! Your enemy has lost 10 health." << endl;
                            enemyGuy.modifyHp(-10); 
                        }

                        cout << endl;
                        cout << "The enemy has "<< enemyGuy.getHp() << " hp." << endl;
                        cout << "You have " << player.getHp() << " hp." << endl;

                        if (enemyGuy.getHp() == 0) // If the enemy has been beaten
                        {
                            cout << "Congratulation! You have beaten " << enemyGuy.getName() << "!" << endl;
                            cout << "You have gained " << enemyGuy.getCoin() << " coins, and 20 elemental points!" << endl;
                            player.modifyCoin(enemyGuy.getCoin());
                            player.modifyElementalLevel(20);
                            UpE++; // Makes sure that the next enemy is not repeated
                            map.setMapData(map.getPlayerRowPosition(), map.getPlayerColPosition()); // Deletes the enemy off of the map

                        }
                        else if (player.getHp() == 0) // If the player dies
                        {
                            cout << "You have died" << endl;
                            return player; // Exists the function
                        }
                        break;
                  
                    case 3:
                        cout << "You have run away." << endl; // If the player chooses to run away
                        break;
                    default:
                        cout << "Invalid Input" << endl; // If the player inputs invalid input
                        break;
                }

            }
            else // If the player in not in an enemy location
            {
                cout << "There is no enemy to battle." << endl; 
            }
            break;
        case 3: //If the player chooses shop
            if(map.isShopLocation() == true)
            {
                string input1; //Shop introduction
                cout << "Welcome to the shop!" << endl;
                cout << "You have " << player.getCoin() << " coins." << endl;
                cout << "The shop currently offers: " << endl;
                shop.getShopInventory();
                
                do{
                cout << endl; // Shop Menu
                cout << "What would you like to purchase?" << endl;
                cout << "1. Elemental Scroll" << endl;
                cout << "2. Healing Salve" << endl;
                cout << "3. Lucky Token" << endl;
                cout << "4. Quit" << endl;

                getline(cin, input1);

                //Check to see if the player has inputed an invalid option
                if (input1 != "1" && input1 != "2" && input1 != "3" && input1 != "4")
                {
                    cout << "Please enter a number" << endl;
                }
                //Gives the player the menu again if they put and invalid character
                }while(input1 != "1" && input1 != "2" && input1 != "3" && input1 != "4");

                switch (stoi(input1))
                {
                    case 1: // If the player chooses the elemental scroll
                        if (player.getCoin() < 20) //If the player doesn't have enouph coins
                        {
                            cout << "You don't have enough coins to purchase this item." << endl;
                        }
                        else if (shop.getShopInventoryAt("elementalScroll") <= 0) // If the shop has 0 of the item
                        {
                            cout << "The shop doesn't have this item." << endl;
                        }
                        else // If the player is able to purchase the item
                        {
                            shop.setShopInventory("elementalScroll", -1);
                            shop.setPlayerInventory("elementalScroll", 1);
                            player.modifyCoin(-20);
                            cout << "You have purchased an elemental scroll." << endl;
                        }
                        break;
                    case 2: // If the player chooses the healing salve
                        if (player.getCoin() < 10) //If the player doesn't have enouph coins
                        {
                            cout << "You don't have enough coins to purchase this item." << endl;
                        }
                        else if (shop.getShopInventoryAt("healingSalve") <= 0) // If the shop has 0 of the item
                        {
                            cout << "The shop doesn't have this item." << endl;
                        }
                        else // If the player is able to purchase the item
                        {
                            shop.setShopInventory("healingSalve", -1);
                            shop.setPlayerInventory("healingSalve", 1);
                            player.modifyCoin(-10);
                            cout << "You have purchased a healing salve." << endl;
                        }
                        break;
                    case 3: // If the player chooses the lucky token
                        if (player.getCoin() < 30) //If the player doesn't have enouph coins
                        {
                            cout << "You don't have enough coins to purchase this item." << endl;
                        }
                        else if (shop.getShopInventoryAt("luckyToken") <= 0) // If the shop has 0 of the item
                        {
                            cout << "The shop doesn't have this item." << endl;
                        }
                        else // If the player is able to purchase the item
                        {
                            shop.setShopInventory("luckyToken", -1);
                            shop.setPlayerInventory("luckyToken", 1);
                            player.modifyCoin(-30);
                            cout << "You have purchased a lucky token." << endl;
                        }
                        break;
                    case 4: // If the player quits
                        break;
                    default: // If the player inputs invalid input
                    cout << "Invalid Input" << endl;
                        break;
                }
            }
            else if (map.isShopLocation() == false) // If the player is not on a shop location
            {
                cout << "There is no shop to enter." << endl;
            }
            break;
        case 4: //If the player chooses to use an item
            do
            {
            cout << "You currently have: " << endl;
            shop.getPlayerInventory();
            cout << endl;
            cout << "Which item do you want to use?" << endl;
            cout << "1. Elemental Scroll" << endl;
            cout << "2. Healing Salve" << endl;
            cout << "3. Lucky Token" << endl;
            cout << "4. Quit" << endl;
            getline(cin, input1);

            //Check to see if the player has inputed an invalid option
            if (input1 != "1" && input1 != "2" && input1 != "3" && input1 != "4")
            {
                cout << "Please enter a number" << endl;
            }
            //Gives the player the menu again if they put and invalid character
            }while(input1 != "1" && input1 != "2" && input1 != "3" && input1 != "4");

            switch (stoi(input1))
            {
                case 1: // If the user chooses an elemental scroll
                    if (shop.getPlayerInventoryAt("elementalScroll") <= 0) // If the player doesn't have the item
                    {
                        cout << "You don't have any elemental scrolls" << endl;
                    }
                    else
                    {
                    player.modifyElementalLevel(25);
                    shop.setPlayerInventory("elementalScroll", -1); 
                    cout << "You have used an elemental scroll. You have gained 25 elemental points!" << endl;  
                    }
                    break;
                case 2: // If the player chooses a healing salve
                if (shop.getPlayerInventoryAt("healingSalve") <= 0)// If the player doesn't have the item
                    {
                        cout << "You don't have any healing salves" << endl;
                    }
                    else
                    {
                    player.modifyHp(25);
                    shop.setPlayerInventory("healingSalve", -1);
                    cout << "You have used a healing salve. You have gained 25 health!" << endl;  
                    }
                    break;
                case 3: // If the player chooses a lucky token
                    if (shop.getPlayerInventoryAt("luckyToken") <= 0)// If the player doesn't have the item
                    {
                        cout << "You don't have any lucky tokens" << endl;
                    }
                    else
                    {
                        player.modifyLuck(1);
                        shop.setPlayerInventory("luckyToken", -1);
                        cout << "You have used a lucky token. You have increased your chance to win a battle!" << endl;  
                    }
                    break;
                case 4: // If the player chooses quit
                    break;
                default: // If the player inputs an invalid number
                    cout << "Invalid Input" << endl;
                    break;
            }

            break;
        case 5: // If the player chooses to display stats
            player.display();
            break;
        case 6: // If the player chooses to quit
            cout << "Are you sure you want to quit, this will end the game and you will lose your progress."<< endl;
            cout << "Y/N"<< endl;
            getline(cin, chars);
            chars1 = chars[0];
            if (tolower(chars1) == tolower('Y'))// If the player chooses yes
            {
                endGame(player);
                setEndGame();
                E = 1;
                break;
            }
            else if(tolower(chars1) == tolower('N')) // If the player chooses no
            {
                break;
            }
            break;
        default: // If the player chooses an invalid number
            cout<< "Please choose a number from the list." << endl;
            break;
    }
    }while(E != 1 && player.getHp() > 0 && player.getElementalLevel() < 100); // Loops while the player is still alive and has not reached the next elemental level
    
    if(E == 1 || player.getHp() <= 0 ) // If the player is dead
    {
        setEndGame();
    }
    else // If the player has reached the next elemental level
    {
        player.setElementalLevel(1);
        player.addCompleteElements(worldNum);//Adds a number that is different in each nation
        
        if (worldNum == 0) //checks to see what world the player is going to move too or the final battle
        {
            cout << "Congrats! You have moved to the \x1B[32mEarth Nation\033[0m!" << endl;
        }
        else if (worldNum == 1)
        {
            cout << "Congrats! You have moved to the \x1B[31mFire Nation\033[0m!" << endl;
        }
        else if (worldNum == 2) //starts the final battle
        {
            cout << "Congrats" << player.getName() <<"you have mastered all the elements now is the time to take down the final boss." << endl;
            cout << "The final boss is tough, the penalty for error is more severe." << endl;
            cout << "Make sure you are prepared and use up any left over items." << endl;
            do
            {
                cout << "You currently have: " << endl;
                shop.getPlayerInventory();
                cout << endl;
                cout << "Which item do you want to use?" << endl;
                cout << "1. Elemental Scroll" << endl;
                cout << "2. Healing Salve" << endl;
                cout << "3. Lucky Token" << endl;
                cout << "4. Don't Use Items" << endl;
                getline(cin, input1);

                //Check to see if the player has inputed an invalid option
                if (input1 != "1" && input1 != "2" && input1 != "3" && input1 != "4")
                {
                    cout << "Please enter a number" << endl;
                }
                //Gives the player the menu again if they put and invalid character
            }while(input1 != "1" && input1 != "2" && input1 != "3" && input1 != "4");

                switch (stoi(input1))
                {
                    case 1: // If the user chooses an elemental scroll
                        if (shop.getPlayerInventoryAt("elementalScroll") <= 0) // If the player doesn't have the item
                        {
                            cout << "You don't have any elemental scrolls" << endl;
                        }
                        else
                        {
                        player.modifyElementalLevel(25);
                        shop.setPlayerInventory("elementalScroll", -1); 
                        cout << "You have used an elemental scroll. You have gained 25 elemental points!" << endl;  
                        }
                        break;
                    case 2: // If the player chooses a healing salve
                    if (shop.getPlayerInventoryAt("healingSalve") <= 0)// If the player doesn't have the item
                        {
                            cout << "You don't have any healing salves" << endl;
                        }
                        else
                        {
                        player.modifyHp(25);
                        shop.setPlayerInventory("healingSalve", -1);
                        cout << "You have used a healing salve. You have gained 25 health!" << endl;  
                        }
                        break;
                    case 3: // If the player chooses a lucky token
                        if (shop.getPlayerInventoryAt("luckyToken") <= 0)// If the player doesn't have the item
                        {
                            cout << "You don't have any lucky tokens" << endl;
                        }
                        else
                        {
                            player.modifyLuck(1);
                            shop.setPlayerInventory("luckyToken", -1);
                            cout << "You have used a lucky token. You have increased your chance to win a battle!" << endl;  
                        }
                        break;
                    case 4: // If the player chooses quit
                        break;
                    default: // If the player inputs an invalid number
                        cout << "Invalid Input" << endl;
                        break;
                }

                finalBattle(player); //calls final battle function

        }
       

       
    }
    
    // :>
    return player;
}




Map Game::createMap(Map map, int worldNum) 
{
    
    int count=0;
    
    int rowarr[8]={0};// Stores the row in an array (to ensure they don't spawn on eachother)
    int colarr[8]={0};// Stores the columns in an array (to ensure they don't spawn on eachother)

    int ran_num1 =rand() %(4); //gets a random number
    int ran_num2 =rand() %(8); //gets a random number

    rowarr[0]=ran_num1;
    colarr[0]=ran_num2;

    map.spawnShop(ran_num1, ran_num2); //spawns a shop
    
    int ran_num5=0;
    int ran_num6=0;
    
    
    ran_num5 =rand() %(4);//gets a random number
    ran_num6 =rand() %(8);//gets a random number
    do{ //checks to make sure that there is not somthing already on the space
        count=0;
        for(int C=0; C < 8; C++) //C++ easter egg :)
        {
            for(int R =0; R < 8; R++)
            {
                if (rowarr[C] == ran_num5 && colarr[R] == ran_num6)
                {
                    count ++;
                }
            }
        }
            if (count == 0)
            {
                rowarr[1]=ran_num5;
                colarr[1]=ran_num6;
            }

            ran_num5 = rand() %(4);//gets a random number
            ran_num6 = rand() %(8);//gets a random number
        
        }while(count != 0);
    map.spawnNaturalDisaster(ran_num5, ran_num6);//spawns a natural disater
    
    int numEnemy= 0;
    for(int h = numEnemy; h < 5; h++)
    {

       int ran_num3 =rand() %(4);//gets a random number
       int ran_num4 =rand() %(8);//gets a random number
        
        do{ //checks to make sure that there is not somthing already on the space
            count=0;
            for(int C=0; C < 8; C++) //C++ easter egg :)
            {
                for(int R =0; R < 8; R++)
                {
                    if (rowarr[C] == ran_num3 && colarr[R] == ran_num4)
                    {
                        count ++;
                    }
                }
            }
                if (count == 0)
                {
                    rowarr[h+3]=ran_num3;
                    colarr[h+3]=ran_num4;
                }

                ran_num3 = rand() %(4);//gets a random number
                ran_num4 = rand() %(8);//gets a random number


            }while(count != 0);
            
        map.spawnEnemy(ran_num3, ran_num4); //spawns enemy
        
    }
    return map;
}

void Game::endGame(Player player) //This will print out the final stats of the player to the output file and sort a leaderboard
{
    cout << "Ended Game" << endl; 
    fstream finout;
    finout.open ("output.text", ios::app | ios::in); // Creates an output file in append mode

    //Outputs stats to a file
    finout << player.getName() << " Hp: " <<player.getHp() << " Elemental Level: " << player.getElementalLevel() << " Coins: "<< player.getCoin()  << endl; 
 
    string line;
    vector<string> vec1;

    finout.seekg(ios::beg); // Puts the curser back at the top

    while(getline(finout,line)) // While there are still lines in the file
    {
        vec1.push_back(line); // Puts all of the lines into a vector
    }
    
    char arr[vec1.size()];
    for(int g = 0 ; g < vec1.size(); g++)
    {
        arr[g]= vec1[g].at(0); // Stores the first letter of each line in an array
    }

    int size = vec1.size();
    //Below is the code for bubble sorting
     for (int i = 0; i < (size-1); i++) 
     {
        bool swap = false;
   
        for (int j = 0; j < (size-i-1); j++) 
        {   
            if (arr[j] > arr[j + 1]) //If the letter is higher in the alphabet 
            {
                int temp = arr[j]; // Switches the letters in the array
                arr[j] = arr[j+ 1];
                arr[j +1] = temp;

                string tempVec = vec1[j]; // Switched the lines in the vector
                vec1[j] = vec1[j + 1];
                vec1[j + 1] = tempVec;
                
                swap = true;
                }
            }
            if (swap == false)
            {
                break;
            }
        }    
    
finout.close();

finout.open ("output.text", ios::out); // Opens the file in overwrite mode
for(int u = 0; u < vec1.size(); u++)
{
    finout << vec1[u] << endl; // Puts the sorted vector lines in the file
}
finout.close();
}

// accessors/getters
string Game::getCurrentNation() const
{
    return currentNation.getName();
}

void Game::setEndGame()
{
    GameEnd = true;
}

bool Game::getEndGame()
{
    return GameEnd;
}

Player Game::finalBattle(Player player)
    {
        Enemy Ozai = Enemy("Ozai", 100, 0, 1000); //the final enemy
       
       int next=0;
        cout << "Time to take down the final boss!" << endl;
        
        string input1;
        ifstream file1;
        string line1;
        string arr1[4];
                       
        // If the player chooses to answer a question
    do{
        
        file1.open("BossQuestions.txt");
        for(int h = 0 ; h < next; h++) //Loops to the next unanswered question (ensures no repeated questions)
        {
            getline(file1,line1); 
        }

        do{ //same thing as the q and a code fro normal battles
            getline(file1,line1);
            split1(line1, '/', arr1, 4);
            cout << arr1[0] << endl;
            cout << arr1[1] << endl;
            cout << arr1[2] << endl;

            getline(cin, input1);
            //Check to see if the player has inputed an invalid option
            if (input1 != "1" && input1 != "2")
            {
                cout << "Please enter a number" << endl;
            }
        }while(input1 != "1" && input1 != "2"); //Gives the player the menu again if they put and invalid character
        
        file1.close();
        
        if(stoi(input1) == stoi(arr1[3])) // If the player answers correct
        {
            cout << "Correct!" << endl;
            Ozai.modifyHp(-10);
            next++; 
        }
        else // If the player answers incorrect
        {
            cout << "Incorrect" << endl;
            player.modifyHp(-20);
            next++;
        }
            cout << endl;
            cout << "The enemy has "<< Ozai.getHp() << " hp." << endl;
            cout << "You have " << player.getHp() << " hp." << endl;

    } while(Ozai.getHp() > 0 && player.getHp() > 0);

        if (Ozai.getHp() == 0) // If the enemy has been beaten
        {
            cout << "Congratulation! You have beaten Lord Ozai and saved the world from assured destruction!" << endl;
            endGame(player);
            return player;
    
        }
        else
        {
            cout << "You have died" << endl;
            endGame(player);
            return player; // Exists the function
        }

    }