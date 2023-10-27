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
		solutions.push_back(Solution{0 , unif(device), unif(device), unif(device)});
		

		// run the fitness function
		for (auto& s : solutions) {
			s.fitness();

}	

		// sort the solutions by rank gained from fitness function
		std::sort(solutions.begin(), solutions.end(), [](const auto& lhs, const auto& rhs){
			return lhs.rank > rhs.rank;
});	

		// print the top 10 solutions
		std::for_each(solutions.begin(), solutions.end() + 10, [](const auto& s){
			std::cout << std::fixed << "Rank: " << static_cast<int>(s.rank) << "\n x: " << s.x << " y: " << s.y << " z: " << s.z << std::endl;
});


}
