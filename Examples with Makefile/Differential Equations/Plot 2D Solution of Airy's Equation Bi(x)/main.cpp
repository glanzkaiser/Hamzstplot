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

	std::vector<double> x = linspace(-10, 3, 150);
	std::vector<double> y = transform(x, [](auto x) { 
	double Ai = 0;
	int n = 50;
	double prod=1;
	for (int i = 1; i <= n ; ++i)
	{	
		prod *= 3*i+1;
		Ai += pow(x,3*i+1)/(pow(3,i)*factorial(i)*prod);
	}	
	return x + Ai; });
	
	std::vector<double> y1 = transform(x, [](auto x) { 	
	double Ai = 0;
	int n = 7;
	double prod = 1;
	for (int i = 1; i <= n ; ++i)
	{	
		prod *= 3*i+1;
		Ai += pow(x,3*i+1)/(pow(3,i)*factorial(i)*prod);
	}	
	return x + Ai; });
	std::vector<double> y2 = transform(x, [](auto x) { 	
	double Ai = 0;
	int n = 17;
	double prod = 1;
	for (int i = 1; i <= n ; ++i)
	{	
		prod *= 3*i+1;
		Ai += pow(x,3*i+1)/(pow(3,i)*factorial(i)*prod);
	}	
	return x + Ai; });
	std::vector<double> y3 = transform(x, [](auto x) { 	
	double Ai = 0;
	int n = 23;
	double prod = 1;
	for (int i = 1; i <= n ; ++i)
	{	
		prod *= 3*i+1;
		Ai += pow(x,3*i+1)/(pow(3,i)*factorial(i)*prod);
	}	
	return x + Ai; });
	std::vector<double> y4 = transform(x, [](auto x) { 	
	double Ai = 0;
	int n = 4;
	double prod = 1;
	for (int i = 1; i <= n ; ++i)
	{	
		prod *= 3*i+1;
		Ai += pow(x,3*i+1)/(pow(3,i)*factorial(i)*prod);
	}	
	return x + Ai; });	
	std::vector<double> y5 = transform(x, [](auto x) { 	
	double Ai = 0;
	int n = 10;
	double prod = 1;
	for (int i = 1; i <= n ; ++i)
	{	
		prod *= 3*i+1;
		Ai += pow(x,3*i+1)/(pow(3,i)*factorial(i)*prod);
	}	
	return x + Ai; });
	std::vector<double> y6 = transform(x, [](auto x) { 
	double Ai = 0;
	int n = 20;
	double prod = 1;
	for (int i = 1; i <= n ; ++i)
	{	
		prod *= 3*i+1;
		Ai += pow(x,3*i+1)/(pow(3,i)*factorial(i)*prod);
	}	
	return x + Ai; });
	
	plot(x, y)->line_width(2).color({0.1f, 0.7f, 0.9f}).line_style("--");
	hold(on);
	plot(x, y1)->line_width(2).color({0.9f, 0.15f, 0.05f});
	plot(x, y2)->line_width(2).color({0.1f, 0.15f, 0.05f});
	plot(x, y3)->line_width(2).color({0.51f, 0.51f, 0.85f});
	plot(x, y4)->line_width(2).color({0.1f, 0.15f, 0.90f}).line_style("-:");
	plot(x, y5)->line_width(2).color({0.9f, 0.5f, 0.05f}).line_style("-:");
	plot(x, y6)->line_width(2).color({0.6f, 0.25f, 0.55f}).line_style("-:");
	
	hold(off);
	auto lgd = ::hamzstplot::legend({"n=50","n=7","n=17", "n=23", "n=4", "n=10", "n=20"});
	lgd->location(legend::general_alignment::topright);
	lgd->box(false);
	title("Polynomial approximations to the solution y_{2}(x) of Airy's equation");
	xlabel("x");
	ylabel("y");
	yrange({-2, 2});
	show();
	return 0;
}