#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	//auto x = linspace(0, 1, 500);
	std::vector<double> x = linspace(0, 50, 500);

	auto y1 = transform(x, [](double x) { return exp(-x/16) * (2*cos(x*sqrt(255)/16) + (2/sqrt(255)) * sin(x*sqrt(255)/16) ); }); 
	auto y2 = transform(x, [](double x) { return 2*cos(x); }); 
	
	plot(x, y1);
	hold(on);
	plot(x, y2);
	hold(off);

	auto lgd = ::hamzstplot::legend({"u'' + 0.125u' + u = 0", "u'' + u = 0"});
	lgd->location(legend::general_alignment::topright);
	lgd->box(false);

	title("Initial Value Problem Solution for Spring Mass System with u(0)=2, u'(0)=0");
	xlabel("t");
	ylabel("u(t)");
	xrange({0, 50});
	yrange({-2.5, 2.5});
	
	show();
	return 0;
}