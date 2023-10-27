// Author: Cameron Scott
// Date: October 1, 2023
// Genetic Algorithm in C++ ...

#include <iostream>
#include <math.h>
#include <random>
#include <vector>

struct Solution {

	double rank, x, y, z;
	void fitness() {
		double ans = (6 * x + -y + std::pow(z, 200)) - 25;
		rank = (ans == 0) ? 9999 : std::abs(1/ans);
}
};

int main() {

	// create the initial random solutions
	std::random_device device;
	std::uniform_real_distribution<double> unif(-10000,10000);
	
	// declare vector to store solutions
	std::vector<Solution> solutions;
	const int NUM = 100000;
	for (int i = 0; i < NUM; i++) {
		solutions.emplace_back(Solution{0 , unif(device), unif(device), unif(device)});

	
}
