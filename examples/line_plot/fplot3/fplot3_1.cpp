#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
    using namespace hamzstplot;

    auto xt = [](double t) { return sin(t); };
    auto yt = [](double t) { return cos(t); };
    auto zt = [](double t) { return t; };
    fplot3(xt, yt, zt);

    show();
    return 0;
}