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

void print_array(const auto &a, std::string_view name = "") {
  if (name.size() != 0)
    std::cout << name << "\n";
  std::ranges::copy(a, std::ostream_iterator<decltype(a[0])>(std::cout, ","));
  std::cout << "\n";
}

void print_matrix(const auto &m, std::string_view name = "") {
  if (name.size() != 0)
    std::cout << name << "\n";
  for (const auto &line : m) {
    std::ranges::copy(line,
                      std::ostream_iterator<decltype(line[0])>(std::cout, ","));
    std::cout << "\n";
  }
}

int main() {
  int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int* aPtr = a;

  int m[4][3] = {{1, 2, 3}, //
                 {4, 5, 6}, //
                 {7, 8, 9}, //
                 {10, 11, 12}};
  int* mPtr = &m[0][0];

  arma::umat m2{{1, 2, 3}, //
                {4, 5, 6}, //
                {7, 8, 9}, //
                {10, 11, 12}};

  arma::mat m3{{1.1, 2.2, 3}, //
               {4, 5, 6},     //
               {7, 8, 9},     //
               {10, 11, 12},  //
               {13, 14, 15},  //
               {16, 17, 18}};
  arma::cx_mat m4{{1.1 - 1.1j, 2.2 - 7.7j, 3},
                  {4, 5, 6},
                  {7, 8, 9},
                  {10, 11, 12},
                  {13, 14, 15},
                  {16, 17, 18}};

  print_array(a, "a");
  print_matrix(m, "m");
  m2.print("m2");
  m2.print("m3");
  m2.print("m4");

  // Add a breakpoint below, load the pretty printers and then try to print the
  // variables
  std::cout << "The End" << std::endl;
  return 0;
}
