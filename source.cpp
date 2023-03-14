#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

int check_priority(char op){
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '-' || op == '+') return 1;
    return 0;
}

double calc_prefix(string exprsn){
    Stack<double> Stack;
    for (int j = exprsn.size() - 1; j >= 0; j--) {
        if (isdigit(exprsn[j]))
            Stack.push(exprsn[j] - '0');
        else {
            double o1 = Stack.top();
            Stack.pop();
            double o2 = Stack.top();
            Stack.pop();
            switch (exprsn[j]) {
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
    return Stack.top();
}


string infix_to_prefix(string inp, string result) {
    Stack<char> st;
    for (int i = inp.size() - 1; i >= 0; i--) {
        if (inp[i] != '+' and inp[i] != '-' and inp[i] != '*' and inp[i] != '/' and inp[i] != '^' and inp[i]!= '(' and inp[i] != ')') {
            result.insert(result.begin(), inp[i]);
        }
        else if (inp[i] == ')') {
            st.push(inp[i]);
        }
        else if (inp[i] == '(') {
            while (st.top() != ')') {
                result.insert(result.begin(), st.top());
                st.pop();
            }
            st.pop();
        }
        else {
            while (not(st.is_empty()) and check_priority(st.top()) > check_priority(inp[i])) {
                result.insert(result.begin(), st.top());
                st.pop();
            }
            st.push(inp[i]);
        }
    }
    while (not(st.is_empty())) {
        result.insert(result.begin(), st.top());
        st.pop();
    }
    return result;
}


int main() {
    string inp = "((1+5)*3+1)*4";
    string result = "";
    double res;
    cout << inp << "\nCONVERTED TO\n";
    inp = infix_to_prefix(inp, result);
    cout << inp << endl;
    res = calc_prefix(inp);
    cout << res;
}