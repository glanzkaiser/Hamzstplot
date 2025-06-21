#include <cmath>
#include <hamzstplot/hamzstplot.h>

double division(double x, double y)
{
	return x/y;
}

int main() {
	using namespace hamzstplot;

	std::vector<double> x = linspace(-3, 3);
	
	std::vector<double> y = transform(x, [](auto x) { 
	float α = 1;
	return α - pow(x,2); });
	plot(x, y)->color({0.1f, 0.7f, 0.9f});
	plot(x, y,"-o")->marker_indices({33,50,66});
	//xticks({});
	//yticks({});
	title("dy/dt = α-y^{2}, α = 1");
	xlabel("y");
	ylabel("f(y)");
	line(0,-10,0,5);
	line(-3,0,3,0);
	arrow(2,0.5,1,0.5)->color({0.1f, 0.7f, 0.9f});
	arrow(-0.5,0.5,0.5,0.5)->color({0.1f, 0.7f, 0.9f});
	arrow(-1,0.5,-2,0.5)->color({0.1f, 0.7f, 0.9f});
	axis({-3, 3, -8, 3});
	show();
	return 0;
}