#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest.h>

#include "math_templates.hpp"
#include "stack.hpp"

int factorial(int n) {
  int result = 1;
  for (int i = 2; i <= n; ++i) {
    result *= i;
  }
  return result;
}

TEST_CASE("factorial computes n!") {
  CHECK(factorial(0) == 1);
  CHECK(factorial(1) == 1);
  CHECK(factorial(5) == 120);
  CHECK(factorial(10) == 3628800);
}

TEST_CASE("buw::square()") {
  auto r = buw::square(3);
  SUBCASE("integer") {
    CHECK(buw::square<int>(0) == 0);
    CHECK(buw::square<int>(3) == 9);
    CHECK(buw::square<int>(-3) == 9);
    CHECK(r == 9);
  }
  SUBCASE("double") {
    CHECK(buw::square<double>(0) == doctest::Approx(0));
    CHECK(buw::square<double>(3.0) == doctest::Approx(9));
    CHECK(buw::square<double>(-3.0) == doctest::Approx(9));
  }
}

TEST_CASE("buw::add()") {
  SUBCASE("integer") {
    CHECK(buw::add<int>(-3, 3) == 0);
    CHECK(buw::add<int>(3, 6) == 9);
    CHECK(buw::add<int>(-3, 12) == 9);
  }
  SUBCASE("double") {
    CHECK(buw::add<double>(0.0, -0.0) == doctest::Approx(0));
    CHECK(buw::add<double>(3.0, 6.0) == doctest::Approx(9));
    CHECK(buw::add<double>(-2.5, 11.5) == doctest::Approx(9));
  }
}

TEST_CASE("buw::Stack") {
  buw::Stack<int> int_stack;
  buw::Stack<std::string> string_stack;
  buw::Stack<float> float_stack;
  SUBCASE("New stack empty") {
    CHECK(int_stack.empty() == true);
    CHECK(int_stack.size() == 0);
    CHECK(string_stack.empty() == true);
    CHECK(string_stack.size() == 0);
    CHECK(float_stack.empty() == true);
    CHECK(float_stack.size() == 0);


    CHECK_NOTHROW(int_stack.pop());
    CHECK_NOTHROW(float_stack.pop());
    CHECK_NOTHROW(string_stack.pop());
  }
  SUBCASE("buw::Stack.top()") {
    int_stack.push(42);
    int_stack.push(24);
    int_stack.push(57);

    float_stack.push(42.2f);
    float_stack.push(24.6f);
    float_stack.push(57.1f);

    string_stack.push("String 1");
    string_stack.push("String 2");
    string_stack.push("String 3");

    CHECK(int_stack.top() == 57);
    CHECK(float_stack.top() == doctest::Approx(57.1f));
    CHECK(string_stack.top() == "String 3");

  }
  SUBCASE("buw::Stack.pop()") {
    int_stack.push(42);
    int_stack.push(24);
    int_stack.push(57);

    float_stack.push(42.2f);
    float_stack.push(24.6f);
    float_stack.push(57.1f);

    string_stack.push("String 1");
    string_stack.push("String 2");
    string_stack.push("String 3");

    int_stack.pop();

    float_stack.pop();
    float_stack.pop();

    string_stack.pop();
    string_stack.pop();
    string_stack.pop();

    CHECK(int_stack.size() == 2);
    CHECK(float_stack.size() == 1);
    CHECK(string_stack.size() == 0);

    CHECK(int_stack.top() == 24);
    CHECK(float_stack.top() == doctest::Approx(42.2f));
    CHECK_THROWS_AS(string_stack.top(), std::out_of_range);

  }
  SUBCASE("buw::Stack.pop() on empty does nothing") {
    CHECK_NOTHROW(int_stack.pop());
    CHECK(int_stack.empty() == true);
  }
}

int main(int argc, char* argv[]) {
  doctest::Context ctx;
  ctx.applyCommandLine(argc, argv);
  return ctx.run();
}
