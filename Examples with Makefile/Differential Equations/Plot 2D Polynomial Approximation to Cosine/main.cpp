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

	std::vector<double> x = linspace(0, 10, 150);
	std::vector<double> y = transform(x, [](auto x) { return cos(x); });
	
	std::vector<double> y1 = transform(x, [](auto x) { 
	double f = 0;
	int n = 1;
	for (int i = 0; i <= 1 ; ++i)
	{
		f += (pow(-1,i)/(factorial(2*i)))*pow(x,2*i) ;
	}	
	return f; });
	std::vector<double> y2 = transform(x, [](auto x) { 
	double f = 0;
	int n = 2;
	for (int i = 0; i <= n ; ++i)
	{
		f += (pow(-1,i)/(factorial(2*i)))*pow(x,2*i) ;
	}	
	return f; });
	std::vector<double> y3 = transform(x, [](auto x) { 
	double f = 0;
	int n = 3;
	for (int i = 0; i <= n ; ++i)
	{
		f += (pow(-1,i)/(factorial(2*i)))*pow(x,2*i) ;
	}	
	return f; });
	std::vector<double> y4 = transform(x, [](auto x) { 
	double f = 0;
	int n = 4;
	for (int i = 0; i <= n ; ++i)
	{
		f += (pow(-1,i)/(factorial(2*i)))*pow(x,2*i) ;
	}	
	return f; });
	std::vector<double> y5 = transform(x, [](auto x) { 
	double f = 0;
	int n = 5;
	for (int i = 0; i <= n ; ++i)
	{
		f += (pow(-1,i)/(factorial(2*i)))*pow(x,2*i) ;
	}	
	return f; });
	std::vector<double> y6 = transform(x, [](auto x) { 
	double f = 0;
	int n = 6;
	for (int i = 0; i <= n ; ++i)
	{
		f += (pow(-1,i)/(factorial(2*i)))*pow(x,2*i) ;
	}	
	return f; });
	std::vector<double> y7 = transform(x, [](auto x) { 
	double f = 0;
	int n = 7;
	for (int i = 0; i <= n ; ++i)
	{
		f += (pow(-1,i)/(factorial(2*i)))*pow(x,2*i) ;
	}	
	return f; });
	std::vector<double> y8 = transform(x, [](auto x) { 
	double f = 0;
	int n = 8;
	for (int i = 0; i <= n ; ++i)
	{
		f += (pow(-1,i)/(factorial(2*i)))*pow(x,2*i) ;
	}	
	return f; });
	std::vector<double> y9 = transform(x, [](auto x) { 
	double f = 0;
	int n = 9;
	for (int i = 0; i <= n ; ++i)
	{
		f += (pow(-1,i)/(factorial(2*i)))*pow(x,2*i) ;
	}	
	return f; });
	std::vector<double> y10 = transform(x, [](auto x) { 
	double f = 0;
	int n = 10;
	for (int i = 0; i <= n ; ++i)
	{
		f += (pow(-1,i)/(factorial(2*i)))*pow(x,2*i) ;
	}	
	return f; });
	plot(x, y)->line_width(2).color({0.1f, 0.7f, 0.9f});
	hold(on);
	plot(x, y1)->line_width(1).color({0.1f, 0.5f, 0.5f}) .line_style("--");
	plot(x, y2)->line_width(1).color({0.1f, 0.5f, 0.5f}) .line_style("--");
	plot(x, y3)->line_width(1).color({0.1f, 0.5f, 0.5f}) .line_style("--");
	plot(x, y4)->line_width(1).color({0.1f, 0.5f, 0.5f}) .line_style("--");
	plot(x, y5)->line_width(1).color({0.1f, 0.5f, 0.5f}) .line_style("--");
	plot(x, y6)->line_width(1).color({0.1f, 0.5f, 0.5f}) .line_style("--");
	plot(x, y7)->line_width(1).color({0.1f, 0.5f, 0.5f}) .line_style("--");
	plot(x, y8)->line_width(1).color({0.1f, 0.5f, 0.5f}) .line_style("--");
	plot(x, y9)->line_width(1).color({0.1f, 0.5f, 0.5f}) .line_style("--");
	plot(x, y10)->line_width(1).color({0.1f, 0.5f, 0.5f}) .line_style("--");
	text(3.7, 1.82, "n = 4");
	text(5, 1.82, "n = 8");
	text(6.2, 1.82, "n = 12");
	text(7.95, 1.82, "n = 16");
	text(9.6, 1.82, "n = 20");
	text(2.4, -1.82, "n = 2");
	text(4, -1.82, "n = 6");
	text(5.9, -1.82, "n = 10");
	text(7.3, -1.82, "n = 14");
	text(8.5, -1.82, "n = 18");
	hold(off);
	//auto lgd = ::hamzstplot::legend({"cos x", "n=2", "n=4", "n=6","n=8", "n=10", "n=12","n=14", "n=16", "n=18", "n=20"});
	//lgd->location(legend::general_alignment::topright);
	//lgd->box(false);
	title("Polynomial approximation to cos x");
	xlabel("x");
	ylabel("y");
	yrange({-2, 2});
	show();
	return 0;
}