#include <Line.h>

namespace Geometery
{
    Line::Line(const Point& start, const Point& end)
        : p1{start}, p2{end} {}

    double Line::lengthImpl() const {
        return std::sqrt(std::pow((p2.X - p1.X), 2) + std::pow((p2.Y - p1.Y), 2));
    }

    void Line::printInfoImpl() const {
        std::cout << "Line Segment: (" << p1.X << ", " << p1.Y << ") -> (" << p2.X << ", " << p2.Y << ")"
                  << " | Length: " << lengthImpl() << '\n';
    }

    void Line::setStartPoint(const Point& point)
    {
        this->p1 = point;
    }

    void Line::setEndPoint(const Point& point)
    {
        this->p2 = point;
    }

    Point Line::getStartPointImpl() const
    {
        return p1;
    }

    Point Line::getEndPointImpl() const
    {
        return p2;
    }
}