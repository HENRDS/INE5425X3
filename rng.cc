//
// Created by henry, jacyara, mathias and rene on 6/3/19.
//

#include "rng.hpp"
#include <cmath>
#include <cstdarg>

RNG::RNG(unsigned int seed) : seed(seed) {
}

// @brief This method generates pseudorandom numbers using the xorshift method
double RNG::random() {
    constexpr auto upperBound = static_cast<double>(static_cast<unsigned int>(-1)) + 1.0;
    this->seed ^= this->seed << 13u;
    this->seed ^= this->seed >> 17u;
    this->seed ^= this->seed << 5u;
    return double(this->seed) / upperBound;
}
double RNG::sampleUniform(double min, double max) {
    double interval = max - min;
    return interval * this->random() + min;
}
double RNG::sampleExponential(double mean) {
    return -mean * log(this->random());
}
double RNG::sampleErlang(double mean, int M) {
    double acc = 1.0;
    for (int i = 0; i < M; ++i)
        acc *= this->random();
    return -mean * log(acc);
}
double RNG::sampleNormal(double mean, double stddev) {
    return mean + stddev * this->probit();
}
double RNG::sampleGamma(double mean, double alpha) {
    return this->marsaglia(alpha, mean / alpha);
}
double RNG::sampleBeta(double alpha, double beta, double infLimit, double supLimit) {
    double x = this->sampleGamma(1, alpha), y = this->sampleGamma(1, beta);
    double multiplier = supLimit - infLimit;
    return multiplier * (x / (x + y)) + infLimit;
}
double RNG::sampleWeibull(double alpha, double scale) {
    // https://www.taygeta.com/random/weibull.html
    return pow(-1.0 / alpha * log(1.0 - this->random()), 1.0 / scale);
}
double RNG::sampleLogNormal(double mean, double stddev) {
    return  exp(this->sampleNormal(mean, stddev));
}
double RNG::sampleTriangular(double min, double mode, double max) {
    double u = this->random(), f = (mode - min) / (max - min);
    if (u < f) return min + sqrt(u * (max - min) * (mode - min));
    return max - sqrt((1.0 - u) * (max - min) * (max - mode));
}
double RNG::probit() {
    // Acklam's Algorithm
    // https://stackedboxes.org/2017/05/01/acklams-normal-quantile-function/

    constexpr double A[6] = {
        -3.969683028665376e+01, 2.209460984245205e+02, -2.759285104469687e+02, 1.383577518672690e+02,
        -3.066479806614716e+01, 2.506628277459239e+00
    };
    constexpr double B[5] = {
        -5.447609879822406e+01, 1.615858368580409e+02, -1.556989798598866e+02, 6.680131188771972e+01,
        -1.328068155288572e+01
    };
    constexpr double C[6] = {
        -7.784894002430293e-03, -3.223964580411365e-01, -2.400758277161838e+00, -2.549732539343734e+00,
        4.374664141464968e+00, 2.938163982698783e+00
    };
    constexpr double D[4] = {
        7.784695709041462e-03, 3.224671290700398e-01, 2.445134137142996e+00, 3.754408661907416e+00
    };

    constexpr double pLow = 0.0245;
    constexpr double pHigh = 1.0 - pLow;
    double p = this->random();
    if (p < pLow) {
        double q = sqrt(-2.0 * log(p));
        return (((((C[0] * q + C[1]) * q + C[2]) * q + C[3]) * q + C[4]) * q + C[5]) /
               ((((D[0] * q + D[1]) * q + D[2]) * q + D[3]) * q + 1);
    }

    if (p > pHigh) {
        double q = sqrt(-2.0 * log(1.0 - p));
        return -(((((C[0] * q + C[1]) * q + C[2]) * q + C[3]) * q + C[4]) * q + C[5]) /
               ((((D[0] * q + D[1]) * q + D[2]) * q + D[3]) * q + 1);
    }

    double q = p - 0.5f;
    double r = q * q;
    return ((((((A[0] * r + A[1]) * r + A[2]) * r + A[3]) * r + A[4]) * r + A[5]) * q) /
           (((((B[0] * r + B[1]) * r + B[2]) * r + B[3]) * r + B[4]) * r + 1);

}
double RNG::sampleDiscrete(double value, double accProb, ...) {
    double val = value, acc = accProb, u = this->random();
    va_list args;
    va_start(args, accProb);
    while (acc < 1.0 && u < acc) {
        val = va_arg(args, double);
        acc += va_arg(args, double);
    }
    va_end(args);
    return val;
}

double RNG::marsaglia(double alpha, double beta) {
    // Marsaglia's squeeze method
    // https://dl.acm.org/citation.cfm?doid=358407.358414
    if (alpha < 1.0) {
        // "boost" alpha
        return pow(marsaglia(1.0 + alpha, beta), 1.0 / alpha);
    }
    double d = alpha - 1.0 / 3.0, c = 1.0 / sqrt(9.0 * d);
    double x, v;
    for (;;) {
        do {
            x = this->probit();
            v = pow(1 + c * x, 3);
        } while (v <= 0.0);
        double u = this->random();
        if (u < 1.0 - 0.331 * pow(x, 4)) return d * v * beta;
        if (log(u) < 0.5 * x * x + d * (1 - v + log(v))) return d * v * beta;
    }
}

void RNG::setSeed(unsigned int newSeed) {
    this->seed = newSeed;
}
unsigned int RNG::getSeed() const {
    return this->seed;
}

