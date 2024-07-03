/*****************************************
** File:    Proj5.cpp
** Project: CMSC 202 Project 5, Spring 2024
** Author:  Josh Ventura
** Date:    5/02/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the main driver fille for proj5.cpp 
**
***********************************************/
#include <iostream>
#include "MoviePlayer.h"
#include "Movie.h"

int main (int argc, char* argv[]) {
  string movieFile;
  cout << "Welcome to UMBC Movie Player"<<endl;
  if(argc > 1){
    movieFile = argv[1];
  } else{
    cout << "One movie files required - try again" << endl;
    cout << "./proj5 proj5_movies.txt" << endl;
    return 0;
  }
  MoviePlayer* myMovie = new MoviePlayer(movieFile);
  myMovie->StartPlayer();
  delete myMovie;
  return 0;
}
