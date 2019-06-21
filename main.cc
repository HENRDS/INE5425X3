#include <iostream>
#include "tests.hpp"
#include <random>
#include <string>
#include <array>
#include <cstring>
#include <fstream>
using namespace std;
void test(unsigned int seed);



int main(int argc, char* argv[]) {
    RNG rng(23);
    for (int i = 0; i < 1000000; ++i) {
        cout << rng.sampleGamma(10, 3.1415) << "\n";
    }
    return 0;
}

void test(unsigned int seed) {
    RNGTest test(seed);
    test.testAll();
}
