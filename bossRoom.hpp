/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/

#ifndef BRIAN_LACCONE_BOSSROOM_HPP
#define BRIAN_LACCONE_BOSSROOM_HPP

#include "room.hpp"
#include "player.hpp"
#include "throwingStar.hpp"
#include "warlock.hpp"
#include "bow.hpp"
#include "archerX.hpp"
#include "blood.hpp"


class bossRoom : public room
{
private:
    warlock warlockOB;
    bow bowOB;
    archerX archerXOB;
    blood bloodOB;
    mapObjects *enemy[6];


public:
    bossRoom(player*);
    ~bossRoom();
    void moveCharacters();
    void printMessage();
    void setPlayerRight(); 
    void setPlayerTop();
    void moveEnemy();
    void interactions();
    bool enterRight();
    bool enterTop();
};

#endif

