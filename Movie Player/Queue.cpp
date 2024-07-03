/*****************************************
** File:    Queue.cpp
** Project: CMSC 202 Project 5, Spring 2024
** Author:  Josh Ventura
** Date:    5/02/24
** Section: 30/31
** E-mail:  j246@umbc.edu
**
**  This is the .cpp file with both the function definitons annd implementationns for
** the templated queue class
***********************************************/



#ifndef QUEUE_CPP
#define QUEUE_CPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Templated linked list
//Note: Because the linked list is a templated class,
//      there is only ONE file (Queue.cpp)

//Templated node class
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
class Queue {
 public:
  // Name: Queue() Queue from a linked list - Default Constructor
  // Desc: Used to build a new linked queue (as a linked list)
  // Preconditions: None
  // Postconditions: Creates a new queue where m_head and m_tail
  //                 point to nullptr and m_size = 0
  Queue();
  // Name: ~Queue() - Destructor
  // Desc: Used to destruct a Queue
  // Preconditions: There is a Queue
  // Postconditions: Queue is deallocated (including dynamically allocated nodes)
  //                 Can just call Clear()
 ~Queue();
  // Name: Queue (Copy Constructor)
  // Preconditions: Creates a copy of existing Queue in separate memory
  //                address (deep copy)
  //                Requires one already existing Queue
  // Postconditions: Copy of existing Queue
  Queue(const Queue&);
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: When two Queue objects exist, sets one to equal another
  //                Requires two Queue objects
  // Postconditions: When completed, you have two Queues in
  //                 separate memory addresses with the same
  //                 number of nodes with the same values in each node
  Queue<T>& operator= (Queue&);
  // Name: PushBack
  // Preconditions: Takes in data. Creates new node. 
  //                Requires a Queue
  // Postconditions: Adds a new node to the end of the Queue.
  void PushBack(const T&);
  // Name: PopFront
  // Preconditions: Queue with at least one node. 
  // Postconditions: Removes first node in the queue and
  //                 returns the data in the first node
  T PopFront();
  // Name: Display
  // Preconditions: Outputs the queue.
  // Postconditions: Displays the data in each node of queue
  // Required (used only for queue testing)
  void Display();
  // Name: Front
  // Preconditions: Requires a Queue with at least one node
  // Postconditions: Returns whatever data is pointed at by m_head -
  //                 Does NOT remove node
  T Front();
  // Name: IsEmpty
  // Preconditions: Requires a queue
  // Postconditions: Returns if the queue is empty.
  bool IsEmpty();
  // Name: GetSize
  // Preconditions: Requires a queue
  // Postconditions: Returns m_size
  int GetSize();
  // Name: Find()
  // Preconditions: Requires a queue
  // Postconditions: Iterates and if it finds the thing, returns index, else -1
  int Find(T);
  // Name: Clear
  // Preconditions: Requires a queue
  // Postconditions: Deallocates and removes all nodes in a queue. No memory leaks
  void Clear();
  // Name: At
  // Precondition: Existing Queue
  // Postcondition: Returns object from Queue at a specific location
  // Desc: Iterates to node x and returns data from Queue
  T& At (int x);
  // Name: Swap(int)
  // Preconditions: Requires a queue
  // Postconditions: Swaps the nodes at the index with the node prior to it.
  // Example: Swap(1) would swap the node 0 with node 1 so
  //          that node 1 would now be m_head
  // Desc: Swaps two nodes by updating the pointers (not just the value)
  // Hint: Think about the special cases! Implement before Sort
  void Swap(int);
  // Name: Sort()
  // Preconditions: Requires a queue with a minimum of 2 nodes
  //                (otherwise notifies user)
  // Postconditions: Sorts the Queue (may use overloaded < or >).
  // Desc: This is used to sort anything in the Queue assuming the
  //       < or > is overloaded
  //        Uses bubble sort and Swap function above.
  //        Ensure working with queue_test before rest of project.
  // Note: Allowed to use the break command in just this function if necessary
  void Sort();
private:
  Node <T> *m_head; //Node pointer for the head
  Node <T> *m_tail; //Node pointer for the tail
  int m_size; //Number of nodes in queue
};

