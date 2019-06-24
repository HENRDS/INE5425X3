//
// Created by henry, jacyara, mathias and rene on 6/12/19.
//

#include "tests.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdarg>
#include <iomanip>

using namespace std;

RNGTest::RNGTest(unsigned int seed, unsigned int digits) : generator(seed), digits(digits) {

}

void RNGTest::testUniform() {
    cout << "Test Uniform" << endl;
    // otherwise the compiler won't know the size of the array until runtime.
    constexpr int num_testes = 4;
    // the parameters for sampleUniform are double
    double min[num_testes] = {1, -100, 1e-42, 1e-22}, max[num_testes] = {2, 502, 1e13, 2e-22};
    for (int j = 0; j < num_testes; j++) {
        cout << "Test " << j << "min: " << min[j] << " max: " << max[j];
        ostringstream stream;
        stream << "../Testes/Uniform_" << j << ".txt";
        string filename = stream.str();
        ofstream f(filename);
        f << setprecision(this->digits);
        if (!f.is_open()) {
            cout << " FAILED! - Error opening file." << endl;
            return;
        }
        for (int i = 0; i < 1000000; ++i) {
            f << this->generator.sampleUniform(min[j], max[j]) << "\n";
        }
    }
}

void RNGTest::testExponential() {
    cout << "Test Uniform" << endl;
    constexpr int num_testes = 4;
    double mean[num_testes] = {7e-31, 4e27, 1024, -33};
    RNG rng(4202369);

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

        for (int i = 0; i < 1000000; ++i) {
            f << rng.sampleExponential(mean[j]) << endl;
        }
    }

}
void RNGTest::testErlang() {
    constexpr int num_testes = 4;
    double mean[num_testes] = {7e-2, 1.698, 89, -8e12},
           M[num_testes] = {1, 6, 7, 165};

    RNG rng(4202369);

    for (int j = 0; j < num_testes; j++) {
        cout << "teste " << j << endl;

        ostringstream stream;
        stream << "../Testes/Erlang_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
        f << setprecision(this->digits);
        if (!f.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        for (int i = 0; i < 1000000; ++i) {
            f << rng.sampleErlang(mean[j], M[j]) << endl;
        }
    }

}
void RNGTest::testNormal() {
    constexpr int num_testes = 4;
    double mean[num_testes] = {11, 7.2e20, -87, 2e-24},
           stddev[num_testes] = {1e-3, 2012e18,  4, 7};

    RNG rng(4202369);

    for (int j = 0; j < num_testes; j++) {
        cout << "teste " << j << endl;

        ostringstream stream;
        stream << "../Testes/Normal_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
        f << setprecision(this->digits);
        if (!f.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        for (int i = 0; i < 1000000; ++i) {
            f << rng.sampleNormal(mean[j], stddev[j]) << endl;
        }
    }

}
void RNGTest::testGamma() {
    constexpr int num_testes = 4;
    double mean[num_testes] = {1e-2, 0, 54.9, -2e4},
           alpha[num_testes] = {0.2, 3.5, 9.1, 45.666};

    RNG rng(4202369);

    for (int j = 0; j < num_testes; j++) {
        cout << "teste " << j << endl;

        ostringstream stream;
        stream << "../Testes/Gamma_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
        f << setprecision(52);
        if (!f.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        for (int i = 0; i < 1000000; ++i) {
            f << rng.sampleGamma(mean[j], alpha[j]) << endl;
        }
    }


}
void RNGTest::testBeta() {
    constexpr int num_testes = 4;
    double alpha[num_testes] = {0.5, 1.2, 1e2, 3e3},
           beta[num_testes] = {0.3, 5.6, 2e7, 6e-2},
           infLimit[num_testes] = {3, 5e-25, -2, 3.33},
           supLimit[num_testes] = {5, 4e-25, 8e10, 6.66};

    RNG rng(4202369);

    for (int j = 0; j < num_testes; j++) {
        cout << "teste " << j << endl;

        ostringstream stream;
        stream << "../Testes/Beta_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
        f << setprecision(52);
        if (!f.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        for (int i = 0; i < 1000000; ++i) {
            f << rng.sampleBeta(alpha[j], beta[j], infLimit[j], supLimit[j]) << endl;
        }
    }
}
void RNGTest::testWeibull() {
    constexpr int num_testes = 4;
    double alpha[num_testes] = {1.5, 0.001,  2.11, 45.2},
           scale[num_testes] = {3.1415e2, 125, 35.55, 3e-2};
    cout << "Weibull" << endl;
    RNG rng(4202369);

    for (int j = 0; j < num_testes; j++) {
        cout << "Test " << j << " alpha " << endl;
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
            f << rng.sampleWeibull(alpha[j], scale[j]) << endl;
        }
    }

}
void RNGTest::testLogNormal() {
    constexpr int num_testes = 4;
    double mean[num_testes] = {-55e33, -2.338, 0.682, 369.666},
           stddev[num_testes] = {144, 5e27, 87.36, 4512.7};

    RNG rng(4202369);

    for (int j = 0; j < num_testes; j++) {
        cout << "teste " << j << endl;

        ostringstream stream;
        stream << "../Testes/LogNormal_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
        f << setprecision(this->digits);
        if (!f.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        for (int i = 0; i < 1000000; ++i) {
            f << rng.sampleLogNormal(mean[j], stddev[j]) << endl;
        }
    }
}
void RNGTest::testTriangular() {
    constexpr int num_testes = 4;
    double min[num_testes] = {2e-30, -7.33, -51e2, 12},
           mode[num_testes] = {0, 8.66, -37e1, 445.6},
           max[num_testes] = {7e27, 100.5, -20e1, 447};

    RNG rng(4202369);

    for (int j = 0; j < num_testes; j++) {
        cout << "teste " << j << endl;

        ostringstream stream;
        stream << "../Testes/Triangular_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
        f << setprecision(this->digits);
        if (!f.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        for (int i = 0; i < 1000000; ++i) {
            f << rng.sampleTriangular(min[j], mode[j], max[j]) << endl;
        }
    }
}
void RNGTest::testDiscrete() {
    /* A little bit of pre-processor sorcery */
#define CALL(idx, value, accProb, ...)\
    x = this->generator.sampleDiscrete(value, accProb, __VA_ARGS__);\
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
}



