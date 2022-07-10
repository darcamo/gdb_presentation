#include <armadillo>
#include <cmath>
#include <complex>
#include <iterator>
#include <tuple>

using namespace std::complex_literals;

auto calcRandomPointsInsideCircle(unsigned int numPoints, double maxRadius) {
    std::default_random_engine generator;
    std::uniform_real_distribution<double> radiusDistribution(0.0, maxRadius);
    std::uniform_real_distribution<double> angleDistribution(0.0, 2 * M_PI);

    std::vector<std::complex<double>> points;
    points.reserve(numPoints);

    std::generate_n(std::back_inserter(points), numPoints, [&]() -> std::complex<double> {
        auto radius = radiusDistribution(generator);
        auto angle  = angleDistribution(generator);
        return radius * std::exp(std::complex<double>(0, -angle));
    });

    return points;
}

int main(int argc, char *argv[]) {
    auto points = calcRandomPointsInsideCircle(1500, 10);

    return 0;
}
