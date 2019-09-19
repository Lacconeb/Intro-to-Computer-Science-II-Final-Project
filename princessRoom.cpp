/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/
#include "princessRoom.hpp"
#include "player.hpp"


princessRoom::princessRoom(player *p) : room(p)
{
    //bottom entrance walls
    for(int i=10 ; i <15; i++)
    {
        map[i][12] = &wallOB;
        map[i][16] = &wallOB;
    }
    
    map[14][13] = &wallOB;
    map[14][15] = &wallOB;

    //bottom and top walls of inner square room
    for(int i=7 ; i <22; i++)
    {
        if (i!=13 && i!=14 && i!=15){
            map[9][i] = &wallOB;
            map[3][i] = &wallOB;
        }
    }

    //left and right walls of inner square room
    for(int i=1; i < 10; i++)
    {
        map[i][6] = &wallOB;
        map[i][22] = &wallOB;
    }

    //used to set the x and y values of each *enemy
    int enemyX[5] = {4, 5, 6, 7, 8};
    int enemyY[5] = {7, 20, 7, 20, 7};

    //set each *enemy to a new throwing star
    for (int i = 0; i < 5; i++)
	{
		enemy[i] = new throwingStar;
        map[enemyX[i]][enemyY[i]] = enemy[i];
        enemy[i]->setXCoord(enemyX[i]);
        enemy[i]->setYCoord(enemyY[i]);
    }
    
    //set the orientation of each throwing star
    enemy[0]->setOrientation("right");
    enemy[1]->setOrientation("left");
    enemy[2]->setOrientation("right");
    enemy[3]->setOrientation("left");
    enemy[4]->setOrientation("right");
    
    //set princess
    map[1][14] = &princessOB;

}

princessRoom::~princessRoom()
{
    mapObjects *temp;
	for(int i = 0; i < 5; i++)
	{
		temp = enemy[i];
		enemy[i] = NULL;
		delete temp;
	}
}

//moves enemies and player
void princessRoom::moveCharacters()
{
    
    moveEnemy();    
    controlPlayer();
}

//prints out the message at the top of the screen
void princessRoom::printMessage()
{
    if(message == 0){ 
        std::cout << "\nYou see the princess on the other side of the room\n";
    }
}

//sets player at the bottom of the room
void princessRoom::setPlayerBottom()
{
    map[13][14] = hero;
	hero->setXCoord(13);
	hero->setYCoord(14);
}

//moves the throwing stars left and right depending on the orientation
void princessRoom::moveEnemy()
{
    for (int i=0; i<5; i++)
    {
        if(enemy[i]->getOrientation() == "right") //if their orientation is right
        {
            if(map[enemy[i]->getXCoord()][enemy[i]->getYCoord()+1] != &wallOB)
            {
                //move player
                map[enemy[i]->getXCoord()][enemy[i]->getYCoord()+1] = enemy[i];
                map[enemy[i]->getXCoord()][enemy[i]->getYCoord()] = NULL;
                enemy[i]->setYCoord(enemy[i]->getYCoord() + 1);

                if(map[enemy[i]->getXCoord()][enemy[i]->getYCoord()+1] == &wallOB) //if the next position is a wall then switch orientation
                    enemy[i]->setOrientation("left");
            }
        }
        else if(enemy[i]->getOrientation() == "left") //if their orientation is left
        {
            if(map[enemy[i]->getXCoord()][enemy[i]->getYCoord()-1] != &wallOB)
            {
                //move player
                map[enemy[i]->getXCoord()][enemy[i]->getYCoord()-1] = enemy[i];
                map[enemy[i]->getXCoord()][enemy[i]->getYCoord()] = NULL;
                enemy[i]->setYCoord(enemy[i]->getYCoord() - 1);

                if(map[enemy[i]->getXCoord()][enemy[i]->getYCoord()-1] == &wallOB) //if the next position is a wall then switch orientation
                    enemy[i]->setOrientation("right");
            }
        }
    }
}

//controls the interactions if an interactable object is near the player
void princessRoom::interactions()
{
    bool interact = false;

    if(map[hero->getXCoord()+1][hero->getYCoord()] == &princessOB) //if princess object is below the player
    {
        interact = true;
    }
    else if(map[hero->getXCoord()-1][hero->getYCoord()] == &princessOB) //if princess object is above the player
    {
        interact = true;
    }
    else if(map[hero->getXCoord()][hero->getYCoord()+1] == &princessOB) //if princess object is to the right of the player
    {
        interact = true;
    }
    else if(map[hero->getXCoord()][hero->getYCoord()-1] == &princessOB) //if princess object is to the left of the player
    {
        interact = true;
    }

    if(interact == true){

        for (int i = 0; i < 100; i++)
		    std::cout << "\n";

        //print out game won message
        std::cout << "\nYou have saved the Princess!!!\n";
        std::cout << "\nThank you for playing :)\n\n";

        //end game
        hero->kill();

    }

}

//checks if the player is at the bottom exit
bool princessRoom::enterBottom()
{
    bool move = false;
    if(bottom != NULL){
        if ((map[14][14] != NULL) && (map[14][14]->getSymbol() == '@')){
            map[14][14] = NULL;
            move = true;
        }
    }

    return move;
}