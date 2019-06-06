//
// Created by henry on 6/3/19.
//

#include "rng.hpp"
#include <cmath>
RNG::RNG(unsigned int seed): seed(seed) {
}
double RNG::random() {
    constexpr auto upperBound = static_cast<unsigned int>(-1);
    unsigned int number = this->seed;
    number ^= number << 13u;
    number ^= number >> 17u;
    number ^= number << 5u;
    this->seed = number;
    return double(number) / double(upperBound);
}
double RNG::sampleUniform(double min, double max) {
    // TODO: check max > min and do something about it
    double interval = max - min;
    return interval * this->random() + min;
}
double RNG::sampleExponential(double mean) {

    return -mean * log(this->random());
}
double RNG::sampleErlang(double mean, int M) {
    return 0;
}
double RNG::sampleNormal(double mean, double stddev) {
    return 0;
}
double RNG::sampleGamma(double mean, double alpha) {
    return 0;
}
double RNG::sampleBeta(double alpha, double beta, double infLimit, double supLimit) {
    return 0;
}
double RNG::sampleWeibull(double alpha, double scale) {
    return 0;
}
double RNG::sampleLogNormal(double mean, double stddev) {
    return 0;
}
double RNG::sampleTriangular(double min, double mode, double max) {
    return 0;
}
double RNG::sampleDiscrete(double value, double acumProb, double rest...) {
    return 0;
}
double RNG::sampleDiscrete(std::pair<double, double> items ...) {
    return 0;
}
