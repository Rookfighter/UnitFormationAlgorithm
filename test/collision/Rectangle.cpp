#include <catch.hpp>
#include "collision/Rectangle.hpp"

TEST_CASE("Collision Rectangle")
{
    float equalEps = 0.01f;
    collision::Vec2f rectCenter(1,1);
    collision::Vec2f rectSize(1,2);
    collision::Rectangle rect(rectCenter, rectSize);

    CHECK(rect.getCenter().equals(rectCenter, equalEps));
    CHECK(rect.getSize().equals(rectSize, equalEps));

    CHECK(rect.getCorners()[0].equals(collision::Vec2f(0.5, 0), equalEps));
}

