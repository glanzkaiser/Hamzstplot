#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	std::vector<double> x = linspace(0, 10, 150);
	std::vector<double> y = transform(x, [](auto x) { 
	double R= 2;
	double delta = 0.5;
	double omega = 1;
	return R*cos(omega*x-delta) ; });
	plot(x, y)->color({0.1f, 0.7f, 0.9f});
	title("2-D Line Plot");
	xlabel("x");
	ylabel("u = R cos(ω_{0}t - δ)");
	axis({0, 10, -2.5, 2.5});

	show();
	return 0;
}