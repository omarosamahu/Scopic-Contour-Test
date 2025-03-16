#ifndef SEGMENT_H
#define SEGMENT_H

#include <cmath>
#include <iostream>
#include <variant>

namespace Geometery
{
    struct Point
    {
        Point() = default;
        Point(double x, double y) : X{x}, Y{y} {}

        float getX() const { return X; }
        float getY() const { return Y; }

        bool operator==(const Point &other) const { return X == other.X && Y == other.Y; }
        bool isCloseTo(const Point &other, double epsilon) const
        {
            return std::abs(X - other.X) < epsilon && std::abs(Y - other.Y) < epsilon;
        }

        friend std::ostream &operator<<(std::ostream &os, const Point &p)
        {
            return os << '(' << p.getX() << ", " << p.getY() << ')';
        }

        double X;
        double Y;
    };

    template <typename Type>
    class Segment
    {
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
