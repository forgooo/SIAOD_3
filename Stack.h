#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename Type>
struct Stack{
    int size = -1;
    Type stack[20];

    bool is_empty() {
        return size == -1;
    }

    void push(Type ch) {
        size++;
        stack[size] = ch;
    }

    Type top() {
        return stack[size];
    }

    void pop() {
        size--;
    }
};