#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	std::vector<double> x = linspace(0, 10, 150);
	std::vector<double> y = transform(x, [](auto x) { return -2*exp(x/4)*cos(3*x) + 0.5*exp(x/4)*sin(3*x); });
	plot(x, y)->color({0.1f, 0.7f, 0.9f});
	title("y(t) = -2e^{t/4}cos(3t) +0.5e^{t/4}sin(3t)");
	xlabel("t");
	ylabel("y");

	show();
	return 0;
}