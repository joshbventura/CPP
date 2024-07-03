/*****************************************
** File:    Route.cpp
** Project: CMSC 202 Project 2, Spring 2024
** Author:  Josh Ventura
** Date:    4/2/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the .cpp file for Route.h which contains the function implementations 
** for the functions outlined in the .h file. This implements the functions needed to make an instance of the Route class. 
**
***********************************************/




#include "Route.h"



// Name: Route() - Default Constructor
  // Desc: Used to build a new Route (linked list) make up of airports
  // Preconditions: None
  // Postconditions: Creates a new Route where m_head and m_tail
  //   point to nullptr and size = 0
  Route::Route(){ 
  m_name = "Test";
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
  }


  // Name: SetName(string)
  // Desc: Sets the name of the route (usually first
  //   airport to last airport)
  // Preconditions: None
  // Postconditions: Sets name of route
  void Route::SetName(string name){
    m_name = name;
  }



  // Name: ~Route() - Destructor
  // Desc: Used to destruct a strand of Route
  // Preconditions: There is an existing Route strand with at least
  //   one airport
  // Postconditions: Route is deallocated (including all
  //   dynamically allocated airports) to have no memory leaks!
 Route::~Route(){
    Airport *current = m_head; 
  while(m_head != nullptr){
    current = m_head->GetNext();
    delete m_head;
    m_head = current;
  }
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
 }



  // Name: InsertEnd (string, string, double double)
  // Desc: Creates a new airport using the data passed to it.
  //   Inserts the new airport at the end of the route
  // Preconditions: Takes in a Airport
  //                Requires a Route
  // Postconditions: Adds the new airport to the end of a route
  void Route::InsertEnd(string code, string name, string city, string country, double north, double west){
       Airport *current;
    current = new Airport(code,name,city,country,north, west);
    
    if (m_head == nullptr){
        m_head = current;
        m_tail = current;
    }
    else{
        m_tail->SetNext(current);
        m_tail = current;
    }
    m_size++;
  }




  // Name: RemoveAirport(int index)
  // Desc: Removes a airport from the route at the index provided
  //   Hint: Special cases (first airport, last airport, middle airport)
  // Preconditions: Index must be less than the size of the route
  //   Cannot make route less than two airports. If the route has
  //   two or fewer airports, fails.
  // Postconditions: Name may be updated. Size is reduced.
  //   Route has one less airport.
  void Route::RemoveAirport(int airport){
      Airport *prev, *current;
    prev = m_head;
    current = m_head;
    int checker = 0;

    while(current != nullptr){
        cout << *current << endl; 
        if (checker == airport){
            if (airport == 0){
                cout << "Enter head" << endl;
                m_head = current->GetNext();
                delete current;
                current = nullptr;
                m_size--;               // decrease m_size by 1 after removing port
                return;
            }
            else if(airport == m_size - 1){
                cout << "Enter Tail" << endl;
                prev->SetNext(current->GetNext());
                delete current;
                current = nullptr;
                m_tail = prev;
                m_size--;  // // decrease m_size by 1 after removing port
                return;
            }
            else{
                cout << "Enter mid" << endl;
                prev->SetNext(current->GetNext());
                delete current;
                current = nullptr;
                m_size--; // // decrease m_size by 1 after removing port
                return;
            } 
        }
         prev = current;
            current = current->GetNext(); 
            checker++;
    }
  }





  // Name: GetName()
  // Desc: Returns the name of the route (Usually starting
  //  airport to last airport)
  //  For example: Baltimore to Boston
  // Preconditions: Requires a Route
  // Postconditions: Returns m_name;
  string Route::GetName(){
      return m_name;
  }





  // Name: UpdateName()
  // Desc: Updates m_name based on the name of the first airport
  //   in the route and the last airport in the route
  //       For example: Baltimore to Boston
  // Preconditions: Requires a Route with at least two airports
  // Postconditions: Returns m_name;
  string Route::UpdateName(){
    m_name = m_head->GetCity() + " to " + m_tail->GetCity();
  return m_name;
  }




  // Name: GetSize()
  // Desc: Returns the number of airports in a route
  // Preconditions: Requires a Route
  // Postconditions: Returns m_size;
  int Route::GetSize(){
      return m_size;
  }




  // Name: ReverseRoute
  // Desc: Reverses a route
  // Preconditions: Reverses the Route
  // Postconditions: Route is reversed in place; nothing returned
  void Route::ReverseRoute(){
 
  Airport *old, *present, *future;

  old = m_head;
  m_tail = old;

  present = old->GetNext();
  future = present->GetNext();

  old->SetNext(nullptr);
  present->SetNext(old);

  while (future != nullptr){
      old = present;
      present = future;
      future = future->GetNext();
      present->SetNext(old);
    }
    m_head = present;
  }



  // Name: GetData (int)
  // Desc: Returns an airport at a specific index
  // Preconditions: Requires a Route
  // Postconditions: Returns the airport from specific item
  Airport* Route::GetData(int index){
      int checker = 0;
  Airport *current = m_head;

  while(current != nullptr){
    if (checker == index){
      return current;
    }
    current = current->GetNext();
    checker++;
  }
  return current;
  }


  // Name: DisplayRoute
  // Desc: Displays all of the airports in a route
  // Preconditions: Requires a Route
  // Postconditions: Displays all of the airports in a route
  // Formatted: Baltimore, Maryland (N39.209 W76.517)
  void Route::DisplayRoute(){
      int checker = 0;
  Airport *current = m_head;
  while(current != nullptr){
    cout << checker + 1 << ". " << current->GetCode()<< ", " << *current << ", " << current->GetCountry() << " (N" << current->GetNorth() << " W" << current->GetWest() << ")" << endl;
    current = current->GetNext();
    checker++;
  }
  }