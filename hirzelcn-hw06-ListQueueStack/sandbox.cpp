#include <iostream>
#include "MyStack.h"
#include "MyQueue.h"
#include "LList.h"
#include <string>

using namespace std;

int main(){

  MyStack<string> a;
  a.push("5");
  cout << a.peek();
  a.pop();
  cout << a.peek();
  // Use this file for testing your implementation.

}
