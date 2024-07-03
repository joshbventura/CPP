/*****************************************
** File:    Proj1.cpp
** Project: CMSC 202 Project 1, Spring 2024
** Author:  Josh Ventura
** Date:    2/27/24
** Section: 10/12
** E-mail:  j246@umbc.edu
**
** This project is a C++ implementation of the game "Wheel of Fortune!", where a puzzle will be randoly selected from 
** a text file with a list of categories/words. The user will then guess the puzzle letter by letter until completion. 
**
***********************************************/

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime> 
#include <cstdlib>
using namespace std;

const int NUM_LINES=48;
const int ASCII = 256; 
const string FILE_NAME= "proj1_data.txt";

void loadFile (string categoryList[], string puzzleList[]);
//---------------------------------------------------------------------------------------------------------------
// Name: loadFile
// PreCondition:  This wunction will take in two empty string arrays, one to hold the categories and another to 
//                 hold the puzzles. 
// PostCondition: This function doesn't return anything, but will append the contents of the loaded file into the arrays
//                 and update the arrays to be used. 
//---------------------------------------------------------------------------------------------------------------
string getAnswer (string wordList[], string categoryList[]);
//---------------------------------------------------------------------------------------------------------------
// Name: getAnswer
// PreCondition:  This function take in two string arrays, one for the word list and another for the category in order 
//                to pick a random index and set those equal to the random puzzle
// PostCondition: Returns a string of the randomly selected p uzzleselected puzzle
//---------------------------------------------------------------------------------------------------------------
 char getInput(int letters[]);
 //---------------------------------------------------------------------------------------------------------------
// Name: getInput
// PreCondition:  Will take in array of guessed letters in order to make sure there are no repeat guesses. 
// PostCondition: Returns a character of the user's guess
//---------------------------------------------------------------------------------------------------------------
bool inPuzzle(string selectedPuzzle, char guess, int letters[]);
//---------------------------------------------------------------------------------------------------------------
// Name: inpuzzle
// PreCondition:  Will take in the string of the randomly selected puzzle, take in the char guess from the user,
//                and a letter array to traverse through each index of the selected puzzle string and check it with
//                the inputted guess. It will then append the guess to the letter array at its ascii value. 
// PostCondition: Updates `letters[]` by marking the guessed letter. Returns true if the guessed letter is in the puzzle, 
//                false otherwise
//---------------------------------------------------------------------------------------------------------------
string printPuzzle(string selectedPuzzle, int letters[]);
//---------------------------------------------------------------------------------------------------------------
// Name: printPuzzle
// PreCondition:  Receives a string `selectedPuzzle` representing the current puzzle and an integer array `letters[]` that 
//                indicates which letters have been guessed.
// PostCondition: Returns a string that visually represents the puzzle to the user, with guessed letters shown and 
//                unguessed letters hidden with a '_'.
//---------------------------------------------------------------------------------------------------------------
bool isCompleted(string guessedLetters);
//---------------------------------------------------------------------------------------------------------------
// Name: isCompleted
// PreCondition:  The function takes a string `guessedLetters`, which represents the current state of the player's 
//                guesses of the puzzle itself. 
// PostCondition: Returns a string of the randomly selected p uzzleselected puzzle
//---------------------------------------------------------------------------------------------------------------

int main() {

    // initializing two seperate string arrays one to hold the puzzles and another to hold 
    // the categories 
    string puzzleList[NUM_LINES/2];  
    string categoryList[NUM_LINES/2]; 
    string guessedLetters = ""; // String to store guessed letters
    bool flag = false; // boolean flag to check if game is complete or not
    int letters[ASCII] = {0};  // Array to track guessed letters

    
    cout << "Welcome to UMBC Fortune Wheel!" << endl;

    loadFile(categoryList, puzzleList); 
    string selectedPuzzle = getAnswer(puzzleList, categoryList); // calls getAnswer function to set a random puzzle.
    

    // Do while loop until the puzzle is complete
    guessedLetters = printPuzzle(selectedPuzzle,letters);
    do {
        char guess = getInput(letters);
        inPuzzle(selectedPuzzle, guess, letters);
        guessedLetters = printPuzzle(selectedPuzzle,letters);
        flag = isCompleted(guessedLetters);
        //cout << flag << endl; 
    }
        while (flag == false);


    cout << "You won!" << endl;
    return 0;
}



