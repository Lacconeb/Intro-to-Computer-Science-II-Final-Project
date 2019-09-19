/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/

#ifndef BRIAN_LACCONE_GOBLINROOM_HPP
#define BRIAN_LACCONE_GOBLINROOM_HPP

#include "room.hpp"
#include "player.hpp"
#include "goblin.hpp"
#include "key.hpp"

class goblinRoom : public room
{
private:
    goblin goblinOB;
    key keyOB;

public:
    goblinRoom(player*);
    void printMessage();
    void setPlayerBottom(); 
    void setPlayerRight();
    void setPlayerLeft();
    bool enterBottom();  
    bool enterRight();
    bool enterLeft();
    void interactions();

};

#endif