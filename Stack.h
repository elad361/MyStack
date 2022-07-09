/* Author: Elad Shoham */

#include <iostream>
#include <string>
#include <cstring>
#include <mutex>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

class Stack {
    struct free_block {
        size_t size;
        struct free_block* next;
    };

    struct Var {
        char* s;
        struct Var* next;
    };
    static const size_t overhead = sizeof(size_t);
    static const size_t align_to = 16;
public:
    Stack(): size(0), last(NULL), free_block_list_head({0, 0}) {};
    
    ~Stack() {
        clear();
    };
    
    void* MyMalloc(size_t size);
    void MyFree(void* ptr);
    string push(string s);
    string pop();
    string top();
    string clear();
private:
    struct free_block free_block_list_head;
    struct Var* last;
    int size;
    mutex m;
};