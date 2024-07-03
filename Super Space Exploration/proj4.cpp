/*****************************************
** File:    Proj4.cpp
** Project: CMSC 202 Project 4, Spring 2024
** Author:  Josh Ventura
** Date:    4/18/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the .cpp file for proj4, which creates begins an instance of the game class
***********************************************/

#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
  if( argc != 3) {
    cout << "This requires an item and planet file to be loaded." << endl;
    cout << "Usage: ./proj4 proj4_items.txt proj4_planets.txt" << endl;
  }

  cout << "Loading files: " << argv[1] << " and " << argv[2]
       << endl << endl;

  string itemName = argv[1];
  string planetName = argv[2];
  srand (time(NULL));
  Game g(itemName, planetName);
  g.StartGame();
  return 0;
}
