/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/

#include <iostream>
#include <string>
#include "player.hpp"

//constructor that sets the symbol, health, and sets the inventory to nothing
player::player()
{
     health = 500;
     symbol = '@';
     for(int i = 0; i < 3; i++)
        inventory[i] = "";
}

player::~player()
{

}

//adds the parameter string to the inventory array
void player::addToInventory(std::string item)
{
    bool isPlaced = false;
	int index = 0;
		while (isPlaced == false)
		{
			if (inventory[index] == "")
			{
				inventory[index] = item;
				isPlaced = true;
			}
			index++;
		}
}

//checks to see if an item is in the inventory
bool player::checkInventory(std::string item)
{
    
    bool isFound = false;

	for (int i = 0; i < 3; i++)
	{
		if (inventory[i] == item)
			isFound = true;
	}

	return isFound;
}

//prints the inventory to the screen
void player::printInventory()
{
    std::cout << "\nInventory:";
	for (int i = 0; i < 3; i++)
	{
		std::cout << " ";
		std::cout << inventory[i];
	}
}

//decrease the players health by 1 and ends game when the health == 0
void player::decreaseHealth()
{
    health = health - 1;

	if(health == 0)
	{
		for (int i = 0; i < 100; i++)
			std::cout << "\n";

		std::cout << "\nYou collapsed from exhaustion :(\n";
		std::cout << "\nTry again!\n\n";
	}
		
}

//returns health int
int player::getHealth()
{
    return health;
}

//sets the players health to 0
void player::kill()
{
    health = 0;
}