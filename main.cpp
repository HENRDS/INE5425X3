#include <iostream>
#include "tests.hpp"


using namespace std;
void test(unsigned  int seed);


int main(int argc, char* argv[]) {
    RNG rng(23);
    for (int i = 0; i < 100000; ++i) {
        cout << rng.sampleGamma(23, 23) << endl;
    }
    return 0;
}

void test(unsigned  int seed) {
    RNGTest test(seed);
    test.testAll();
}