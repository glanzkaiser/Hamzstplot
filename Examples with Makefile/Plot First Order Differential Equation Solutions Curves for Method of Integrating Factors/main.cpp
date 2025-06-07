#include <cmath>
#include <hamzstplot/hamzstplot.h>

using namespace std;

int main() {
	using namespace hamzstplot;
	
	vector_2d newcolors = {{0.83, 0.14, 0.14},
						{1.00, 0.54, 0.00},
						{0.10, 0.6, 0.70},
						{0.47, 0.25, 0.80},
						{0.50, 0.2, 0.60},
						{0.25, 0.80, 0.54}};
	colororder(newcolors);

	std::vector<double> t = linspace(-2 * pi, 2 * pi);
	std::vector<double> y1 = transform(t, [](auto t) { return pow(t,2) + 0.1/(pow(t,2)); });
	std::vector<double> y2 = transform(t, [](auto t) { return pow(t,2) + 0.23/(pow(t,2)); });
	std::vector<double> y3 = transform(t, [](auto t) { return pow(t,2) + 0.5/(pow(t,2)); });
	std::vector<double> y4 = transform(t, [](auto t) { return pow(t,2) + 1/(pow(t,2)); });
	std::vector<double> y5 = transform(t, [](auto t) { return pow(t,2) + 2/(pow(t,2)); });
	std::vector<double> y6 = transform(t, [](auto t) { return pow(t,2) + -1/(pow(t,2)); });
	std::vector<double> y7 = transform(t, [](auto t) { return pow(t,2) + -2/(pow(t,2)); });
	std::vector<double> y8 = transform(t, [](auto t) { return pow(t,2) + -3/(pow(t,2)); });
	std::vector<double> y9 = transform(t, [](auto t) { return pow(t,2) + -4/(pow(t,2)); });
	std::vector<double> y10 = transform(t, [](auto t) { return pow(t,2) + -5/(pow(t,2)); });
	std::vector<double> y11 = transform(t, [](auto t) { return pow(t,2); });
	
//	plot(t, y1, t, y2, t, y3, t, y4, "-", t, y5,"-", t,y6, "-", t,y7, "-", t,y8, "-", t,y9, "-", t,y10, "-", t,y11, "-",x, y4, "o");
//	plot(x, y4, "o")->marker_indices({1});
	std::vector<double> x_point = transform(x, [](double x) { return 1; });
	std::vector<double> y_point = transform(x, [](double x) { return 2; });
	
	plot(t, y1)->line_width(2);
	hold(on);
	plot(t, y2)->line_width(2);
	plot(t, y3)->line_width(2);
	plot(t, y4)->line_width(2);
	plot(t, y5)->line_width(2);
	plot(t, y6)->line_width(2);
	plot(t, y7)->line_width(2);
	plot(t, y8)->line_width(2);
	plot(t, y9)->line_width(2);
	plot(t, y10)->line_width(2);
	plot(t, y11)->line_width(2);
	plot(x_point, y_point, "o"); // How to plot a point
	
	hold(off);
	axis({-2, 2, -1, 3});
	title("ty' + 2y = 4t^2");
	xlabel("t");
	ylabel("y(t)");
	show();
	return 0;
}