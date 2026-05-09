//
// Created by ibo on 09.05.26.
//
#include <iostream>
#include <random>
#include <vector>

int main(int argc, char* argv[]) {
  std::vector<unsigned int> int_vec;
  std::mt19937 engine{ std::random_device{}() };
  std::uniform_int_distribution<unsigned int> dist{ 0, 99 };
  for (int i = 0; int_vec.size() < 300; ++i) {
    int_vec.push_back(dist(engine));
  }
  unsigned int sum = 0;
  for (unsigned int element: int_vec) {
    std::cout << element << std::endl;
    sum += element;
  }
  double average = static_cast<double>(sum) / static_cast<double>(int_vec.size());

  std::cout << "SUM: " << sum << std::endl;
  std::cout << "AVG: " << average << std::endl;

}
