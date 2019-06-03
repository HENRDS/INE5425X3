#include <iostream>
#include "rng.hpp"



int main() {
    RNG rng(23);
    for (int i = 0; i <100; ++i) {
        std::cout << rng.random() << std::endl;
    }
    return 0;
}