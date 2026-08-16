#include <cmath>
#include <hamzstplot/hamzstplot.h>
#include "symintegrationc++.h"

int main() {
	using namespace hamzstplot;

	std::vector<double> x = linspace(-2, 10, 150);
	std::vector<double> y = transform(x, [](auto x) { return 4*exp(-x) - 3*exp(-2*x); });
	
	std::vector<double> y1 = transform(x, [](auto x) { 	
	double y0 = 1.0;
	double dy0 = 2.0;
	double p = 3.0;
	double q = 2.0;
	int n = 8;
	// Class from SymIntegration to compute power series solution for homogeneous second order linear differential equations
	SecondOrderLinearDiffEq_Homogeneous_SeriesSolution solver(y0, dy0, p, q); 
	
	vector<double> v = solver.coefficientsvector(n);
	
	double f = 0;
	for (int  i = 0; i < n; ++i)
	{
		f += pow(x,i)*v[i];
	}
	return f; });
	
	std::vector<double> y2 = transform(x, [](auto x) { 	
	
	double y0 = 1.0;
	double dy0 = 2.0;
	double p = 3.0;
	double q = 2.0;
	int n = 12;
	// Class from SymIntegration to compute power series solution for homogeneous second order linear differential equations
	SecondOrderLinearDiffEq_Homogeneous_SeriesSolution solver(y0, dy0, p, q); 
	
	vector<double> v = solver.coefficientsvector(n);
	
	double f = 0;
	for (int  i = 0; i < n; ++i)
	{
		f += pow(x,i)*v[i];
	}
	return f; });
	
	std::vector<double> y3 = transform(x, [](auto x) { 	
	
	double y0 = 1.0;
	double dy0 = 2.0;
	double p = 3.0;
	double q = 2.0;
	int n = 16;
	// Class from SymIntegration to compute power series solution for homogeneous second order linear differential equations
	SecondOrderLinearDiffEq_Homogeneous_SeriesSolution solver(y0, dy0, p, q); 
	
	vector<double> v = solver.coefficientsvector(n);
	
	double f = 0;
	for (int  i = 0; i < n; ++i)
	{
		f += pow(x,i)*v[i];
	}
	return f; });

	std::vector<double> y4 = transform(x, [](auto x) { 	
	
	double y0 = 1.0;
	double dy0 = 2.0;
	double p = 3.0;
	double q = 2.0;
	int n = 20;
	// Class from SymIntegration to compute power series solution for homogeneous second order linear differential equations
	SecondOrderLinearDiffEq_Homogeneous_SeriesSolution solver(y0, dy0, p, q); 
	
	vector<double> v = solver.coefficientsvector(n);
	
	double f = 0;
	for (int  i = 0; i < n; ++i)
	{
		f += pow(x,i)*v[i];
	}
	return f; });
	
	std::vector<double> y5 = transform(x, [](auto x) { 	
	
	double y0 = 1.0;
	double dy0 = 2.0;
	double p = 3.0;
	double q = 2.0;
	int n = 30;
	// Class from SymIntegration to compute power series solution for homogeneous second order linear differential equations
	SecondOrderLinearDiffEq_Homogeneous_SeriesSolution solver(y0, dy0, p, q); 
	
	vector<double> v = solver.coefficientsvector(n);
	
	double f = 0;
	for (int  i = 0; i < n; ++i)
	{
		f += pow(x,i)*v[i];
	}
	return f; });


	plot(x, y)->line_width(2).color({0.1f, 0.7f, 0.9f});
	hold(on);
	plot(x, y1)->line_width(2).color({0.33f, 0.51f, 0.5f}).line_style("--");
	plot(x, y2)->line_width(2).color({0.51f, 0.95f, 0.25f}).line_style("--");
	plot(x, y3)->line_width(2).color({0.9f, 0.15f, 0.05f}).line_style("--");
	plot(x, y4)->line_width(2).color({0.1f, 0.15f, 0.05f}).line_style("--");
	plot(x, y5)->line_width(2).color({0.51f, 0.51f, 0.90f}).line_style("--");
	hold(off);
	auto lgd = ::hamzstplot::legend({"Exact","Series, n=8", "Series, n=12", "Series, n=16", "Series, n=20", "Series, n=30"});
	lgd->location(legend::general_alignment::topright);
	lgd->box(false);
	title("Homogeneous Second Order Linear Differential Equation Solutions");
	xlabel("x");
	ylabel("y(x)");
	yrange({-10, 10});
	show();
	return 0;
}