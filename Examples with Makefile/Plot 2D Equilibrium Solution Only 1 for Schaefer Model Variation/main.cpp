#include <cmath>
#include <hamzstplot/hamzstplot.h>

double division(double x, double y)
{
	return x/y;
}

int main() {
	using namespace hamzstplot;

	std::vector<double> x = linspace(0, 1);
	// dy/dt = r(1-y/K)y - Ey
	std::vector<double> y = transform(x, [](auto x) { 
	float r = 1;
	float h = division(1,4);
	float K = 1;	
	return r*(1-(x/K))*x - h; });
	plot(x, y)->color({0.1f, 0.7f, 0.9f});
	plot(x, y,"-o")->marker_indices({50});
	//xticks({});
	//yticks({});
	title("");
	xlabel("y");
	ylabel("f(y)");
	line(0, 0, 2, 0);
	arrow(0.4,0.02,0.1,0.02)->color({0.1f, 0.7f, 0.9f});
	arrow(1.1,0.02,0.8,0.02)->color({0.1f, 0.7f, 0.9f});
	
	show();
	return 0;
}