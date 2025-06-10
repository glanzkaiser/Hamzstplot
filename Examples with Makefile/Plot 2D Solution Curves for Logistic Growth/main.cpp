#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	auto x = linspace(0, 1.1*pi);
	//y(t) = y_{0} * k / (y_{0} + (K - y_{0})*e^{-rt})
	auto y1 = transform(x, [](double x) { return (1*5) / (1+(5-1)*(exp(-2*x))); }); // r = 2, K = 5, y_{0} = 1
	auto y2 = transform(x, [](double x) { return (2*5) / (2+(5-2)*(exp(-2*x))); }); // r = 2, K = 5, y_{0} = 2
	auto y3 = transform(x, [](double x) { return (3*5) / (3+(5-3)*(exp(-2*x))); }); // r = 2, K = 5, y_{0} = 3
	auto y4 = transform(x, [](double x) { return (6*5) / (6+(5-6)*(exp(-2*x))); }); // r = 2, K = 5, y_{0} = 6
	auto y5 = transform(x, [](double x) { return (7*5) / (7+(5-7)*(exp(-2*x))); }); // r = 2, K = 5, y_{0} = 7

	plot(x, y1);
	hold(on);
	plot(x, y2);
	plot(x, y3);
	plot(x, y4);
	plot(x, y5);
	hold(off);

	auto lgd = ::hamzstplot::legend({"y_{0} = 1", "y_{0} = 2", "y_{0} = 3","y_{0} = 6", "y_{0} = 7", "", "","Φ_{1} (t) = 0"});
	lgd->location(legend::general_alignment::bottomright);
	lgd->box(false);

	title("Logistic Growth with K=5, r = 2");
	xlabel("t");
	ylabel("y(t)");
	arrow(3,5,3,4.2)->color({0.1f, 0.7f, 0.9f});
	text(2.7, 3.7, "Φ_{2} (t) = K");
	line(0,0,3.14,0)->line_width(4);
	
	show();
	return 0;
}