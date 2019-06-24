//
// Created by henry, jacyara, mathias and rene on 6/12/19.
//

#include "tests.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdarg>
#include <iomanip>
#include <limits>

using namespace std;

struct IterativeMean {
    IterativeMean(): _mean(0.0), _count(0) {}
    void add_value(double value) {
        this->_count++;
        this->_mean += (value - this->_mean) / this->_count;
    }
    double mean() const { return this->_mean; }
    unsigned int count() const { return this->_count; }
    inline IterativeMean& operator<<(double value) {
        this->add_value(value);
        return *this;
    }
private:
    double _mean;
    unsigned int _count;
};

RNGTest::RNGTest(unsigned int seed, unsigned int digits, double error) : generator(seed), digits(digits), error(error) {
}

void RNGTest::testUniform() {
    cout << "Uniform" << endl;
    constexpr int num_testes = 4;
    double min[num_testes] = {1, -100, 1e3, 1e-22}, max[num_testes] = {2, 502, 1e13, 2e-22};
    for (int j = 0; j < num_testes; j++) {
        cout << "Test " << j << " min: " << min[j] << " max: " << max[j];
        ostringstream stream;
        stream << "../Testes/Uniform_" << j << ".txt";
        string filename = stream.str();
        ofstream f(filename);
        f << setprecision(this->digits);
        if (!f.is_open()) {
            cout << " FAILED! - Error opening file." << endl;
            return;
        }

        double gen_min = numeric_limits<double>::infinity(), gen_max = - gen_min, x = 0;
        for (int i = 0; i < 1000000; ++i) {
            x = this->generator.sampleUniform(min[j], max[j]);
            gen_min = std::min(x, gen_min);
            gen_max = std::max(x, gen_max);
            f << x << "\n";
        }

        if (gen_min >= min[j] && gen_max <= max[j])
            cout << " PASSED!" << endl;
        else
            cout << " FAILED! - min: " << gen_min << " max: " << gen_max << endl;
    }
}

