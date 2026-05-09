//
// std::array wird std::vector vorgezogen, falls die Größe des Elementcontainers zur Compile-Zeit bekannt ist und gleich bleiben wird.
// Da std::array im Stack und std::vector im Heap ist, sind die operationen bei array wesentlich schneller
//
#include <array>
#include <iostream>
#include <ostream>

int main(int argc, char* argv[]) {
  std::array<int, 10> int_arr{ 1, 3, 4, 5, 2, 6, 71, 2, 4, 5 };

  for (int element: int_arr) {
    std::cout << element << std::endl;
  }
}
