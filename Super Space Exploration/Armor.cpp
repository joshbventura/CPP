/*****************************************
** File:    Armor.cpp
** Project: CMSC 202 Project 4, Spring 2024
** Author:  Josh Ventura
** Date:    4/18/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the .cpp file for Armor.h which contains the function implementations 
** for the functions outlined in the .h file. This implements the functions needed to make an instance of the armor class. 
**
***********************************************/


#include "Armor.h"
#include <iostream>
using namespace std; 


  // Name: Armor(string name, string type, int value)
  // Description: Creates a new Armor item
  // Preconditions: None
  // Postconditions: Can create a Armor item
  Armor::Armor(string name, string type, int value): Item(name,type,value){}

  
  // Name: Display
  // Description: Displays ARMOR, name, and value of armor
  // Preconditions: None
  // Postconditions: Displays information about the armor
  void Armor::Display(){
    cout << ARMOR << GetName() << "(" << GetValue() << ")" << endl; 
  }