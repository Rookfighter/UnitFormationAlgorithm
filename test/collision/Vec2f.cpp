#include <catch.hpp>
#include "collision/Vec2f.hpp"
#include "collision/utils.hpp"

TEST_CASE("basics float vector")
{
    collision::Vec2f v1(2,0);
    collision::Vec2f v2(v1);
    collision::Vec2f v3(-1, 4.5);
    collision::Vec2f v4(0, 2);

    SECTION("vector coordinates")
    {
        float posEps = 0.01;
        CHECK(collision::sameFloat(v1.x, 2.0, posEps));
        CHECK(collision::sameFloat(v1.y, 0, posEps));

        v1.set(-1, 1.5);
        CHECK(collision::sameFloat(v1.x, -1, posEps));
        CHECK(collision::sameFloat(v1.y, 1.5, posEps));
    }

    SECTION("vector operators")
    {
        float posEps = 0.01;
        collision::Vec2f result;

        result = v1 + v3;
        CHECK(collision::sameFloat(result.x, 1, posEps));
        CHECK(collision::sameFloat(result.y, 4.5, posEps));
        result = v3 - v1;
        CHECK(collision::sameFloat(result.x, -3, posEps));
        CHECK(collision::sameFloat(result.y, 4.5, posEps));
        result = v3 * 3;
        CHECK(collision::sameFloat(result.x, -3, posEps));
        CHECK(collision::sameFloat(result.y, 13.5, posEps));
        CHECK(v1 == v1);
        CHECK_FALSE(v1 != v1);
        CHECK(v1 != v3);
        CHECK_FALSE(v1 == v3);
    }

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

TEST_CASE("dot product float vector")
{
    float prodEps = 0.01;
    collision::Vec2f v1(2,1);
    collision::Vec2f v2(1,0);
    collision::Vec2f v3(-1,0);
    collision::Vec2f v4(0,1);

    // project v1 on v2 -> only x value should remain
    CHECK(collision::sameFloat(v1 * v2, 2, prodEps));
    // should be commutative with unit vectors
    CHECK(collision::sameFloat(v2 * v1, 2, prodEps));
    CHECK(collision::sameFloat(v1 * v3, -2, prodEps));
    CHECK(collision::sameFloat(v2 * v4, 0, prodEps));
}
