/*****************************************
** File:    Engine.cpp
** Project: CMSC 202 Project 4, Spring 2024
** Author:  Josh Ventura
** Date:    4/18/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the .cpp file for Engine.h which contains the function implementations 
** for the functions outlined in the Engine.h file. This implements the functions needed to make an instance of the Engine class. 
**
***********************************************/

#include "Engine.h"
#include <iostream>

 // Name: Engine(string name, string type, int value)
  // Description: Creates a new Engine item
  // Preconditions: None
  // Postconditions: Can create a Engine
  Engine::Engine(string name, string type, int value):Item(name, type, value){}




  // Name: Display
  // Description: Displays ENGINE, name, and value of engine item
  // Preconditions: None
  // Postconditions: Displays information about the engine
  void Engine::Display(){
    cout << ENGINE << GetName() << "(" << GetValue() << ")" << endl; 
  }