#include <cmath>
#include <hamzstplot/hamzstplot.h>
#include <random>
#include "symintegrationc++.h"

using namespace std::chrono;
using namespace std;

double division(double x, double y)
{
	return x/y;
}

int main() {
	using namespace hamzstplot;

	// Get starting timepoint
	//auto start = high_resolution_clock::now();
	std::vector<double> x =vrandn_gamma(2, 1.5,1000); 

	auto h = hist(x);
	std::cout << "Histogram with " << h->num_bins() << " bins" << std::endl;

	show();

	// Get ending timepoint
	//auto stop = high_resolution_clock::now();
	//auto duration = duration_cast<microseconds>(stop - start);

	//cout << "\nTime taken by function: " << duration.count() << " microseconds" << endl;

	return 0;
}