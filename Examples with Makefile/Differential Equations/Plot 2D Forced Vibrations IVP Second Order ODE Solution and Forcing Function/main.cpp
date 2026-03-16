#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	//auto x = linspace(0, 1, 500);
	std::vector<double> x = linspace(0, 60, 500);

	auto y1 = transform(x, [](double x) { return 3*cos(x) ; }); 
	auto y2 = transform(x, [](double x) { return 2*exp(-0.0625*x)*cos(0.998045*x) - 23.9218*exp(-0.0625*x)*sin(0.998045*x) + 24*sin(x); }); 
	
	plot(x, y1,"--")->line_width(2).color({0.1f, 0.7f, 0.1f});
	hold(on);
	plot(x, y2)->line_width(2).color({0.3f, 0.5f, 0.7f});
	hold(off);

	auto lgd = ::hamzstplot::legend({"Forcing function", "Full solution"});
	lgd->location(legend::general_alignment::topright);
	lgd->box(false);

	title("Initial Value Problem Solution for Forced Vibration with Damping u'' + 0.125u' + u = 3 cos(t) with u(0)=2, u'(0)=0");
	xlabel("t");
	ylabel("u(t)");
	xrange({0, 60});
	yrange({-30, 30});
	
	show();
	return 0;
}