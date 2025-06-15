#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	std::vector<double> x = linspace(-0.5, 3.5);
	// dy/dt = r(1-y/K)y - Ey
	// r = 5, E = 1.5, K = 3
	std::vector<double> y = transform(x, [](auto x) { return 5*(1-(x/3))*x - 1.5*x; });
	plot(x, y)->color({0.1f, 0.7f, 0.9f});
	plot(x, y,"-o")->marker_indices({13,38,64});
	xticks({});
	yticks({});
	title("");
	xlabel("y");
	ylabel("f(y)");
	text(0.4, 2.9, "(K(r-E)/2r, (2rK-K^{2} (r-E) - 2EK)(r-E) / 4r");
	text(2, -0.5, "K(1 - E/r)");
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