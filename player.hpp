/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/

#ifndef BRIAN_LACCONE_PLAYER_HPP
#define BRIAN_LACCONE_PLAYER_HPP

#include <iostream>
#include <string>
#include "mapObjects.hpp"


class player : public mapObjects 
{
protected:
	std::string inventory[3];
public:
	player();
	~player();
	void addToInventory(std::string);
	bool checkInventory(std::string);
	void printInventory();
	void decreaseHealth();
	int getHealth();
	void kill();
};

#endif