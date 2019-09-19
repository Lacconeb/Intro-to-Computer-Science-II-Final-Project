/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/

#ifndef BRIAN_LACCONE_WATERROOM_HPP
#define BRIAN_LACCONE_WATERROOM_HPP

#include "room.hpp"
#include "player.hpp"
#include "water.hpp"


class waterRoom : public room
{
private:
    water waterOB;
    int waterCount;

public:
    waterRoom(player*);
    void moveCharacters();
    void printMessage();
    void setPlayerLeft(); 

};

#endif