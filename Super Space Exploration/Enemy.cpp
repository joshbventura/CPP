/*****************************************
** File:    Enemy.cpp
** Project: CMSC 202 Project 4, Spring 2024
** Author:  Josh Ventura
** Date:    4/18/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the .cpp file for Enemy.h which contains the function implementations 
** for the functions outlined in the .h file. This implements the functions needed to make an instance of the Enemy class. 
**
***********************************************/

#include "Enemy.h"


 // Name: Enemy(string name, int challenge)
  // Description: Creates a new Enemy planet
  // Preconditions: None
  // Postconditions: Creates a new Enemy planet
  Enemy::Enemy(string name, int challenge):Planet(name, challenge){}

  // Name: GetType
  // Description: Returns type of planet
  // Preconditions: None
  // Postconditions: Returns the type of planet
  string Enemy::GetType(){
    return "Enemy";
  }