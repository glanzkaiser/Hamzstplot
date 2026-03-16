#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	//auto x = linspace(0, 1, 500);
	std::vector<double> x = linspace(0, 2, 500);

	auto y1 = transform(x, [](double x) { 
	double gamma = 1;
	return 1/sqrt(pow(1-(x*x),2) + gamma*pow(x,2)); }); 
	auto y2 = transform(x, [](double x) { 
	double gamma = 0.5;
	return 1/sqrt(pow(1-(x*x),2) + gamma*pow(x,2)); }); 
	auto y3 = transform(x, [](double x) { 
	double gamma = 0.1;
	return 1/sqrt(pow(1-(x*x),2) + gamma*pow(x,2)); }); 
	auto y4 = transform(x, [](double x) { 
	double gamma = 0.015625;
	return 1/sqrt(pow(1-(x*x),2) + gamma*pow(x,2)); }); 
	auto y5 = transform(x, [](double x) { 
	double gamma = 0;
	return 1/sqrt(pow(1-(x*x),2) + gamma*pow(x,2)); }); 
		
	plot(x, y1)->line_width(2).color({0.1f, 0.7f, 0.1f});
	hold(on);
	plot(x, y2)->line_width(2).color({0.83f, 0.14f, 0.14f});
	plot(x, y3)->line_width(2).color({0.3f, 0.5f, 0.7f});
	plot(x, y4)->line_width(2).color({0.5f, 0.2f, 0.6f});
	plot(x, y5)->line_width(2).color({0.7f, 0.65f, 0.7f});
	hold(off);

	auto lgd = ::hamzstplot::legend({"Γ = 1", "Γ = 0.5", "Γ = 0.1", "Γ = 0.015625",  "Γ = 0"});
	lgd->location(legend::general_alignment::topright);
	lgd->box(false);

	title("Forced Vibration with Damping");
	xlabel("ω/ω_{0}");
	ylabel("Rk/F_{0}");
	xrange({0, 2});
	yrange({0, 10});
	
	show();
	return 0;
}