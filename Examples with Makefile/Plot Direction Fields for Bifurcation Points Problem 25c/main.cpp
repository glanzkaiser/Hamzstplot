#include <cmath>
#include <hamzstplot/hamzstplot.h>

using namespace std;


int main() {
	using namespace hamzstplot;
	double dx, dy, magnitude;
	auto [x, y] = meshgrid(iota(0, 0.5, 12), iota(-3, 0.5, 3));
	
	vector_2d u = transform(x, y, [](double x, double y) { 
	double dx= 1;
	double dy = y*(-1 - pow(y,2)) ;
	//double dy = - pow(y,3) ;
	//double dy = 1 - pow(y,2) ;
	double magnitude= sqrt((dx*dx) + (dy*dy));
	return 1/magnitude ; }); // dx
	vector_2d v = transform(x, y, [](double x, double y) { 
	double dx= 1;
	double dy = y*(-1 - pow(y,2)) ;
	//double dy = - pow(y,3) ;
	//double dy = 1 - pow(y,2) ;
	double magnitude= sqrt((dx*dx) + (dy*dy));
	return (y*(-1 - pow(y,2)))/magnitude ; }); // dy

	quiver(x, y, u, v);
	xlabel("t");
	ylabel("y");
	title("Direction field for <1, y(-1 - y^{2})>");
	
	show();
	return 0;
}