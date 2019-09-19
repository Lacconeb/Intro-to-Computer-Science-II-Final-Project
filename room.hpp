/*************************************************************************
* Author: Brian Laccone
* Date: 3/15/2017
* Assignment: Final Project
*************************************************************************/

#ifndef BRIAN_LACCONE_ROOM_HPP
#define BRIAN_LACCONE_ROOM_HPP

#include<iostream>
#include "mapObjects.hpp"
#include "player.hpp"
#include "wall.hpp"

class room
{
protected:

   room *top;
   room *right;
   room *bottom;
   room *left;
   int rows;
   int cols;
   mapObjects ***map;
   player *hero;
   wall wallOB;
   int message;

public:
  room(player* p);
  virtual ~room() = 0;
  virtual void moveCharacters();
  void controlPlayer();
  virtual room* getRight() const;
  virtual room* getLeft() const;
  virtual room* getTop() const;
  virtual room* getBottom() const;
  virtual void setRight(room*);
  virtual void setLeft(room*);
  virtual void setTop(room*);
  virtual void setBottom(room*);
  virtual void printRoom();
  virtual void printMessage();
  virtual void setPlayerTop();
  virtual void setPlayerBottom();
  virtual void setPlayerLeft();
  virtual void setPlayerRight();
  virtual bool enterTop();
  virtual bool enterBottom();
  virtual bool enterRight();
  virtual bool enterLeft();
  virtual void interactions();

};

#endif