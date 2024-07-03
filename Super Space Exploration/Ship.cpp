/*****************************************
** File:    Ship.cpp
** Project: CMSC 202 Project 4, Spring 2024
** Author:  Josh Ventura
** Date:    4/18/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the .cpp file for Ship.h which contains the function implementations 
** for the functions outlined in the .h file. This implements the functions needed to make an instance of the Ship class. 
**
***********************************************/

#include "Ship.h" 


// Name: Ship(string) - Overloaded ship 
  // Description: Creates a new ship that can hold items (MAX_ITEMS)
  //              and Fuel (STARTING_FUEL). Populates m_name
  // Preconditions: None
  // Postconditions: A new ship
  Ship::Ship(string name): m_name(name), m_fuel(STARTING_FUEL){}


  // Name: GetName()
  // Description: Returns m_name
  // Preconditions: None
  // Postconditions: Returns ship's m_name
  string Ship::GetName(){
    return m_name;
  }



  // Name: GetTotal(string type)
  // Description: Passed an item type (armor, weapon, or engine)
  //     Iterates over all items on ship and totals type passed in
  // Preconditions: None
  // Postconditions: Returns total value for armor, weapon, or engine

  int Ship::GetTotal(string type){
    int total =0; 
    for(Item* item:m_shipItems){ //iterate through m_shipItems vector
        if(item->GetType() == type){
            total += item->GetValue(); 
        }
    }
    return total; 
  }
  
  // Name: AddItem
  // Description: Adds a new item into m_items up to MAX_ITEMS.
  //    If at max, calls ReplaceItem
  // Preconditions: None
  // Postconditions: m_items is populated

  void Ship::AddItem(Item* item){
  if (m_shipItems.size() < MAX_ITEMS) { // checks if 10 item limit is reached
        m_shipItems.push_back(item);
    } else {

        ReplaceItem(item);  // Prompts to replace an item if 10 item limit is reached 
    }
  }


  // Name: ReplaceItem(Item*)
  // Description: Used when m_shipItem is at capacity.
  //   Lists all ship items and replaces with updated pointer
  //   Does NOT make a new object - just updates pointer
  // Preconditions: None
  // Postconditions: Used to replace an item in inventory (m_shipItems)
  void Ship::ReplaceItem(Item* newItem){
    cout << "Which item would you like to replace?" << endl;
    DisplayItems();  // Show existing items
    
    int index;
    cin >> index;  
    index -= 1;  
    if (index >= 0 && index < static_cast<int>(m_shipItems.size())) {
        m_shipItems[index] = newItem;
        cout << "Item replaced with: " << newItem->GetName() << endl;
    } else {
        cout << "Invalid index. No item replaced." << endl;
    }
  }



  // Name: GetFuel
  // Description: Returns fuel
  // Preconditions: None
  // Postconditions: Returns m_fuel
  int Ship::GetFuel(){
    return m_fuel; 
  }



  // Name: ModifyFuel(int)
  // Description: Used to increase (positive int) or
  //              decrease (negative int) m_fuel
  // Preconditions: None
  // Postconditions: Used to update fuel.
  void Ship::ModifyFuel(int amount){
    m_fuel += amount; 
  }



  // Name: DisplayItems
  // Description: Displays a numbered list of all items on ship.
  // Preconditions: None
  // Postconditions: m_items is populated
  void Ship::DisplayItems(){
    int index =1; 
      for (std::vector<Item*>::iterator it = m_shipItems.begin(); it != m_shipItems.end(); ++it) {
        cout << index << ". ";
         (*it)->Display();  // Call Display on each item
        index++;
    }
  
  }


  // Name: GetItemCount();
  // Description: Returns number of items in m_shipItems
  // Preconditions: None
  // Postconditions: Returns items in m_shipItems
  int Ship::GetItemCount(){
    return m_shipItems.size();
  }


  // Name: DisplayShip;
  // Description: Displays stats about the ship
  // Displays name, fuel, attack(weapon), defense(armor), engine(engine) all all items
  // Preconditions: None
  // Postconditions: None
  void Ship::DisplayShip(){
    cout << "******************************" << endl; 
    cout << "Name: " << m_name << endl;
    cout << "Fuel: " << m_fuel << endl;
    cout << "Attack: " << GetTotal("weapon") << endl;
    cout << "Defense: " << GetTotal("armor") << endl;
    cout << "Engine: " << GetTotal("engine") << endl;
    cout << "******************************" << endl; 
    DisplayItems();
  }