#include "Chemist.h"
#include "Lab.h"


Chemist::Chemist(){
m_myName = "Beaker";
m_numSubstances = 0; 
}

// Overloaded constructor
Chemist::Chemist(string name){
m_myName = name;
m_numSubstances = 0; 
}

string Chemist::GetName(){
    return m_myName;
}

void Chemist::SetName(string name){
    m_myName = name;
}

int Chemist::CheckSubstance(Substance elem){

for (int i=0; i<PROJ2_SIZE ; i++){

if (elem.m_name == m_mySubstances[i].m_name){
    
    return i;} 

else{
    return -1; }
}}

void Chemist::AddSubstance(Substance elem){
bool flag = false; 
for (int i= 0 ; i<m_numSubstances ; i++){

    if (m_mySubstances[i].m_name == elem.m_name ){
    flag = true;
    }}  
    if(flag == false){
        m_mySubstances[m_numSubstances] = elem;
        m_mySubstances[m_numSubstances].m_quantity= 0;
        m_numSubstances++;
    }   
}

void Chemist::IncrementQuantity(Substance elem){

for (int i=0 ; i<m_numSubstances ; i++){

    if(m_mySubstances[i].m_name == elem.m_name);

    m_mySubstances[i].m_quantity++;

}}



bool Chemist::DecrementQuantity(Substance elem){

for (int i=0 ; i<m_numSubstances ; i++){

    if(m_mySubstances[i].m_name == elem.m_name){

        m_mySubstances[i].m_quantity--;

        return true;
    }
}
    return false;
}

bool Chemist::CheckQuantity(Substance elem1, Substance elem2){
bool flag1 = false; 
for (int i=0 ; i<PROJ2_SIZE; i++){
    if(m_mySubstances[i].m_name == elem1.m_name ){
    if (m_mySubstances[i].m_quantity > 1){
        flag1 = true;
    }}
 
}
bool flag2 = false; 
for (int i=0 ; i<PROJ2_SIZE ;  i++){

    if(m_mySubstances[i].m_name == elem2.m_name){
         if (m_mySubstances[i].m_quantity > 1){
        flag2 = true; 
    }
}}
if(flag1 && flag2){
    return true;
}
return false;
}

Substance Chemist::GetSubstance(int num){
   return m_mySubstances[num];


}

int Chemist::GetTotalSubstances(){
    int totalSubstance = 0;

    for (int i=0 ;  i< PROJ2_SIZE; i++){

         if (m_mySubstances[i].m_quantity > 0){
        totalSubstance++;
         }
    return totalSubstance;  
    }
}