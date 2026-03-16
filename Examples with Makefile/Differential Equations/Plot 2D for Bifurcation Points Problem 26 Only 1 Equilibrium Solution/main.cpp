#include <cmath>
#include <hamzstplot/hamzstplot.h>

double division(double x, double y)
{
	return x/y;
}

int main() {
	using namespace hamzstplot;

	std::vector<double> x = linspace(-1, 1);
	
	std::vector<double> y = transform(x, [](auto x) { 
	float α = -1; // float α = 0;
	return x*(α - pow(x,2)); });
	plot(x, y)->color({0.1f, 0.7f, 0.9f});
	plot(x, y,"-o")->marker_indices({50});
	//xticks({});
	//yticks({});
	title("dy/dt = y(α-y^{2}), α = -1");
	xlabel("y");
	ylabel("f(y)");
	line(0,-2,0,2);
	line(-1,0,1,0);
	arrow(0.6,0.1,0.2,0.1)->color({0.1f, 0.7f, 0.9f});
	arrow(-0.6,0.1,-0.2,0.1)->color({0.1f, 0.7f, 0.9f});
	axis({-1, 1, -2, 2});
	show();
	return 0;
}