#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	//auto x = linspace(0, 1, 500);
	std::vector<double> x = linspace(0, 10, 500);

	auto y1 = transform(x, [](double x) { 
	double gamma = 1;
	return 8/sqrt(16*pow(x,4) - 63*pow(x,2) +64); }); 

		
	plot(x, y1)->line_width(2).color({0.1f, 0.7f, 0.1f});

	title("Forced Vibration with Damping, A(ω) = 8/(16ω^{4}  - 63 ω^{2} + 64)^{1/2}");
	xlabel("ω");
	ylabel("A");
	xrange({0, 10});
	yrange({0, 6.5});
	
	show();
	return 0;
}