#include <iostream>
#include "Calc_prefix.h"

int main(){
    std::string prefix = "";
    while(prefix != "0"){
        std::cout << "Input prefix expression:";
        std::cin >> prefix;
        Calc input(prefix);
        std::cout << "Answer: " << input.calc_prefix() << std::endl;
    }
    return 0;
}