//File: SStack.h
//Provided by Teacher, but made some modifications
//Email:carpenter.102@wright.edu

#ifndef _StackClass_
#define  _StackClass_

#include <cstdlib>
#include <string>

class SStack
{
 public:
  // Constructor
  SStack( int cap);

  // Copy Constructor
  SStack( const SStack& s );

  ~SStack(); //destructor */
  
  //Assignment operator
  void operator=(const SStack& stack);

  // The member function push: Precondition:  the stack is not full.
  void push ( const std::string&  s);
  
  // The member function pop: Precondition:  the stack is not empty.
  std::string& pop ();
  
  // The member function top: Precondition:  the stack is not empty.
  std::string&  top () const;

  //Returns true if stack is empty else false
  bool IsEmpty() const {return (used == 0) ? true : false;}
  
  //Returns the size of the stack
  int size() const {return used;}
  
  //Returns the stack's maximum capacity
  int getCapacity() const {return Capacity;}
  
  // NONMEMBER FUNCTIONS for the stack class
  // Precondition:  s1.size( ) + s2.size( ) <= s1.Capacity.
  // Postcondition: The stack returned is the union of s1 and s2.
  SStack operator +(const SStack& s2);

  //Prints out the entire stack
  void printStackTrace();

 private:
  int Capacity; // Capacity is the maximum number of items that a stack can hold
  std::string* DynamicStack; 
  int used; // How many items are stored in the stack
};

#endif //_StackClass_
