//
// Created by henry on 6/12/19.
//

#include "tests.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

RNGTest::RNGTest(unsigned int seed) : generator(seed) {

}

void RNGTest::testUniform() {
    // otherwise the compiler won't know the size of the array until runtime.
    constexpr int num_testes = 4;
    // the parameters for sampleUniform are double
    double min[num_testes] = {1, -100, 1e-42, 1e-22},
           max[num_testes] = {2, 502, 1e13, 2e-22};
    // creates the generator only once
    RNG rng(4202369);

    for (int j = 0; j < num_testes; j++) {
        cout << "teste " << j << endl;
        // don't use a fixed-size array, segfault might happen with sprintf.
        // If you really need it to have fixed side, prefer snprintf.
        ostringstream stream;
        stream << "Uniform_"<< j << ".txt";
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

        for (int i = 0; i < 1000000; ++i) {
            f << rng.sampleUniform(min[j], max[j]) << endl;
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