//**********Implement Queue Class Here***********
//**********All Functions Are Required Even If Not Used for Project**************
//**********No references to anything from Movie here*****************


  // Name: Queue() Queue from a linked list - Default Constructor
  // Desc: Used to build a new linked queue (as a linked list)
  // Preconditions: None
  // Postconditions: Creates a new queue where m_head and m_tail
  //                 point to nullptr and m_size = 0
  template <class T>
  Queue<T>::Queue(){
      m_head = nullptr; 
      m_tail = nullptr; 
      m_size = 0; 
  }



  // Name: ~Queue() - Destructor
  // Desc: Used to destruct a Queue
  // Preconditions: There is a Queue
  // Postconditions: Queue is deallocated (including dynamically allocated nodes)
  //                 Can just call Clear()
 template <class T>
  Queue<T>::~Queue(){
   Clear();
  }


  // Name: Queue (Copy Constructor)
  // Preconditions: Creates a copy of existing Queue in separate memory
  //                address (deep copy)
  //                Requires one already existing Queue
  // Postconditions: Copy of existing Queue
  template <class T>
  Queue<T>::Queue(const Queue& original){
   m_head = nullptr;
   m_tail = nullptr;
   m_size = 0;
   Node<T> *originalcurrent = original.m_head; 
   while(original.m_size > m_size){
      PushBack(originalcurrent->GetData());
      originalcurrent = originalcurrent->GetNext();
   }
  }



  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: When two Queue objects exist, sets one to equal another
  //                Requires two Queue objects
  // Postconditions: When completed, you have two Queues in
  //                 separate memory addresses with the same
  //                 number of nodes with the same values in each node
  template <class T> 
  Queue<T>& Queue<T>::operator= (Queue& copyLqueue){ 

   if (this != &copyLqueue){
   Clear();
   Node<T> *originalcurrent = copyLqueue.m_head; 
   while(copyLqueue.m_size > m_size){
      PushBack(originalcurrent->GetData());
      originalcurrent = originalcurrent->GetNext();
    }
  }
  return *this;
  
  }


  
  // Name: PushBack
  // Preconditions: Takes in data. Creates new node. 
  //                Requires a Queue
  // Postconditions: Adds a new node to the end of the Queue.
  template <class T>
  void Queue<T>::PushBack(const T& addData){

   Node<T>* addNode = new Node<T>(addData);
   if (m_tail != nullptr){
      m_tail -> SetNext(addNode);
      m_tail = addNode;
   } else{
      m_head = addNode;
      m_tail = addNode;
   }
      m_size++; 

  } 



  // Name: PopFront
  // Preconditions: Queue with at least one node. 
  // Postconditions: Removes first node in the queue and
  //                 returns the data in the first node
  template <class T> 
  T Queue<T>::PopFront(){

    Node<T>* current = m_head;
  T nodeData= m_head->GetData();
  m_head = m_head->GetNext();
  delete current;
  m_size--;
  return nodeData;

  }


  // Name: Display
  // Preconditions: Outputs the queue.
  // Postconditions: Displays the data in each node of queue
  // Required (used only for queue testing)
  template <class T> 
  void Queue<T>::Display(){

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
  // Preconditions: Requires a Queue with at least one node
  // Postconditions: Returns whatever data is pointed at by m_head -
  //                 Does NOT remove node
template <class T> 
T Queue<T>::Front(){

     if(IsEmpty() == false){
      return m_head->GetData(); // returns data from first node
   }else{
      return NULL;
      cout << "ERROR: List empty" << endl;
   }

  }



  // Name: IsEmpty
  // Preconditions: Requires a queue
  // Postconditions: Returns if the queue is empty.
  template <class T> 
  bool Queue<T>::IsEmpty(){

     if (m_size <=0){
      return true;
   } else{
      return false;
   }

  }


  // Name: GetSize
  // Preconditions: Requires a queue
  // Postconditions: Returns m_size
  template <class T> 
  int Queue<T>::GetSize(){
    return m_size;
  }



  // Name: Find()
  // Preconditions: Requires a queue
  // Postconditions: Iterates and if it finds the thing, returns index, else -1
  template <class T> 
  int Queue<T>::Find(T data){

    if(IsEmpty() == false){
      int index = 0;
   Node<T> *current = m_head;

      while(current->GetNext() != nullptr){ 

         if (current->GetData() == data){
            return index;
         }
         current = current->GetNext();
         index++;
      }
   }
   return -1;

  }




  // Name: Clear
  // Preconditions: Requires a queue
  // Postconditions: Deallocates and removes all nodes in a queue. No memory leaks
  template <class T> 
  void Queue<T>::Clear(){

    while(GetSize() > 0){

      PopFront();
   }
   m_head = nullptr;
   m_tail = nullptr;

  }


  // Name: At
  // Precondition: Existing Queue
  // Postcondition: Returns object from Queue at a specific location
  // Desc: Iterates to node x and returns data from Queue
  template <class T> 
  T& Queue<T>::At(int x){

    int flag = 0;
  Node<T>* current = m_head; 
  while(flag != x){
    current = current->GetNext();
    flag++;
  }
  return current->GetData();

  }



  // Name: Swap(int)
  // Preconditions: Requires a queue
  // Postconditions: Swaps the nodes at the index with the node prior to it.
  // Example: Swap(1) would swap the node 0 with node 1 so
  //          that node 1 would now be m_head
  // Desc: Swaps two nodes by updating the pointers (not just the value)
  // Hint: Think about the special cases! Implement before Sort
  template <class T> 
  void Queue<T>::Swap(int index){

  int flag = 0;
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

   while (flag != index){
	prev = current;
	current = next;
	next = next->GetNext();
	flag++;
      }

      prev->SetNext(next);
      current->SetNext(next->GetNext());
      next->SetNext(current);
      
    if (index == m_size){
	   m_tail = current;
    }
  }
  }
  
  // Name: Sort()
  // Preconditions: Requires a queue with a minimum of 2 nodes
  //                (otherwise notifies user)
  // Postconditions: Sorts the Queue (may use overloaded < or >).
  // Desc: This is used to sort anything in the Queue assuming the
  //       < or > is overloaded
  //        Uses bubble sort and Swap function above.
  //        Ensure working with queue_test before rest of project.
  // Note: Allowed to use the break command in just this function if necessary
  template <class T> 
 void Queue<T>::Sort(){
 }



#endif
