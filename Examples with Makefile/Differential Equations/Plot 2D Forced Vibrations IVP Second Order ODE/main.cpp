#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	//auto x = linspace(0, 1, 500);
	std::vector<double> x = linspace(0, 20, 500);

	auto y1 = transform(x, [](double x) { return 1.29412*exp(-0.5*x) * cos(x) + 0.823529*exp(-0.5*x)*sin(x) ; }); 
	auto y2 = transform(x, [](double x) { return 2.82353*sin(x) + 0.705882*cos(x); }); 
	auto y3 = transform(x, [](double x) { return 1.29412*exp(-0.5*x) * cos(x) + 0.823529*exp(-0.5*x)*sin(x) + 2.82353*sin(x) + 0.705882*cos(x); }); 
	
	plot(x, y1)->line_width(2).color({0.1f, 0.7f, 0.1f});
	hold(on);
	plot(x, y2,"--")->line_width(2).color({0.1f, 0.7f, 0.9f});
	plot(x, y3)->line_width(2).color({0.3f, 0.5f, 0.7f});
	hold(off);

	auto lgd = ::hamzstplot::legend({"Transient", "Steady state", "Full solution"});
	lgd->location(legend::general_alignment::topright);
	lgd->box(false);

	title("Initial Value Problem Solution for Forced Vibration with Damping u'' + u' + 1.25u = 3 cos(t) with u(0)=2, u'(0)=3");
	xlabel("t");
	ylabel("u(t)");
	xrange({0, 20});
	yrange({-3.3, 3.7});
	
	show();
	return 0;
}