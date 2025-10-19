#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;
	auto [x, y] = meshgrid(iota(0, 0.5, 10), iota(0, 0.5, 10));
	
	vector_2d u = transform(x, y, [](double x, double y) { 
	double dx = 1;
	double dy = 5 - 3*sqrt(y);
	double magnitude = sqrt((dx * dx) + (dy * dy) );
	return dx/magnitude; });
	vector_2d v = transform(x, y, [](double x, double y) { 
	double dx = 1;
	double dy = 5 - 3*sqrt(y);
	double magnitude = sqrt((dx * dx) + (dy * dy) );
	return (dy)/magnitude; });

	quiver(x, y, u, v);

	xlabel("t");
	ylabel("y");
	title("Direction field for <1, 5 - 3 y^{0.5}>");
	show();
    return 0;
}