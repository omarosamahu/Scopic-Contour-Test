#ifndef SEGMENT_H
#define SEGMENT_H

#include <cmath>
#include <iostream>
#include <variant>

struct Point
{
    Point() = default;
    Point(float x, float y) : X{x}, Y{y} {}

    bool operator==(const Point& other) const { return X == other.X && Y == other.Y; }

    float X;
    float Y;
};

namespace Geometery{
    template <typename Type>
    class Segment {
    public:

    float length() const
    {
        return static_cast<const Type*>(this)->lengthImpl();
    }


    void printInfo() const
    {
        static_cast<const Type*>(this)->printInfoImpl();
    }
    };
}
#endif // SEGMENT_H
