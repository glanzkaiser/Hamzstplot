#include <cmath>
#include <hamzstplot/hamzstplot.h>

double division(double x, double y)
{
	return x/y;
}

int main() {
	using namespace hamzstplot;

	std::vector<double> x = linspace(-2, 2);
	
	std::vector<double> y = transform(x, [](auto x) { 
	float α = 1;
	return x*(α - pow(x,2)); });
	plot(x, y)->color({0.1f, 0.7f, 0.9f});
	plot(x, y,"-o")->marker_indices({25,50,74});
	//xticks({});
	//yticks({});
	title("dy/dt = y(α-y^{2}), α = 1");
	xlabel("y");
	ylabel("f(y)");
	line(0,-2,0,2);
	line(-1.5,0,1.5,0);
	arrow(1.4,0.1,1.1,0.1)->color({0.1f, 0.7f, 0.9f});
	arrow(0.2,0.1,0.6,0.1)->color({0.1f, 0.7f, 0.9f});
	arrow(-0.2,0.1,-0.6,0.1)->color({0.1f, 0.7f, 0.9f});
	arrow(-1.4,0.1,-1.1,0.1)->color({0.1f, 0.7f, 0.9f});
	axis({-1.5, 1.5, -2, 2});
	show();
	return 0;
}