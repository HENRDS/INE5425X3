//
// Created by henry on 6/3/19.
//

#ifndef INE5425X3_RNG_HPP
#define INE5425X3_RNG_HPP

#include <utility>

class RNG {

public:
    explicit RNG(unsigned int seed);
    /// @brief Sets the seed for the random generator
    /// @param newSeed The new value of the seed
    void setSeed(unsigned int newSeed);
    /// @brief Generates a random uniforme variate
    /// @returns Variate following the uniform distributuion (0, 1] 
    double random();
    /// @brief Generates a random uniforme variate
    /// @param min The minimum value of the variate
    /// @param max The maximum value of the variate 
    /// @returns variate following the uniform distributuion (min, max)
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
    double marsaglia(double alpha, double beta);
    double probit();
};

#endif //INE5425X3_RNG_HPP
