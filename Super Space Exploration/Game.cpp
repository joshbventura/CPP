/*****************************************
** File:    Game.cpp
** Project: CMSC 202 Project 4, Spring 2024
** Author:  Josh Ventura
** Date:    4/18/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the .cpp file for Game.h which contains the function implementations 
** for the functions outlined in the .h file. This implements the functions needed to make an instance of the Game class. 
**
***********************************************/


#include "Game.h"

#include <iostream>
#include <string>
#include <vector> 
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std; 

// Name: Game(string itemFile, string planetFile) - Overloaded Constructor
  // Description: Creates a new Game by setting m_fileItems and m_filePlanets
  // Preconditions: None
  // Postconditions: Sets two file names in Game
  Game::Game(string itemFile, string planetFile){

    m_fileItems = itemFile;
    m_filePlanets = planetFile;
    m_ship = nullptr;
    m_curPlanet = nullptr;

  }

  // Name: ~Game
  // Description: Destructor
  // Preconditions: None
  // Postconditions: Deallocates anything dynamically allocated
  //                 in Game (ship, items, and planets)
  Game::~Game(){

   for (unsigned int i = 0; i < m_items.size(); i++) {
        delete m_items[i];  // Ensure these are not deleted elsewhere
        m_items[i] = nullptr;
    }
    for (unsigned int i = 0; i < m_planets.size(); i++) {
        delete m_planets[i];  // Ensure these are not deleted elsewhere
        m_planets[i] = nullptr;
    }
    delete m_ship;  // Ensure m_ship is only owned and deleted by Game
    m_ship = nullptr;
   
cout << "Good bye!" << endl;   }


  // Name: LoadItems()
  // Description: Dynamically allocates items and inserts them into
  //              the m_items vector
  // Note: the number of items is NOT known - you should not use constants
  // Hint: Use getline(file,variable,delimiter) - may also use stoi
  // Precondition: m_itemFile is populated
  // Postcondition: m_items is populated

  void Game::LoadItems(){

    ifstream inputStream; 
    inputStream.open(m_fileItems); // opens the file

    if (inputStream.is_open()) {
        string name, type, strValue;
        int value;

        while (getline(inputStream, name, DELIMITER) &&
               getline(inputStream, type, DELIMITER) && 
               getline(inputStream, strValue)) {

            value = stoi(strValue);
          
            Item *item;

           /* cout << "Name: " << name << endl;
            cout << "Type: " << type << endl;  
            cout << "Value: " << strValue << endl; */

            if (type == "armor") {
                item = new Armor(name, type, value);
            } else if (type == "engine") {
                item = new Engine(name, type, value);
            } else if (type == "weapon") {
                item = new Weapon(name, type, value);
            } else {
                cout << "Invalid item type: " << type << endl;
            }
            m_items.push_back(item);
        }

        inputStream.close();
    } else {
        cout << "File Could Not Be Found!" << endl; 
    }

    cout << m_items.size() << " items loaded. " << endl; 

  }

  
  // Name: LoadPlanets()
  // Description: Dynamically allocates items and inserts them into
  //              the m_planets vector
  // Note: the number of planets is NOT known - you should NOT use constants
  // Hint: Use getline(file,variable,delimiter) - may also use stoi
  // Precondition: m_planetFile is populated
  // Postcondition: m_planets is populated
  void Game::LoadPlanets(){ 

    ifstream inputStream;
    inputStream.open(m_filePlanets); // Open the file

    if (inputStream.is_open()) {
        string name, type, strChallenge;
        int challenge;

        while (getline(inputStream, name, DELIMITER) &&
               getline(inputStream, type, DELIMITER) &&
               getline(inputStream, strChallenge)) {
           
            challenge = stoi(strChallenge);

            /*cout << "Name: " << name << endl; 
            cout << "Type: " << type << endl; 
            cout << "Challenge: " << challenge << endl;  */

            // Create the appropriate planet based on type
            Planet *planet = nullptr;

            if (type == "gas") {
                planet = new Gas(name, challenge);
            } else if (type == "mining") {
                planet = new Mining(name, challenge);
            } else if (type == "enemy") {
                planet = new Enemy(name, challenge);
            } 

            // Add the planet to the vector
            m_planets.push_back(planet);
        }

        inputStream.close(); //Close file
    } else {
        cout << "File Could Not Be Found!" << endl;
    }

    cout << m_planets.size() << " planets loaded." << endl; 
    
    }

  

   
  
  
  // Name: ShipCreation()
  // Description: Populates m_ship and asks name (sets name of ship)
  //              Also adds items (START_ENGINE, START_ARMOR, START_WEAPON)
  // Preconditions: None
  // Postconditions: m_ship is populated
  void Game::ShipCreation(){

    string shipName;
    
    cout << "Enter the name of your ship: ";
    getline(cin, shipName); // Get ship name from user
    
    // Create the ship object with the provided name
    m_ship = new Ship(shipName);

    // Add initial items to the ship
    m_ship->AddItem(m_items[START_ENGINE]);
    m_ship->AddItem(m_items[START_ARMOR]);
    m_ship->AddItem(m_items[START_WEAPON]);

    cout << "Ship Name: " <<  m_ship->GetName()  << endl; 

  }


  // Name: StartGame()
  // Description: Welcomes the player to the game. "Super Space Exploration"
  //              Calls LoadPlanets, LoadItems, ShipCreation, sets the m_curPlanet (0)
  //              randomizes m_winEngine based on UTOPIA_MAX and UTOPIA_MIN
  //              Finally, calls Action (which is the main menu)
  // Preconditions: Input files must exist
  // Postconditions: All game components loaded to play game
  void Game::StartGame(){
    cout << "Welcome to Super Space Exploration!" << endl; 
    LoadPlanets();
    LoadItems();
    ShipCreation();
    m_curPlanet = m_planets[START_PLANET];
    cout << *m_curPlanet <<endl;
    
    
    m_winEngine = UTOPIA_MIN + (rand() % (UTOPIA_MAX - UTOPIA_MIN + 1));
    Action();
  }




  // Name: Action()
  // Description: Menu for game. Displays menu.
  //              Player can examine the ship's items, move, attack planet,
  //              Try to travel to Utopia, check stats, or quit
  //              Player dies in one of two ways: 1. <= 0 fuel or
  //                   2. Tries to go to Utopia but doesn't have high enough engine
  // Preconditions: Everything in start has been completed
  // Postconditions: Game continues until quit or player dies
  void Game::Action(){
      int choice = 0;
    while(choice !=6){

    cout << "What would you like to do?:" << endl;  
    cout << "1. Examine Items" << endl;
    cout << "2. Move" << endl;
    cout << "3. Attack Planet" << endl;
    cout << "4. Travel to Utopia" << endl; 
    cout << "5. Check Stats" << endl;
    cout << "6. Quit" << endl; 
    cin >> choice;

    while(choice < 1 || choice >6 ){
    
    cout << "What would you like to do?:" << endl;  
    cout << "1. Examine Items" << endl;
    cout << "2. Move" << endl;
    cout << "3. Attack Planet" << endl;
    cout << "4. Travel to Utopia" << endl; 
    cout << "5. Check Stats" << endl;
    cout << "6. Quit" << endl; 
    cin >> choice;
    }

    if(choice == 1){
        DisplayShipItems();
    }
    else if(choice == 2){
        Move();
        if (m_ship->GetFuel() <= 0) {  // end game when fuel reaches 0
                    cout << "You have run out of fuel." << endl;
                    cout << "Game Over: You have lost the game." << endl;
                    return;}
                 
    }
    else if (choice == 3){
        AttackPlanet();
    }
    else if (choice == 4){
       TravelUtopia();
    }
    else if (choice == 5){
        Stats();
    }
    }
  }
  
  



  // Name: Move
  // Description: Moves ship to new random location
  //              Charges MOVE_FUEL as cost to move to new planet
  //              Displays information about new planet
  // Preconditions: Must be valid move (may go to same planet more than once)
  // Postconditions: Displays planet information and reduces fuel
  void Game::Move(){
    srand(time(NULL));
    int index = rand() % m_planets.size();

   // cout << "random index: " << index << endl; 

      m_curPlanet = m_planets[index];
      m_ship->ModifyFuel(MOVE_FUEL);

    cout << "You travel to the next planet" << endl;
    cout << *m_curPlanet << endl;  

    cout << "Your fuel has been modified by " << MOVE_FUEL << " fuel" << endl; 


  }




  // Name: AttackPlanet
  // Description: Allows ship to attack a planet
  //              1. Checks if planet already defeated (displays message if already won)
  //              2. Calls Planet's battle with ship (if not already defeated)
  //              3. Displays if win or not. Can attack again if not defeated.
  //              4. If winner, Identifies an item load on ship
  // Preconditions: None
  // Postconditions: Fuel may be below zero. May get new item.
  void Game::AttackPlanet(){

       if (m_curPlanet == nullptr) {
        cout << "No current planet to attack." << endl;
        return;
    }

    // Check if the planet has already been explored or defeated
    if (m_curPlanet->GetIsExplored()) {
        cout << "This planet has already been defeated." << endl;
        return;
    }

    // Engage in battle with the current planet
    bool victory = m_curPlanet->Battle(m_ship);

    // Check the outcome of the battle
    if (victory) {
        IdentifyItem(m_curPlanet->GetChallenge());
    } else {
        cout << "You did not defeat the planet. Try again!" << endl;
    }

  

    // Check for ship fuel levels
    if (m_ship->GetFuel() <= 0) {
        cout << "Your ship has run out of fuel!" << endl;
        // Additional handling could be added here, such as ending the game or giving the player options to refuel.
    }

  }
  
  // Name: IdentifyItem(int challenge)
  // Description: Randomly identifies an item of the challenge's level
  //              Calls AddItem in ship and tries to add the item
  // Preconditions: None
  // Postconditions: Will try to add an item to the ship of a random type
  void Game::IdentifyItem(int challenge){
      if (m_items.empty()) {
        cout << "No items available to identify." << endl;
        return;
    }

    // Filter items by challenge level or another suitable criterion
    vector<Item*> filteredItems;
    for (Item* item : m_items) {
        if (item->GetValue() == challenge) {  // Assuming GetValue returns an int that can be compared to challenge
            filteredItems.push_back(item);
        }
    }


    // Select a random item from the filtered list
    int randomIndex = rand() % filteredItems.size();
    Item* selectedItem = filteredItems[randomIndex];

    // Attempt to add the selected item to the ship

     cout << "You have found: " << selectedItem->GetName() <<"(" << selectedItem->GetType() <<") "<<selectedItem->GetValue()  << endl;

    m_ship->AddItem(selectedItem);

  }


  // Name: Stats()
  // Description: Calls the ship's display function
  // Preconditions: None
  // Postconditions: None
  void Game::Stats(){
    m_ship->DisplayShip();
  }

  // Name: TravelUtopia()
  // Description: Attempts to win game if total engine value > m_engineValue
  //              if total engine value is below UTOPIA_MIN, returns 0
  //              If total engine value above m_engineValue, returns 1
  //              If total engine value below m_engineValue, returns -1
  // Preconditions: None
  // Postconditions: -1 = lose; 0 = continue, 1 = win
  int Game::TravelUtopia(){

     int totalEngineValue = m_ship->GetTotal("engine");  // Assuming GetTotal is implemented to sum values based on type

    if (totalEngineValue < UTOPIA_MIN) {
        // If the total engine value is less than the minimum required to attempt traveling to Utopia
        cout << "You are not prepared to try to travel to Utopia" << endl;
        cout << "Perhaps develop your engines more?" << endl; 
        return 0;  // Continue the game
    } else if (totalEngineValue > m_winEngine) {
        // If the total engine value exceeds the target, the player wins the game
        cout << "You have successfully traveled to Utopia! Congratulations, you win!" << endl;
        return 1;  // Win
    } else {
        // If the total engine value is above the minimum but below the win condition
        cout << "Your ship attempts to make it to Utopia." << endl;
        cout << "The engines just weren't powerful enough." << endl;
        cout << "You evetually ran out of food and fuel and died." << endl; 
        cout << "Please play again!" << endl; 
        return -1;  // Lose
    }
  }
  

  // Name: DisplayShipItems
  // Description: Displays a numbered list of all items on ship
  // Preconditions: m_items has items in it otherwise says No Items Found
  // Postconditions: None
  void Game::DisplayShipItems(){
    m_ship -> DisplayItems();
  }




