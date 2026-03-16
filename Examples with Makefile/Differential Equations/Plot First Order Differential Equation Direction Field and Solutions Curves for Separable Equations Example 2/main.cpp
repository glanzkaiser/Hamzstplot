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

	auto [x, y] = meshgrid(iota(-3, 0.5, 3), iota(-3, 0.5, 3));
	vector_2d u = transform(x, y, [](double x, double y) { return 2*(y-1); }); // dx
	vector_2d v = transform(x, y, [](double x, double y) { return 3*pow(x,2) + 4*x + 2; }); // dy
	
	quiver(x, y, u, v);
	hold(on);
//	fimplicit([](double x, double y) { return y + sqrt(pow(x, 3) + 2*pow(x,2) + 2*x + 4) - 1  ; },"-")->line_width(1);
	fimplicit([](double x, double y) { return pow(y,2) - 2*y - pow(x, 3) - 2*pow(x,2) - 2*x - 1  ; },"-")->line_width(1);
	fimplicit([](double x, double y) { return pow(y,2) - 2*y - pow(x, 3) - 2*pow(x,2) - 2*x - 2  ; },"-")->line_width(1);
	fimplicit([](double x, double y) { return pow(y,2) - 2*y - pow(x, 3) - 2*pow(x,2) - 2*x - 3  ; },"-")->line_width(1);
	fimplicit([](double x, double y) { return pow(y,2) - 2*y - pow(x, 3) - 2*pow(x,2) - 2*x - 4  ; },"-")->line_width(1);
	fimplicit([](double x, double y) { return pow(y,2) - 2*y - pow(x, 3) - 2*pow(x,2) - 2*x - 6  ; },"-")->line_width(1);
	fimplicit([](double x, double y) { return pow(y,2) - 2*y - pow(x, 3) - 2*pow(x,2) - 2*x + 1  ; },"-")->line_width(1);
	fimplicit([](double x, double y) { return pow(y,2) - 2*y - pow(x, 3) - 2*pow(x,2) - 2*x + 2  ; },"-")->line_width(1);
	fimplicit([](double x, double y) { return pow(y,2) - 2*y - pow(x, 3) - 2*pow(x,2) - 2*x + 3  ; },"-")->line_width(1);
	fimplicit([](double x, double y) { return pow(y,2) - 2*y - pow(x, 3) - 2*pow(x,2) - 2*x + 5  ; },"-")->line_width(1);
	fimplicit([](double x, double y) { return pow(y,2) - 2*y - pow(x, 3) - 2*pow(x,2) - 2*x + 7  ; },"-")->line_width(1);
	fimplicit([](double x, double y) { return pow(y,2) - 2*y - pow(x, 3) - 2*pow(x,2) - 2*x + 9  ; },"-")->line_width(1);
	hold(off);	
	
	axis({-3, 3, -3, 3});
	title("Direction field and integral curves of y' = (3x^{2} + 4x + 2) / 2(y-1)");
	xlabel("x");
	ylabel("y(x)");
	show();
	return 0;
}