#include <iostream>
#include "tests.hpp"
#include <random>
#include <string>
#include <array>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
void test(unsigned int seed);

class XorShift {

};

int main(int argc, char* argv[]) {
    unsigned int seed = 4202369;
    int n = 1000000;
    RNG rng(seed);
    cout << std::setprecision(32);
    for (int i = 0; i < n; ++i) {
        cout << rng.random() << "\n";

    }
    return 0;
}

void test(unsigned int seed) {
    RNGTest test(seed);
    test.testAll();
}
