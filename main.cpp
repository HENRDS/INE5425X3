#include <iostream>
#include "tests.hpp"
#include <random>

using namespace std;
void test(unsigned int seed);


int main(int argc, char* argv[]) {
    RNG rng(23);
    for (int i = 0; i < 10000000; ++i) {
        cout << rng.random() << "\n";
    }
    return 0;
}

void test(unsigned int seed) {
    RNGTest test(seed);
    test.testAll();
}

