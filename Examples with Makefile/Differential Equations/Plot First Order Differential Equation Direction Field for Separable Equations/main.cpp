#include <cmath>
#include <hamzstplot/hamzstplot.h>

using namespace std;

int main() {
	using namespace hamzstplot;

	// For dy/dx = x^2 / (1-y^2)
	auto [x, y] = meshgrid(iota(-4, 0.5, 4), iota(-4, 0.5, 4));
	vector_2d u = transform(x, y, [](double x, double y) { return 1-pow(y,2) ; });
	vector_2d v = transform(x, y, [](double x, double y) { return pow(x,2); });

	quiver(x, y, u, v);
	
	axis({-4, 4, -4, 4});
	title("Direction field of y' = x^{2} / (1-y^{2})");
	xlabel("x");
	ylabel("y(x)");
	show();
	return 0;
}