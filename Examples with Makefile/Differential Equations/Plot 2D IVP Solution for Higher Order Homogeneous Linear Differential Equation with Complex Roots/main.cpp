#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	//auto x = linspace(0, 1, 500);
	std::vector<double> x = linspace(0, 15, 500);

	auto y1 = transform(x, [](double x) { 
	return 3*exp(-x) + 0.5*cos(x) - sin(x); }); 
	auto y2 = transform(x, [](double x) { 
	return (0.03125)*exp(x) + (2.96875)*exp(-x) + 0.5*cos(x) - (1.0625)*sin(x); }); 
		
	plot(x, y1)->line_width(2).color({0.1f, 0.7f, 0.1f});
	hold(on);
	plot(x, y2)->line_width(2).color({0.83f, 0.14f, 0.14f});
	hold(off);

	auto lgd = ::hamzstplot::legend({"y(0) = 7/2, y'(0) = -4, y''(0) = 5/2, y'''(0) = -2", "y(0) = 7/2, y'(0) = -4, y''(0) = 5/2, y'''(0) = -15/8"});
	lgd->location(legend::general_alignment::topright);
	lgd->box(false);

	title("Solution for Initial Value Problem y^{(4)} - y = 0");
	xlabel("t");
	ylabel("y");
	xrange({0, 15});
	yrange({-1.5, 10});
	
	show();
	return 0;
}