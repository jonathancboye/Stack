//File: SStack.cpp
//by: Jonathan Carpenter
//Email: carpenter.102@wright.edu

#include "SStack.h"
#include<iostream>
using namespace std;

SStack::SStack(int cap){
  Capacity = cap;
  used = 0;
  DynamicStack = new string[Capacity];
}

SStack::SStack(const SStack& s){
  Capacity = s.Capacity;
  used = s.used;
  DynamicStack = new string[Capacity];

  for(int i=0;i < s.used;++i){
    DynamicStack[i] = s.DynamicStack[i];
  } 
}
  
SStack::~SStack(){
  delete[] DynamicStack;
}

void SStack::operator=(const SStack& stack){
  if(this != &stack){
    delete[] DynamicStack;
    Capacity = stack.Capacity;
    used = stack.used;
    DynamicStack = new string[Capacity];
 
    
    for(int i=0;i<stack.used;++i)
      DynamicStack[i] = stack.DynamicStack[i];
  }
  return;
}

void SStack::push(const string& s){
  if(Capacity == used) {
    cout << "ERROR: stack is full" << endl;
    return;
  }

  DynamicStack[used++] = s;
}

string& SStack::pop(){
  if(IsEmpty()){
    cout << "ERROR: stack is empty" << endl;
    return DynamicStack[used];
  }
  return DynamicStack[--used];
} 

string& SStack::top() const{
  if(IsEmpty()){
    cout << "ERROR: stack is empty" << endl;
    return DynamicStack[used];
  }
  return DynamicStack[used - 1];
}

//Wouldn't this be a member function?
SStack SStack::operator +(const SStack& s2){
  int cap = this -> size() + s2.size();
  
  if(cap <= this -> Capacity){
    SStack stack(*this);
    for(int i=0;i< s2.size();++i){
      stack.push(s2.DynamicStack[i]);
    }
    return stack; 
  }
  else{
    
    cout << "Resizing the stack" << endl;
    SStack rstack(cap * 2);
    
    for(int i=0;i < this -> size();++i){
      rstack.push(this -> DynamicStack[i]);
    }
    for(int i =0;i < s2.size();++i){
      rstack.push(s2.DynamicStack[i]);
    }
    return rstack;
  }
}

void SStack::printStackTrace(){
  if(IsEmpty()){return;}
  int s = size();
  cout << "[";
  for(int i=s-1;i>0;--i){
    if((i-s)%5 == 0){cout << endl;}
    cout << DynamicStack[i] << ", ";
  }
  cout << DynamicStack[0] << "]" << endl;
  cout << "size: " << used << endl;
  cout << endl;
}
