/*****************************************
** File:    Item.h
** Project: CMSC 202 Project 4, Spring 2024
** Author:  Josh Ventura
** Date:    4/18/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the header file for Item.cpp which contains the constants and function definitions for the 
** Item class. 
**
***********************************************/


#ifndef _ITEM_H_
#define _ITEM_H_
#include <iostream>
#include <string>
using namespace std;

class Item {
 public:
  // Name: Item(string name, string type, int value) - Overload constructor
  // Description: Creates a new item of a specific type
  // Preconditions: None
  // Postconditions: Used by all child classes
  Item(string name, string type, int value);
  // Name: ~Item - Virtual Destructor
  // Description: Required because child classes exist
  // Preconditions: None
  // Postconditions: Nothing to deallocate
  virtual ~Item();
  // Name: GetType()
  // Description: Returns the type of item
  // Preconditions: None
  // Postconditions: Returns type of item (weapon, armor, or engine)
  string GetType();
  // Name: GetName()
  // Description: Returns the name of item
  // Preconditions: None
  // Postconditions: Returns name of item
  string GetName();
  // Name: GetValue
  // Description: Gets Value of item
  // Preconditions: None
  // Postconditions: Returns value of item
  int GetValue();
  // Name: Display()
  // Description: Used in child classes for special attacks
  // Preconditions: None
  // Postconditions: Used to call child class SpecialAttack
  virtual void Display() = 0;
private:
  string m_name; //Name of the item
  string m_type; //Type of item (armor, weapon, or engine)
  int m_value; //Value of the item
};
#endif
