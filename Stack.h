#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename Type>
struct Stack{
    int size = -1;
    Type stack[100];
    Type top() {
        return stack[size];
    }
    bool is_empty(){
        return size == -1;
    }
    void push(Type ch) {
        size++;
        stack[size] = ch;
    }
    void pop() {
        size--;
    }
};