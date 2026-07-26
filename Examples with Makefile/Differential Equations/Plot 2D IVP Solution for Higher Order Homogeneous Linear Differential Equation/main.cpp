#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	//auto x = linspace(0, 1, 500);
	std::vector<double> x = linspace(0, 2, 500);

	auto y1 = transform(x, [](double x) { 
	double gamma = 1;
	return 1.375*exp(x) - 0.666667*exp(2*x) + 0.416667*exp(-x) - 0.125*exp(-3*x); }); 

		
	plot(x, y1)->line_width(2).color({0.1f, 0.7f, 0.1f});

	title("Solution of the initial value problem of y^{(4)} + y''' - 7y'' - y' + 6y");
	xlabel("y");
	ylabel("t");
	xrange({0, 2});
	yrange({-2, 2});
	
	show();
	return 0;
}