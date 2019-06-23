//
// Created by henry, jacyara, mathias and rene on 6/3/19.
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
    /// @brief Generates a random uniform variate
    /// @returns Variate following the uniform distributuion (0, 1] 
    double random();
    /// @brief Generates a random uniform variate
    /// @param min The minimum value of the variate
    /// @param max The maximum value of the variate 
    /// @returns variate following the uniform distributuion (min, max)
    double sampleUniform(double min, double max);
    /// @brief Generates a random exponential variate
    /// @param mean The average value of the variate
    /// @returns variate following the exponential distribution (mean)
    double sampleExponential(double mean);
    /// @brief Generates a random erlang variate
    /// @param mean The scale parameter that represents the average value
    /// @param M The shape parameter that represents independent exponential variables
    /// @returns variate following the erland distribution (mean, M)
    double sampleErlang(double mean, int M);
    /// @brief Generates a random normal variate
    /// @param mean The average value of the variate
    /// @param stddev The standard deviation of the variate
    /// @returns variate following the normal distribution (mean, stdddev)   
    double sampleNormal(double mean, double stddev);
    /// @brief Generates a random gamma variate
    /// @param mean The average value of the variate
    /// @param alpha The shape parameter alpha of the variate
    /// @returns variate following the gamma distribution (mean, alpha)   
    double sampleGamma(double mean, double alpha);
    /// @brief Generates a random beta variate
    /// @param alpha The shape parameter alpha of the variate
    /// @param beta The shape parameter beta of the variate
    /// @param infLimit The value of the lower limit of the range
    /// @param supLimit The value of the upper limit of the range
    /// @returns variate following the beta distribution (alpha, beta, infLimit, supLimit)  
    double sampleBeta(double alpha, double beta, double infLimit, double supLimit);
    /// @brief Generates a random weibull variate
    /// @param alpha The shape parameter alpha of the variate
    /// @param scale The scale parameter of the variate
    /// @returns variate following the weibull distribution (alpha, scale)   
    double sampleWeibull(double alpha, double scale);
    /// @brief Generates a random lognormal variate
    /// @param mean The average value of the variate
    /// @param stddev The standard deviation of the variate
    /// @returns variate following the lognormal distribution (mean, stdddev)  
    double sampleLogNormal(double mean, double stddev);
    /// @brief Generates a random triangular variate
    /// @param min The value of the lower limit
    /// @param max The value of the upper limit
    /// @param mode The mode parameter where min < max and min ≤ mode ≤ max
    /// @returns variate following the triangular distribution (min, mode, max)  
    double sampleTriangular(double min, double mode, double max);
    /// @brief Generates a random discrete variate
    /// @param value The observed value of the class
    /// @param accProb The value of the accumulated probability
    /// @returns variate following the discrete distribution (value, accProb, ...) 
    double sampleDiscrete(double value, double accProb, ...);
    
private:
    unsigned int seed;
    /// @brief Generates a gamma distribution. Called by sampleGamma.
    double marsaglia(double alpha, double beta);
    /// @brief Generates a normal distribution centered on zero. Called by sampleNormal and marsaglia.
    double probit();
};

#endif //INE5425X3_RNG_HPP
