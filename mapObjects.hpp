/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/

#ifndef BRIAN_LACCONE_MAPOBJECTS_HPP
#define BRIAN_LACCONE_MAPOBJECTS_HPP

#include <string>

class mapObjects
{
protected:
    char symbol;
    int xCoord;
    int yCoord;
    bool moving;
    int health;
    std::string name;
    std::string orientation;
   

public:
    mapObjects();
    virtual ~mapObjects() = 0;
    char getSymbol();
    void setXCoord(int);
    void setYCoord(int);
    int getXCoord() const;
    int getYCoord() const;
    std::string getName();
    void setOrientation(std::string);
    std::string getOrientation();
    

};

#endif