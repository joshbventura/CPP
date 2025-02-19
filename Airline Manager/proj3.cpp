/*****************************************
** File:    Proj3.cpp
** Project: CMSC 202 Project 2, Spring 2024
** Author:  Josh Ventura
** Date:    4/2/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the .cpp file for proj3, which creates begins an instance of the navigator class
***********************************************/

#include "Navigator.h"
#include <iostream>
using namespace std;

int main (int argc, char* argv[]) {
  if (argc < 2)
    {
      cout << "You are missing a data file." << endl;
      cout << "Expected usage ./proj3 proj3_data.txt" << endl;
      cout << "File 1 should be a file with airport data" << endl;
    }
  else
    {
      cout << endl << "***Navigator***" << endl << endl;
      Navigator S = Navigator(argv[1]);
      S.Start();
    }
  return 0;
}
