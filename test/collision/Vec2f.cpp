#include <catch.hpp>
#include "collision/Vec2f.hpp"
#include "collision/utils.hpp"

TEST_CASE("basics float vector")
{
    collision::Vec2f v1(2,0);
    collision::Vec2f v2(v1);
    collision::Vec2f v3(-1, 4.5);
    collision::Vec2f v4(0, 2);

    SECTION("vector length")
    {
        float lenEps = 0.01;
        CHECK(collision::sameFloat(v1.length(), 2.0, lenEps));
        CHECK(collision::sameFloat(v1.lengthSQ(), 4.0, lenEps));
    }

    SECTION("vector equality")
    {
        float equalEps = 0.01;
        CHECK(v1.equals(collision::Vec2f(2,0), equalEps));
        CHECK(v1.equals(v2, equalEps));
        CHECK(v2.equals(v1, equalEps));
        CHECK_FALSE(v1.equals(v3, equalEps));
        CHECK_FALSE(v1.equals(v4, equalEps));
    }
}

TEST_CASE("normalize float vector")
{
    float lenEps = 0.01;
    collision::Vec2f v1(1.25,3.25);

    REQUIRE_FALSE(collision::sameFloat(v1.length(), 1.0, lenEps));
    v1.normalize();
    CHECK(collision::sameFloat(v1.length(), 1.0, lenEps));
    v1.normalize();
    CHECK(collision::sameFloat(v1.length(), 1.0, lenEps));
}

TEST_CASE("invert float vector")
{
    float equalEps = 0.01;
    collision::Vec2f v1(1.0,-2.0);
    collision::Vec2f v2(v1);

    REQUIRE(v1.equals(v2, equalEps));
    REQUIRE(collision::sameFloat(v1.length(), v2.length(), equalEps));

    v2.invert();
    CHECK_FALSE(v1.equals(v2, equalEps));
    CHECK(collision::sameFloat(v1.length(), v2.length(), equalEps));
    CHECK(collision::sameFloat(-v1.x, v2.x, equalEps));
    CHECK(collision::sameFloat(-v1.y, v2.y, equalEps));
}
