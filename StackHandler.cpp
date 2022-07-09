/* Author: Elad Shoham */

#include "StackHandler.h"

string StackHandler::command(string c) {
    stringstream ss(c);
    string temp;
    ss >> temp;
    if(temp.compare("POP") == 0) {
        return stack.pop();
    }
    else if (temp.compare("TOP") == 0) {
        return "OUTPUT:" + stack.top();
    }
    else if (c.compare("CLEAR") == 0) {
        return stack.clear();
    }
    else if (temp.compare("PUSH") == 0) {
        string tempVal;
        getline(ss, tempVal);
        tempVal = tempVal.substr(1, tempVal.length());
        return stack.push(tempVal);
    }
    else {
        return "ERROR: unknown command: " + c;
    }
}