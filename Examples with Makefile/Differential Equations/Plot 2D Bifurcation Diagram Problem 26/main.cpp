#include <cmath>
#include <hamzstplot/hamzstplot.h>

double division(double x, double y)
{
	return x/y;
}

int main() {
	using namespace hamzstplot;

	std::vector<double> x = linspace(0, 4);
	std::vector<double> x2 = linspace(-4, 0);
	
	std::vector<double> y1 = transform(x, [](auto x) { 
	return pow(x,0.5); });
	std::vector<double> y2 = transform(x, [](auto x) { 
	return -pow(x,0.5); });
	std::vector<double> y3 = transform(x, [](auto x) { 
	return 0; });
	std::vector<double> y4 = transform(x2, [](auto x2) { 
	return 0; });
	
	plot(x, y1)->line_width(2).color({0.1f, 0.7f, 0.9f});
	hold(on);
	plot(x, y2)->line_width(2).color({0.1f, 0.7f, 0.9f});
	plot(x, y3,"--")->line_width(2).color({0.1f, 0.7f, 0.9f});
	plot(x2, y4)->line_width(2).color({0.1f, 0.7f, 0.9f});
	hold(off);
	//xticks({});
	//yticks({});
	title("Bifurcation diagram for dy/dt = y(a - y^{2})");
	xlabel("a");
	ylabel("y");
	text(1.2, 0.5, "Unstable");
	arrow(1.4, 0.4, 1.4, 0.05);
	text(-1.6, 0.5, "Stable");
	arrow(-1.4, 0.4, -1.4, 0.05);
	
	text(0.3, 1.84, "Stable");
	arrow(0.7, 1.7, 1.03, 1.2);
	text(3, -0.9, "Stable");
	arrow(3,-1,2.5, -1.4);
	line(0,-2,0,2);
	axis({-4, 4, -2, 2});
	show();
	return 0;
}