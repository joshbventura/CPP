/*****************************************
** File:    Planet.cpp
** Project: CMSC 202 Project 4, Spring 2024
** Author:  Josh Ventura
** Date:    4/18/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the .cpp file for Planet.h which contains the function implementations 
** for the functions outlined in the .h file. This implements the functions needed to make an instance of the Planet class. 
**
***********************************************/

#include "Planet.h"
#include <cstdlib>

using namespace std; 

  // Name: Planet(string name, int challenge)
  // Description: Used to populate name, challenge, and isExplored (defaults to false)
  // Preconditions: None
  // Postconditions: Used to populate planet data
  Planet::Planet(string name, int challenge): m_name(name), m_challenge(challenge), m_isExplored(false) {}


  // Name: Planet Destructor
  // Description: Virtual destructor for an planet
  // Preconditions: None
  // Postconditions: Does nothing but cannot be omitted
  Planet::~Planet(){}



  // Name: Battle()
  // Description: Describes battle between planet and ship
  //              1. Indicates that the battle is starting
  //              2. Randomly chooses the difficult based on m_challenge + 1
  //              3. Gets the ship's attack and defense
  //              4. Compares difficulty with the ship's attack
  //                 If difficult is greater, notifies player, and calculates
  //                 the delta and multiplies with FUEL_COST_DELTA
  //                 and modifies the ship fuel (penalty)
  //                 If ship attack is higher, increases fuel by FUEL_MULTI_WIN
  //                 and sets isExplored
  // Preconditions: None
  // Postconditions: Returns true if win, else false
  bool Planet::Battle(Ship* ship){

      cout << "Battle Commencing!" << endl; 
      int difficulty = rand() % (m_challenge + 1);
      int shipAttack = ship->GetTotal("weapon");
      //int shipDefense = ship->GetTotal("armor");

       if (difficulty > shipAttack) {
        cout << "Your attack was too weak!" << endl;
        int delta = difficulty - shipAttack;
        int fuelPenalty = delta * FUEL_COST_DELTA;
        ship->ModifyFuel(-fuelPenalty);
        cout << "Your fuel has been modified by -" << fuelPenalty << " fuel." << endl;
        return false;
    } else {
        ship->ModifyFuel(FUEL_MULTI_WIN);
        m_isExplored = true;
        cout << "Your planetary bombardment worked. You won!" << endl;
        cout << "Your fuel has been modified by " << FUEL_MULTI_WIN << " fuel." << endl;
        return true;
    }
}




 
 
 

  
  



 



  // Name: GetName()
  // Description: Returns planet name
  // Preconditions: None
  // Postconditions: Returns planet name
  string Planet::GetName(){
    return m_name; 
  }




  // Name: SetIsExplored
  // Description: Sets IsExplored to true
  // Preconditions: None
  // Postconditions: Toggles from false to true when explored
  void Planet::SetIsExplored(){
    m_isExplored = true; 
  }





  // Name: GetIsExplored
  // Description: Returns m_isExplored
  // Preconditions: None
  // Postconditions: Returns true if m_isExplored is true
  bool Planet::GetIsExplored(){
    return m_isExplored;
  }




  // Name: GetChallenge
  // Description: Returns challenge of planet
  // Preconditions: None
  // Postconditions: Returns challenge of planet
  int Planet::GetChallenge(){
    return m_challenge; 
  }




  // Name: Overloaded <<
  // Description: Prints the details of planet (name, type, and challenge)
  // Preconditions: None
  // Postconditions: returns an ostream with output of planet
  ostream& operator<<(ostream& os, Planet& planet){
    os << planet.GetName() << "(" << planet.GetType() << ")" << " Challenge: " <<planet.GetChallenge(); 
    return os; 
  }