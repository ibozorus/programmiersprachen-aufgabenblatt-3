#include <iostream>

#include "math_templates.hpp"

int main() {
    std::cout << "Aufgabenblatt 3\n";
    std::cout << buw::square<int>(3) << std::endl;
    std::cout << buw::square(2.4) << std::endl;
    std::cout << buw::add(0, 3) << std::endl;
    std::cout << buw::add<double>(0.0, 3.0) << std::endl;
    std::cout << buw::add<std::string>("asd", "3.0") << std::endl;
    return 0;
}
