/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/
#include "mazeRoom.hpp"
#include "player.hpp"


mazeRoom::mazeRoom(player *p) : room(p)
{
    //used to determine wether the lever is flipped
    flipSwitch = false;

    //used to set the x and y values of each *enemy
    int enemyX[4] = {9, 11, 12, 14};
    int enemyY[4] = {7, 10, 13, 16};

    //set each *enemy to a new throwing star
    for (int i = 0; i < 4; i++)
	{
		enemy[i] = new throwingStar;
        map[enemyX[i]][enemyY[i]] = enemy[i];
        enemy[i]->setXCoord(enemyX[i]);
        enemy[i]->setYCoord(enemyY[i]);
    }
    
    //set the orientation of each throwing star
    enemy[0]->setOrientation("down");
    enemy[1]->setOrientation("up");
    enemy[2]->setOrientation("down");
    enemy[3]->setOrientation("up");

    //spawn top left walls
    for(int j = 6; j <=13; j++)
        map[j][25] = &wallOB;

    for(int j = 2; j <=14; j++)
    {
        if(j!=7)
            map[j][22] = &wallOB;
    }
   
    for (int i = 21; i > 15; i--)
        map[8][i] = &wallOB;

    for (int i = 21; i > 11; i--)
        map[6][i] = &wallOB;

    for (int i = 21; i > 2; i--)
        map[2][i] = &wallOB;

    for (int i = 19; i > 0; i--)
        map[4][i] = &wallOB;

    for (int i = 28; i > 24; i--)
        map[2][i] = &wallOB;

    for (int i = 26; i > 22; i--)
        map[4][i] = &wallOB;

    //bottom left walls
    for (int i = 18; i > 11; i--)
        map[10][i] = &wallOB;

    map[9][12] = &wallOB;

    for (int i = 10; i < 13; i++)
        map[i][18] = &wallOB;
   
    //right entrance walls
    map[6][28] = &wallOB;
    map[6][27] = &wallOB;
    map[6][26] = &wallOB;
    map[8][28] = &wallOB;

    //left entrance walls extended to middle
    for (int i = 9; i > 0; i--)
        map[6][i] = &wallOB;

    for (int i = 12; i > 0; i--)
        map[8][i] = &wallOB;

    map[7][12] = &wallOB;

    //lever
    map[9][1] = &leverOB;
    map[10][1] = &leverOB;
}

mazeRoom::~mazeRoom()
{
    mapObjects *temp;
	for(int i = 0; i < 4; i++)
	{
		temp = enemy[i];
		enemy[i] = NULL;
		delete temp;
	}
}

//if the player reaches a certain tile, spawn walls to block path
void mazeRoom::moveCharacters()
{
    if (map[8][23] == hero || map[8][24] == hero)
    {
        if(flipSwitch == false)
        {
            //spawn walls
            map[6][23] = &wallOB;
            map[6][24] = &wallOB;

            message = 1;
        }
    }

    moveEnemy();    
    controlPlayer();
}

//prints out the message at the top of the screen
void mazeRoom::printMessage()
{
    if(message == 0){
        std::cout << "\nYou have entered a room with many walls\n";
        std::cout << "Make your way through the maze\n";
    }else if (message == 1){ //when the walls block the path
        std::cout << "\nThe walls have closed in front of you\n";
        std::cout << "You must flip the switch to continue\n";
    }else if (message == 2){ //when the lever has been pulled
        std::cout << "\nYou have flipped the switch and the path has cleared\n";
    }
}

//sets player at the right of the room
void mazeRoom::setPlayerRight()
{
    map[7][27] = hero;
	hero->setXCoord(7);
	hero->setYCoord(27);
}

//sets player at the left of the room
void mazeRoom::setPlayerLeft()
{
    map[7][2] = hero;
	hero->setXCoord(7);
	hero->setYCoord(2);
}

//moves the throwing stars up and down depending on the orientation
void mazeRoom::moveEnemy()
{
    for (int i=0; i<4; i++)
    {
        if(enemy[i]->getOrientation() == "up") //if their orientation is up
        {
            if(map[enemy[i]->getXCoord()-1][enemy[i]->getYCoord()] != &wallOB)
            {
                map[enemy[i]->getXCoord() - 1][enemy[i]->getYCoord()] = enemy[i];
                map[enemy[i]->getXCoord()][enemy[i]->getYCoord()] = NULL;
                enemy[i]->setXCoord(enemy[i]->getXCoord() - 1);

                if(map[enemy[i]->getXCoord()-1][enemy[i]->getYCoord()] == &wallOB) //if the next position is a wall then switch orientation
                    enemy[i]->setOrientation("down");
            }
        }
        else if(enemy[i]->getOrientation() == "down") //if their orientation is down
        {
            if(map[enemy[i]->getXCoord()+1][enemy[i]->getYCoord()] != &wallOB)
            {
                map[enemy[i]->getXCoord() + 1][enemy[i]->getYCoord()] = enemy[i];
                map[enemy[i]->getXCoord()][enemy[i]->getYCoord()] = NULL;
                enemy[i]->setXCoord(enemy[i]->getXCoord() + 1);

                if(map[enemy[i]->getXCoord()+1][enemy[i]->getYCoord()] == &wallOB) //if the next position is a wall then switch orientation
                    enemy[i]->setOrientation("up");
            }
        }
    }
}

//controls the interactions if an interactable object is near the player
void mazeRoom::interactions()
{
     
     bool interact = false;

     if (message == 1)
     {

        if(map[hero->getXCoord()-1][hero->getYCoord()] == &leverOB) //if lever is above the player
        {
            interact = true;
        }
        else if(map[hero->getXCoord()][hero->getYCoord()-1] == &leverOB) //if lever is to the left of the player
        {
            interact = true;
        }

     }

    if(interact == true)
    {
        message = 2;

        //remove blocked walls
        map[6][23] = NULL;
        map[6][24] = NULL;
        
        //change flipswitch to indicate that it has been flipped
        flipSwitch = true;

    }
   

}

//checks if the player is at the left exit
bool mazeRoom::enterLeft()
{
    bool move = false;
    if((left != NULL) && (flipSwitch == true)){
        if ((map[7][1] != NULL) && (map[7][1]->getSymbol() == '@')){
            map[7][1] = NULL;
            move = true;
        }
    }

    return move;
}