#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
	using namespace hamzstplot;

	auto x = linspace(0, 1.1*pi);
	//y(t) = (-K*T+K+T) / (1-exp((K*T*(-K*T*log((K*T-K-T+y0)/y0)/(-K*T+K+T) + K*log((K*T-K-T+y0)/y0)/(-K*T+K+T) + T*log((K*T-K-T+y0)/y0)/(-K*T+K+T) + r*x) - K*r*x - T*r*x)/(K*T)))
	// Better use IF THEN, because the explicit solution cannot plot it correctly.
	auto y1 = transform(x, [](double x) { 
		float r = 1 ;
		float T = 3 ;
		float K = 5 ;
		float y0 = 1 ;
		if (y0>T)
			return (y0*K) / (y0+(K-y0)*(exp(-r*x))); 
		else if(y0<T)
			return (y0*T) / (y0+(T-y0)*(exp(r*x))); 
		}); 
	auto y2 = transform(x, [](double x) { 
		float r = 1 ;
		float T = 3 ;
		float K = 5 ;
		float y0 = 2 ;
		if (y0>T)
			return (y0*K) / (y0+(K-y0)*(exp(-r*x))); 
		else if(y0<T)
			return (y0*T) / (y0+(T-y0)*(exp(r*x))); 
		}); 
	auto y3 = transform(x, [](double x) { 
		float r = 1 ;
		float T = 3 ;
		float K = 5 ;
		float y0 = 3.5 ;
		if (y0>T)
			return (y0*K) / (y0+(K-y0)*(exp(-r*x))); 
		else if(y0<T)
			return (y0*T) / (y0+(T-y0)*(exp(r*x))); 
		}); 
	auto y4 = transform(x, [](double x) { 
		float r = 1 ;
		float T = 3 ;
		float K = 5 ;
		float y0 = 4 ;
		if (y0>T)
			return (y0*K) / (y0+(K-y0)*(exp(-r*x))); 
		else if(y0<T)
			return (y0*T) / (y0+(T-y0)*(exp(r*x))); 
		}); 
	auto y5 = transform(x, [](double x) { 
		float r = 1 ;
		float T = 3 ;
		float K = 5 ;
		float y0 = 6 ;
		if (y0>T)
			{return (y0*K) / (y0+(K-y0)*(exp(-r*x)));} 
		else if(y0<T)
			{return (y0*T) / (y0+(T-y0)*(exp(r*x)));} 
		}); 
	auto y6 = transform(x, [](double x) { 
		float r = 1 ;
		float T = 3 ;
		float K = 5 ;
		float y0 = 7 ;
		if (y0>T)
			return (y0*K) / (y0+(K-y0)*(exp(-r*x))); 
		else if(y0<T)
			return (y0*T) / (y0+(T-y0)*(exp(r*x))); 
		}); 
	
	plot(x, y1);
	hold(on);
	plot(x, y2);
	plot(x, y3);
	plot(x, y4);
	plot(x, y5);
	plot(x, y6);
	hold(off);

	auto lgd = ::hamzstplot::legend({"y_{0} = 1", "y_{0} = 2", "y_{0} = 3.5","y_{0} = 4", "y_{0} = 6", "y_{0} = 7","Φ_{1} (t) = 0","Φ_{2} (t) = K","Φ_{3} (t) = T"});
	lgd->location(legend::general_alignment::topright);
	lgd->box(false);

	title("Logistic Growth with a Threshold with T=3, K = 5, r = 1");
	xlabel("t");
	ylabel("y(t)");
	xrange({0, 3});
	yrange({0, 10});
	line(0,0,99,0)->line_width(3).color({0.1f, 0.7f, 0.1f});
	line(0,5,99,5)->line_width(3).color({0.3f, 0.5f, 0.7f});
	line(0,3,99,3)->line_width(3).color({0.6f, 0.1f, 0.1f});
	
	show();
	return 0;
}