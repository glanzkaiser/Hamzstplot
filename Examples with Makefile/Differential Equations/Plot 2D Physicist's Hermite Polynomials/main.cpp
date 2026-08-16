#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	std::vector<double> x = linspace(-4, 6, 150);
	std::vector<double> y = transform(x, [](auto x) { return 1; });
	
	std::vector<double> y1 = transform(x, [](auto x) { 	
	
	return 2*x; });
	std::vector<double> y2 = transform(x, [](auto x) { 
	double H_prev = 1;
	double H_current = 2*x;
	double H_next = 0;
	int n = 2;
	for (int i = 2; i <= n ; ++i)
	{
		H_next = (2*x*H_current)- (2*(i-1)*H_prev);
		H_prev = H_current;
		H_current = H_next;
	}	
	return H_next; });
	std::vector<double> y3 = transform(x, [](auto x) { 
	double H_prev = 1;
	double H_current = 2*x;
	double H_next = 0;
	int n = 3;
	for (int i = 2; i <= n ; ++i)
	{
		H_next = (2*x*H_current)- (2*(i-1)*H_prev);
		H_prev = H_current;
		H_current = H_next;
	}	
	return H_next; });
	std::vector<double> y4 = transform(x, [](auto x) { 
	double H_prev = 1;
	double H_current = 2*x;
	double H_next = 0;
	int n = 4;
	for (int i = 2; i <= n ; ++i)
	{
		H_next = (2*x*H_current)- (2*(i-1)*H_prev);
		H_prev = H_current;
		H_current = H_next;
	}	
	return H_next; });
	std::vector<double> y5 = transform(x, [](auto x) { 
	double H_prev = 1;
	double H_current = 2*x;
	double H_next = 0;
	int n = 5;
	for (int i = 2; i <= n ; ++i)
	{
		H_next = (2*x*H_current)- (2*(i-1)*H_prev);
		H_prev = H_current;
		H_current = H_next;
	}	
	return H_next; });
	
	plot(x, y)->line_width(2).color({0.1f, 0.7f, 0.9f}).line_style("--");
	hold(on);
	plot(x, y1)->line_width(2).color({0.33f, 0.51f, 0.5f});
	plot(x, y2)->line_width(2).color({0.51f, 0.95f, 0.25f});
	plot(x, y3)->line_width(2).color({0.9f, 0.15f, 0.05f});
	plot(x, y4)->line_width(2).color({0.1f, 0.15f, 0.05f});
	plot(x, y5)->line_width(2).color({0.51f, 0.51f, 0.90f}) ;
	hold(off);
	auto lgd = ::hamzstplot::legend({"n=0","n=1", "n=2", "n=3", "n=4","n=5"});
	lgd->location(legend::general_alignment::topright);
	lgd->box(false);
	title("Physicist's Hermite polynomials");
	xlabel("x");
	ylabel("H_{n}(x)");
	yrange({-40, 50});
	show();
	return 0;
}