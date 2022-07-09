/* Author: Elad Shoham */

#include <string>
#include <iostream>
#include <sstream>
#include "Stack.h"

using namespace std;

class StackHandler {
public:
    StackHandler(): stack() {}
    ~StackHandler() {stack.clear();}
    string command(string c);
private:
    Stack stack;
};
