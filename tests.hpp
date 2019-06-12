//
// Created by henry on 6/3/19.
//

#ifndef INE5425X3_TESTS_HPP
#define INE5425X3_TESTS_HPP
#include <random>
#include "rng.hpp"
#include <type_traits>
#include <string>

class RNGTest {
public:
    explicit RNGTest(unsigned int seed);
    void testUniform();
    void testExponential();
    void testErlang();
    void testNormal();
    void testGamma();
    void testBeta();
    void testWeibull();
    void testLogNormal();
    void testTriangular();
    void testDiscrete();
    void testAll();
private:

    RNG generator;
};


#endif //INE5425X3_TESTS_HPP
