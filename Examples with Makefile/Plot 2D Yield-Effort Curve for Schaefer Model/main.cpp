#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	std::vector<double> x = linspace(0, 2);
	// Y(E) = EK (1 - E/r)
	std::vector<double> y = transform(x, [](auto x) { 
	float r = 2;
	float K = 1;	
	return x*K*(1 - x/r); });
	plot(x, y)->color({0.1f, 0.7f, 0.9f});
	plot(x, y,"-o")->marker_indices({49});
	//xticks({});
	//yticks({});
	title("");
	xlabel("E");
	ylabel("Y(E)");
	text(0.95, 0.55, "Y_{m}");
	//arrow(0, 0, 3, 0);
	//arrow(0, 0, 0, 5);
	
	show();
	return 0;
}