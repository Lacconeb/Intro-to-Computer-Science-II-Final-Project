/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/

#include "room.hpp"
#include "entryRoom.hpp"
#include "goblinRoom.hpp"
#include "waterRoom.hpp"
#include "mazeRoom.hpp"
#include "bossRoom.hpp"
#include "princessRoom.hpp"
#include "controller.hpp"
#include "player.hpp"


using std::cout;
using std::endl;
using std::cin;

//create a new player
controller::controller()
{
    hero = new player();    
}

controller::~controller()
{
    delete gobRoom;
    delete entRoom;
    delete watRoom;
    delete mazRoom;
    delete bosRoom;
    delete priRoom;
    delete hero;
}

//function responsible for controlling the flow of the game
//creates all the rooms and sets all the connecting rooms
void controller::menu()
{
    for (int i = 0; i < 100; i++)
		cout << "\n";
	cout << "An evil and powerful warlock has attacked your hold and has taken your princess" << endl;
    cout << "                   You were injured during the struggle" << endl;
    cout << "                  Save the princess before you bleed out" << endl << endl << endl;
    cout << "                      Enter any number to continue" << endl;

    int check = 0;
    int option;
    
    do{
        
        cin >> option;

        if(cin.fail()){
            cin.clear();
            cin.ignore(256,'\n');
            cout << endl << "Please enter a number" << endl;

        }else {
            check = 1;
        }

    }while(check !=1);

    //create all the rooms for the game
    entRoom = new entryRoom(hero);
    gobRoom = new goblinRoom(hero);
    watRoom = new waterRoom(hero);
    mazRoom = new mazeRoom(hero);
    bosRoom = new bossRoom(hero);
    priRoom = new princessRoom(hero);

    //sets the connecting rooms
    entRoom->setTop(gobRoom);
    gobRoom->setBottom(entRoom);
    gobRoom->setRight(watRoom);
    gobRoom->setLeft(mazRoom);
    mazRoom->setRight(gobRoom);
    mazRoom->setLeft(bosRoom);
    bosRoom->setRight(mazRoom);
    bosRoom->setTop(priRoom);
    priRoom->setBottom(bosRoom);

    //sets current room to the entranceRoom
    currentRoom = entRoom;

    //while the player's health is above 0 continue the game
    while (hero->getHealth() > 0)
    {
         for (int j = 0; j < 100; j++)
		std::cout << "\n";

        //print the visuals for the room
        currentRoom->printRoom();

        //moves all the mapObjects and player
        currentRoom->moveCharacters();

        //checks to see if player is walking through an exit
        if (currentRoom->enterTop() == true)
        {
            currentRoom = currentRoom->getTop();
            currentRoom->setPlayerBottom();
        }
        else if (currentRoom->enterBottom() == true)
        {
            currentRoom = currentRoom->getBottom();
            currentRoom->setPlayerTop();
        }
        else if (currentRoom->enterRight() == true)
        {
            currentRoom = currentRoom->getRight();
            currentRoom->setPlayerLeft();
        }
        else if (currentRoom->enterLeft() == true)
        {
            currentRoom = currentRoom->getLeft();
            currentRoom->setPlayerRight();
        }

        //decrease the health of player by 1
        hero->decreaseHealth();
    }

    
}