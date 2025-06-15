#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	auto x = linspace(0, 1.1*pi);
	//y(t) = K*(E/r - 1) / (exp((E*x) + E*ln((E*K-K*r+r*y0)/(r*y0))/(E-r) - r*x -  r*ln((E*K-K*r+r*y0)/(r*y0))/(E-r) ) -1 )
	// y(t) = (K*(E/r - 1)) / (exp(E*x) * exp(-r*x) * ( pow((E/(E-r)),((E*K-K*r+r*y0)/(r*y0)) ) * ( pow((r/(E-r)),((E*K-K*r+r*y0)/(r*y0)) )  )
	auto y1 = transform(x, [](double x) { 
		float E = 4;
		float r = 5;
		float K = 3;
		float y0 = 1;
		return (K*(E/r - 1)) / (exp(E*x) * exp(-r*x) * pow((E/(E-r)),((E*K-K*r+r*y0)/(r*y0))) * pow((r/(E-r)),((E*K-K*r+r*y0)/(r*y0))) )  ; }); 
	auto y2 = transform(x, [](double x) { 
		float E = 1;
		float r = 2;
		float K = 3;
		float y0 = 1;
		return (K*(E/r - 1)) / (exp(E*x) * exp(-r*x) * pow((E/(E-r)),((E*K-K*r+r*y0)/(r*y0))) * pow((r/(E-r)),((E*K-K*r+r*y0)/(r*y0))) )  ; }); 
	auto y3 = transform(x, [](double x) { return (3*(1.5/5 - 1)) / (exp(1.5*x) * exp(-5*x) ) ; }); // K = 3, r = 5, E = 1.5, y_{0} = 1
	//auto y2 = transform(x, [](double x) { return 3*(1.5/5 - 1) / (exp((1.5*x) + 1.5*log((1.5*3-3*5+5*2)/(5*2))/(1.5-5) - 5*x -  5*log((1.5*3-3*5+5*2)/(5*2))/(1.5-5) ) -1 ) ; }); // K = 3, r = 5, E = 1.5, y_{0} = 2
//	auto y1 = transform(x, [](double x) { return 3*(1.5/5 - 1) / (exp((1.5*x) + 1.5*ln((1.5*3-3*5+5*y0)/(5*y0))/(1.5-5) - 5*x -  5*ln((1.5*3-3*5+5*y0)/(5*y0))/(1.5-5) ) -1 ) ; }); // K = 3, r = 5, E = 1.5, y_{0} = 1
	
	plot(x, y1);
	hold(on);
	plot(x, y2);
	plot(x, y3);
	//plot(x, y4);
	//plot(x, y5);
	//plot(x, y6);
	hold(off);

	auto lgd = ::hamzstplot::legend({"y_{0} = 1", "y_{0} = 2", "y_{0} = 3.5","y_{0} = 4", "y_{0} = 6", "y_{0} = 7","Φ_{1} (t) = 0","Φ_{2} (t) = K","Φ_{3} (t) = T"});
	lgd->location(legend::general_alignment::topright);
	lgd->box(false);

	title("Logistic Growth with a Threshold with T=3, K = 5, r = 1");
	xlabel("t");
	ylabel("y(t)");
	xrange({-30, 30});
	yrange({-100, 1000});
	line(0,0,99,0)->line_width(3).color({0.1f, 0.7f, 0.1f});
	line(0,5,99,5)->line_width(3).color({0.3f, 0.5f, 0.7f});
	line(0,3,99,3)->line_width(3).color({0.6f, 0.1f, 0.1f});
	
	show();
	return 0;
}