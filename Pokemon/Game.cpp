/*****************************************
** File:    Game.cpp
** Project: CMSC 202 Project 2, Spring 2024
** Author:  Josh Ventura
** Date:    3/12/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This file contains the main driver program for Project 2.
** This file creates an instance of the game class and implements the functions outlined in the game.h file. 
**
**
***********************************************/


Game::Game(string filename){  //Default game constructor
    m_filename = filename; 
  /*  for(int i=0; i<NUM_TEAM;i++){
        m_team[i] = Pokemon();
    }*/
}

void Game::LoadFile(){  //This is the function that will laod in the text file. 
    string name;
    int num, CP, rarity; 

    ifstream inputStream;

    inputStream.open(m_filename);
    int i=0; 
    while(inputStream >> num && inputStream >> name && inputStream >> CP && inputStream >> rarity){ //Will continue going through file until end of text doc
    //cout << num << " " << name << " " << CP << " " << rarity << endl; 
        m_pokeDex[i] = Pokemon(num,name,CP,rarity);
        i++;
    }
    inputStream.close(); //closing filestream

   /* for (int i=0; i<TOTAL_POKEMON; i++){
        cout << m_pokeDex[i].GetNum() << m_pokeDex[i].GetName() << m_pokeDex[i].GetCP() << m_pokeDex[i].GetRarity() << endl;  
    }
    */
}

void Game::DisplayPokeDex(){
    for (int i=0; i<TOTAL_POKEMON; i++){
        cout << setw(NUM_WIDTH) << m_pokeDex[i].GetNum() << ". " << setw(NAME_WIDTH) << m_pokeDex[i].GetName() << endl; //iterates through pokedex, utilizes getter function to output name
    }
}


void Game::MainMenu(){

    int choice = 0;   //will continue to show user the menu until 6 is inputted
    do{

        cout << "What would you like to do?" << endl;
        cout << "1. Display Complete Pokedex" << endl;
        cout << "2. Display Your Team" << endl;
        cout << "3. Search for a New Pokemon" << endl;
        cout << "4. Battle your Pokemon" << endl;
        cout << "5. Train your Pokemon" << endl;
        cout << "6. Exit" << endl;
        cin >> choice;

       switch(choice){
        case 1: 
            DisplayPokeDex();
            break;
        case 2:
            DisplayTeam();
            break;
        case 3: 
            CatchPokemon();
            break;
        case 4: 
            BattlePokemon();
            break;
        case 5: 
            TrainPokemon();
            break;
        case 6: 
            break;
        default: 
          cout << "Invalid input! (1-6)" << endl;  // case if 1-6 is not selected
       }
    }
    while(choice!=6);
}

void Game::CatchPokemon(){
    int chosenRarity = CatchMenu();
    int randomRarity = 0;
    srand(time(NULL)); // seeds ranndom functionn 
    randomRarity = rand() % 99 + 0; 
    Pokemon chosenOne;
    srand(time(NULL));
    cout << randomRarity << endl;
    double powerNerf = ((rand() % 50 + 30));
    switch (chosenRarity)
    {
    case 1: // CASE FOR LOOKING FOR COMMON POKEMON
        if(randomRarity < COMMON){
            chosenOne = FoundPokemon(chosenRarity); //sets selected pokemon
          // cout << "original CP " << chosenOne.GetCP() << endl;  //test to see original vs new cp 
         //   cout << "gets nerfed by " << powerNerf << "% " << endl;
           chosenOne.SetCP((chosenOne.GetCP())* (powerNerf/100));
           // cout << "new CP " << chosenOne.GetCP() << endl;
           // cout << "CP of first team member after decrease " << m_team[0].GetCP() << endl;
         //   cout << "Test after fiding " << chosenOne.GetName() << "|" << chosenOne.GetCP() << " |" << endl; 
            AddPokemon(chosenOne);   // adds found pokemon to team
        }
        else {
            cout << "None found" << endl; 
        }
        break;
    case 2: // CASE FOR LOOKING FOR UNCOMMON POKEMON
        if(randomRarity <UNCOMMON){
            chosenOne = FoundPokemon(chosenRarity);
            chosenOne.SetCP((chosenOne.GetCP())* (powerNerf/100));
            AddPokemon(chosenOne); 
        }
        else{
            cout << "None found" << endl;
            }
        break;
    case 3: // CASE FOR LOOKING FOR ULTRA RARE POKEMON
        if(randomRarity<ULTRA){
            chosenOne = FoundPokemon(chosenRarity);
            chosenOne.SetCP((chosenOne.GetCP())* (powerNerf/100));
            AddPokemon(chosenOne);
        }
        else{
            cout << "None found" << endl; 
        }
        break;
    default:
        break;
    }

   // cout << "Made it out the loop " << endl; 

}

