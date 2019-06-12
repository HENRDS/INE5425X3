//
// Created by henry on 6/12/19.
//

#include "tests.hpp"
#include <iostream>

using namespace std;

RNGTest::RNGTest(unsigned int seed): generator(seed) {

}
void RNGTest::testUniform() {

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



