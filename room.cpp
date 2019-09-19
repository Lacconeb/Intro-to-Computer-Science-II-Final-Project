/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/

#include "room.hpp"
#include <iostream>

room::room(player* p)
{
    top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
	rows = 16; //16 rows for the map
	cols = 30; //30 columns for the map
    hero = p; //set player* hero
    message = 0;

    //create empty map
	map = new mapObjects**[rows];
	for (int i = 0; i < rows; i++)
		map[i] = new mapObjects*[cols];

	//set all map elements to NULL
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			map[i][j] = NULL;

	//make edges of map wall
	for (int i = 0; i < rows; i++)
	{
		map[i][0] = &wallOB;
		map[i][cols - 1] = &wallOB;
	}
	for (int j = 1; j < cols-1; j++)
	{
		map[0][j] = &wallOB;
		map[rows - 1][j] = &wallOB;
	}
}

room::~room()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			map[i][j] = NULL;
			delete map[i][j]; // delete stored pointer
		}
		delete[] map[i]; // delete sub array
	}
	delete[] map; //delete outer array
	
	map = NULL;

}

void room::moveCharacters()
{
	controlPlayer();
}

//controls the movements of the player
void room::controlPlayer()
{
    char choice = 'n';
    bool done = false;
    while (done != true){
        std::cout << "\nPlease enter a move\n";
        std::cin >> choice;

        switch (choice)
		{
		//move right
		case 'd': 
        
            done = true;

            if (hero->getYCoord() < cols - 1)
            {
                //set new position for hero and change old position to NULL
                if (map[hero->getXCoord()][hero->getYCoord() + 1] == NULL)
                {
                    map[hero->getXCoord()][hero->getYCoord() + 1] = hero;
                    map[hero->getXCoord()][hero->getYCoord()] = NULL;
                    hero->setYCoord(hero->getYCoord() + 1);
                }
                else if (map[hero->getXCoord()][hero->getYCoord() + 1]->getName() == "water") //if the player is trying to move to a position holding a water object
                {
                    
                     for (int i = 0; i < 100; i++)
		                std::cout << "\n";

                    std::cout << "\nYou drowned!!!\n"
                            << "\nDon't Trust Nasty Goblins\n"<< std::endl;
                    
                    
                    hero->kill();
                }
                else if (map[hero->getXCoord()][hero->getYCoord() + 1]->getName() == "throwingStar")
                {
                    
                     for (int i = 0; i < 100; i++)
		                std::cout << "\n";

                    std::cout << "\nYou Died!!!\n"
                            << "\nWatch out for throwing stars\n"<< std::endl;
                    
                    
                    hero->kill();
                }
            }
				  break;

         //move down
		 case 's': 
        
            done = true;
        
            if (hero->getXCoord() < rows - 1)
            {
                if (map[hero->getXCoord() + 1][hero->getYCoord()] == NULL)
                {
                    //set new position for hero and change old position to NULL
                    map[hero->getXCoord() + 1][hero->getYCoord()] = hero;
                    map[hero->getXCoord()][hero->getYCoord()] = NULL;
                    hero->setXCoord(hero->getXCoord() + 1);
                }
                else if (map[hero->getXCoord() + 1][hero->getYCoord()]->getName() == "water") //if the player is trying to move to a position holding a water object
                {
                    
                     for (int i = 0; i < 100; i++)
		                std::cout << "\n";

                    std::cout << "\n    You drowned!!!\n"
                            << "\n  Don't Trust Nasty Goblins\n"<< std::endl;
                    
                    
                    hero->kill();
                }
                else if (map[hero->getXCoord() + 1][hero->getYCoord()]->getName() == "throwingStar") //if the player is trying to move to a position holding a throwingStar object
                {
                    
                     for (int i = 0; i < 100; i++)
		                std::cout << "\n";

                    std::cout << "\nYou Died!!!\n"
                            << "\nWatch out for throwing stars\n"<< std::endl;
                    
                    
                    hero->kill();
                }
            }
				  break;

         //move left
		 case 'a': 
        
            done = true;

            if (hero->getYCoord() > 0)
            {
                if (map[hero->getXCoord()][hero->getYCoord() - 1] == NULL)
                {
                    //set new position for hero and change old position to NULL
                    map[hero->getXCoord()][hero->getYCoord() - 1] = hero;
                    map[hero->getXCoord()][hero->getYCoord()] = NULL;
                    hero->setYCoord(hero->getYCoord() - 1);
                }
                else if (map[hero->getXCoord()][hero->getYCoord() - 1]->getName() == "water") //if the player is trying to move to a position holding a water object
                {
                    
                     for (int i = 0; i < 100; i++)
		                std::cout << "\n";

                    std::cout << "\nYou drowned!!!\n"
                            << "\nDon't Trust Nasty Goblins\n"<< std::endl;
                    
                    
                    hero->kill();
                }
                else if (map[hero->getXCoord()][hero->getYCoord() - 1]->getName() == "throwingStar") //if the player is trying to move to a position holding a throwingStar object
                {
                    
                     for (int i = 0; i < 100; i++)
		                std::cout << "\n";

                    std::cout << "\nYou Died!!!\n"
                            << "\nWatch out for throwing stars\n"<< std::endl;
                    
                    
                    hero->kill();
                }
            }
                break;

         //move up
		 case 'w': 
        
            done = true;
        
            if (hero->getXCoord() < rows - 1)
            {
                if (map[hero->getXCoord() - 1][hero->getYCoord()] == NULL)
                {
                    //set new position for hero and change old position to NULL
                    map[hero->getXCoord() - 1][hero->getYCoord()] = hero;
                    map[hero->getXCoord()][hero->getYCoord()] = NULL;
                    hero->setXCoord(hero->getXCoord() - 1);
                }
                else if (map[hero->getXCoord() - 1][hero->getYCoord()]->getName() == "water") //if the player is trying to move to a position holding a water object
                {
                    
                    for (int i = 0; i < 100; i++)
		                std::cout << "\n";

                    std::cout << "\nYou drowned!!!\n"
                            << "\nDon't Trust Nasty Goblins\n"<< std::endl;
                    
                    
                    hero->kill();
                }
                else if (map[hero->getXCoord() - 1][hero->getYCoord()]->getName() == "throwingStar") //if the player is trying to move to a position holding a throwingStar object
                {
                    
                     for (int i = 0; i < 100; i++)
		                std::cout << "\n";

                    std::cout << "\nYou Died!!!\n"
                            << "\nWatch out for throwing stars\n"<< std::endl;
                    
                    
                    hero->kill();
                }
            }
				  break;
        //interact
        case 'e': 
        
            done = true;
        
            interactions();
           

				  break;

        }//end switch

    }//end while
}

