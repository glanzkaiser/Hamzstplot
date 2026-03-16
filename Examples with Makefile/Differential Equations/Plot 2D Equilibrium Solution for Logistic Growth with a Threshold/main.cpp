#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	std::vector<double> x = linspace(-0.5, 3.5);
	// T = 1, K = 3, r = 8
	std::vector<double> y = transform(x, [](auto x) { return -8*(1-(x/1))*(1-(x/3))*x; });
	plot(x, y)->color({0.1f, 0.7f, 0.9f});
	plot(x, y,"-o")->marker_indices({12,23,37,68,87});
	xticks({});
	yticks({});
	title("");
	xlabel("y");
	ylabel("f(y)");
	text(1, -1, "T");
	text(2.9, -1, "K");
	text(0.3, -2, "y_{1}");
	text(2.3, 6.5, "y_{2}");
	text(3.8, -0.5, "y");
	text(0, 7.3, "f(y)");
	arrow(0, 0, 3.8, 0);
	arrow(0, 0, 0, 7);
	arrow(0.7,0.3,0.3,0.3)->color({0.1f, 0.7f, 0.9f});
	arrow(1.2,0.3,1.7,0.3)->color({0.1f, 0.7f, 0.9f});
	arrow(2.3,0.3,2.7,0.3)->color({0.1f, 0.7f, 0.9f});
	arrow(3.5,0.3,3.2,0.3)->color({0.1f, 0.7f, 0.9f});
	
	show();
	return 0;
}