/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/
#include "bossRoom.hpp"
#include "player.hpp"


bossRoom::bossRoom(player *p) : room(p)
{
    
    //spawn warlock in the middle of room
    map[7][14] = &warlockOB;

    //spawn bow
    map[9][25] = &bowOB;

    //walls for bow position
    map[9][24] = &wallOB;
    map[10][24] = &wallOB;
    map[10][25] = &wallOB;
    map[10][26] = &wallOB;
    map[9][26] = &wallOB;

    //used to set the x and y values of each *enemy
    int enemyX[6] = {8, 6, 6, 6, 8, 8};
    int enemyY[6] = {14, 14, 13, 15, 13, 15};

    //set each *enemy to a new throwing star
    for (int i = 0; i < 6; i++)
	{
		enemy[i] = new throwingStar;
        map[enemyX[i]][enemyY[i]] = enemy[i];
        enemy[i]->setXCoord(enemyX[i]);
        enemy[i]->setYCoord(enemyY[i]);
    }
    
    //set the orientation of each throwing star
    enemy[0]->setOrientation("down");
    enemy[1]->setOrientation("up");
    enemy[2]->setOrientation("up left");
    enemy[3]->setOrientation("up right");
    enemy[4]->setOrientation("down left");
    enemy[5]->setOrientation("down right");

    //right entrance walls
    for (int i = 20; i < 29; i++)
    {
        map[6][i] = &wallOB;

        if(i!=25)
            map[8][i] = &wallOB;
    }

    //top and bottom inner walls
    for(int i=9; i < 20; i++)
    {
        map[2][i] = &wallOB;
        map[12][i] = &wallOB;
    }

    //left and right inner walls
    for(int i=3; i < 12; i++)
    {
        if(i!=6 && i!=7 && i!=8)
            map[i][9] = &wallOB;
        else
            map[i][8] = &wallOB;

        if(i != 7)
            map[i][19] = &wallOB;
    }

    map[5][8] = &wallOB;
    map[9][8] = &wallOB;

    map[6][9] = &archerXOB;
    map[8][9] = &archerXOB;

    
}

bossRoom::~bossRoom()
{
    mapObjects *temp;
	for(int i = 0; i < 6; i++)
	{
		temp = enemy[i];
		enemy[i] = NULL;
		delete temp;
	}
}

//moves enemies and player
void bossRoom::moveCharacters()
{

    moveEnemy();    
    controlPlayer();
}

//prints out the message at the top of the screen
void bossRoom::printMessage()
{
    if(message == 0){
        std::cout << "\nYou see the warlock that took the princess\n";
        std::cout << "Find a weapon to defeat him with\n";
    }else if (message == 1){ //once the bow is interacted with
        std::cout << "\nYou have picked up a Bow and arrows\n";
        std::cout << "Go in the middle of the X's and shoot an arrow at the warlock\n";
    }else if (message == 2){ //once the warlock is defeated
        std::cout << "\nYou have defeated the warlock!!\n";
        std::cout << "Make your way to the top room\n";
    }
}

//sets player at the right of the room
void bossRoom::setPlayerRight()
{
    map[7][27] = hero;
	hero->setXCoord(7);
	hero->setYCoord(27);
}

//sets player at the left of the room
void bossRoom::setPlayerTop()
{
    map[2][14] = hero;
    hero->setXCoord(2);
	hero->setYCoord(14);
}

