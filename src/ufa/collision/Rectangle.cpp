#include "ufa/collision/Rectangle.hpp"

namespace collision
{
    Rectangle::Rectangle(const Vec2f& p_center, const Vec2f& p_size)
    : center_(p_center), size_(p_size), corners_(4)
    {
        float widthHalf = size_.x / 2;
        float heightHalf = size_.y / 2;
        corners_[0].set(center_.x - widthHalf, center_.y - heightHalf);
        corners_[1].set(center_.x + widthHalf, center_.y - heightHalf);
        corners_[2].set(center_.x + widthHalf, center_.y + heightHalf);
        corners_[3].set(center_.x - widthHalf, center_.y + heightHalf);
    }

    Rectangle::~Rectangle()
    {
    }

    const Vec2f& Rectangle::getCenter() const
    {
        return center_;
    }

    Vec2f Rectangle::getTopLeft() const
    {
        Vec2f result(center_);
        result -= (size_ / 2);
        return result;
    }

    const Vec2f& Rectangle::getSize() const
    {
        return size_;
    }

    const std::vector<Vec2f>& Rectangle::getCorners() const
    {
        return corners_;
    }
}


