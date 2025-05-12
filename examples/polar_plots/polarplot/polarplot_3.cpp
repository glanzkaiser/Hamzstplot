#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
    using namespace hamzstplot;

    std::vector<double> theta = linspace(0, 6 * pi);
    std::vector<double> rho1 = transform(theta, [](auto t) { return t / 10.; });
    polarplot(theta, rho1);

    std::vector<double> rho2 = transform(theta, [](auto t) { return t / 12.; });
    hold(on);
    polarplot(theta, rho2, "--");
    hold(off);

    show();
    return 0;
}