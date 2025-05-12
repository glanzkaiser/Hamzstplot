#include <cmath>
#include <hamzstplot/hamzstplot.h>

int main() {
    using namespace hamzstplot;

    fplot("cos(x)", "o-r")->line_width(2);
    hold(on);
    fplot([](double x) { return sin(x); }, std::array<double, 2>{-10, 10},
          "x--b")
        ->line_width(2);

    show();
    return 0;
}