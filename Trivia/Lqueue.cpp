#ifndef LQUEUE_CPP
#define LQUEUE_CPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Templated node class used in templated linked list
template <class T>
class Node {
   public:
  Node( const T& data ); //Constructor
  T& GetData(); //Gets data from node
  void SetData( const T& data ); //Sets data in node
  Node<T>* GetNext(); //Gets next pointer
  void SetNext( Node<T>* next ); //Sets next pointer
private:
  T m_data;
  Node<T>* m_next;
};

//Overloaded constructor for Node
template <class T>
Node<T>::Node( const T& data ) {
   m_data = data;
   m_next = NULL;
}

//Returns the data from a Node
template <class T>
T& Node<T>::GetData() {
   return m_data;
}

//Sets the data in a Node
template <class T>
void Node<T>::SetData( const T& data ) {
   m_data = data;
}

//Gets the pointer to the next Node
template <class T>
Node<T>* Node<T>::GetNext() {
   return m_next;
}

//Sets the next Node
template <class T>
void Node<T>::SetNext( Node<T>* next ) {
   m_next = next;
}

template <class T>
class Lqueue {
 public:
  // Name: Lqueue() (Linked List Queue) - Default Constructor
  // Desc: Used to build a new linked queue (as a linked list)
  // Preconditions: None
  // Postconditions: Creates a new lqueue where m_head and m_tail point to nullptr
  // Required
  Lqueue();
  // Name: ~Lqueue() - Destructor
  // Desc: Used to destruct a Lqueue
  // Preconditions: There is an existing lqueue with at least one node
  // Postconditions: An lqueue is deallocated (including dynamically allocated nodes)
  //                 to have no memory leaks!
  // Required
 ~Lqueue();
  // Name: Lqueue (Copy Constructor)
  // Preconditions: Creates a copy of existing LQueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  // Required
  Lqueue(const Lqueue&);
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: Copies an Lqueue into an existing Lqueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  // Required
  Lqueue<T>& operator= (Lqueue&);
  // Name: Push
  // Preconditions: Takes in data. Creates new node. 
  //                Requires a Lqueue
  // Postconditions: Adds a new node to the end of the lqueue.
  // Required
  void Push(const T&);
  // Name: Pop
  // Preconditions: Lqueue with at least one node. 
  // Postconditions: Removes first node in the lqueue, returns data from first node.
  // Required
  T Pop();
  // Name: Display
  // Preconditions: Outputs the lqueue.
  // Postconditions: Displays the data in each node of lqueue
  // Required (used only for testing)
  void Display();
  // Name: Front
  // Preconditions: Requires a populated lqueue
  // Postconditions: Returns whatever data is in front
  // Required
  T Front();
  // Name: IsEmpty
  // Preconditions: Requires a lqueue
  // Postconditions: Returns if the lqueue is empty.
  // Required
  bool IsEmpty();
  // Name: GetSize
  // Preconditions: Requires a lqueue
  // Postconditions: Returns m_size
  // Required
  int GetSize();
  // Name: Find()
  // Preconditions: Requires a lqueue
  // Postconditions: Iterates and if it finds the thing, returns index, else -1
  // Required
  int Find(T&);
  // Name: Swap(int)
  // Preconditions: Requires a lqueue
  // Postconditions: Swaps the nodes at the index with the node prior to it.
  // Required
  void Swap(int);
  // Name: Clear
  // Preconditions: Requires a lqueue
  // Postconditions: Removes all nodes in a lqueue
  // Required
  void Clear();
  // Name: At
  // Precondition: Existing Lqueue
  // Postcondition: Returns object from Lqueue at a specific location
  // Desc: Iterates to node x and returns data from Lqueue
  // Required
  T At (int x);
private:
  Node <T> *m_head; //Node pointer for the head
  Node <T> *m_tail; //Node pointer for the tail
  int m_size; //Number of nodes in queue
};

//**********Implement Lqueue Class Here***********


// Name: Lqueue() (Linked List Queue) - Default Constructor
// Desc: Used to build a new linked queue (as a linked list)
// Preconditions: None
// Postconditions: Creates a new lqueue where m_head and m_tail point to nullptr
// Required
template <class T>
Lqueue<T>::Lqueue(){
   m_head = nullptr;
   m_tail = nullptr;
   m_size = 0;
}


// Name: ~Lqueue() - Destructor
// Desc: Used to destruct a Lqueue
// Preconditions: There is an existing lqueue with at least one node
// Postconditions: An lqueue is deallocated (including dynamically allocated nodes)
//                 to have no memory leaks!
// Required

template <class T>
Lqueue<T>::~Lqueue(){
Clear();
}


// Name: Lqueue (Copy Constructor)
// Preconditions: Creates a copy of existing LQueue
//                Requires a Lqueue
// Postconditions: Copy of existing Lqueue
// Required

template <class T>
Lqueue<T>::Lqueue(const Lqueue& original){
   m_head = nullptr;
   m_tail = nullptr;
   m_size = 0;
   Node<T> *originalcurrent = original.m_head; 
   while(original.m_size > m_size){
      Push(originalcurrent->GetData());
      originalcurrent = originalcurrent->GetNext();
}
}



