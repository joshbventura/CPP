/*****************************************
** File:    Weapon.cpp
** Project: CMSC 202 Project 4, Spring 2024
** Author:  Josh Ventura
** Date:    4/18/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the .cpp file for Weapon.h which contains the function implementations 
** for the functions outlined in the .h file. This implements the functions needed to make an instance of the Weapon class. 
**
***********************************************/

 #include "Weapon.h"


 // Name: Weapon(string name, string type, int value)
  // Description: Creates a new Weapon item
  // Preconditions: None
  // Postconditions: Can create a Weapon
  Weapon::Weapon(string name, string type, int value):Item(name,type,value){}


  // Name: Display
  // Description: Displays WEAPON, name, and value of weapon
  // Preconditions: None
  // Postconditions: Displays information about the weapon
  void Weapon::Display(){
    cout << WEAPON << GetName() << "(" << GetValue() << ")" << endl; 
  }