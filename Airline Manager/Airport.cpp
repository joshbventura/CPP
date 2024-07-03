/*****************************************
** File:    Airport.cpp
** Project: CMSC 202 Project 3, Spring 2024
** Author:  Josh Ventura
** Date:    4/2/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the .cpp file for Airport.h which contains the function implementations 
** for the functions outlined in the .h file. This implements the functions needed to make an instance of the Airport class. 
**
***********************************************/
  
  
  #include "Airport.h"
  // Name: Airport() - Default Constructor
  // Desc: Used to build a new empty airport
  // Preconditions: None
  // Postconditions: Creates a new Airport for use in a Route
  Airport::Airport(){
    m_code = "New Code"; 
    m_name = "New Name";
    m_city = "New City";
    m_country = "New Country";
    m_north = 0;
    m_west = 0; 
    m_next = nullptr;

  }


  // Name: Airport(string, string, string, string, double, double)
  // Overloaded Constructor
  // Desc: Used to build a new Airport passing it a
  //   airport code, name, city, country, north, and west
  // Preconditions: None
  // Postconditions: Creates a new airport for use in a Route
  Airport::Airport(string code, string name, string city, string country , double north, double west){
    m_code = code;
    m_name = name; 
    m_city = city;
    m_country = country;
    m_north = north;
    m_west = west; 
    m_next = nullptr;
  }



  // Name: ~Airport() - Destructor
  // Desc: Used to destruct a airport
  //**This function should be empty but must be implemented
  // Preconditions: There is an existing airport
  // Postconditions: Airport is deallocated and has no memory leaks!
 Airport::~Airport(){}



  // Name: GetCode()
  // Desc: Returns the three letter code of the airport
  // Preconditions: None
  // Postconditions: Returns the three letter code of the airport
  string Airport::GetCode(){
    return m_code;
  }




  // Name: GetName()
  // Desc: Returns the name of the airport
  // Preconditions: None
  // Postconditions: Returns the name of the airport
  string Airport::GetName(){
    return m_name;
  }




  // Name: GetNext()
  // Desc: Returns the pointer to the next airport
  // Preconditions: None (may return either airport or nullptr)
  // Postconditions: Returns m_next;
  Airport* Airport::GetNext(){
    return m_next;
  }



  // Name: GetNorth()
  // Desc: Returns the northern coordinates of the airport
  // Preconditions: None
  // Postconditions: Returns the N coordinates of the port
  double Airport::GetNorth(){
    return m_north;
  }




  // Name: GetWest()
  // Desc: Returns the western coordinates of the airport
  // Preconditions: None
  // Postconditions: Returns the W coordinates of the airport
  double Airport::GetWest(){
    return m_west; 
  }




  // Name: GetCity()
  // Desc: Returns the city of where the airport is located
  // Preconditions: None
  // Postconditions: Returns the city of where the airport is located
  string Airport::GetCity(){
    return m_city;
  }



  // Name: GetCountry()
  // Desc: Returns the country of where the airport is located
  // Preconditions: None
  // Postconditions: Returns the country of where the airport is located
  string Airport::GetCountry(){
    return m_country;
  }




  // Name: SetNext()
  // Desc: Updates the pointer to a new target (either a airport or nullptr)
  // Preconditions: None
  // Postconditions: Sets the next airport
  void Airport::SetNext(Airport* airport){
    m_next = airport;
  }