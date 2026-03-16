#include <cmath>
#include <hamzstplot/hamzstplot.h>

using namespace std;


int main() {
	using namespace hamzstplot;
	double dx, dy, magnitude;
	auto [x, y] = meshgrid(iota(0, 0.25, 10), iota(-2, 0.25, 2));
	
	vector_2d u = transform(x, y, [](double x, double y) { return 1 ; }); // dx
	vector_2d v = transform(x, y, [](double x, double y) { return -1 - pow(y,2) ; }); // dy
	quiver(x, y, u, v);
	xlabel("t");
	ylabel("y");
	title("Direction field for <1, -1 - y^{2}>");
	
	show();
	return 0;
}