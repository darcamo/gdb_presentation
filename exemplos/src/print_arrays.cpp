#include <algorithm>
#include <armadillo>
#include <iostream>
#include <iterator>
#include <vector>

#if defined(ARMA_USE_EXTERN_CXX11_RNG)
namespace arma {
thread_local arma_rng_cxx11 arma_rng_cxx11_instance; // NOLINT
} // namespace arma
#endif

using namespace std::complex_literals;

int main() {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int* aPtr = a;

    int m[4][3] = {{1, 2, 3}, //
                   {4, 5, 6}, //
                   {7, 8, 9}, //
                   {10, 11, 12}};
    int* mPtr = &m[0][0];

    return 0;
}
