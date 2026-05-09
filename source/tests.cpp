#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest.h>

#include "math_templates.hpp"

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

int main(int argc, char *argv[]) {
    doctest::Context ctx;
    ctx.applyCommandLine(argc, argv);
    return ctx.run();
}
