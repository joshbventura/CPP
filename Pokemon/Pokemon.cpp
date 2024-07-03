/*****************************************
** File:    Pokemon.cpp
** Project: CMSC 202 Project 2, Spring 2024
** Author:  Josh Ventura
** Date:    3/12/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
** This is the .cpp file for Pokemon.h which contains the function implementations 
** for the functions outlined in the .h file. This implements the functions needed to make an instance of the pokemonn class. 
***********************************************/
#include "Pokemon.h" //header guards
#include "Game.h" //header guards


//Default Constructor
Pokemon::Pokemon(){
    int num = 0;
    string name = "";
    int CP = 0;
    int rarity = 0;
}

//Overloaded Constructor
Pokemon::Pokemon(int num, string name, int cp, int rarity){
    m_num = num;
    m_name = name;
    m_CP = cp;
    m_rarity = rarity;
}

//Getter 
int Pokemon::GetCP(){
    return m_CP;
}

//Getter
int Pokemon::GetRarity(){
    return m_rarity;
}

//Getter
string Pokemon::GetName(){
    return m_name;
}


//Getter
int Pokemon::GetNum(){
    return m_num;
}

//Setter
void Pokemon::SetRarity(int newRarity){
     if (newRarity >= 1 && newRarity <= 3) {
        m_rarity = newRarity;
    }
}



//Setter
void Pokemon::SetName(string newName){
      m_name = newName;
}

//Setter
void Pokemon::SetCP(int newCP){
      m_CP = newCP;
}

// Name: Train
// Desc: Increases the CP by TRAIN_POWER up to maxCP
// Preconditions - maxCP is calculated and passed to this function
// Postconditions - Updates m_CP by TRAIN_POWER to maxCP
void Pokemon::Train(int maxCP){
    if (m_CP + TRAIN_VALUE <= maxCP){
        m_CP += TRAIN_VALUE; 
    }
        else{
            m_CP = maxCP;
        }

}
















