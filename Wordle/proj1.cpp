/* 
Title: UMBC Wordle
Author: Josh Ventura
Date: 3/1/22
Section: 14
E-mail: j246@umbc.edu
Description: C++ adaptation of wordle

*/

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

const int WORD_COUNT = 2315;
const string CORRECT = "!";
const string CLOSE = "&";
const string WRONG = "_";
const string EMPTY = "_____";

void loadWords (string wordList[]);
// Function name: loadWords
// Pre-condition: wordlist is an array of strings
// Post-condition: will successfully import word list file
void displayCurrent (string symbolList[], string stringList[]);
// Function name: displayCurrent
// Pre-condition: symbolList is an empty array with the means of displaying past and previous word guesses
//     stringList will display past word guesses
// Post-condition: Will display an array with user history towards game progress
void guessWord (string wordList[]);
// Function name: guessWord
// Pre-conditiion: takes in word list, chooses a random word and sets word as the selectedWor
// Post-condiition: returns wordlist, this function will take user input and see if the word is the same as        selectedWord 
int checkWin (string symbols, string selectedWord,  int index, string wordList[]);
// Function name: checkWin
// Pre-condition: will take in selected word and guess and loop to see if word matches selected word
// Post-condition: will let user know if theres a win, and allow user to loop and play another round
string checkLetter (string guess, string selectedWord) ;
// Function name: checkLetter
// Pre-condition: will take in two strings, guess and selectedWord
// Post-condition: will iterate between both strings and let user know if letter is in selectedWord


int main() {
  
    string wordList[WORD_COUNT];
    
    loadWords(wordList);
    guessWord(wordList);
    return 0;
}

void loadWords (string wordList[]){
  cout << "Welcome to UMBC Wordle!" << endl;
    int index = 0;

    fstream file;   // opening file 
    file.open("proj1_data.txt");

    while(getline(file, wordList[index]) ){ // looping through file and indexing words into an array
      // cout << wordList[index] << endl;
        index++;
	
    }

    cout << "Your file was imported! " << endl;
    cout << WORD_COUNT << " words imported." << endl;
    

}



void guessWord (string wordList[]){
  string displayString[6];
  string displaySymbols[6];
  
  
  for (int k=0; k<6; k++){
    displayString[k] = EMPTY;
    displaySymbols[k] = EMPTY;
    
  }
    
  int i=0;
  string guess;
    
    string selectedWord; 

    srand(time(NULL));      // used in order to select a random word 
    int randIndex = rand() % WORD_COUNT;
    
    selectedWord = wordList[randIndex];

   
    do{
      bool flag = false;
       cout << "What word would you like to guess?" << endl;

       cin >> guess;
       for (int j = 0; j<WORD_COUNT; j++){
	 if(guess == wordList[j]){
	   flag = true;}
       }
	 if (flag == false){
	   cout << "That word is not in the word list!" << endl;
	   
	 }
	 else {
	   string symbols ="";
	   displayString[i] = guess; 
	   displaySymbols[i] =  checkLetter(guess,selectedWord); 
	  
	   displayCurrent(displaySymbols,displayString); 
	   
	   bool status = checkWin(guess,selectedWord,i,wordList);
	   if(status == 0){
	     break;}
	   
	     
	   i++;
	 }
	   
    }

	 while(i<6);
    if(i == 6){
    checkWin(guess,selectedWord,i,wordList);
    }
}

string checkLetter(string guess,string selectedWord){
  string symbol = "";
    
  for (int i=0; i<5; i++){
    bool check = false;
    for(int j=0; j<5; j++){
      if (guess[i] == selectedWord[j]){
	check = true;
	if((guess[i]== selectedWord[i]) and (guess[j] == selectedWord[j])){
	  symbol += CORRECT;
    
	}
	else{
	  symbol += CLOSE; }
   
      }
    
    }
    if (check != true){
      symbol += WRONG;

    }
    
    
    }
  
    return symbol;
}

void displayCurrent (string symbolList[], string stringList[]){
  for (int i=0; i < 5; i++){
    if(stringList[i] != EMPTY){
      cout << stringList[i] << endl;
    }
    cout << symbolList[i] << endl;

  }
}
int checkWin (string guess,string selectedWord, int index,string wordList[]){
   string repeat;
   if(guess == selectedWord){
     cout<< "Congrats you won!" << endl;
     cout << "The correct word was " << selectedWord << endl;
     cout << "Another game? y/n" << endl;
     cin >> repeat ;
   }
   
   if(index== 6){
     cout << "Sorry, you lost!" << endl;
     cout<< "The correct word was " << selectedWord << endl;
     cout << "Another game? y/n" << endl;
     cin>> repeat;
   }
  
   
   if(repeat == "y"){
       guessWord(wordList);
   }
   else if(repeat == "n"){
       cout<< "Thank you!" << endl;
       return 0;
       

     }
   return 1;
}

   
