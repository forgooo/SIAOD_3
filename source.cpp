#include <iostream>
#include "Calc_prefix.h"

int main(){
    std::string prefix = "";
    while(prefix != "0"){
        std::cout << "Input prefix expression:";
        std::cin >> prefix;
        std::cout << "Answer: " << calc_prefix(prefix) << std::endl;
    }
    return 0;
}