/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/

#ifndef BRIAN_LACCONE_ENTRYROOM_HPP
#define BRIAN_LACCONE_ENTRYROOM_HPP

#include "room.hpp"
#include "player.hpp"
#include "blood.hpp"

class entryRoom : public room
{
private:
    blood bloodOB;

public:
    entryRoom(player*);
    void printMessage();
    void interactions();
    void setPlayerTop(); 
    bool enterTop();    

};

#endif