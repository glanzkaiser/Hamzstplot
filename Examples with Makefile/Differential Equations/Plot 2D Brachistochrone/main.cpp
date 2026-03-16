#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	std::vector<double> x = linspace(0, 10, 150);
	std::vector<double> y = transform(x, [](auto x) { return 1 - cos(x) - 2*x + 2*sin(x); });
	plot(x, y)->color({0.1f, 0.7f, 0.9f});
	title("2-D Line Plot");
	xlabel("x");
	ylabel("1 - cos(x) - 2*x + 2*sin(x)");

	show();
	return 0;
}