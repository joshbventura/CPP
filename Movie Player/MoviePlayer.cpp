/*****************************************
** File:    MoviePlayer.cpp
** Project: CMSC 202 Project 5, Spring 2024
** Author:  Josh Ventura
** Date:    5/02/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the .cpp file for MoviePlayer.h which contains the function implementations 
** for the functions outlined in the .h file. This implements the functions needed to make an instance of the MoviePlayer class. 
**
***********************************************/

#include "MoviePlayer.h"

#include <iostream>
#include <string>
#include <vector> 
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>


using namespace std; 
 
  //Name: MoviePlayer - Default Constructor
  //Precondition: None
  //Postcondition: Creates a new MoviePlayer with m_filename of "proj5_movies.txt"
  MoviePlayer::MoviePlayer(){
    m_filename = "proj5_movies.txt";
  }



  //Name: MoviePlayer - Overloaded Constructor
  //Precondition: None
  //Postcondition: Creates a new MoviePlayer with passed filename
  MoviePlayer::MoviePlayer(string filename){
    m_filename = filename; 
  }



  //Name: ~MoviePlayer - Destructor
  //Precondition: None
  //Postcondition: Deallocates movies from m_movieCatalog
  MoviePlayer::~MoviePlayer(){

    for (unsigned int i = 0; i < m_movieCatalog.size(); i++) {
        delete m_movieCatalog[i]; 
        m_movieCatalog[i] = nullptr; 
    }
    m_movieCatalog.clear();   

  }




  //Name: LoadCatalog()
  //Precondition: Requires m_filename to be populated
  //Postcondition: Dynamically allocates each movie and inserts into m_movieCatalog
  //Hint:          Allowed to use stoi (string to integer) if needed
  //Hint:          Allowed to use stoul (string to long) if needed
  void MoviePlayer::LoadCatalog(){
     string title, rating, genre, syear, director, star, sbudget, sgross, studio, sruntime; 
     int year, runtime; 
     long budget, gross; 

    fstream newFile; 
    newFile.open(m_filename);

    if(newFile.is_open()){
        cout << "Opened file" << endl; 
        while((getline(newFile, title, ';')&& 
                getline(newFile, rating, ';') && 
                getline(newFile, genre, ';') && 
                getline(newFile, syear, ';') && 
                getline(newFile, director, ';') && 
                getline(newFile, star, ';') &&
                getline(newFile, sbudget, ';') && 
                getline(newFile, sgross, ';') && 
                getline(newFile, studio, ';') && 
                getline(newFile, sruntime) )){

                year = stoi(syear); 
                runtime = stoi(sruntime);
                budget = stoul(sbudget); 
                gross = stoul(sgross); 


                Movie *movie = new Movie(title, rating, genre, year, director, star, budget, gross, studio, runtime);
                m_movieCatalog.push_back(movie);
                //cout << *movie << endl; 
    }
     
     cout << "Movie loaded: " << m_movieCatalog.size() << endl; 

  } 
  else{
     cout << "ERROR: File could not be loaded" << endl; 
  }
  newFile.close();
  }




  //Name: MainMenu
  //Precondition: None
  //Postcondition: Manages the menu
  void MoviePlayer::MainMenu(){
int choice = 0;
while(choice !=6){

    cout << "What would you like to do?:" << endl;  
    cout << "1. Display Movie by Type and Year" << endl;
    cout << "2. Add Movie to Playlist" << endl;
    cout << "3. Display Playlist" << endl;
    cout << "4. Sort Playlist by Year" << endl; 
    cout << "5. Search for Movie" << endl;
    cout << "6. Quit" << endl; 
    cin >> choice;

    while(choice < 1 || choice >6 ){
    cout << "Invalid input!" << endl;
    cout << "What would you like to do?:" << endl;  
    cout << "1. Display Movie by Type and Year" << endl;
    cout << "2. Add Movie to Playlist" << endl;
    cout << "3. Display Playlist" << endl;
    cout << "4. Sort Playlist by Year" << endl; 
    cout << "5. Search for Movie" << endl;
    cout << "6. Quit" << endl; 
    cin >> choice;

    }

if(choice == 1){
    DisplayMovie();
}
else if(choice == 2){
    AddMovie();
}
else if (choice == 3){
    DisplayPlaylist();
}
else if (choice == 4){
    SortPlaylist();
}
else if (choice ==5){
    return; 
}
}

  }



  //Name: DisplayMovie
  //Desc: Asks user for year (between min and max year)
  //      Asks user for genre (no validation)
  //      Displays all movies with year and genre with location in vector
  //      Uses iterators
  //Precondition: m_movieCatalog, MIN_YEAR, and MAX_YEAR are all populated
  //Postcondition: Returns count of movies found matching year and genre else 0
  //Hint: Allowed to use ** if necessary
  int MoviePlayer::DisplayMovie(){
    int yearInput, count; 
    string genreInput; 
    

    cout << "Which year would you like to display? (1980-2020)" << endl;
    cin >> yearInput;
    cout << "******" << yearInput << "******" << endl; 

    cout << "Which genre would you like?" << endl;
    cin >> genreInput; 
    cout << "******" << genreInput << "******" << endl;
     
    cout << "MOVIE TOTAL: " << m_movieCatalog.size() << endl; 

    for (unsigned int i = 0; i < m_movieCatalog.size(); i++) {
        if (m_movieCatalog[i]->GetYear() == yearInput && m_movieCatalog[i]->GetGenre() == genreInput) {
            cout << i+1 << " " << *m_movieCatalog[i] << endl; 
            count++;
        }
    }

    cout << count << " movies found." << endl;
    return count; 

  }



  //Name: AddMovie
  //Desc: Calls DisplayMovie where user chooses year and genre
  //      User enters index of movie to choose
  //      Validates for number to be between 0 - m_movieCatalog size
  //      Does NOT validate that movie chosen was from year and genre
  //      Uses overloaded << operator to display the example below
  //Example: Airplane! by Jim Abrahams from 1980 added to the playlist
  //Precondition: m_movieCatalog is populated
  //Postcondition: Adds pointer from m_catalog and inserts into m_playList
  void MoviePlayer::AddMovie(){
    int movieIndex = 0; 

    cout << "Choose the movie you would like to add to playlist. " << endl; 
    DisplayMovie(); 
    cout << "Enter the number of the movie you would like to add. " << endl; 
    cin >> movieIndex; 
    
    if (movieIndex >= 0 && movieIndex < static_cast<int>(m_movieCatalog.size())) {
        Movie* selectedMovie = m_movieCatalog[movieIndex-1];
        m_playList.PushBack(selectedMovie);  // Add the movie to the playlist queue
        cout << *selectedMovie << " Added to the playlist. " << endl;
      /*  cout << selectedMovie->GetTitle() << " by " << selectedMovie->GetDirector()
             << " from " << selectedMovie->GetYear() << " added to the playlist." << endl; */
    } else {
        cout << "Enter a valid index!" << endl;
    }

  }



  //Name: DisplayPlaylist
  //Precondition: None (will indicate if list is empty)
  //Postcondition: Displays the playlist using the overloaded << operator
  void MoviePlayer::DisplayPlaylist(){

    if (m_playList.GetSize() == 0) {
        cout << "The playlist is currently empty." << endl;
    } else {
        cout << "Current Playlist:" << endl;
        for (int i = 0; i < m_playList.GetSize(); i++) {
            cout << i + 1 << ". " << *(m_playList.At(i)) << endl;
        }
    }

  }



  //Name: SortPlaylist
  //Precondition: None (will indicate if list is empty)
  //Postcondition: Sorts the playlist by year
  void MoviePlayer::SortPlaylist(){
    if (m_playList.GetSize() < 2){
        cout << "The playlist needs at lesat two movies to sort" << endl; 
    } else {
        return;
    }
  }


  





  //Name: StartPlayer
  //Precondition: None (file name has already been provided)
  //Postcondition: Loads file and calls main menu
  void MoviePlayer::StartPlayer(){

    LoadCatalog();
    MainMenu();

  }








  //OPTIONAL: EXTRA CREDIT
  //Name: SearchMovie
  //See project document for details - must complete and submit base project first
