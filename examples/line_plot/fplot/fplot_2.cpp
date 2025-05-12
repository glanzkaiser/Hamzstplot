#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
    using namespace hamzstplot;

    fplot([](double t) { return cos(3 * t); },
          [](double t) { return sin(2 * t); });

    show();
    return 0;
}