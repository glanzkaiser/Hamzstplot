#include <cmath>
#include <hamzstplot/hamzstplot.h>
#define pi  3.1415926535897

int main() {
	using namespace hamzstplot;

	//auto x = linspace(0, 1, 500);
	std::vector<double> x0 = linspace(0, 1, 100);
	std::vector<double> x = linspace(1, 5, 100);

	auto y01 = transform(x0, [](double x0) { 
	double Gamma = 0.015625;
	return atan(2*Gamma*x0/(1-pow(x0,2))) ; }); 
	auto y1 = transform(x, [](double x) { 
	double Gamma = 0.015625;
	return atan(2*Gamma*x/(1-pow(x,2))) + pi; }); 
	auto y02 = transform(x0, [](double x0) { 
	double Gamma = 0.1;
	return atan(2*Gamma*x0/(1-pow(x0,2))) ; }); 
	auto y2 = transform(x, [](double x) { 
	double Gamma = 0.1;
	return atan(2*Gamma*x/(1-pow(x,2))) + pi; }); 
	auto y03 = transform(x0, [](double x0) { 
	double Gamma = 0.5;
	return atan(2*Gamma*x0/(1-pow(x0,2))) ; }); 
	auto y3 = transform(x, [](double x) { 
	double Gamma = 0.5;
	return atan(2*Gamma*x/(1-pow(x,2))) + pi; }); 
	auto y04 = transform(x0, [](double x0) { 
	double Gamma = 1;
	return atan(2*Gamma*x0/(1-pow(x0,2))) ; }); 
	auto y4 = transform(x, [](double x) { 
	double Gamma = 1;
	return atan(2*Gamma*x/(1-pow(x,2))) + pi; }); 
	auto y05 = transform(x0, [](double x0) {
	double Gamma = 2;
	return atan(2*Gamma*x0/(1-pow(x0,2))) ; }); 
	auto y5 = transform(x, [](double x) {
	double Gamma = 2;
	return atan(2*Gamma*x/(1-pow(x,2))) + pi; }); 
		
	plot(x0, y01)->line_width(2).color({0.1f, 0.7f, 0.1f});
	hold(on);
	plot(x0, y02)->line_width(2).color({0.83f, 0.14f, 0.14f});
	plot(x0, y03)->line_width(2).color({0.3f, 0.5f, 0.7f});
	plot(x0, y04)->line_width(2).color({0.5f, 0.2f, 0.6f});
	plot(x0, y05)->line_width(2).color({0.7f, 0.65f, 0.7f});
	plot(x, y1)->line_width(2).color({0.1f, 0.7f, 0.1f});
	plot(x, y2)->line_width(2).color({0.83f, 0.14f, 0.14f});
	plot(x, y3)->line_width(2).color({0.3f, 0.5f, 0.7f});
	plot(x, y4)->line_width(2).color({0.5f, 0.2f, 0.6f});
	plot(x, y5)->line_width(2).color({0.7f, 0.65f, 0.7f});
	hold(off);

	auto lgd = ::hamzstplot::legend({"Γ = 0.015625", "", "Γ = 0.1", "Γ = 0.5", "Γ = 1",  "Γ = 2"});
	lgd->location(legend::general_alignment::topright);
	lgd->box(false);

	title("Forced Vibration with Damping");
	xlabel("ω/ω_{0}");
	ylabel("𝛿");
	xrange({0, 5});
	yrange({0, 5});
	
	show();
	return 0;
}