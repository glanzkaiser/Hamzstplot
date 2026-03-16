#include <cmath>
#include <hamzstplot/hamzstplot.h>

using namespace std;


int main() {
	using namespace hamzstplot;
	double dx, dy, magnitude;
	auto [x, y] = meshgrid(iota(0, 0.5, 5), iota(895, 0.5, 905));
	
	vector_2d u = transform(x, y, [](double x, double y) { return 1 ; }); // dx
	vector_2d v = transform(x, y, [](double x, double y) { return 0.5*y - 450 ; }); // dy
	quiver(x, y, u, v);

	show();
	return 0;
}