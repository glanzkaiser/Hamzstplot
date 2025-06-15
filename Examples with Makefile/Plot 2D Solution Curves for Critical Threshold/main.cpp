#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	auto x = linspace(0, 1.1*pi);
	//y(t) = y_{0} * T / (y_{0} + (T - y_{0})*e^{rt})
	auto y1 = transform(x, [](double x) { return (1*5) / (1+(5-1)*(exp(0.5*x))); }); // r = 0.5, T = 5, y_{0} = 1
	auto y2 = transform(x, [](double x) { return (2*5) / (2+(5-2)*(exp(0.5*x))); }); // r = 0.5, T = 5, y_{0} = 2
	auto y3 = transform(x, [](double x) { return (3*5) / (3+(5-3)*(exp(0.5*x))); }); // r = 0.5, T = 5, y_{0} = 3
	auto y4 = transform(x, [](double x) { return (4*5) / (4+(5-4)*(exp(0.5*x))); }); // r = 0.5, T = 5, y_{0} = 3
	auto y5 = transform(x, [](double x) { return (6*5) / (6+(5-6)*(exp(0.5*x))); }); // r = 0.5, T = 5, y_{0} = 6
	auto y6 = transform(x, [](double x) { return (7*5) / (7+(5-7)*(exp(0.5*x))); }); // r = 0.5, T = 5, y_{0} = 7

	plot(x, y1);
	hold(on);
	plot(x, y2);
	plot(x, y3);
	plot(x, y4);
	plot(x, y5);
	plot(x, y6);
	hold(off);

	auto lgd = ::hamzstplot::legend({"y_{0} = 1", "y_{0} = 2", "y_{0} = 3","y_{0} = 4", "y_{0} = 6", "y_{0} = 7","Φ_{1} (t) = 0","Φ_{2} (t) = T"});
	lgd->location(legend::general_alignment::topright);
	lgd->box(false);

	title("A Critical Threshold with T=5, r = 0.5");
	xlabel("t");
	ylabel("y(t)");
	yrange({0, 10});
	line(0,0,3.14,0)->line_width(3).color({0.1f, 0.7f, 0.1f});
	line(0,5,3.14,5)->line_width(3).color({0.3f, 0.5f, 0.7f});
	
	show();
	return 0;
}