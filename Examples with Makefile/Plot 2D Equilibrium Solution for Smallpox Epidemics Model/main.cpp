#include <cmath>
#include <hamzstplot/hamzstplot.h>

double division(double x, double y)
{
	return x/y;
}

int main() {
	using namespace hamzstplot;

	std::vector<double> x = linspace(0, 1);
	// dy/dt = αy(1-y)
	std::vector<double> y = transform(x, [](auto x) { 
	float α = 1;
	return α*x*(1-x); });
	plot(x, y)->color({0.1f, 0.7f, 0.9f});
	plot(x, y,"-o")->marker_indices({0,50,99});
	//xticks({});
	//yticks({});
	title("dy/dt = αy(1-y), α = 1");
	xlabel("y");
	ylabel("f(y)");
	text(0.5, 0.26, "(0.5, 0.25α)");
	arrow(-0.1,0.02,-0.30,0.02)->color({0.1f, 0.7f, 0.9f});
	arrow(0.5,0.02,0.8,0.02)->color({0.1f, 0.7f, 0.9f});
	arrow(0.1,0.02,0.3,0.02)->color({0.1f, 0.7f, 0.9f});
	arrow(1.4,0.02,1.1,0.02)->color({0.1f, 0.7f, 0.9f});
	//axis({-3, 3, -3, 3});
	show();
	return 0;
}