//returns room to the right
room* room::getRight() const
{
    return right;
}

//returns room to the left
room* room::getLeft() const
{
    return left;
}

//returns room at the top
room* room::getTop() const
{
    return top;
}

//returns room at the bottom
room* room::getBottom() const
{
    return bottom;
}

//set room to the right
void room::setRight(room* r)
{
    right = r;
}

//set room to the left
void room::setLeft(room* r)
{
    left = r;
}

//set room at the top
void room::setTop(room* r)
{
    top = r;
}

//set room at the bottom
void room::setBottom(room* r)
{
    bottom = r;
}

//print the room to the screen
void room::printRoom()
{
    printMessage(); 

	hero->printInventory();//print player inventory
	std::cout << "\nCurrent Health: " << this->hero->getHealth() << "\n";//print health

    std::cout << "\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (map[i][j] == NULL)
				std::cout << '.';
			else
				std::cout << map[i][j]->getSymbol();
		}
		std::cout << "\n";
	}
	std::cout << "\n      w = up    a = right     Press e to"
		<< "\n      s = down  d = left       interact";
}

//prints the message at the top of the screen
void room::printMessage()
{
    std::cout << "\nShould not show up. Parent class\n";
}

void room::setPlayerTop()
{
    //parent does nothing
}

void room::setPlayerBottom()
{
    //parent does nothing
}

void room::setPlayerLeft()
{
    //parent does nothing
}

void room::setPlayerRight()
{
    //parent does nothing
}

//returns whether the player will move to the top room
bool room::enterTop()
{
    return false;
}

//returns whether the player will move to the bottom room
bool room::enterBottom()
{
    return false;
}

//returns whether the player will move to the right room
bool room::enterRight()
{
    return false;
}

//returns whether the player will move to the left room
bool room::enterLeft()
{
    return false;
}

//called when 'e' is pressed
void room::interactions()
{
    //parent does nothing
}
