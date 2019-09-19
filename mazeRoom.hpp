/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/

#ifndef BRIAN_LACCONE_MAZEROOM_HPP
#define BRIAN_LACCONE_MAZEROOM_HPP

#include "room.hpp"
#include "player.hpp"
#include "throwingStar.hpp"
#include "lever.hpp"


class mazeRoom : public room
{
private:
    bool flipSwitch;
    lever leverOB;
    mapObjects *enemy[4];


public:
    mazeRoom(player*);
    ~mazeRoom();
    void moveCharacters();
    void printMessage();
    void setPlayerRight(); 
    void setPlayerLeft();
    void moveEnemy();
    void interactions();
    bool enterLeft();
};

#endif