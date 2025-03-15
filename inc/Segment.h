#ifndef SEGMENT_H
#define SEGMENT_H

#include <cmath>
#include <iostream>
#include <variant>

struct Point
{
    Point() = default;
    Point(double x, double y) : X{x}, Y{y} {}

    bool operator==(const Point& other) const { return X == other.X && Y == other.Y; }
    bool isApproxEqual(const Point &other, double epsilon) const
    {
        return std::abs(X - other.X) < epsilon && std::abs(Y - other.Y) < epsilon;
    }

    double X;
    double Y;
};

namespace Geometery{
    template <typename Type>
    class Segment {
    public:
        double length() const
        {
            return static_cast<const Type *>(this)->lengthImpl();
        }

        void printInfo() const
        {
            static_cast<const Type *>(this)->printInfoImpl();
        }

        Point getStartPoint() const
        {
            return static_cast<const Type *>(this)->getStartPointImpl();
        }

        Point getEndPoint() const
        {
            return static_cast<const Type *>(this)->getEndPointImpl();
    }
    };
}
#endif // SEGMENT_H
