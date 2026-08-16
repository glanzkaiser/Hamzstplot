#include <cmath>
#include <hamzstplot/hamzstplot.h>

double factorial(int n) {
	if (n <= 1) 
	{
		return 1;
	}
	double result = 1;
	for (int i = 2; i <= n; ++i) 
	{
		result *= i;
	}
	return result;
}
int main() {
	using namespace hamzstplot;

	std::vector<double> x = linspace(-4, 7, 150);
	std::vector<double> y = transform(x, [](auto x) { return 1; });
	
	std::vector<double> y1 = transform(x, [](auto x) { 	
	
	return x; });
	std::vector<double> y2 = transform(x, [](auto x) { 
	double He_prev = 1;
	double He_current = x;
	double He_next = 0;
	int n = 2;
	for (int i = 2; i <= n ; ++i)
	{
		He_next = (x*He_current)- ((i-1)*He_prev);
		He_prev = He_current;
		He_current = He_next;
	}	
	return He_next; });
	std::vector<double> y3 = transform(x, [](auto x) { 
	double He_prev = 1;
	double He_current = x;
	double He_next = 0;
	int n = 3;
	for (int i = 2; i <= n ; ++i)
	{
		He_next = (x*He_current)- ((i-1)*He_prev);
		He_prev = He_current;
		He_current = He_next;
	}	
	return He_next; });
	std::vector<double> y4 = transform(x, [](auto x) { 
	double He_prev = 1;
	double He_current = x;
	double He_next = 0;
	int n = 4;
	for (int i = 2; i <= n ; ++i)
	{
		He_next = (x*He_current)- ((i-1)*He_prev);
		He_prev = He_current;
		He_current = He_next;
	}	
	return He_next; });
	std::vector<double> y5 = transform(x, [](auto x) { 
	double He_prev = 1;
	double He_current = x;
	double He_next = 0;
	int n = 5;
	for (int i = 2; i <= n ; ++i)
	{
		He_next = (x*He_current)- ((i-1)*He_prev);
		He_prev = He_current;
		He_current = He_next;
	}	
	return He_next; });
	
	plot(x, y)->line_width(1).color({0.1f, 0.7f, 0.9f}).line_style("--");
	hold(on);
	plot(x, y1)->line_width(1).color({0.33f, 0.51f, 0.5f});
	plot(x, y2)->line_width(1).color({0.51f, 0.25f, 0.25f}).line_style("--");;
	plot(x, y3)->line_width(1).color({0.9f, 0.15f, 0.05f});
	plot(x, y4)->line_width(1).color({0.1f, 0.15f, 0.05f});
	plot(x, y5)->line_width(1).color({0.51f, 0.51f, 0.90f}) ;
	hold(off);
	auto lgd = ::hamzstplot::legend({"n=0","n=1", "n=2", "n=3", "n=4","n=5"});
	lgd->location(legend::general_alignment::topright);
	lgd->box(false);
	title("Probabilist's Hermite polynomials");
	xlabel("x");
	ylabel("He_{n}(x)");
	yrange({-10, 20});
	show();
	return 0;
}