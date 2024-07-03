#include "Port.h"

// Name: Port() - Default Constructor
// Desc: Used to build a new empty port
// Preconditions: None
// Postconditions: Creates a new Port for use in a Route
Port::Port() {
  m_name = "New Port";
  m_location = "New Location";
  m_north = 0;
  m_west = 0;
  m_next = nullptr;
}

//Overloaded Constructor
// Name: Port(string, string, double, double) - Overloaded Constructor
// Desc: Used to build a new Port passing it a name, location, north, and west
// Preconditions: None
// Postconditions: Creates a new port for use in a Route
Port::Port(string name, string location, double north, double west) {
  m_name = name;
  m_location = location;
  m_north = north;
  m_west = west;
  m_next = nullptr;
}

// ***********************
// Destructor
// Name: Port() - Default Constructor
// Desc: Used to build a new empty port
// Preconditions: None
// Postconditions: Creates a new Port for use in a Route
Port::~Port(){}

// **********************
// Name: Port(string, string, double, double) - Overloaded Constructor
// Desc: Used to build a new Port passing it a name, location, north, and west
// Preconditions: None
// Postconditions: Creates a new port for use in a Route
string Port::GetName() {
  return m_name;
}

// ***********************
// Name: GetNext()
// Desc: Returns the pointer to the next port
// Preconditions: None (may return either port or nullptr)
// Postconditions: Returns m_next;
Port* Port::GetNext() {
  return m_next;
}

// **********************
// Name: GetNorth()
// Desc: Returns the northern coordinates of the port
// Preconditions: None
// Postconditions: Returns the N coordinates of the port
double Port::GetNorth() {
  return m_north;
}

// ***********************
// Name: GetWest()
// Desc: Returns the western coordinates of the port
// Preconditions: None
// Postconditions: Returns the W coordinates of the port
double Port::GetWest() {
  return m_west;
}

// ***********************
// Name: GetLocation()
// Desc: Returns the description of where the port is located
// Preconditions: None
// Postconditions: Returns the description of where the port is located

string Port::GetLocation() {
  return m_location;
}

// ************************
// Name: SetNext()
// Desc: Updates the pointer to a new target (either a port or nullptr)
// Preconditions: None
// Postconditions: Sets the next port
void Port::SetNext(Port* port) {
  m_next = port;
}