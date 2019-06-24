//
// Created by henry, jacyara, mathias and rene on 6/12/19.
//

#ifndef INE5425X3_TESTS_HPP
#define INE5425X3_TESTS_HPP
#include <random>
#include "rng.hpp"
#include <vector>
#include <type_traits>
#include <string>

class RNGTest {
public:
    explicit RNGTest(unsigned int seed, unsigned int digits = 4, double error = 1e-3);
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
    bool almost_equal(double x, double y);
    // Number of digits of decimal output
    unsigned int digits;
    RNG generator;
    double error;

};


#endif //INE5425X3_TESTS_HPP
