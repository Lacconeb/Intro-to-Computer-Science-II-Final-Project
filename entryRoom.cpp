/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/
#include "entryRoom.hpp"
#include "player.hpp"

entryRoom::entryRoom(player *p) : room(p)
{
    //set player position
    map[14][14] = p;
	hero->setXCoord(14);
	hero->setYCoord(14);

    //set bottom entrance walls
    map[14][13] = &wallOB;
    map[14][15] = &wallOB;
    
    //set blood at top right
    map[3][20] = &bloodOB;
    map[3][21] = &bloodOB;
    map[4][20] = &bloodOB;
    map[4][21] = &bloodOB;

}

//prints out the message at the top of the screen
void entryRoom::printMessage()
{
    if(message == 0){
        std::cout << "\nYou see a puddle of liquid in the distance"
         << "\nYou should go investigate it\n";
    }else if(message == 1){ //once the puddle is interacted with
        std::cout << "\nYou touch the puddle and realize it is blood"
         << "\nThe princess must have gone this way\n";
         message = 2;
    }else if(message == 2){ //after a step the door at top will open
        std::cout << "\nA door has opened up\n";
        map[1][13] = &wallOB;
        map[1][15] = &wallOB;
    }
}

//checks for interactable objects once 'e' is pressed
void entryRoom::interactions()
{
    bool interact = false;

    if(map[hero->getXCoord()+1][hero->getYCoord()] == &bloodOB) //if blood object is below player
    {
        interact = true;
    }
    else if(map[hero->getXCoord()-1][hero->getYCoord()] == &bloodOB) //if blood object is above player
    {
        interact = true;
    }
    else if(map[hero->getXCoord()][hero->getYCoord()+1] == &bloodOB) //if blood object is to the right of the player
    {
        interact = true;
    }
    else if(map[hero->getXCoord()][hero->getYCoord()-1] == &bloodOB) //if blood object is to the left of the player
    {
        interact = true;
    }

    if(interact == true){ //change message if the object is interacted with
        message = 1;
    }

}

//sets player at the top of the room
void entryRoom::setPlayerTop()
{
    hero->setXCoord(2);
	hero->setYCoord(14);
    map[2][14] = hero;
}

//checks if the player is at the exit up top
bool entryRoom::enterTop()
{
    bool move = false;
    if((top != NULL) && (message == 2)){
        if ((map[1][14] != NULL) && (map[1][14]->getSymbol() == '@')){
            map[1][14] = NULL;
            move = true;
        }
    }

    return move;
}
