#include "Navigator.h"

// Name: Navigator (string) - Overloaded Constructor
// Desc: Creates a navigator object to manage routes
// Preconditions:  Provided with a filename of ports to load
// Postconditions: m_filename is populated with fileName
Navigator::Navigator(string fileName){
    m_fileName = fileName;
}

// Name: Navigator (destructor)
// Desc: Deallocates all dynamic aspects of a Navigator
// Preconditions: There is an existing Navigator
// Postconditions: All ports and routes are cleared
Navigator::~Navigator() { // Function destruction
cout << "Routes removed from memory"  << endl;
  cout << "Deleting routes" << endl;
  for (unsigned int i = 0; i < m_routes.size(); i++){
    delete m_routes[i];
    m_routes[i] = nullptr;
  }
  cout << "Deleting ports" << endl;
  for (unsigned int i = 0; i < m_ports.size(); i++){
    delete m_ports[i];
    m_ports[i] = nullptr;
  }

  m_routes.resize(0);
  m_ports.resize(0);
}

// Name: Start
// Desc: Loads the file and calls the main menu
// Preconditions: m_fileName is populated
// Postconditions: All ports are loaded and the main menu runs
void Navigator::Start(){
ReadFile();
MainMenu();
}

// *************************
// Name: ReadFile
// Desc: Reads in a file that has data about each port including name, location, degrees
//       north and degrees west. Dynamically allocates ports and stores them in m_ports
//       The vector can hold many ports.
// Preconditions: Valid file name of ports
// Postconditions: Dynamically allocates each port and enters it into m_ports
void Navigator::ReadFile(){

string name, location, sNorth, sWest;
double north, west;

fstream newFile;
newFile.open(m_fileName);

if (newFile.is_open()) {
cout << "Opened File" << endl;
while(getline(newFile, name, ',')&& getline(newFile, location, ',') && getline(newFile, sNorth, ',') && getline(newFile, sWest )){
     north = stod(sNorth);
     west = stod(sWest);

     Port *port = new Port(name,location,north,west);
     m_ports.push_back(port);
     //cout << *port << endl; 
    }
    cout << "Ports loaded: " << m_ports.size() << endl; 
}
else {
    cout << "ERROR: File could not be found" << endl;
}
newFile.close();
}
//***********************************
// Name: InsertNewRoute
// Desc: Dynamically allocates a new route with the user selecting each port in the route.
//       Route named based on the first and last port automatically
//       For example, Baltimore to Boston
//       Once route is created, inserted into m_routes.
// Preconditions: Populated m_routes
// Postconditions: Inserts a new route into m_routes
void Navigator::InsertNewRoute(){
int choice =0;
Route *Routes = new Route();
DisplayPorts();
while(choice != -1){
    cout << "Enter the number of the port to add to your Route: (-1 to end) " << endl;
    cin >> choice; 
    while((choice < 0 || choice > (int)m_ports.size()) && (choice != -1)){
        cout << "Invalid input!" << endl;
        cout << "Enter the number of the port to add to your Route: (-1 to end) " << endl;
        cin >> choice; 
    }
    
    
    if(choice != -1){
        Port *choiceptr = m_ports[choice-1];
        Routes -> InsertEnd(choiceptr ->GetName(), choiceptr ->GetLocation(), choiceptr -> GetNorth(), choiceptr -> GetWest()); 
    }
    else if(Routes -> GetSize() <= 1){
        cout << "Invalid: A route must have at least 2 ports" << endl;
        choice = 1;
    }
}

m_routes.push_back(Routes);
Routes -> UpdateName();

cout << "Successfully created new route named  " << Routes -> GetName() << endl;
}
//***********************
// Name: MainMenu
// Desc: Displays the main menu and manages exiting
// Preconditions: Populated m_ports
// Postconditions: Exits when someone chooses 5
void  Navigator::MainMenu(){

int choice = 0;
while(choice !=5){

    cout << "What would you like to do?" << endl;  
    cout << "1. Create New Route" << endl;
    cout << "2. Display Route" << endl;
    cout << "3. Remove Port From Route" << endl;
    cout << "4. Reverse Route" << endl; 
    cout << "5. Exit" << endl;
    cin >> choice;

    while(choice < 1 || choice >5 ){
    cout << "Invalid input!" << endl;
    cout << "What would you like to do?" << endl;  
    cout << "1. Create New Route" << endl;
    cout << "2. Display Route" << endl;
    cout << "3. Remove Port From Route" << endl;
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
    RemovePortFromRoute();
}
else if (choice == 4){
    ReverseRoute();
}
}
}