void RNGTest::testExponential() {
    cout << "Exponential" << endl;
    constexpr int num_testes = 4;
    double mean[num_testes] = {7e-31, 4e27, 1024, -33};

    for (int j = 0; j < num_testes; j++) {
        cout << "Test " << j << " mean: " << mean[j] << endl;

        ostringstream stream;
        stream << "../Testes/Exponential_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
        f << setprecision(this->digits);
        if (!f.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }
        IterativeMean it;
        double x = 0;
        for (int i = 0; i < 1000000; ++i) {
            x = this->generator.sampleExponential(mean[j]);
            it.add_value(x);
            f << x << "\n";
        }
        if (this->almost_equal(it.mean(), mean[j]))
            cout << " PASSED!" << endl;
        else
            cout << " FAILED! - mean: " << it.mean() << endl;
    }

}
void RNGTest::testErlang() {
    constexpr int num_testes = 4;
    double mean[num_testes] = {7e-2, 1.698, 89, -8e12};
    int M[num_testes] = {1, 6, 7, 165};
    cout << "Erlang" << endl;


    for (int j = 0; j < num_testes; j++) {
        cout << "Test " << j << " mean: " << mean[j] << " M: " << M[j] << endl;

        ostringstream stream;
        stream << "../Testes/Erlang_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
        f << setprecision(this->digits);
        if (!f.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }
        IterativeMean it;
        double x = 0;
        for (int i = 0; i < 1000000; ++i) {
            x = this->generator.sampleErlang(mean[j], M[j]);
            it << x;
            f << x << "\n";
        }
        if (this->almost_equal(it.mean(), mean[j]))
            cout << " PASSED!" << endl;
        else
            cout << " FAILED! - mean: " << it.mean() << endl;
    }

}
void RNGTest::testNormal() {
    constexpr int num_testes = 4;
    double mean[num_testes] = {11, 7.2e20, -87, 2e-24},
           stddev[num_testes] = {5, 2012e18,  4, 7};
    cout << "Normal" << endl;
    for (int j = 0; j < num_testes; j++) {
        cout << "Test " << j << " mean: " << mean[j] << " stddev: " << stddev[j] << endl;

        ostringstream stream;
        stream << "../Testes/Normal_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
        f << setprecision(this->digits);
        if (!f.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }
        IterativeMean it;
        double x = 0;
        for (int i = 0; i < 1000000; ++i) {
            x = this->generator.sampleNormal(mean[j], stddev[j]);
            it << x;
            f << x << "\n";
        }

        if (this->almost_equal(it.mean(), mean[j]))
            cout << " PASSED!" << endl;
        else
            cout << " FAILED! - mean: " << it.mean() << endl;
    }

}
void RNGTest::testGamma() {
    constexpr int num_testes = 4;
    double mean[num_testes] = {1e-2, 1.1, 54.9, -2e4},
           alpha[num_testes] = {0.2, 3.5, 9.1, 45.666};
    cout << "Gamma" << endl;
    for (int j = 0; j < num_testes; j++) {
        cout << "Test " << j << " mean: " << mean[j] << " alpha: " << alpha[j] << endl;

        ostringstream stream;
        stream << "../Testes/Gamma_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
        f << setprecision(52);
        if (!f.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }
        IterativeMean it;
        double x = 0;
        for (int i = 0; i < 1000000; ++i) {
            x = this->generator.sampleGamma(mean[j], alpha[j]);
            it << x;
            f << x << "\n";
        }
        if (this->almost_equal(it.mean(), mean[j]))
            cout << " PASSED!" << endl;
        else
            cout << " FAILED! - mean: " << it.mean() << endl;
    }


}
void RNGTest::testBeta() {
    constexpr int num_testes = 4;
    double alpha[num_testes] = {0.5, 1.2, 1e2, 3e3},
           beta[num_testes] = {0.3, 5.6, 2e7, 6e-2},
           infLimit[num_testes] = {3, 4e-25, -2, 3.33},
           supLimit[num_testes] = {5, 5e-25, 8e10, 6.66};
    cout << "Beta" << endl;
    for (int j = 0; j < num_testes; j++) {
        cout << "Test " << j << " alpha: " << alpha[j] << " beta: " << beta[j]
             << " infLimit: " << infLimit[j] << " supLimit: " << supLimit[j] << endl;
        ostringstream stream;
        stream << "../Testes/Beta_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
        f << setprecision(52);
        if (!f.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }
        double gen_min = numeric_limits<double>::infinity(), gen_max = - gen_min, x = 0;
        for (int i = 0; i < 1000000; ++i) {
            x = this->generator.sampleBeta(alpha[j], beta[j], infLimit[j],supLimit[j]);
            gen_min = std::min(x, gen_min);
            gen_max = std::max(x, gen_max);
            f << x << "\n";
        }
        if (gen_min >= infLimit[j] && gen_max <= supLimit[j])
            cout << " PASSED!" << endl;
        else
            cout << " FAILED! - min: " << gen_min << " max: " << gen_max << endl;


    }
}
void RNGTest::testWeibull() {
    constexpr int num_testes = 4;
    double alpha[num_testes] = {1.5, 0.001,  2.11, 45.2},
           scale[num_testes] = {3.1415e2, 125, 35.55, 3e-2};
    cout << "Weibull" << endl;

    for (int j = 0; j < num_testes; j++) {
        cout << "Test " << j << " alpha: " << alpha[j] << " scale: " << scale[j]  << endl;
        ostringstream stream;
        stream << "../Testes/Weibull_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
        f << setprecision(this->digits);
        if (!f.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        for (int i = 0; i < 1000000; ++i) {
            f << this->generator.sampleWeibull(alpha[j], scale[j]) << "\n";
        }
    }

}
void RNGTest::testLogNormal() {
    constexpr int num_testes = 4;
    double mean[num_testes] = {55, 1, 1.682, 366},
           stddev[num_testes] = {12, 0.25, 87.36, 4.7};
    cout << "Log-Normal" << endl;
    for (int j = 0; j < num_testes; j++) {
        cout << "Test " << j << " mean: " << mean[j] << " stddev: " << stddev[j] << endl;

        ostringstream stream;
        stream << "../Testes/LogNormal_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
        f << setprecision(this->digits);
        if (!f.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }
        IterativeMean it;
        double x = 0;
        for (int i = 0; i < 1000000; ++i) {
            x = this->generator.sampleLogNormal(mean[j], stddev[j]);
            it << x;
            f << x << "\n";
        }
        if (this->almost_equal(it.mean(), mean[j]))
            cout << " PASSED!" << endl;
        else
            cout << " FAILED! - mean: " << it.mean() << endl;

    }
}
void RNGTest::testTriangular() {
    constexpr int num_testes = 4;
    double min[num_testes] = {2e-30, -7.33, -51e2, 12},
           mode[num_testes] = {0, 8.66, -37e1, 445.6},
           max[num_testes] = {7e27, 100.5, -20e1, 447};
    cout << "Triangular" << endl;
    for (int j = 0; j < num_testes; j++) {
        cout << "Test " << j << " min: " << min[j] << " mode: " << mode[j] << " max: " << max[j] << endl;
        ostringstream stream;
        stream << "../Testes/Triangular_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
        f << setprecision(this->digits);
        if (!f.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }
        double gen_min = numeric_limits<double>::infinity(), gen_max = - gen_min, x = 0;
        for (int i = 0; i < 1000000; ++i) {
            x = this->generator.sampleTriangular(min[j], mode[j], max[j]);
            gen_min = std::min(x, gen_min);
            gen_max = std::max(x, gen_max);
            f << x << "\n";
        }
        if (gen_min >= min[j] && gen_max <= max[j])
            cout << " PASSED!" << endl;
        else
            cout << " FAILED! - min: " << gen_min << " max: " << gen_max << endl;
    }
}
void RNGTest::testDiscrete() {
    /* A little bit of pre-processor sorcery so we can call the sampleDiscrete easily */
#define CALL(idx, value, accProb, ...)\
    x = this->generator.sampleDiscrete(value, accProb, #__VA_ARGS__);\
    streams[idx] << x << "\n"
// Remember to update testCount if you change the macro table!
// F is for the macro CALL
#define TEST_CASES(F) \
        F(0, 1,   0.2,  2,   0.2004, 3,   .5, 4,  .69, 5, 1); \
        F(1, 1e-4, 1e-3, 1e3, 1e-2,   100, .1, 10, 1); \
        F(2, 1, 0.16667, 2, 0.33334, 3, 0.5, 4, 0.66667, 5, 0.83334, 6, 1);\
        F(3, 23, 0.5, 32, 1.0)


        constexpr int testCount = 4;
        std::vector<ofstream> streams;
        cout << "Discrete" << endl;
        for (int i = 0; i < testCount; ++i) {
            streams.emplace_back(ofstream("../Testes/Discrete" + to_string(i) + ".txt"));
            streams[i] << setprecision(this->digits);
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
    this->testSetSeed();
}
bool RNGTest::almost_equal(double x, double y) {
    return abs(x - y) < this->error;
}
void RNGTest::testSetSeed() {
    cout << "Test setSeed " << endl;
    constexpr auto testCount = 4;
    unsigned int cases[testCount] = { 23, 17, 1000002, 2 };
    for (int i = 0; i < testCount; ++i) {
        cout << "Test " << i << " seed: " << cases[i];
        this->generator.setSeed(cases[i]);
        if (this->generator.getSeed() == cases[i])
            cout << " PASSED!" << endl;
        else
            cout << " FAILED! - seed: " << cases[i] << endl;
    }
}



