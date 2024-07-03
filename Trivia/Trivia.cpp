/*****************************************************************************
 ** File: Trivia.cpp
 ** Project: CMSC 202 Project 5, Spring 2022
 ** Author:  Kush Shah and CMSC202
 ** Date:    04/05/2022
 ** Email:   k216@umbc.edu
 **
 Description: CPP file for Trivia class. Includes both class definition and
 class function definitions. Loads a file of trivia questions
*****************************************************************************/

#ifndef TRIVIA_CPP
#define TRIVIA_CPP
#include "Lqueue.cpp"
#include "Question.cpp"
#include <fstream>
#include <vector>
using namespace std;

const string DEFAULT_FILE = "proj5_string.tTriviaDatat";
const char DELIMITER = '|';

template <class T>
class Trivia {
public:
  // Name: Default Constructor
  // Desc: Displays the title, Loads Questions and calls menu
  // Indicates if the file was not loaded.
  // Precondition: None
  // Postcondition: User is prompted with assignment menus
  Trivia(string filename= DEFAULT_FILE);
  // Name: Destructor
  // Desc: Deallocates memory allocated for the Questions and
  // resets all variables.
  // Precondition: A Trivia exists.
  // Postcondition: All dynamically allocated memory in Trivia is deleted.
  ~Trivia();
  // Name: LoadQuestions
  // Desc: Each input file will be for a specific type of question (int, double, string)
  //       Reads in Questions from a file and stores them in anLqueue.
  //       An input file will be for exactly one type of question (int, double, string)
  // Precondition: None.
  // Postcondition: Returns true if file was read. Otherwise, it returns false.
  bool LoadQuestions(string filename);
  // Name: MainMenu
  // Desc: Presents user with menu options for showing subjects and allowing
  // user to work on a subject.
  // Precondition: None.
  // Postcondition: The main menu is presented.
  void MainMenu();
  // Name: DisplaySubjects
  // Desc: Presents all Subjects with corresponding numerical identifiers.
  // Precondition: Subjects have been added.
  // Postcondition: All assignments are printed to the screen.
  void DisplaySubjects();
  // Name: StartSubject
  // Desc: Starts working on a selected Subject.
  // Displays the number of questions in subject.
  // Starts at beginning and goes through each question.
  // After all questions have been answered:
  //       displays total score, inscore, and percentage score
  // Precondition: m_questions has been populated
  // Postcondition: Returns to main menu
  void StartSubject();
  // Name: AddSubject
  // Desc: Checks to see if a subject exists in m_subjects.
  //       If not, inserts subject into m_subjects.
  // Precondition: A Subject exists.
  // Postcondition: Add subject to m_subjects if new subject.
  void AddSubject(string subject);
  // Name: ChooseSubject
  // Desc: Allows a user to choose one of the subjects to work on. Lists all subjects
  // in m_subjects and allows use to choose one. Returns value - 1 (location in vector)
  // Precondition: A Subject exists.
  // Postcondition: Returns value entered minus one
  int ChooseSubject();
  // Name: QuestionsPerSubject
  // Desc: Iterates over m_questions and counts how many questions match the subject
  // passed into function
  // Precondition: A Subject exists.
  // Postcondition: Returns number of questions of a particular subject
  int QuestionsPerSubject(string subject);
  // Name: DisplayTitle
  // Desc: Displays opening Welcome message
  // Precondition: None.
  // Postcondition: Title is displayed.
  void DisplayTitle();
private:
  Lqueue<Question<T>* >* m_questions; // Holds questions using a specific data type
  vector<string> m_subjects; //Populated as file is loaded
};

//**********Implement Trivia Class Here***********


// Name: Default Constructor
// Desc: Displays the title, Loads Questions and calls menu
// Indicates if the file was not loaded.
// Precondition: None
// Postcondition: User is prompted with assignment menus

template <class T>
Trivia<T>::Trivia(string filename){
  DisplayTitle();
  m_questions = new Lqueue<Question<T>* >; // constructing new lqueue
  LoadQuestions(filename); //Loads questions
  MainMenu();

}


// Name: Destructor
// Desc: Deallocates memory allocated for the Questions and
// resets all variables.
// Precondition: A Trivia eTriviaDataists.
// Postcondition: All dynamically allocated memory in Trivia is deleted.
template <class T>
Trivia<T>::~Trivia(){
for(int i=0; i< m_questions->GetSize() ; i++){
  delete m_questions->At(i);    //deallocate question pointer, 
}
  delete m_questions; //deallocate node, lqueue destructed
}


// Name: LoadQuestions
// Desc: Each input file will be for a specific type of question (int, double, string)
//       Reads in Questions from a file and stores them in anLqueue.
//       An input file will be for eTriviaDataactly one type of question (int, double, string)
// Precondition: None.
// Postcondition: Returns true if file was read. Otherwise, it returns false.
template <class T>
bool Trivia<T>::LoadQuestions(string filename){

  //loads all questions into the Lqueue, and subjets into m_subjects
  fstream TriviaData;
  TriviaData.open(filename);

  string subject, question, datatype, difficulty, newLine;
  T answer;

  cout << "Loading questions..." << endl;
  if (TriviaData.is_open()){ //checks if file is open

  while (getline (TriviaData, subject, DELIMITER)){
  
    getline(TriviaData, question, DELIMITER);
    getline(TriviaData, datatype, DELIMITER); 
    getline(TriviaData, difficulty, DELIMITER);
    TriviaData >> answer;
    getline(TriviaData,newLine); // ensures subjects are displayed in line 


    Question<T>* questionPtr = new Question(subject, question, datatype, stoi(difficulty), answer);
    m_questions->Push(questionPtr);
    AddSubject(questionPtr->m_subject);

  }
   cout << "Loading complete!" <<  endl; 
   return true; 
  }
  else {
    cout << "ERROR: File could not be loaded" << endl; 
    return false;
  }

}

