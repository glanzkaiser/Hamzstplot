#include <cmath>
#include <hamzstplot/hamzstplot.h>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std::chrono;
using namespace std;

int main() {
	using namespace hamzstplot;
	
	// Get starting timepoint
	auto start = high_resolution_clock::now();
	
	vector<double> t = linspace(0, 10, 150);
	vector<double> x = transform(t, [](auto t) { 
	float k = 1;
	return k*k*(t - 0.5*sin(2*t)) ; });
	vector<double> y = transform(t, [](auto t) { 
	float k = 1;
	return 0.5*k*k*(1 - cos(2*t)) ; });

	plot(x, y)->color({0.1f, 0.7f, 0.9f});

	auto lgd = ::hamzstplot::legend({"(x(t) , y(t)) = ( k^{2} * (t - 0.5*sin(2t))  ,  0.5*k^{2} (1 - cos(2t)  )", ""});
	lgd->location(legend::general_alignment::topright);
	lgd->box(false);

	title("Parametric Plot for Brachistochrone");
	xlabel("t");
	ylabel("");
	axis({0, 3, 0, 2});

	show();
	// Get ending timepoint
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	ofstream MyFile("./time.txt"); ;
	MyFile << duration.count() << " microseconds " ;

	return 0;
	
}