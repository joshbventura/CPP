/*****************************************
** File:    Gas.h
** Project: CMSC 202 Project 4, Spring 2024
** Author:  Josh Ventura
** Date:    4/18/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the header file for Gas.cpp which contains the constants and function definitions for the 
** Gas class. 
**
***********************************************/
#ifndef _GAS_H_
#define _GAS_H_

#include "Planet.h"

// Gas are planets that can be used to harvest fuel from

class Gas: public Planet {
 public:
  // Name: Gas(string name)
  // Description: Creates a new Gas planet with name and challenge
  // Preconditions: None
  // Postconditions: Creates a new Gas planet
  Gas(string, int);
  // Name: GetType
  // Description: Returns type of planet
  // Preconditions: None
  // Postconditions: Returns the type of planet
  string GetType();
};
#endif
