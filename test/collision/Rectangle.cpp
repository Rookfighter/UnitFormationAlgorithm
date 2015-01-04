#include <catch.hpp>
#include "collision/Rectangle.hpp"

TEST_CASE("init rectangle")
{
    float equalEps = 0.01f;
    collision::Vec2f rectCenter(1,1);
    collision::Vec2f rectSize(1,2);
    collision::Rectangle rect(rectCenter, rectSize);

    CHECK(rect.getCenter().equals(rectCenter, equalEps));
    CHECK(rect.getSize().equals(rectSize, equalEps));

    // check that corners are ordered counter clockwise
    CHECK(rect.getCorners()[0].equals(collision::Vec2f(0.5, 0), equalEps));
    CHECK(rect.getCorners()[1].equals(collision::Vec2f(1.5, 0), equalEps));
    CHECK(rect.getCorners()[2].equals(collision::Vec2f(1.5, 2), equalEps));
    CHECK(rect.getCorners()[3].equals(collision::Vec2f(0.5, 2), equalEps));
}

