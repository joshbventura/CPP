/*****************************************
** File:    Item.cpp
** Project: CMSC 202 Project 4, Spring 2024
** Author:  Josh Ventura
** Date:    4/18/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the .cpp file for Item.h which contains the function implementations 
** for the functions outlined in the .h file. This implements the functions needed to make an instance of the Item class. 
**
***********************************************/

#ifndef ITEM_CPP
#define ITEM_CPP

#include "Item.h"
#include <iostream>
using namespace std; 


 // Name: Item(string name, string type, int value) - Overload constructor
  // Description: Creates a new item of a specific type
  // Preconditions: None
  // Postconditions: Used by all child classes
  Item::Item(string name, string type, int value){
    m_name = name;
    m_type = type; 
    m_value = value; 
  }


  // Name: ~Item - Virtual Destructor
  // Description: Required because child classes exist
  // Preconditions: None
  // Postconditions: Nothing to deallocate
  Item::~Item(){}



  // Name: GetType()
  // Description: Returns the type of item
  // Preconditions: None
  // Postconditions: Returns type of item (weapon, armor, or engine)
  string Item::GetType(){
    return m_type; 
  }


  // Name: GetName()
  // Description: Returns the name of item
  // Preconditions: None
  // Postconditions: Returns name of item
  string Item::GetName(){
    return m_name; 
  }


  // Name: GetValue
  // Description: Gets Value of item
  // Preconditions: None
  // Postconditions: Returns value of item
  int Item::GetValue(){
    return m_value; 
  }


  // Name: Display()
  // Description: Used in child classes for special attacks
  // Preconditions: None
  // Postconditions: Used to call child class SpecialAttack
  void Item::Display(){}





#endif