// Name: operator= (Overloaded Assignment Operator)
// Preconditions: Copies an Lqueue into an existing Lqueue
//                Requires a Lqueue
// Postconditions: Copy of existing Lqueue
// Required
template <class T>
Lqueue<T>& Lqueue<T>::operator= (Lqueue& copyLqueue){
   if (this != &copyLqueue){
   Clear();
   Node<T> *originalcurrent = copyLqueue.m_head; 
   while(copyLqueue.m_size > m_size){
      Push(originalcurrent->GetData());
      originalcurrent = originalcurrent->GetNext();
    }
  }
  return *this;
}


// Name: Push
// Preconditions: Takes in data. Creates new node. 
//                Requires a Lqueue
// Postconditions: Adds a new node to the end of the lqueue.
// Required
template <class T>
void Lqueue<T>::Push(const T& addData){
  Node<T>* addNode = new Node<T>(addData);
  if (m_tail != nullptr){
    m_tail->SetNext(addNode);
    m_tail = addNode;
  }else{
    m_head = addNode;
    m_tail = addNode;
  }
  m_size++;
}

// Name: Pop
// Preconditions: Lqueue with at least one node. 
// Postconditions: Removes first node in the lqueue, returns data from first node.
// Required
template <class T>
T Lqueue<T>::Pop(){

  Node<T>* current = m_head;
  T nodeData= m_head->GetData();
  m_head = m_head->GetNext();
  delete current;
  m_size--;

  return nodeData;
}


// Name: Display
// Preconditions: Outputs the lqueue.
// Postconditions: Displays the data in each node of lqueue
// Required (used only for testing)
template <class T>
void Lqueue<T>::Display(){

 if(IsEmpty() == false){
      Node<T> *current = m_head;

      while(current->GetNext() != nullptr){
         cout << current->GetData() << "->" << endl;
         current = current->GetNext();
      }
      cout << current->GetData() << endl;
   }else{
      cout << "ERROR: List empty." << endl;

   }
}

// Name: Front
// Preconditions: Requires a populated lqueue
// Postconditions: Returns whatever data is in front
// Required
template <class T>
T Lqueue<T>::Front(){  
   
   if(IsEmpty() == false){
      return m_head->GetData(); // returns data from first node
   }else{
      return NULL;
      cout << "ERROR: List empty" << endl;
   }
}

// Name: IsEmpty
// Preconditions: Requires a lqueue
// Postconditions: Returns if the lqueue is empty.
// Required
template <class T>
bool Lqueue<T>::IsEmpty(){
   if (m_size <=0){
      return true;
   } else{
      return false;
   }
}

// Name: GetSize
// Preconditions: Requires a lqueue
// Postconditions: Returns m_size
// Required
template <class T>
int Lqueue<T>::GetSize(){
   return m_size;
}

// Name: Find()
// Preconditions: Requires a lqueue
// Postconditions: Iterates and if it finds the thing, returns index, else -1
// Required
template <class T>
int Lqueue<T>::Find(T& compData){
   if(IsEmpty() == false){
      int counter = 0;
      Node<T> *current = m_head;

      while(current->GetNext() != nullptr){ 

         if (current->GetData() == compData){
            return counter;
         }
         current = current->GetNext();
         counter++;
      }
   }
   return -1;
}

// Name: Swap(int)
// Preconditions: Requires a lqueue
// Postconditions: Swaps the nodes at the index with the node prior to it.
// Required
template <class T>
void Lqueue<T>::Swap(int index){

  int checker = 0;
  Node<T>* prev = m_head;
  Node<T>* current = m_head;
  Node<T>* next = m_head;

    if (index == 1){
      next = next->GetNext();
      current->SetNext(next->GetNext());
      next->SetNext(prev);
      m_head = next;
      if (m_size == 2){
	m_tail = current;
      }
    }
   else{
   while (checker != index){
	prev = current;
	current = next;
	next = next->GetNext();
	checker++;
      }
      prev->SetNext(next);
      current->SetNext(next->GetNext());
      next->SetNext(current);
      
   if (index == m_size){
	m_tail = current;
    }
  }
}
  


// Name: Clear
// Preconditions: Requires a lqueue
// Postconditions: Removes all nodes in a lqueue
// Required
template <class T>
void Lqueue<T>::Clear(){
   while(GetSize() > 0){

      Pop();
   }
   m_head = nullptr;
   m_tail = nullptr;

}


// Name: At
// Precondition: Existing Lqueue
// Postcondition: Returns object from Lqueue at a specific location
// Desc: Iterates to node x and returns data from Lqueue
// Required
template <class T>
T Lqueue<T>::At(int x){
  int flag = 0;
  Node<T>* current = m_head; 
  while(flag != x){
    current = current->GetNext();
    flag++;
  }
  return current->GetData();
}




//**********All Functions Are Required Even If Not Used for Trivia**************


#endif
