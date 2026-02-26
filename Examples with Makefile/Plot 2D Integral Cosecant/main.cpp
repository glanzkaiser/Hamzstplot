#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	std::vector<double> x = linspace(0, 10, 150);
	//std::vector<double> y = transform(x, [](auto x) { return 1.5*(log((1/sin(x)) - (1/tan(x)) ))*sin(2*x) +  3*cos(x)*sin(2*x) ; });
	std::vector<double> y = transform(x, [](auto x) { return 0.75*sin(2*x)*log(abs(cos(x)-1)) - 0.75*sin(2*x)*log(abs(cos(x)+1)) + 3*sin(2*x)*cos(x) ; });
	plot(x, y)->color({0.1f, 0.7f, 0.9f});
	title("2-D Line Plot");
	xlabel("x");
	ylabel("cos(x) - x");

	show();
	return 0;
}