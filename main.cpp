//File: main.cpp
//by: Jonathan Carpenter
//Email: carpenter.102@wright.edu

#include "SStack.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

SStack create();
void push(SStack& stack);
void pop(SStack& stack);
void top(SStack& stack);
void save(SStack& stack);
void addStacks(SStack& stack);
void topNames(const SStack &stack);

int main()
{
  SStack stack(0);
  string input;
  int menuOption = 0;
  int menu = 1;
  while(menu == 1){
    cout << "####################" << endl;
    cout << "#       MENU       #" << endl;
    cout << "####################" << endl;
    cout << "1) Create a new stack" << endl;
    cout << "2) Quit" << endl;
    cout << "Select an option: ";
    getline(cin,input);
    menuOption = atoi(input.c_str());
    cout << endl;
 
    switch(menuOption){
    case 1:
      stack = create();
      menu++;
      break;
    case 2:
      cout << "Awwwww, quitting so soon?"<<endl;
      cout << "Hope to see you agian :)" << endl;
      return EXIT_SUCCESS;
      break;
    default:
      cout << "Please select a menu option" << endl;
    }
  }

  while(menu == 2){
    cout << "####################" << endl;
    cout << "#       MENU       #" << endl;
    cout << "####################" << endl;
    cout << "1) Create a new stack" << endl;
    cout << "2) Push a name onto the stack" << endl;
    cout << "3) Pop names from the stack" << endl;
    cout << "4) Top name in the stack" << endl;
    cout << "5) Save" << endl;
    cout << "6) Add Stacks" <<endl;
    cout << "7) Quit" << endl;
    cout << endl;
    cout << "Select an option: ";
    getline(cin, input);
    menuOption = atoi(input.c_str());
    cout << endl;
    switch(menuOption){
    case 1:
      stack = create();
      break;
    case 2:
      push(stack);
      break;
    case 3:
      pop(stack);
      break;
    case 4:
      top(stack);
      break;
    case 5:
      save(stack);
      break;
    case 6:
      addStacks(stack);
      break;
    case 7:
      cout << "Goodbye :)" << endl;
      return EXIT_SUCCESS;
    default:
      cout << "Please select an option" << endl;
    }
  }
}


// Create a stack of type string with specified capacity, read the 
// specified number of the last names from the file, all.last.txt, 
// and push these last names into the stack. 
// Print the number of the elements in the stack, the number of 
// elements pushed to the stack, and also the top 5 elements in the 
// stack to the screen if the number of elements in the stack is larger
// than 5.
SStack create(){
  ifstream ifs;
  string var,name;
  int capacity, numNames;
  
  //prompt the user for capacity and number of names
  //to be placed in stack
  do{    
    
    cout << "Enter the capacity of the stack: ";
    getline(cin,var);
    capacity = atoi(var.c_str());
    cout << endl;
    cout << "Enter the number of names you wish "
	 << "to be placed in the stack" << endl
	 << "Note: This number must be less than " 
	 << "the size of the stack\n" << endl;
    cout << "# of Names: ";
    getline(cin, var);
    numNames = atoi(var.c_str());
    cout << endl;

    if(capacity < numNames){
      cout << "OoOoOops: The number of names must be\n"
	   <<"less than the capacity of the stack"
	   << endl << endl;
    }
    
    
    if(capacity == 0 || numNames == 0){
      cout << "Please make sure the capacity and the" << endl;
      cout <<"number of names entered are greater than zero" << endl;
    }
  }
  while(capacity <= numNames);

  SStack stack(capacity);
  cout << "You have created a new stack" << endl;
  cout << "stack size: " << stack.size() << endl;
  cout << "stack capacity: " << stack.getCapacity() << endl;
  cout << endl;
  
  //open file and read names into stack
  ifs.open("all.last.txt");
  
  if(!ifs.fail()){
    for(int i=0;i < numNames;++i){
      getline(ifs,name);
      stack.push(name);
    }
    ifs.close();
  }
  else {
    cout << "Failed to open file all.last.txt" << endl;
    exit(EXIT_FAILURE);
  }

  cout << "You have pushed " << numNames << " names into the stack." 
       << endl;
  cout << "stack size: " << stack.size() << endl;
  cout << "stack capacity: " << stack.getCapacity() << endl;
  cout << endl;

  topNames(stack);

  return stack;

}

// prompt user for a last name, and push it onto the top of the stack, 
// then print the number of the elements in the stack, 
// and also the top 5 elements in the stack to the screen 
// if the number of elements in the stack is larger than 5. 
void push(SStack& stack){
  string lastName;
  cout << "Enter a last name: ";
  getline(cin,lastName);  
  stack.push(lastName);
  topNames(stack);
  cout << "stack size: " << stack.size() << endl;
  cout << endl;
}

//Pop: prompt user for a number, and if the number of the elements in 
//the stack is larger than the number entered by the user, pop the 
//specified number of the elements from the stack, and print the last 
//names popped from the stack, and the remaining number of the elements
//in the stack to the screen. Otherwise, pop all the elements from the
//stack, and print them and the remaining number of the elements in
// the stack to the screen.
void pop(SStack& stack){
  string number;
  int num;
  cout << "Enter the number of names to pop out"
       << " of the stack: ";
  getline(cin,number);
  num = atoi(number.c_str());
  if(num < stack.size()){
    cout << "Names popped off the stack: "<< endl;
    for(int i=0;i<num;++i)
      cout << stack.pop() << endl;
  }
  else
    while(!stack.IsEmpty())
      cout << stack.pop() << endl;
  cout << "size of stack: " << stack.size() << endl;
  cout << endl;
}

//Top: print the last name on the top of the stack and the 
//remaining number of the elements in the stack to the screen. 
void top(SStack& stack){
  cout << "Top of the stack: ";
  cout << stack.top() << endl;
  cout << "size of stack: " << stack.size() << endl;
  cout << endl;
}

//Save: save all the elements in the stack to a file on the disk.
//Note: save.txt is the file used for saving the stack
void save(SStack& stack){
  ofstream ofs;  

  ofs.open("save.txt");
  if(!ofs.fail()){
    while(!stack.IsEmpty())
      ofs << stack.pop() << endl;
    ofs.close();
    cout << "Successful Save to file 'save.txt' ;)" << endl;
    cout << endl;
  }
  else {
    cout << "Error: could not save stack to file save.txt" << endl;
  }
}

//Lets the user create another stack and 
//add this new stack to the old one.
void addStacks(SStack& stack){

  cout << "We are going to make a new stack" << endl;
  cout << "and then add it to our previous stack."<< endl;
  SStack stack2 = create();
  cout << "stack: " << endl;
  stack.printStackTrace();
  cout << "stack to add: " << endl;
  stack2.printStackTrace();
  stack = stack + stack2;
  cout << "Here is your new stack: " << endl;
  stack.printStackTrace();
  cout << endl;
}
  
//Print top five elements
void topNames(const SStack &stack){
  SStack temp(stack);
  cout << "Top names in the stack:" << endl;
  for(int i=0;i<5;++i){
    if(temp.IsEmpty())
      break;
    else
      cout << temp.pop() << endl;
  }
  cout << endl;
}