Pokemon Game::FoundPokemon(int rarity) {
    srand(time(NULL)); // seeds ranndom functionn 
    int randomIndex = 0; 
    randomIndex = rand() % TOTAL_POKEMON;
    //cout << randomIndex << endl;  
    bool flag = false; 
    Pokemon chosenOne;
    do{
        if (m_pokeDex[randomIndex].GetRarity() == rarity) //conditional statement to make sure rarities align
        {
            //cout << m_pokeDex[randomIndex].GetName() << " " << m_pokeDex[randomIndex].GetRarity() << endl; 
            cout <<"You found a " << m_pokeDex[randomIndex].GetName() << endl;
            //cout << m_pokeDex[randomIndex].GetName() << " added to your team! " << endl;
            chosenOne = m_pokeDex[randomIndex];
            flag = true;
        }
        else{
            //cout << "Didn't align" << endl; 
            randomIndex = rand() % TOTAL_POKEMON; // reassigns random number in case rarities dont match up 
            //cout << randomIndex << endl;  
        }
    }
    while (!flag);
 return chosenOne;

}


int Game::CatchMenu(){
    int choice = 0; 
  
    cout << "What rarity of Pokemon would you like to catch?" << endl;  
    cout << "1. Common (High Proability)" << endl; 
    cout << "2. Uncommon (Normal Probablity)" << endl; 
    cout << "3. Ultra Rare (Extremely Low Probability)" << endl; 
    cin >> choice; 
    while (choice <1 || choice>3){   //validates user input
        cout<< "Invalid input! (1-3)" << endl;
        cout << "What rarity of Pokemon would you like to catch?" << endl; 
        cout << "1. Common (High Proability)" << endl; 
        cout << "2. Uncommon (Normal Probablity)" << endl; 
        cout << "3. Ultra Rare (Extremely Low Probability)" << endl; 
        cin >> choice;
    }
   return choice; 
}
void Game::AddPokemon(Pokemon newPokemon){
    Pokemon acquiredPokemon; //creating new pokemon instance, will  be used as comparison 
    acquiredPokemon = newPokemon;
   // acquiredPokemon.SetName(newPokemon.GetName()); 
   // acquiredPokemon.SetCP(newPokemon.GetCP());
   //cout << "The new pokemon CP is "<<  newPokemon.GetCP() << endl;
    if(TeamSize()< NUM_TEAM){ 
        m_team[TeamSize()] = acquiredPokemon;
        
    }
    else{
        for (int i=0; i<NUM_TEAM; i++){
            //cout << "The one we are comparing with is " << m_team[i].GetName() << " with a CP of " << m_team[i].GetCP() << endl; 
            if(newPokemon.GetCP() > m_team[i].GetCP()){
                m_team[i] = newPokemon;
               return;
            }
            else{     
            }
        }
    }

}   
int Game::TeamSize(){
    int teamNum = 0;
    for (int i=0; i<NUM_TEAM;i++){
        if(m_team[i].GetName() !=""){  //if name is retrieved and it's not blank, it means theres a pokemon at that index
            teamNum+=1;
        }
        else
        {
            return teamNum;
        }
    }
  return teamNum;
}

