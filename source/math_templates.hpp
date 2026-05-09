#ifndef BUW_MATH_TEMPLATES_HPP
#define BUW_MATH_TEMPLATES_HPP

namespace buw {
    template<typename T>
    T square(T const &n) {
        return n * n;
    }

    template<typename T>
    T add(T const &n1, T const &n2) {
        return n1 + n2;
    }
}
#endif // BUW_MATH_TEMPLATES_HPP
