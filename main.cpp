#include <iostream>
#include "rng.hpp"
#include <random>







int main() {


    RNG rng(23);
    std::cout << sizeof(unsigned int) << std::endl;
    for (int i = 0; i < 1000; ++i) {
        std::cout << rng.sampleExponential(23.23) << std::endl;
    }
    return 0;
}