void Game::DisplayTeam(){
//cout << "Test: " << TeamSize() << endl; 
        if(TeamSize() != 0){
            for (int i=0; i<TeamSize(); i++){
            cout << i+1 << ". " << m_team[i].GetName() << " " << m_team[i].GetCP() << " " << endl; // will iterate through m_team and display pokemon.
            }
        }
        else{
         cout << "You have no team yet. Maybe search for a Pokemon?!" << endl; 
        return;
}
return;
}

int Game::FindPokemon(string name){
    int pokeIndex = 0; 
    for(int i=0; i<TOTAL_POKEMON; i++){
        if(name == m_pokeDex[i].GetName()){
            pokeIndex = i;
        }
    }
   return pokeIndex;
}

void Game::TrainPokemon(){
int selectedPokemon = 0; 
    if(TeamSize() == 0){
        cout << "You have no team yet. Maybe search for a Pokemon?!" << endl; 
        return;
    }   
    else{
        DisplayTeam(); 
        cout << "Which of your Pokemon would you like to train? (1-4)" << endl; 
        cin >> selectedPokemon;
        selectedPokemon = selectedPokemon-1; 
        //finding max cp to pass inn.
        int maxCPLocator = FindPokemon(m_team[selectedPokemon].GetName());  //uses find pokemon to get max CP of pokemon
       // cout << "the index of " << m_team[selectedPokemon].GetName() << " is " << maxCPLocator << endl;
        //cout << "You chose to train " << m_team[selectedPokemon].GetName() <<" their orginal CP is " << m_team[selectedPokemon].GetCP() << endl; 
        m_team[selectedPokemon].Train(m_pokeDex[maxCPLocator].GetCP());
       // cout << m_team[selectedPokemon].GetName() << " has been trained to " << m_team[selectedPokemon].GetCP() << endl;
       cout << "Your " << m_team[selectedPokemon].GetName() << "'s CP goes up! " << endl;
    }   
}

void Game::BattlePokemon(){
    int opponentPokemon = 0; 
    srand(time(NULL)); 
    opponentPokemon =rand() % TOTAL_POKEMON;
    int selectedPokemon = 0;
    int enemyBaseCP = 0;
    if(TeamSize() == 0){ // output for when user has no Pokemon in team. 
        cout << "You have no team yet. Maybe search for a Pokemon?!"  << endl; 
    }
    else {
        cout << "You are going to fight a "<< m_pokeDex[opponentPokemon].GetName() << endl; 
        Pokemon enemyPokemon = m_pokeDex[opponentPokemon];
        enemyBaseCP = rand() % enemyPokemon.GetCP();
        enemyPokemon.SetCP(enemyBaseCP+ 200);
        cout << "The enemy has a CP of " << enemyPokemon.GetCP() << endl; 
        cout << "Which of your Pokemon would you like to use? " << endl;  
        DisplayTeam();
        cin >> selectedPokemon; 
        selectedPokemon = selectedPokemon -1;  // since user inputs 1-4, will need to subtract 1 so it matches with m_team intdex
       /* Pokemon enemyPokemon = m_pokeDex[opponentPokemon];
        enemyPokemon.SetCP(0 - (enemyPokemon.GetCP()) + 200);
        cout << "The enemy pokemon has a CP of " << enemyPokemon.GetCP() << endl; */
            if (m_team[selectedPokemon].GetCP() <= enemyPokemon.GetCP()){
                cout << "You lost" << endl;
                cout <<  "Your " << m_team[selectedPokemon].GetName() << " can't lift it's head" << endl;
                cout << "You should probably replace them " << endl;
                m_team[selectedPokemon].SetCP(0); // sets CP to 0 after a lost battle. 
                }
            else{
                cout <<"You won!!" << endl; 
                }
        }
}


void Game::Start(){
    LoadFile();  // function that essentially starts the game. 
    MainMenu();
}

