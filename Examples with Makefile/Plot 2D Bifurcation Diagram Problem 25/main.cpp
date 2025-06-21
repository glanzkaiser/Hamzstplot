#include <cmath>
#include <hamzstplot/hamzstplot.h>

double division(double x, double y)
{
	return x/y;
}

int main() {
	using namespace hamzstplot;

	std::vector<double> x = linspace(0, 3);
	
	std::vector<double> y1 = transform(x, [](auto x) { 
	return pow(x,0.5); });
	std::vector<double> y2 = transform(x, [](auto x) { 
	return -pow(x,0.5); });
	
	plot(x, y1)->line_width(2).color({0.1f, 0.7f, 0.9f});
	hold(on);
	plot(x, y2,"--")->line_width(2).color({0.1f, 0.7f, 0.9f});
	hold(off);
	//xticks({});
	//yticks({});
	title("y = a^{1/2}");
	xlabel("a");
	ylabel("y");
	text(2, 0.84, "Asymptotically stable");
	arrow(2.7, 0.98, 2.2, 1.3);
	text(3, -0.9, "Unstable");
	arrow(3,-1,2.5, -1.4);
	line(0,-2,0,2);
	line(-2,0,4,0);
	axis({-2, 4, -2, 2});
	show();
	return 0;
}