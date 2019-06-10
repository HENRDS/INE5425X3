#include <iostream>
#include "rng.hpp"
#include <random>







int main() {
    RNG rng(23);
    for (int i = 0; i < 100000; ++i) {
        std::cout << rng.sampleGamma(23, 23) << std::endl;
    }
    return 0;
}