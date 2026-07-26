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
	dvec learningrate =loadVectorFromFile("learningrate.txt");
 	dvec loss =loadVectorFromFile("loss.txt");
	std::vector<double> x = linspace(0, 37,21);

	plot(x, loss)->line_width(2).color({0.1f, 0.7f, 0.1f});
	hold(on);
	plot(x, learningrate,"--")->line_width(2).color({0.1f, 0.7f, 0.9f});

	hold(off);
	auto lgd = ::hamzstplot::legend({"Learning Rate", "Loss"});
	lgd->location(legend::general_alignment::topright);
	lgd->box(false);

	xlabel("Epoch");
	ylabel("y");
	xrange({0, 21});
	yrange({0, 3});
	title("CNN Loss and Leaning Rate with LeNet-5 Architecture");

	show();

	// Get ending timepoint
	//auto stop = high_resolution_clock::now();
	//auto duration = duration_cast<microseconds>(stop - start);

	//cout << "\nTime taken by function: " << duration.count() << " microseconds" << endl;

	return 0;
}