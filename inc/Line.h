#ifndef LINE_H
#define LINE_H

#include <Segment.h>
namespace Geometery{class Line : public Segment<Line> {
    public:
        Line() = default;
        Line(const Point& start, const Point& end);

        double lengthImpl() const;
        void printInfoImpl() const;

        void setStartPoint(const Point& p);
        void setEndPoint(const Point& p);

        Point getStartPointImpl() const;
        Point getEndPointImpl() const;

        bool operator==(const Line& other) const { return p1 == other.p1 && p2 == other.p2; }

    private:
        Point p1;
        Point p2;
    };
}
#endif // LINE_H