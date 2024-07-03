/*****************************************
** File:    Engine.h
** Project: CMSC 202 Project 4, Spring 2024
** Author:  Josh Ventura
** Date:    4/18/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the header file for Engine.cpp which contains the constants and function definitions for the 
** Engine class. 
**
***********************************************/



#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "Item.h"

//Constants
const string ENGINE = "->ENGINE-> ";

// The Engine is a type of item used by your ship. It affects engine.

class Engine: public Item {
 public:
  // Name: Engine(string name, string type, int value)
  // Description: Creates a new Engine item
  // Preconditions: None
  // Postconditions: Can create a Engine
  Engine(string, string, int);
  // Name: Display
  // Description: Displays ENGINE, name, and value of engine item
  // Preconditions: None
  // Postconditions: Displays information about the engine
  void Display();
};
#endif
