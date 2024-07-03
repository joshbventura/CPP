/*****************************************
** File:    Weapon.h
** Project: CMSC 202 Project 4, Spring 2024
** Author:  Josh Ventura
** Date:    4/18/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the header file for Weapon.cpp which contains the constants and function definitions for the 
** Weapon class. 
**
***********************************************/




#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "Item.h"

//Constants
const string WEAPON = "**WEAPON** ";

// The Weapon is a type of item used by your ship. It affects attack.

class Weapon: public Item {
 public:
  // Name: Weapon(string name, string type, int value)
  // Description: Creates a new Weapon item
  // Preconditions: None
  // Postconditions: Can create a Weapon
  Weapon(string, string, int);
  // Name: Display
  // Description: Displays WEAPON, name, and value of weapon
  // Preconditions: None
  // Postconditions: Displays information about the weapon
  void Display();
};
#endif
