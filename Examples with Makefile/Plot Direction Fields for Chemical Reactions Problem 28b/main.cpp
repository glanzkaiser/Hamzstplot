#include <cmath>
#include <hamzstplot/hamzstplot.h>

using namespace std;


int main() {
	using namespace hamzstplot;
	
	auto [x, y] = meshgrid(iota(0, 0.5, 10), iota(-2, 0.5, 5));
	
	vector_2d u = transform(x, y, [](double x, double y) { 
	double dx= 1;
	double dy = 1*pow((1-y),2);
	double magnitude= sqrt((dx*dx) + (dy*dy));
	return 1/magnitude ; }); // dx
	vector_2d v = transform(x, y, [](double x, double y) { 
	double dx= 1;
	double dy = 1*pow((1-y),2);
	double magnitude= sqrt((dx*dx) + (dy*dy));
	return (1*pow((1-y),2))/magnitude ; }); // dy
	quiver(x, y, u, v);
	xlabel("t");
	ylabel("x");
	title("Direction field for <1,α(p-x)^{2}>");
	
	show();
	return 0;
}