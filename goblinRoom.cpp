/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/
#include "goblinRoom.hpp"
#include "player.hpp"


goblinRoom::goblinRoom(player *p) : room(p)
{
    //sets the bottom entrance walls
    map[14][13] = &wallOB;
    map[14][15] = &wallOB;
    map[7][14] = &goblinOB;

}

//prints out the message at the top of the screen
void goblinRoom::printMessage()
{
    if(message == 0){
        std::cout << "\nGoblin: 'Come close my friend'\n";
        std::cout << "Goblin: 'I know what happened to your princess'\n";
    }else if(message == 1){ //once the player talks to the goblin
        std::cout << "\nGoblin: 'This key opens the door to where they are holding her'\n";
    }else if(message == 2){ //once the player picks up the key object
        std::cout << "\nGoblin: 'Use the door on the right'\n";
    }
}

//sets player at the top of the room
void goblinRoom::setPlayerBottom()
{
    map[13][14] = hero;
	hero->setXCoord(13);
	hero->setYCoord(14);
}

//sets player at the right of the room
void goblinRoom::setPlayerRight()
{
    map[7][27] = hero;
	hero->setXCoord(7);
	hero->setYCoord(27);
}

//sets player at the left of the room
void goblinRoom::setPlayerLeft()
{
    map[7][2] = hero;
	hero->setXCoord(7);
	hero->setYCoord(2);
}

//checks if the player is at the bottom exit
bool goblinRoom::enterBottom()
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

//checks if the player is at the right exit
bool goblinRoom::enterRight()
{
    bool move = false;
    if((right != NULL) && (hero->checkInventory("key")==true)){
        if ((map[7][28] != NULL) && (map[7][28]->getSymbol() == '@')){
            map[7][28] = NULL;
            move = true;
        }
    }

    return move;
}

//checks if the player is at the left exit
bool goblinRoom::enterLeft()
{
    bool move = false;
    if((left != NULL) && (hero->checkInventory("key")==true)){
        if ((map[7][1] != NULL) && (map[7][1]->getSymbol() == '@')){
            map[7][1] = NULL;
            move = true;
        }
    }

    return move;
}

//controls the interactions if an interactable object is near the player
void goblinRoom::interactions()
{
     
     bool interact = false;

     if (message == 0)
     {

        if(map[hero->getXCoord()+1][hero->getYCoord()] == &goblinOB) //if goblin object is below the player
        {
            interact = true;
        }
        else if(map[hero->getXCoord()-1][hero->getYCoord()] == &goblinOB) //if goblin object is above the player
        {
            interact = true;
        }
        else if(map[hero->getXCoord()][hero->getYCoord()+1] == &goblinOB) //if goblin object is to the right of the player
        {
            interact = true;
        }
        else if(map[hero->getXCoord()][hero->getYCoord()-1] == &goblinOB) //if goblin object is to the left of the player
        {
            interact = true;
        }

        if(interact == true){ //if true switch message and spawn key object
            message = 1;
            map[9][22] = &keyOB;
        }

     }
     else if (hero->checkInventory("key") == false) //if key is in the player's inventory
     {
        
        if(map[hero->getXCoord()+1][hero->getYCoord()] == &keyOB) //if key object is below the player
        {
            interact = true;
            hero->addToInventory(map[hero->getXCoord()+1][hero->getYCoord()]->getName());
            map[hero->getXCoord() + 1][hero->getYCoord()] = NULL;


        }
        else if(map[hero->getXCoord()-1][hero->getYCoord()] == &keyOB) //if key object is above the player
        {
            interact = true;
            hero->addToInventory(map[hero->getXCoord()-1][hero->getYCoord()]->getName()); 
            map[hero->getXCoord() - 1][hero->getYCoord()] = NULL;

        }
        else if(map[hero->getXCoord()][hero->getYCoord()+1] == &keyOB) //if key object is to the right of the player
        {
            interact = true;
            hero->addToInventory(map[hero->getXCoord()][hero->getYCoord()+1]->getName());
            map[hero->getXCoord()][hero->getYCoord() +1] = NULL;

        }
        else if(map[hero->getXCoord()][hero->getYCoord()-1] == &keyOB) //if key object is to the left of the player
        {
            interact = true;
            hero->addToInventory(map[hero->getXCoord()][hero->getYCoord()-1]->getName());
            map[hero->getXCoord()][hero->getYCoord() - 1] = NULL;

        }

        if(interact == true){
            message = 2;
            //spawn left walls
            map[6][1] = &wallOB;
            map[8][1] = &wallOB;
            //spawn right walls
            map[6][28] = &wallOB;
            map[8][28] = &wallOB;

        }

     }
     
}
