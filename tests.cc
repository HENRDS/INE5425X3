//
// Created by henry on 6/12/19.
//

#include "tests.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdarg>
using namespace std;

RNGTest::RNGTest(unsigned int seed) : generator(seed) {

}

double mean(int n, double val, ...) {
    va_list args;
    va_start(args, val);
    double avg = val;
    int t = 1;
    while (t <= n) {
        avg += (va_arg(args, double) - avg) / t;
        t++;
    }
    return avg;
}

void RNGTest::testUniform() {
    // otherwise the compiler won't know the size of the array until runtime.
    constexpr int num_testes = 4;
    // the parameters for sampleUniform are double
    double min[num_testes] = {1, -100, 1e-42, 1e-22}, max[num_testes] = {2, 502, 1e13, 2e-22};
    for (int j = 0; j < num_testes; j++) {
        cout << "teste " << j << endl;
        // don't use a fixed-size array, segfault might happen with sprintf.
        // If you really need it to have fixed side, prefer snprintf.
        ostringstream stream;
        stream << "./data/Uniform_" << j << ".txt";
        string filename = stream.str();
        // ofstream closes the file when the variable goes out of scope, so we don't have to do it.
        // If we had to, it's good to surround everything with a try-finally and
        // put fclose inside the finally section, so you guarantee that it will be called.
        ofstream f(filename);
        if (!f.is_open()) {
            cout << "Error opening file!" << endl;
            // don't stop the whole program if this test fails
            return;
        }
        double gen_min,
        for (int i = 0; i < 1000000; ++i) {
            f << this->generator.sampleUniform(min[j], max[j]) << "\n";
        }
    }
}

void RNGTest::testExponential() {

}
void RNGTest::testErlang() {

}
void RNGTest::testNormal() {

}
void RNGTest::testGamma() {

}
void RNGTest::testBeta() {

}
void RNGTest::testWeibull() {

}
void RNGTest::testLogNormal() {

}
void RNGTest::testTriangular() {

}
void RNGTest::testDiscrete() {
    /* A little bit of pre-processor sorcery */
#define CALL(idx, value, accProb, ...)\
    x = this->generator.sampleDiscrete(value, accProb, __VA_ARGS__);\
    streams[idx] << x
// Remember to update testCount if you change the macro table!
// F is for the macro CALL
#define TEST_CASES(F) \
        F(0, 1,   0.2,  2,   0.2004, 3,   .5, 4,  .69, 5, 1); \
        F(1, 1e4, 1e-3, 1e3, 1e-2,   100, .1, 10, 1); \
        F(2, 1, 0.16667, 2, 0.33334, 3, 0.5, 4, 0.66667, 5, 0.83334, 6, 1)

        constexpr int testCount = 4;
        std::vector<ofstream> streams;
        for (int i = 0; i < testCount; ++i) {
            streams.emplace_back(ofstream("DISC_" + to_string(i)));
        }
        double x;
        for (int i = 0; i < 1000000; ++i) {
            TEST_CASES(CALL);
        }
#undef TEST_CASES
#undef CALL
}
void RNGTest::testAll() {
    cout << "Testing all functions" << endl;
    this->testBeta();
    this->testDiscrete();
    this->testErlang();
    this->testExponential();
    this->testGamma();
    this->testLogNormal();
    this->testNormal();
    this->testTriangular();
    this->testUniform();
    this->testWeibull();
}



