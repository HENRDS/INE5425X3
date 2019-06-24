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

int main(int argc, char* argv[]) {
    unsigned int seed = 4202369;
    test(seed);
    return 0;
}

void test(unsigned int seed) {
    RNGTest test(seed);
    test.testLogNormal();
}
