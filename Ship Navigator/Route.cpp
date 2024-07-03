#include "Route.h"

// ********************************
// Name: Route() - Default Constructor
// Desc: Used to build a new Route (linked list) make up of ports
// Preconditions: None
// Postconditions: Creates a new Route where m_head and m_tail point to nullptr and size = 0
Route::Route() {
  m_name = "Test";
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}

// *******************************
// Name: ~Route() - Destructor
// Desc: Used to destruct a strand of Route
// Preconditions: There is an existing Route strand with at least one port
// Postconditions: Route is deallocated (including all dynamically allocated ports)
//                 to have no memory leaks!
Route::~Route(){
  Port *current = m_head; 
  while(m_head != nullptr){
    current = m_head->GetNext();
    delete m_head;
    m_head = current;
  }
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}
// *****************************
// Name: SetName(string)
// Desc: Sets the name of the route (usually first port to last port)
// Preconditions: None
// Postconditions: Sets name of route
void Route::SetName(string name){
  m_name = name;
}

// *********************************
// Name: InsertEnd (string, string, double double)
// Desc: Creates a new port using the data passed to it.
//       Inserts the new port at the end of the route
// Preconditions: Takes in a Port
//                Requires a Route
// Postconditions: Adds the new port to the end of a route
void Route::InsertEnd(string name, string location, double north, double west){
    Port *current;
    current = new Port(name,location,north,west);
    
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

// *******************************
// Name: ReverseRoute
// Desc: Reverses a route
// Preconditions: Reverses the Route
// Postconditions: Route is reversed in place; nothing returned
  void ReverseRoute();
void Route::ReverseRoute(){
  Port *old, *present, *future;

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

// ***************************
// Name: GetName()
// Desc: Returns the name of the route (Usually starting port to last port)
//       For example: Baltimore to Brunswick
// Preconditions: Requires a Route
// Postconditions: Returns m_name;
string Route::GetName() {
  return m_name;
}

// ***************************
// Name: UpdateName()
// Desc: Updates m_name based on the name of the first port in the route
//       and the last port in the route
//       For example: Baltimore to Brunswick
// Preconditions: Requires a Route with at least two ports
// Postconditions: Returns m_name;
string Route::UpdateName(){
  m_name = m_head->GetName() + " to " + m_tail->GetName();
  return m_name;
}

// *****************************
// Name: GetSize()
// Desc: Returns the number of ports in a route
// Preconditions: Requires a Route
// Postconditions: Returns m_size;
int Route::GetSize(){
  return m_size;
}

// *******************************
// Name: GetData (int)
// Desc: Returns a port at a specific index
// Preconditions: Requires a Route
// Postconditions: Returns the port from specific item
Port* Route::GetData(int index){
  int checker = 0;
  Port *current = m_head;

  while(current != nullptr){
    if (checker == index){
      return current;
    }
    current = current->GetNext();
    checker++;
  }
  return current;
}

// ************************************
// Name: DisplayRoute
// Desc: Displays all of the ports in a route
// Preconditions: Requires a Route
// Postconditions: Displays all of the ports in a route
// Formatted: Baltimore, Maryland (N39.209 W76.517)
void Route::DisplayRoute(){
  int checker = 0;
  Port *current = m_head;
  while(current != nullptr){
    cout << checker + 1 << ". " << *current << " (N" << current->GetNorth() << " W" << current->GetWest() << ")" << endl;
    current = current->GetNext();
    checker++;
  }}


// ***********************************************
// Name: RemovePort(int index)
// Desc: Removes a port from the route at the index provided
//       Hint: Special cases (first port, last port, middle port)
// Preconditions: Index must be less than the size of the route
//       Cannot make route less than two ports. If the route has
//       two or fewer ports, fails.
// Postconditions: Name may be updated. Size is reduced. Route has one less port.
void Route::RemovePort(int index){
    Port *prev, *current;
    prev = m_head;
    current = m_head;
    int checker = 0;

    while(current != nullptr){
        cout << *current << endl; 
        if (checker == index){
            if (index == 0){
                cout << "Enter head" << endl;
                m_head = current->GetNext();
                delete current;
                current = nullptr;
                m_size--;               // decrease m_size by 1 after removing port
                return;
            }
            else if(index == m_size - 1){
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





