/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/
#include "mapObjects.hpp"

mapObjects::mapObjects()
{
    //parent class
}

mapObjects::~mapObjects()
{
    
}

//returns the symbol char
char mapObjects::getSymbol()
{
    return symbol;
}

//sets the x coord
void mapObjects::setXCoord(int x)
{
    xCoord = x;
}

//sets the y coord
void mapObjects::setYCoord(int y)
{
    yCoord = y;
}

//returns the x coord
int mapObjects::getXCoord() const
{
    return xCoord;
}

//returns the y coord
int mapObjects::getYCoord() const
{
    return yCoord;
}

//returns the name of the mapObject
std::string mapObjects::getName()
{
    return name;
}

//sets the orientation of object
void mapObjects::setOrientation(std::string s)
{
    orientation = s;
}

//returns the orientation of object
std::string mapObjects::getOrientation()
{
    return orientation;
}