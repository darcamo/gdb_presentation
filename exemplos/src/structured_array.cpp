#include <algorithm>
#include <iostream>
#include <string>

struct Person {
  std::string name;
  int id;
};

int main(int argc, char *argv[]) {
  constexpr size_t N = 5;
  Person people[5];
  std::generate(std::begin(people), std::end(people), [i = 0]() mutable {
    return Person{"Name " + std::to_string(i), 10 * i++};
  });

  std::cout << people[0].name << std::endl;
  std::cout << people[1].name << std::endl;
  std::cout << people[2].name << std::endl;
  std::cout << people[3].name << std::endl;
  std::cout << people[4].name << std::endl;

  return 0;
}
