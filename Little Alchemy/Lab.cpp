#include "Lab.h"
#include "Chemist.h"
Lab::Lab(){}

void Lab::StartLab(){

    LabTitle();
    LoadSubstances();
    string name;
    cout <<  "What is the name of your chemist?" << endl; 
    getline(cin,name);
    m_myChemist.SetName(name);
int choice;
do{
  
   choice = MainMenu(); 
    switch (choice)
    {
    case 1 :
      DisplaySubstances();

      break;
    case 2: 
      SearchSubstances();
      break;
    
    case 3: 
      CombineSubstances();
      break;
    case 4:
      CalcScore();

    default:
    cout << "You have entered an invalid command!" << endl; 
      break;
    }}while (choice != 5 && m_myChemist.GetTotalSubstances() != PROJ2_SIZE);
    

   
}

void Lab::LoadSubstances(){
    string name, type, formula, sub1, sub2; 
    fstream newFile;
    newFile.open(PROJ2_DATA);

    for (int i = 0 ; i < PROJ2_SIZE ; i++){

        getline(newFile, name, ',');
        getline(newFile, type, ',');
        getline(newFile, formula, ',');
        getline(newFile, sub1, ',');
        getline(newFile, sub2 );
    
    Substance inst(name, type, formula, sub1, sub2, 0);
    m_substances[i] = inst;

    m_myChemist.AddSubstance(inst);  
    }    
}
void Lab::DisplaySubstances(){

  for(int i=0 ;  i< PROJ2_SIZE ; i++)
  
  cout << i+1 << ". " << m_myChemist.GetSubstance(i).m_name  << " " << "(" << m_myChemist.GetSubstance(i).m_formula << ")" << " " << m_myChemist.GetSubstance(i).m_quantity << endl;
  
}

int Lab::MainMenu(){

  int choice;
  do{
  cout << "What would you like to do?" << endl;
  cout << "1. Display your Chemist's substances" << endl;
  cout << "2. Search for elements" << endl; 
  cout << "3. Attempt to Merge Substance" << endl; 
  cout << "4. See Score" << endl;
  cout << "Quit" << endl; 
  cin >> choice ; 

  if (choice < 1 && choice > 5){
    cout << "Invalid choice! Try again!" << endl; 
  }
} while (choice < 1 && choice > 5);
  
   return choice;
}


void Lab::SearchSubstances(){

  srand(time(NULL));
  int num = rand() % PROJ2_SIZE;

  while (m_substances[num].m_type != "element"){
    num = rand() %PROJ2_SIZE;
  }
  m_myChemist.IncrementQuantity(m_substances[num]);

  cout << m_substances[num].m_name  << " found!" << endl;
  cout << endl;
}

void Lab::CombineSubstances(){

int choice, num;
Substance elem1, elem2; 

RequestSubstance(choice);

elem1 = m_myChemist.GetSubstance(choice - 1);

RequestSubstance(choice);

elem2 = m_myChemist.GetSubstance(choice - 1);

num = SearchFormulas(elem1.m_name, elem2.m_name);

if (num == -1){
    cout << "Nothing happened when you tried to combine " << elem1.m_formula << " and " << elem2.m_formula << endl;

  }else{
    if (m_myChemist.CheckQuantity(elem1, elem2)){

      m_myChemist.DecrementQuantity(elem1);
      m_myChemist.DecrementQuantity(elem2);

      m_myChemist.IncrementQuantity(m_myChemist.GetSubstance(num));

      cout << elem1.m_formula << " combined with " << elem2.m_formula << " to make " << m_myChemist.GetSubstance(num).m_name << "!" << endl;
      cout << "Your Chemist has built " << m_myChemist.GetSubstance(num).m_name << "." << endl;
    }else{
      cout << "You do not have enough " << elem1.m_name << " or " << elem2.m_name << " to attempt that merge" << endl;
    }
  }


}


void Lab::CalcScore(){

  cout << "The Great Chemist " << m_myChemist.GetName() << endl;
  cout << "There are " << PROJ2_SIZE << " Substances available to find." << endl;
  cout << "You have found " << m_myChemist.GetTotalSubstances() << " so far." << endl;
  cout << "This is " << double ((m_myChemist.GetTotalSubstances()) / (PROJ2_SIZE)) * 100 << "%" << endl;

 }

void Lab::RequestSubstance(int &choice){

cout << "Which substances would you like to merge? " << endl; 
cout << "To list known substances enter -1" << endl;
cin >> choice; 

while(choice <1 || choice > PROJ2_SIZE){
  if (choice == -1){
    DisplaySubstances();
  }
  else{
    cout << "Invalid index! Enter again." << endl;
    cout << "Which substances would you like to merge? " << endl; 
    cout << "To list known substances enter -1" << endl;
    cin >> choice; 

  }
}

}

int Lab::SearchFormulas(string title1, string title2){

  string compound1, compound2; 


  for (int i = 0; i< PROJ2_SIZE; i++){
    
    if(m_myChemist.GetSubstance(i).m_name == title1) {
      compound1 = m_myChemist.GetSubstance(i).m_formula; 
    }
    
     if(m_myChemist.GetSubstance(i).m_name == title2) {
      compound2 = m_myChemist.GetSubstance(i).m_formula; 
    }


  }

  for (int i =0; i<PROJ2_SIZE; i++){
    if ((m_myChemist.GetSubstance(i).m_substance1 == compound1) && (m_myChemist.GetSubstance(i).m_substance2 == compound2)) {

      return i;

    if ((m_myChemist.GetSubstance(i).m_substance1 == compound2) && (m_myChemist.GetSubstance(i).m_substance2 == compound1)) {

      return i;
    

  }

 
    }}
    return 0;
    }