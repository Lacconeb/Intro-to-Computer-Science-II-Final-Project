/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/
#include "waterRoom.hpp"
#include "player.hpp"


waterRoom::waterRoom(player *p) : room(p)
{
    //spawn first column of water
    for (int i = 28; i > 27; i--)
    {
        for(int j = 1; j <=14; j++)
        {
            map[j][i] = &waterOB;
        }
    }

    waterCount = 27;
}

void waterRoom::moveCharacters()
{
    //spawn water for a single column
    for (int i = waterCount; i > waterCount-1; i--)
    {
        for(int j = 1; j <=14; j++)
        {
            map[j][i] = &waterOB;
        }
    }
    waterCount--; //decrease the column of water
    controlPlayer();
}

//prints out the message at the top of the screen
void waterRoom::printMessage()
{
    if(message == 0){
        std::cout << "\nWater begins to fill the room!\n";
        std::cout << "Goblin: 'mmmmmwwwwahahahahahaha'\n";
    }
}

//sets player at the left of the room
void waterRoom::setPlayerLeft()
{
    map[7][2] = hero;
	hero->setXCoord(7);
	hero->setYCoord(2);
}