// **************************
// Name: ChooseRoute
// Desc: Allows user to choose a specific route to work with by displaying numbered list
// Preconditions: Populated m_routes
// Postconditions: Returns the index of the selected route minus 1
int Navigator::ChooseRoute() {
  int index;
  cin >> index;

  while (index < 1 or index > (int)m_routes.size()){
    cout << "Unable to find route! Try again!" << endl;
    cin >> index;
  }

  return index;
}

// *******************
// Name: DisplayPorts
// Desc: Displays each port in m_ports
// Preconditions: At least one port is in m_ports
// Postconditions: Displays all ports. Uses overloaded << provided in Port.h
void Navigator::DisplayPorts(){

        for(unsigned int i = 0; i < m_ports.size(); i++ ){
        cout << i+1 << ". "<<*m_ports[i] << endl;
    }
    cout << endl;
}

// ********************
// Name: DisplayRoute
// Desc: Using ChooseRoute, displays a numbered list of all routes.
//       If no routes, indicates that there are no routes to display
//       User selects a route from list to display
//       Displays numbered list of each port in route
//       Displays total miles of a route using RouteDistance
// Preconditions: Routes has more than one port
// Postconditions: Displays all ports in a route and the total miles of the route
void Navigator::DisplayRoute() {
  int choice;

  if (m_routes.size() > 0){
    cout << "Which route would you like to use?" << endl;

    for (unsigned int i = 0; i < m_routes.size(); i++) 
        cout << i+1 << ". " << m_routes[i]->GetName() << endl;
    
    choice = ChooseRoute() - 1;
    Route *Route = m_routes[choice];

    cout << Route->GetName() << endl;
    m_routes[choice]->DisplayRoute();

    cout << "The total miles of this route is " << RouteDistance(Route) << " miles" << endl;

  }else{
    cout << "There are no routes to display!" << endl;
  }
}

// ******************************
// Name: RemovePortFromRoute()
// Desc: Using ChooseRoute, displays a numbered list of all routes.
//       User selects one of the routes to remove a port from.
//       Displays a numbered list of all ports in selected route.
//       User selects port to remove from list.
//       Removes port from route. If first or last port removed, updates name of route.
// Preconditions: Routes has more than one port
// Postconditions: Displays updated route with removed port and new name
void Navigator::RemovePortFromRoute(){
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
      Route->RemovePort(choice2-1);
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

// ********************************
// Name: ReverseRoute
// Desc: Using ChooseRoute, users chooses route  and the route is reversed
//       If no routes in m_routes, indicates no routes available to reverse
//       Renames route based on new starting port and ending port
//       For example, Baltimore to Boston becomes Boston to Baltimore
// Preconditions: Populated m_routes
// Postconditions: Reverses a specific route by reversing the ports in place
//                 Must move ports, cannot just change data in ports.

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

    cout << "Done Reversing Route " << choice +1 << endl;

}
else{
    cout << "No route to reverse" << endl;
}
}

// *********************
// Name:  CalcDistance (provided - DO NOT EDIT)
// Desc: Calculates the distance between two ports by using their coordinates
//       Takes in port1 latitude (North), Port1 Longitude (West)
//       Takes in port2 latitude (North), Port2 longitude (West)
// Preconditions: Requires two ports with their N (in degrees) and W (in degrees)
// Postconditions: Returns distance in miles between two ports
double Navigator::RouteDistance(Route *route) {
  double miles = 0;

  for (int i = 0; i < route->GetSize() - 1; i++) {

    miles += CalcDistance(route->GetData(i)->GetNorth(), route->GetData(i)->GetWest(), route->GetData(i+1)->GetNorth(), route->GetData(i+1)->GetWest());
  }

  return miles;
}




