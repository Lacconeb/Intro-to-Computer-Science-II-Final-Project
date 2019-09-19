/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/

#ifndef BRIAN_LACCONE_PRINCESSROOM_HPP
#define BRIAN_LACCONE_PRINCESSROOM_HPP

#include "room.hpp"
#include "player.hpp"
#include "throwingStar.hpp"
#include "princess.hpp"
#include "water.hpp"


class princessRoom : public room
{
private:
    princess princessOB;
    mapObjects *enemy[5];


public:
    princessRoom(player*);
    ~princessRoom();
    void moveCharacters();
    void printMessage();
    void setPlayerBottom(); 
    void moveEnemy();
    void interactions();
    bool enterBottom();
};

#endif