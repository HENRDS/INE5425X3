//
// Created by henry on 6/12/19.
//

#include "tests.hpp"
#include <iostream>

using namespace std;

RNGTest::RNGTest(unsigned int seed): generator(seed) {


}



void RNGTest::testUniform() {
	int num_testes = 4;
	int min[num_testes] = {1, 3, 5, 7};
	int max[num_testes] = {2, 4, 6, 8};

	for (int j=0; j<num_testes; j++){
		FILE *f = fopen("Uniform.txt", "w");
		if (f == NULL) {
			printf("Error opening file!\n");
			exit(1);
		}

		RNG rng(4202369);
		for (int i = 0; i < 1000000; ++i) {

			double var = rng.sampleUniform(min[j], max[j]);
			cout << i << " = " << var << endl;
			fprintf(f, "%f\n", var);
		}

		fclose(f);
	}
}

void RNGTest::testExponential() {

}
void RNGTest::testErlang() {

}
void RNGTest::testNormal() {

}
void RNGTest::testGamma() {

}
void RNGTest::testBeta() {

}
void RNGTest::testWeibull() {

}
void RNGTest::testLogNormal() {

}
void RNGTest::testTriangular() {

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