void loadFile(string categoryList[], string puzzleList[]){

    ifstream dataFile;  // opens the file
    dataFile.open(FILE_NAME);

    // traverses through the file line-by-line alternating what is appended into the category list
    // and then the puzzle list
    int i=0;
     while (i < NUM_LINES && getline(dataFile, categoryList[i]) && getline(dataFile, puzzleList[i])){ 
        i++;
    }

    dataFile.close();
    cout << i << " puzzles loaded. " << endl;
    }
    
string getAnswer(string puzzleList[], string categoryList[]){
    int puzzleIndex = 0;  //initializing inter value that will updated with a random index. 
    string selectedPuzzle; // initializing a string to be returned
    string selectedCategory; 

    srand(time(NULL)); // seeds ranndom functionn 
    puzzleIndex = (rand() % (NUM_LINES/2));
    //cout << puzzleIndex << endl; 

    selectedPuzzle = puzzleList[puzzleIndex]; //goes through the two arrays and sets the newly initialized string equal to the value at the randomly generated index
    selectedCategory = categoryList[puzzleIndex];

    cout << "Category is: " << selectedCategory << endl;
    // cout << selectedPuzzle << endl;
    return selectedPuzzle;
}

 char getInput(int letters[]) {
    char input;
    int asciiValue; // variable to store the ASCII value of input

    do {
        cout << "What letter would you like to try?" << endl;
        cin >> input;
        input = toupper(input); // standardize to uppercase
        asciiValue = static_cast<int>(input); // Convert character to its ASCII value

        // check if the ASCII value is within the range of uppercase letters and not guessed before
        if (asciiValue < 65 || asciiValue > 90 || letters[asciiValue] > 0) {
            if (asciiValue < 65 || asciiValue > 90) {
                cout << "Invalid input. Please enter a letter." << endl;
            } else {
                cout << input << " already guessed." << endl;
            }
        }
    } while (asciiValue < 65 || asciiValue > 90 || letters[asciiValue] > 0); // repeat until a valid, new letter is entered

    return input;
}


bool inPuzzle(string selectedPuzzle, char guess, int letters[]) {


    int traverse =0; // traverse is that value used so we know what index in the ASCII array to increase by 1
    int selectedPuzzleASCII[ASCII] = {0}; // initializing an array that will be used to see what letters are included in the puzzle
    int updateGuess =0; //used for index purposes, will turn guess into char, and then used to traverse through guessed letters array
    int puzzleLength = selectedPuzzle.length();

    for (int i =0; i<puzzleLength; i++){
        traverse = static_cast<int> (selectedPuzzle[i]);
            selectedPuzzleASCII[traverse]+=1;      
            }

    updateGuess = static_cast<int>(guess);
    letters[updateGuess] +=1;    

    if (selectedPuzzleASCII[updateGuess] > 0){  // if index is greater than 1 then that means it is present in the puzzle
        cout << "There are " << selectedPuzzleASCII[updateGuess] << " " << guess << "'s found in the puzzle"  << endl; 
        
       /* for (int i=0; i<ASCII; i++){
        cout << "PUZZLE ASCII" << endl; 
        cout << i << endl; 
        cout << selectedPuzzleASCII[i] << endl;
          }
          for (int i=0; i<ASCII; i++){

        cout << "GUESS ASCII" << endl; 
        cout << i << endl;
        cout << letters[i] << endl; 
     } */

return true;
    }
    else{
        cout << "No " << guess << "'s found in the puzzle" << endl; 
        return false;
    }

    }


string printPuzzle(string selectedPuzzle, int letters[]){
    string puzzlePrint =""; // creating an empty string to display current state of the puzzle to the user
    int puzzleLength = selectedPuzzle.length(); //used for traversing through randomly selected puzzle in for loop

    for (int i=0; i<puzzleLength ; i++){
        if(static_cast<int> (selectedPuzzle[i] == 32)){
            puzzlePrint+=" " ;  //adds a space anytime the ASCII value of a space is found in the random puzzle
        }
        else {
            if(letters[static_cast<int>(selectedPuzzle[i])] >0){
                puzzlePrint+=selectedPuzzle[i];

            }
                else{puzzlePrint+="_"; } // prints '_" in place of unguessed lettere
        }
    }

    cout << puzzlePrint << endl; 

    return puzzlePrint;

}


bool isCompleted(string guessedLetters){
    int guessLength = guessedLetters.length();
    for (int i=0; i<guessLength;i++){
        if(guessedLetters[i] == '_'){  // traverses through guessed letters, if there still is a '_' present, it means game is still in progress
            return false;               // will mark game as incomplete until no more '_' present

        }
    }
    return true;
}
