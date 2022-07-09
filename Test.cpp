#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "StackHandler.h"

using namespace std;

int main(){
    StackHandler handler;
    handler.command("PUSH hey");
    assert(handler.command("TOP") == "hey");
    handler.command("PUSH hello");
    handler.command("POP");
    assert(handler.command("TOP") == "hey");
    handler.command("POP");
    assert(handler.command("TOP") == "STACK IS EMPTY");
    handler.command("POP");
    assert(handler.command("TOP") == "STACK IS EMPTY");
    char c = 97;
    for (size_t i = 0; i < 20; i++)
    {
        string check;
        check.push_back(c);
        handler.command("PUSH check");
        c++;
    }
    assert(handler.command("TOP") == "t");

    cout << "Test has been done successfully" << endl;
}