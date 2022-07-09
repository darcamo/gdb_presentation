#include <ctime>
#include <stdexcept>
#include <iostream>


double computeInverse(double value) {
    if (value == 0) throw std::runtime_error("Value cannot be zero");
    return 1.0 / value;
}

int main() {
    srand(time(NULL));

    constexpr unsigned int arraySize = 20;
    int array[arraySize];

    for(unsigned int i = 0; i < arraySize; i++) {
        auto denominator = rand() % 200;
        array[i]         = computeInverse(denominator);
    }

    std::cout << "Fim" << std::endl;
    return 0;
}
