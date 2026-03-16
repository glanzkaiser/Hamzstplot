#include <cmath>
#include <hamzstplot/hamzstplot.h>

using namespace std;


int main() {
	using namespace hamzstplot;
	auto [x, y] = meshgrid(iota(0, 0.5, 10), iota(-2, 0.5, 5));
	
	vector_2d u = transform(x, y, [](double x, double y) { 
	double dx= 1;
	double dy = 1*(1-y)*(2- y) ;
	double magnitude= sqrt((dx*dx) + (dy*dy));
	return 1 ; }); // dx

	vector_2d v = transform(x, y, [](double x, double y) { 
	double dx= 1;
	double dy = 1*(1-y)*(2- y) ;
	double magnitude= sqrt((dx*dx) + (dy*dy));
	return 1*(1-y)*(2- y) ; }); // dy

	quiver(x, y, u, v);
	xlabel("t");
	ylabel("x");
	title("Direction field for <1,α(p-x)(q-x)>");
	
	show();
	return 0;
}