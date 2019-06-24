//
// Created by henry on 6/12/19.
//

#include "tests.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

RNGTest::RNGTest(unsigned int seed) : generator(seed) {

}

void RNGTest::testUniform() {
    // otherwise the compiler won't know the size of the array until runtime.
    constexpr int num_testes = 4;
    // the parameters for sampleUniform are double
    double min[num_testes] = {1, -100, 1e-42, 1e-22},
           max[num_testes] = {2, 502, 1e13, 2e-22};
    // creates the generator only once
    RNG rng(4202369);

    for (int j = 0; j < num_testes; j++) {
        cout << "teste " << j << endl;
        // don't use a fixed-size array, segfault might happen with sprintf.
        // If you really need it to have fixed side, prefer snprintf.
        ostringstream stream;
        stream << "Uniform_"<< j << ".txt";
        string filename = stream.str();
        // ofstream closes the file when the variable goes out of scope, so we don't have to do it.
        // If we had to, it's good to surround everything with a try-finally and
        // put fclose inside the finally section, so you guarantee that it will be called.
        ofstream f(filename);
        if (!f.is_open()) {
            cout << "Error opening file!" << endl;
            // don't stop the whole program if this test fails
            return;
        }

        for (int i = 0; i < 1000000; ++i) {
            f << rng.sampleUniform(min[j], max[j]) << endl;
        }
    }
}

void RNGTest::testExponential() {
    constexpr int num_testes = 4;
    double mean[num_testes] = {7e-31, 4e27, 1024, -33};
    RNG rng(4202369);

    for (int j = 0; j < num_testes; j++) {
        cout << "teste " << j << endl;

        ostringstream stream;
        stream << "Exponential_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
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
        stream << "Erlang_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
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
           stddev[num_testes] = {1e-3, 2012,  4, 7};

    RNG rng(4202369);

    for (int j = 0; j < num_testes; j++) {
        cout << "teste " << j << endl;

        ostringstream stream;
        stream << "Normal_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
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

}
void RNGTest::testBeta() {

}
void RNGTest::testWeibull() {
    constexpr int num_testes = 4;
    double alpha[num_testes] = {1.5, 0.001,  2.11, 45.2},
           scale[num_testes] = {3.1415e2, 125, 35.55, 3e-2};

    RNG rng(4202369);

    for (int j = 0; j < num_testes; j++) {
        cout << "teste " << j << endl;

        ostringstream stream;
        stream << "Weibull_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
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
        stream << "LogNormal_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
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
        stream << "Triangular_"<< j << ".txt";
        string filename = stream.str();

        ofstream f(filename);
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



