/*****************************************
** File:    Navigator.cpp
** Project: CMSC 202 Project 3, Spring 2024
** Author:  Josh Ventura
** Date:    4/2/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the .cpp file for Navigator.h which contains the function implementations 
** for the functions outlined in the .h file. This implements the functions needed to make an instance of the Navigator class. 
**
***********************************************/
  
  
  
  #include "Navigator.h"
  #include "Route.h"
  // Name: Navigator (string) - Overloaded Constructor
  // Desc: Creates a navigator object to manage routes
  // Preconditions:  Provided with a filename of airports to load
  // Postconditions: m_filename is populated with fileName
  Navigator::Navigator(string fileName){
    m_fileName = fileName;
  }
  
  
  
  // Name: Navigator (destructor)
  // Desc: Deallocates all dynamic aspects of a Navigator
  // Preconditions: There is an existing Navigator
  // Postconditions: All airports and routes are cleared
  Navigator::~Navigator(){
    cout << "Routes removed from memory"  << endl;
    cout << "Deleting Airports" << endl;
  for (unsigned int i = 0; i < m_airports.size(); i++){ //Iterates through m_airports vector and deletes airport nodes to avoid memory leaks
    delete m_airports[i];     
    m_airports[i] = nullptr;
  }

  cout << "Deleting Routes" << endl;
  for (unsigned int i = 0; i < m_routes.size(); i++){ //Iterates through m_route vector and deletes route nodes to avoid memory leaks
    delete m_routes[i];
    m_routes[i] = nullptr;
  }
 
  m_routes.resize(0);
  m_airports.resize(0);
  }
  
  
  
  // Name: Start
  // Desc: Loads the file and calls the main menu
  // Preconditions: m_fileName is populated
  // Postconditions: All ports are loaded and the main menu runs
  void Navigator::Start(){
    ReadFile();
    MainMenu();
  }



  // Name: DisplayAirports
  // Desc: Displays each airport in m_airports
  // Preconditions: At least one airport is in m_airports
  // Postconditions: Displays all airports.
  //  Uses overloaded << provided in Airport.h
  void Navigator::DisplayAirports(){

        for(unsigned int i = 0; i < m_airports.size(); i++ ){  //iterates through airport vector and displays the data being pointed to (Code, city, country, etc.)
        cout << i+1 << ". "<<*m_airports[i] << endl;
    }
    cout << endl;
  }



  // Name: ReadFile
  // Desc: Reads in a file that has data about each airport
  //   including code, name, city, country, degrees north and degrees west.
  //   Dynamically allocates airports and stores them in m_airports
  //   The vector can hold many airports.
  // Preconditions: Valid file name of airports
  // Postconditions: Dynamically allocates each airport
  //   and enters it into m_airports
  void Navigator::ReadFile(){

    string code, name, city, country, sNorth, sWest;
    double north, west;

    fstream newFile;
    newFile.open(m_fileName);

  if (newFile.is_open()) {
    cout << "Opened File" << endl; //Iterates through text file and appends data at each instance of ',', in order of code, name,city, counyty, north, and west. 
  while(getline(newFile, code, ',')&& getline(newFile, name, ',') && getline(newFile, city, ',') && getline(newFile, country, ',') && getline(newFile, sNorth, ',') && getline(newFile, sWest)){
     north = stod(sNorth);
     west = stod(sWest);

     Airport *airport = new Airport(code,name,city,country,north,west);
     m_airports.push_back(airport);
     //cout << *airport << endl; 
    }
    cout << "Airports loaded: " << m_airports.size() << endl; 
}
else {
    cout << "ERROR: File could not be found" << endl;
}
newFile.close();
  }



  // Name: InsertNewRoute
  // Desc: Dynamically allocates a new route with the user selecting
  //   each airport in the route. Each route can have a minimum of two
  //   airports. Will not allow a one airport route.
  //   Checks for min of two valid airports (1-40)
  //   Route named using Route's UpdateName.
  //   For example, Baltimore to Boston
  //   Once route is created, inserted into m_routes.
  // Preconditions: Populated m_routes
  // Postconditions: Inserts a new route into m_routes

  void Navigator::InsertNewRoute(){

  int choice =0;
  Route *Routes = new Route();
  DisplayAirports();

while(choice != -1){
    cout << "Enter the number of the airport to add to your Route: (-1 to end) " << endl;
    cin >> choice; 
    while((choice < 0 || choice > (int)m_airports.size()) && (choice != -1)){
        cout << "Invalid input!" << endl;
        cout << "Enter the number of the airport to add to your Route: (-1 to end) " << endl;
        cin >> choice; 
    }
    
    
    if(choice != -1){
        Airport *choiceptr = m_airports[choice-1];
        Routes -> InsertEnd(choiceptr->GetCode(), choiceptr->GetName(), choiceptr->GetCity(), choiceptr-> GetCountry(), choiceptr-> GetNorth(), choiceptr-> GetWest()); 
    }
    else if(Routes -> GetSize() <= 1){
        cout << "Invalid: A route must have at least 2 ports" << endl;
        choice = 1;
    }
}

  m_routes.push_back(Routes);
  Routes -> UpdateName();

  cout << "Done Building a New Route named " << Routes -> GetName() << endl;

}



  // Name: MainMenu
  // Desc: Displays the main menu and manages exiting
  // Preconditions: Populated m_airports
  // Postconditions: Exits when someone chooses 5

  void Navigator::MainMenu(){
  int choice = 0;
while(choice !=5){

    cout << "What would you like to do?:" << endl;  
    cout << "1. Create New Route" << endl;
    cout << "2. Display Route" << endl;
    cout << "3. Remove Airport From Route" << endl;
    cout << "4. Reverse Route" << endl; 
    cout << "5. Exit" << endl;
    cin >> choice;

    while(choice < 1 || choice >5 ){
    cout << "Invalid input!" << endl;
    cout << "What would you like to do?:" << endl;  
    cout << "1. Create New Route" << endl;
    cout << "2. Display Route" << endl;
    cout << "3. Remove Airport From Route" << endl;
    cout << "4. Reverse Route" << endl; 
    cout << "5. Exit" << endl;
    cin >> choice;
    }

if(choice == 1){
    InsertNewRoute();
}
else if(choice == 2){
    DisplayRoute();
}
else if (choice == 3){
    RemoveAirportFromRoute();
}
else if (choice == 4){
    ReverseRoute();
}
}
  }




  // Name: ChooseRoute
  // Desc: Allows user to choose a specific route to work with
  //   by displaying numbered list
  // Preconditions: Populated m_routes
  // Postconditions: Returns the index of the selected route minus 1
  int Navigator::ChooseRoute(){
     int index;
  cin >> index;

  while (index < 1 or index > (int)m_routes.size()){
    cout << "Unable to find route! Try again!" << endl;
    cin >> index;
  }

  return index;
  }




  // Name: DisplayRoute
  // Desc: Using ChooseRoute, displays a numbered list of all routes.
  //    If no routes, indicates that there are no routes to display
  //    User selects a route from list to display
  //    Displays numbered list of each airport in route
  //    Displays total miles of a route using RouteDistance
  // Preconditions: Routes has more than one airport
  // Postconditions: Displays all airports in a route and
  //    the total miles of the route
  void Navigator::DisplayRoute(){
      int choice;

  if (m_routes.size() > 0){
    cout << "Which route would you like to use?" << endl;

    for (unsigned int i = 0; i < m_routes.size(); i++) 
        cout << i+1 << ". " <<  m_routes[i]->GetName()  << endl;
    
    choice = ChooseRoute() - 1;
    Route *Route = m_routes[choice];

    cout <<  Route->GetName() << endl;
    m_routes[choice]->DisplayRoute();

    cout << "The total miles of this route is " << RouteDistance(Route) << " miles" << endl;

  }else{
    cout << "There are no routes to display!" << endl;
  }
  }



  // Name: RemoveAirportFromRoute()
  // Desc: Using ChooseRoute, displays a numbered list of all routes.
  //    User selects one of the routes to remove an airport from.
  //    Displays a numbered list of all airports in selected route.
  //    User selects airport to remove from list.
  //    Each route has a minimum of two airports (will not allow).
  //    Removes airport from route if more than two.
  //    If first or last airport removed,
  //    updates name of route using UpdateName
  // Preconditions: Route has more than one airport
  // Postconditions: Displays updated route with removed airport
  //    and new name
  void Navigator::RemoveAirportFromRoute(){
     int choice1, choice2;

  if (m_routes.size() > 0){
    cout << "Which Route would you like to use?" << endl;

    for (unsigned int i = 0; i < m_routes.size(); i++) 
        cout << i+1 << ". " << m_routes[i]->GetName() << endl;
    
    choice1 = ChooseRoute() - 1;
    Route *Route = m_routes[choice1];

    if (Route->GetSize() > 2){
      cout << Route->GetName() << endl;
      m_routes[choice1]->DisplayRoute();


      cout << "Which port would you like to remove?" << endl;
      cin >> choice2;
      //cout << "Test" << endl; 
      Route->RemoveAirport(choice2-1);
      m_routes[choice1]->DisplayRoute();

      Route->UpdateName();
      cout << "Route named " << Route->GetName() << " updated" << endl;
    }else{
      cout << "Error! You must have more than two ports!" << endl;
    }

  }else{
    cout << "There are no routes!" << endl;
  }
  }



  // Name: RouteDistance
  // Desc: Calculates the total distance of a route
  //    Goes from airport 1 to airport 2 then airport 2 to airport 3
  //    and repeats for length of route.
  //    Calculates the distance using CalcDistance (provided)
  //    Aggregates the total and returns the total in miles
  // Preconditions: Populated route with more than one airport
  // Postconditions: Returns the total miles between all airports in a route
  double Navigator::RouteDistance(Route* route){
     double miles = 0;

  for (int i = 0; i < route->GetSize() - 1; i++) {

    miles += CalcDistance(route->GetData(i)->GetNorth(), route->GetData(i)->GetWest(), route->GetData(i+1)->GetNorth(), route->GetData(i+1)->GetWest());
  }

  return miles;

  }



  // Name: ReverseRoute
  // Desc: Using ChooseRoute, users chooses route and the route is reversed
  //   If no routes in m_routes, indicates no routes available to reverse
  //   Updates route name using UpdateName
  //   For example, Baltimore to Boston becomes Boston to Baltimore
  // Preconditions: Populated m_routes
  // Postconditions: Reverses a specific route by reversing the airports
  //   in place. Must move airports, cannot just change data in airports.
  void Navigator::ReverseRoute(){

      int choice;

  if (m_routes.size() > 0){
    cout << "Which Route would you like to use?" << endl;

    for (unsigned int i = 0; i < m_routes.size(); i++) 
        cout << i+1 << ". " << m_routes[i]->GetName() << endl;
    
    choice = ChooseRoute() - 1;
    Route *Route = m_routes[choice];

    Route->ReverseRoute();
    Route->UpdateName();

    cout << "Done Reversing Route " << m_routes[choice]-> GetName()<< endl;

}
else{
    cout << "No route to reverse" << endl;
}

  }







