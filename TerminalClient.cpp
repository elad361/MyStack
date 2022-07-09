/* Author: Elad Shoham */

#include <cstring>
#include <iostream>
#include "StackHandler.h"

using namespace std;

int main() {
    StackHandler handler;
    bool isRunning = true;
    cout << "Hello" << endl;
    while (isRunning) {
        string input;
        cout << "$ ";
        getline(cin, input);
        cout << handler.command(input) << endl;
    }
}