//moves the throwing stars up, down, or diagonal depending on the orientation
void bossRoom::moveEnemy()
{
    for (int i=0; i<6; i++)
    {
        if(enemy[i]->getOrientation() == "up") //if their orientation is up
        {
                //move player
                map[enemy[i]->getXCoord() - 1][enemy[i]->getYCoord()] = enemy[i];
                map[enemy[i]->getXCoord()][enemy[i]->getYCoord()] = NULL;
                enemy[i]->setXCoord(enemy[i]->getXCoord() - 1);

                if(map[enemy[i]->getXCoord()-1][enemy[i]->getYCoord()] == &wallOB || 
                    map[enemy[i]->getXCoord()-1][enemy[i]->getYCoord()] == &warlockOB || 
                    map[enemy[i]->getXCoord()-1][enemy[i]->getYCoord()] == &bloodOB) //if the next position is a wall, warlock, or blood object then switch orientation
                    enemy[i]->setOrientation("down");
            
        }
        else if(enemy[i]->getOrientation() == "down") //if their orientation is down
        {
                //move player
                map[enemy[i]->getXCoord() + 1][enemy[i]->getYCoord()] = enemy[i];
                map[enemy[i]->getXCoord()][enemy[i]->getYCoord()] = NULL;
                enemy[i]->setXCoord(enemy[i]->getXCoord() + 1);

                if(map[enemy[i]->getXCoord()+1][enemy[i]->getYCoord()] == &wallOB || 
                    map[enemy[i]->getXCoord()+1][enemy[i]->getYCoord()] == &warlockOB || 
                    map[enemy[i]->getXCoord()+1][enemy[i]->getYCoord()] == &bloodOB) //if the next position is a wall, warlock, or blood object then switch orientation
                    enemy[i]->setOrientation("up");
            
        }
        else if(enemy[i]->getOrientation() == "up left") //if their orientation is up left
        {
                //move player
                map[enemy[i]->getXCoord()-1][enemy[i]->getYCoord()-1] = enemy[i];
                map[enemy[i]->getXCoord()][enemy[i]->getYCoord()] = NULL;
                enemy[i]->setYCoord(enemy[i]->getYCoord()-1);
                enemy[i]->setXCoord(enemy[i]->getXCoord()-1);

                if(map[enemy[i]->getXCoord()-1][enemy[i]->getYCoord()-1] == &wallOB || 
                    map[enemy[i]->getXCoord()-1][enemy[i]->getYCoord()-1] == &warlockOB || 
                    map[enemy[i]->getXCoord()-1][enemy[i]->getYCoord()-1] == &bloodOB) //if the next position is a wall, warlock, or blood object then switch orientation
                    enemy[i]->setOrientation("down right");
            
            
        }
        else if(enemy[i]->getOrientation() == "up right") //if their orientation is up right
        {
                //move player
                map[enemy[i]->getXCoord()-1][enemy[i]->getYCoord()+1] = enemy[i];
                map[enemy[i]->getXCoord()][enemy[i]->getYCoord()] = NULL;
                enemy[i]->setXCoord(enemy[i]->getXCoord()-1);
                enemy[i]->setYCoord(enemy[i]->getYCoord()+1);
                

                if(map[enemy[i]->getXCoord()-1][enemy[i]->getYCoord()+1] == &wallOB || 
                    map[enemy[i]->getXCoord()-1][enemy[i]->getYCoord()+1] == &warlockOB || 
                    map[enemy[i]->getXCoord()-1][enemy[i]->getYCoord()+1] == &bloodOB) //if the next position is a wall, warlock, or blood object then switch orientation
                    enemy[i]->setOrientation("down left");
            
            
        }
        else if(enemy[i]->getOrientation() == "down left") //if their orientation is down left
        {
                //move player
                map[enemy[i]->getXCoord()+1][enemy[i]->getYCoord()-1] = enemy[i];
                map[enemy[i]->getXCoord()][enemy[i]->getYCoord()] = NULL;
                enemy[i]->setXCoord(enemy[i]->getXCoord()+1);
                enemy[i]->setYCoord(enemy[i]->getYCoord()-1);

                if(map[enemy[i]->getXCoord()+1][enemy[i]->getYCoord()-1] == &wallOB || 
                    map[enemy[i]->getXCoord()+1][enemy[i]->getYCoord()-1] == &warlockOB || 
                    map[enemy[i]->getXCoord()+1][enemy[i]->getYCoord()-1] == &bloodOB) //if the next position is a wall, warlock, or blood object then switch orientation
                    enemy[i]->setOrientation("up right");
            
            
        }
        else if(enemy[i]->getOrientation() == "down right") //if their orientation is down right
        {
                //move player
                map[enemy[i]->getXCoord()+1][enemy[i]->getYCoord()+1] = enemy[i];
                map[enemy[i]->getXCoord()][enemy[i]->getYCoord()] = NULL;
                enemy[i]->setXCoord(enemy[i]->getXCoord()+1);
                enemy[i]->setYCoord(enemy[i]->getYCoord()+1);

                if(map[enemy[i]->getXCoord()+1][enemy[i]->getYCoord()+1] == &wallOB || 
                    map[enemy[i]->getXCoord()+1][enemy[i]->getYCoord()+1] == &warlockOB || 
                    map[enemy[i]->getXCoord()+1][enemy[i]->getYCoord()+1] == &bloodOB) //if the next position is a wall, warlock, or blood object then switch orientation
                    enemy[i]->setOrientation("up left");
            
            
        }
    }
}

//controls the interactions if an interactable object is near the player
void bossRoom::interactions()
{
     if (hero->checkInventory("bow") == false) //if bow is not in the player's inventory
     {
        
        if(map[hero->getXCoord()+1][hero->getYCoord()] == &bowOB) //if bow is below the player
        {
            hero->addToInventory(map[hero->getXCoord()+1][hero->getYCoord()]->getName());
            map[hero->getXCoord() + 1][hero->getYCoord()] = NULL;
            message = 1;

        }

     }
     else if (hero->checkInventory("bow") == true) //if bow is in the player's inventory
     {
        if(map[hero->getXCoord()+1][hero->getYCoord()] == &archerXOB) //if an archerX is below the player
        {
            
            if(map[hero->getXCoord()-1][hero->getYCoord()] == &archerXOB) //if an archerX is above the player
            {
                message = 2;

                //change the warlock to blood
                map[7][14] = &bloodOB;

                //open top inner walls to exit
                map[2][14] = NULL;

                //create top exit walls
                map[1][13] = &wallOB;
                map[1][15] = &wallOB;
            }
        }
     }


}

//checks if the player is at the right exit
bool bossRoom::enterRight()
{
    bool move = false;
    if(right != NULL){
        if ((map[7][28] != NULL) && (map[7][28]->getSymbol() == '@')){
            map[7][28] = NULL;
            move = true;
        }
    }

    return move;
}

//checks if the player is at the top exit
bool bossRoom::enterTop()
{
    bool move = false;
    if((top != NULL) && (map[7][14] != &warlockOB)){
        if ((map[1][14] != NULL) && (map[1][14]->getSymbol() == '@')){
            map[1][14] = NULL;
            move = true;
        }
    }

    return move;
}