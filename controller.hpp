/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/

#ifndef BRIAN_LACCONE_CONTROLLER_HPP
#define BRIAN_LACCONE_CONTROLLER_HPP

#include "room.hpp"
#include "player.hpp"

#include <string>


class controller
{
private:

    std::string message; //message at top of screen

    player *hero;
    room *currentRoom;
    room *gobRoom;
    room *entRoom;
    room *watRoom;
    room *mazRoom;
    room *bosRoom;
    room *priRoom;

public:

    controller();
    ~controller();
    void menu();
    

};

#endif