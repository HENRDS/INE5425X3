//
// Created by henry on 6/3/19.
//

#ifndef INE5425X3_RNG_HPP
#define INE5425X3_RNG_HPP

#include <utility>

class RNG {

public:
    explicit RNG(unsigned int seed);
    double random();
    double sampleUniform(double min, double max);
    double sampleExponential(double mean);
    double sampleErlang(double mean, int M);
    double sampleNormal(double mean, double stddev);
    double sampleGamma(double mean, double alpha);
    double sampleBeta(double alpha, double beta, double infLimit, double supLimit);
    double sampleWeibull(double alpha, double scale);
    double sampleLogNormal(double mean, double stddev);
    double sampleTriangular(double min, double mode, double max);
    double sampleDiscrete(double value, double accProb, ...);
private:
    unsigned int seed;
    double probit();
};

#endif //INE5425X3_RNG_HPP
