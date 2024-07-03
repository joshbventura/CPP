/*****************************************
** File:    Enemy.h
** Project: CMSC 202 Project 4, Spring 2024
** Author:  Josh Ventura
** Date:    4/18/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the header file for Enemy.cpp which contains the constants and function definitions for the 
** Enemy class. 
**
***********************************************/



#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Planet.h"

// Enemy are planets that can be used to harvest fuel from

//***Constants***
const int ENEMY_SPECIAL = 2; //Base addition for Enemy

class Enemy: public Planet {
 public:
  // Name: Enemy(string name, int challenge)
  // Description: Creates a new Enemy planet
  // Preconditions: None
  // Postconditions: Creates a new Enemy planet
  Enemy(string, int);
  // Name: GetType
  // Description: Returns type of planet
  // Preconditions: None
  // Postconditions: Returns the type of planet
  string GetType();
};
#endif
