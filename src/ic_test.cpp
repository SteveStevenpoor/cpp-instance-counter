#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include <ic.h>

class Foo: Counter<Foo, 5> { };

TEST(ic_test, SimpleTest) {
    try {
        Foo a, b, c, d, e, f;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}