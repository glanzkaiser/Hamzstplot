#include <cmath>
#include <hamzstplot/hamzstplot.h>

using namespace std;

int main() {
	using namespace hamzstplot;
	
	std::vector<double> t = linspace(0, 2 * pi);
	std::vector<double> y1 = transform(t, [](auto t) { return 900 + 1*exp(0.5*t); });
	std::vector<double> y2 = transform(t, [](auto t) { return 900 + 2*exp(0.5*t); });
	std::vector<double> y3 = transform(t, [](auto t) { return 900 + 3*exp(0.5*t); });
	std::vector<double> y4 = transform(t, [](auto t) { return 900 + -1*exp(0.5*t); });
	std::vector<double> y5 = transform(t, [](auto t) { return 900 + -2*exp(0.5*t); });
	std::vector<double> y6 = transform(t, [](auto t) { return 900 + -3*exp(0.5*t); });
	
	plot(t, y1, t, y2, t, y3, t, y4, "-", t, y5,"-", t,y6, "-");
	title("Population of Field Mice");
	xlabel("t");
	ylabel("p(t)");
	show();
	return 0;
}