/*****************************************
** File:    Mining.cpp
** Project: CMSC 202 Project 4, Spring 2024
** Author:  Josh Ventura
** Date:    4/18/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the .cpp file for Mining.h which contains the function implementations 
** for the functions outlined in the .h file. This implements the functions needed to make an instance of the Mining class. 
**
***********************************************/

#include "Mining.h"
  
  
// Name: Mining(string name, int challenge)
// Description: Creates a new Mining planet
// Preconditions: None
// Postconditions: Creates a new Mining planet
Mining::Mining(string name, int challenge):Planet(name, challenge){}

  
// Name: GetType
// Description: Returns type of planet
// Preconditions: None
// Postconditions: Returns the type of planet
string Mining::GetType(){
  return "Mining";
 }