#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

struct Calc {
    Calc(string _input) : input(_input){}
    string input;
    double result;

    double calc_prefix() {
        Stack<double> Stack;
        for (int j = input.size() - 1; j >= 0; j--) {
            if (isdigit(input[j]))
                Stack.push(input[j] - '0');
            else {
                double o1 = Stack.top();
                Stack.pop();
                double o2 = Stack.top();
                Stack.pop();
                switch (input[j]) {
                    case '+':
                        Stack.push(o1 + o2);
                        break;
                    case '-':
                        Stack.push(o1 - o2);
                        break;
                    case '*':
                        Stack.push(o1 * o2);
                        break;
                    case '/':
                        Stack.push(o1 / o2);
                        break;
                }
            }
        }
        result = Stack.top();
        return result;
    }
};