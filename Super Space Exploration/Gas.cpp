 /*****************************************
** File:    Gas.cpp
** Project: CMSC 202 Project 4, Spring 2024
** Author:  Josh Ventura
** Date:    4/18/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the .cpp file for Gas.h which contains the function implementations 
** for the functions outlined in the .h file. This implements the functions needed to make an instance of the Gas class. 
**
***********************************************/

 #include "Gas.h"
 
  // Name: Gas(string name)
  // Description: Creates a new Gas planet with name and challenge
  // Preconditions: None
  // Postconditions: Creates a new Gas planet
  Gas::Gas(string name, int challenge):Planet(name, challenge){}


  // Name: GetType
  // Description: Returns type of planet
  // Preconditions: None
  // Postconditions: Returns the type of planet
  string Gas::GetType(){
    return "Gas";
  }