#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	std::vector<double> x = linspace(-0.5, 3.5);
	std::vector<double> y = transform(x, [](auto x) { return -3*(1-(x/2))*x; });
	plot(x, y)->color({0.1f, 0.7f, 0.9f});
	plot(x, y,"-o")->marker_indices({12,38,62});
	xticks({});
	yticks({});
	title("");
	xlabel("y");
	ylabel("f(y)");
	text(0.8, -1.9, "(T/2, -rT/4)");
	text(2, -0.5, "T");
	text(3, -0.5, "y");
	text(0, 5.3, "f(y)");
	arrow(0, 0, 3, 0);
	arrow(0, 0, 0, 5);
	arrow(0.7,0.3,0.3,0.3)->color({0.1f, 0.7f, 0.9f});
	arrow(1.7,0.3,1.2,0.3)->color({0.1f, 0.7f, 0.9f});
	arrow(2.3,0.3,2.7,0.3)->color({0.1f, 0.7f, 0.9f});
	
	show();
	return 0;
}