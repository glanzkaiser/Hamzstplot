#include <cmath>
#include <hamzstplot/hamzstplot.h>

using namespace std;

int main() {
	using namespace hamzstplot;
	
	vector_2d newcolors = {{0.10, 0.2, 0.80},
						{0.83, 0.14, 0.14},
						{1.00, 0.54, 0.00},
						{0.10, 0.6, 0.70},
						{0.47, 0.25, 0.80},
						{0.50, 0.2, 0.60},
						{0.25, 0.80, 0.54}};
	colororder(newcolors);

	auto [x, y] = meshgrid(iota(-4, 0.5, 5), iota(-4, 0.5, 4));
	vector_2d u = transform(x, y, [](double x, double y) { return x-y ; }); // dx
	vector_2d v = transform(x, y, [](double x, double y) { return y - 4*x ; }); // dy
	
	//subplot(1, 2, 0);
	quiver(x, y, u, v);
	hold(on);
	fimplicit([](double x, double y) { return -0.25*log(y/x - 2) - 0.75*log(y/x + 2) - log(x) ; },"-")->line_width(1);
	fimplicit([](double x, double y) { return -0.25*log(y/x - 2) - 0.75*log(y/x + 2) - log(x)- 1; },"-")->line_width(1);
	fimplicit([](double x, double y) { return -0.25*log(y/x - 2) - 0.75*log(y/x + 2) - log(x) - 2; },"-")->line_width(1);
	fimplicit([](double x, double y) { return -0.25*log(y/x - 2) - 0.75*log(y/x + 2) - log(x) - 3; },"-")->line_width(1);
	fimplicit([](double x, double y) { return -0.25*log(y/x - 2) - 0.75*log(y/x + 2) - log(x) + 1; },"-")->line_width(1);	
	fimplicit([](double x, double y) { return -0.25*log(y/x - 2) - 0.75*log(y/x + 2) - log(x) + 2; },"-")->line_width(1);
	fimplicit([](double x, double y) { return -0.25*log(y/x - 2) - 0.75*log(y/x + 2) - log(x)+ 3; },"-")->line_width(1);	
	hold(off);	
	
	axis({-4, 4, -4, 4});
	title("Direction field and integral curves of y' = (y - 4x) / (x-y)");
	xlabel("x");
	ylabel("y(x)");
	show();
	return 0;
}