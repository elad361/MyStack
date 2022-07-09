/* Author: Elad Shoham */
#include "Stack.h"

void* Stack::MyMalloc(size_t size) {
    size = (size + sizeof(size_t) + (align_to - 1)) & ~ (align_to - 1);
    free_block* block = free_block_list_head.next;
    free_block** head = &(free_block_list_head.next);
    while (block != 0) {
        if (block->size >= size) {
            *head = block->next;
            return ((char*)block) + sizeof(size_t);
        }
        head = &(block->next);
        block = block->next;
    }

    block = (free_block*)sbrk(size);
    block->size = size;

    return ((char*)block) + sizeof(size_t);
}

void Stack::MyFree(void* ptr) {
    free_block* block = (free_block*)(((char*)ptr) - sizeof(size_t));
    block->next = free_block_list_head.next;
    free_block_list_head.next = block;
}

string Stack::push(string s) {
    struct Var* temp = (struct Var*)MyMalloc(sizeof(struct Var));
    if (!temp) {
        return "ERROR: Memory Allocation Failed";
    }
    temp->s = (char*)malloc(sizeof(char) * (s.length() + 1));
    if (!temp->s) {
        free(temp);
        return "ERROR: Memory Allocation Failed";
    }
    strcpy(temp->s, s.c_str());
    m.lock();
    temp->next = last;
    last = temp;
    size += 1;
    m.unlock();
    return "DEBUG: " + s + " added";
}

string Stack::top() {
    if (last == NULL) {
        return "ERROR: Stack is empty";
    }
    char* temp = last->s;
    string answer(temp);
    return answer;
}

string Stack::pop() {
    if (last == NULL) {
        return "ERROR: Stack is empty";
    }
    m.lock();
    string tempS(last->s);
    MyFree(last->s);
    struct Var* tempV = last;
    last = last->next;
    MyFree(tempV);
    m.unlock();
    return "DEBUG: " + tempS + " poped";
}

string Stack::clear() {
    m.lock();
    while (last != NULL) {
        struct Var* temp = last;
        MyFree(last->s);
        last = last->next;
        MyFree(temp);
        size -=1;
    }
    m.unlock();
    return "DEBUG: stack cleared";
}