// Name: MainMenu
// Desc: Presents user with menu options for showing subjects and allowing
// user to work on a subject.
// Precondition: None.
// Postcondition: The main menu is presented.

template <class T>
void Trivia<T>::MainMenu(){
int choice = 0; 

while(choice !=3){
  cout << "Choose an option." << endl; 
  cout << "1. Display subjects" << endl;
  cout << "2. Start subject" << endl;
  cout << "3. Quit" << endl; 
  cin >> choice;

  while(choice<1 || choice >3){  //validates input
  cout << "Invalid input!" << endl;
  cout << "Choose an option." << endl;
  cout << "1. Display subjects" << endl;
  cout << "2. Start subject" << endl;
  cout << "3. Quit" << endl; 
  cin >> choice;
  }

if(choice == 1){ 
  DisplaySubjects();
}
else if(choice == 2){
  StartSubject();
}

}
cout << "Thank you for using UMBC Trivia!" << endl;
}

// Name: DisplaySubjects
// Desc: Presents all Subjects with corresponding numerical identifiers.
// Precondition: Subjects have been added.
// Postcondition: All assignments are printed to the screen.
template <class T>
void Trivia<T>::DisplaySubjects(){
  cout << "Possible subjects:" << endl; 
  for (unsigned int i = 0; i < m_subjects.size(); i++){
    cout << i+1 << ". " << m_subjects[i] << endl; 
  }
}

// Name: StartSubject
// Desc: Starts working on a selected Subject.
// Displays the number of questions in subject.
// Starts at beginning and goes through each question.
// After all questions have been answered:
//       displays total score, inscore, and percentage score
// Precondition: m_questions has been populated
// Postcondition: Returns to main menu
template <class T>
void Trivia<T>::StartSubject(){
  string subject;
  T userInput;
  int questionCounter = 0; // total questions in the subject
  int questionNum = 0; // current question tracker
  int score = 0; // keeps track of user score
  
  int index = ChooseSubject();
  subject = m_subjects[index];
  
  questionCounter = QuestionsPerSubject(subject);
  cout << "There are " << questionCounter << " questions in this subject" << endl;

  for (int i = 0; i < m_questions->GetSize(); i++){

    //Checks to ask questions from same subject
    if (m_questions->At(i)->m_subject == subject){
    questionNum++;
      
      cout << questionNum << ". Question: " << *(m_questions->At(i)) << endl;
      cout << "Please answer with a(n) string." << endl << endl;
      cin >> userInput;
      
      m_questions->At(i)->m_isAnswered = true;
    
      if (m_questions->At(i)->CheckAnswer(userInput)){
	cout << "correct" << endl;
  
	score++;
	
    }else{

	cout << "Incorrect" << endl;
	
      }
    }
  }

  
  cout << "You got " << score << " answers correct." << endl;  //calculuates score
  cout << "You got " << questionCounter - score << " answers incorrect." << endl;
  cout << "Which is a " << score*100/double(questionCounter) << "%." << endl; // returns score as a double

  }


// Name: AddSubject
// Desc: Checks to see if a subject exists in m_subjects.
//       If not, inserts subject into m_subjects.
// Precondition: A Subject exists.
// Postcondition: Add subject to m_subjects if new subject.
template <class T>
void Trivia<T>::AddSubject(string subject){
  bool check = false;
  
  for (unsigned int i = 0; i < m_subjects.size(); i++){
    if (m_subjects[i] == subject){
      check = true;
    }
  }
  
  if(check == false){
    m_subjects.push_back(subject);
  }
}


// Name: QuestionsPerSubject
// Desc: Iterates over m_questions and counts how many questions match the subject
// passed into function
// Precondition: A Subject exists.
// Postcondition: Returns number of questions of a particular subject
template <class T>
int Trivia<T>::QuestionsPerSubject(string subject){    
  int checker = 0;
  
  for (int i = 0; i < m_questions->GetSize(); i++){ 
    if (m_questions->At(i)->m_subject == subject){
      checker++;
    }
  } 
  return checker;
}

// Name: DisplayTitle
// Desc: Displays opening Welcome message
// Precondition: None.
// Postcondition: Title is displayed.
template <class T>
void Trivia<T>::DisplayTitle(){
cout << "Welcome to UMBC Trvia!" << endl; 
}


// Name: ChooseSubject
// Desc: Allows a user to choose one of the subjects to work on. Lists all subjects
// in m_subjects and allows use to choose one. Returns value - 1 (location in vector)
// Precondition: A Subject exists.
// Postcondition: Returns value entered minus one
template <class T>
int Trivia<T>::ChooseSubject(){
  int choice = 0;
  
  cout << "What subject would you like to attempt?" << endl;
  DisplaySubjects();  

while(choice<1 || choice > int(m_subjects.size())){ // input validation
    cout << "Please enter a valid option. "<< endl; 
    cin >> choice; 
  }
    return choice -1; 
}
#endif
