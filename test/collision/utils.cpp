#include <catch.hpp>
#include "collision/utils.hpp"

TEST_CASE("utils same float")
{
    float f1 = 1.0;
    float f2 = 1.02;
    float f3 = 1.022;
    float f4 = 1.0;

    CHECK(collision::sameFloat(f1, f2, 0.1));
    CHECK_FALSE(collision::sameFloat(f1, f2, 0.01));
    CHECK(collision::sameFloat(f2, f3, 0.01));
    CHECK_FALSE(collision::sameFloat(f2, f3, 0.001));
    CHECK(collision::sameFloat(f1, f4, 0.000001));
}
