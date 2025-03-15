#ifndef CONTOUR_H
#define CONTOUR_H

#include <Line.h>
#include <Arc.h>
#include <vector>

namespace Geometery{
using Shape = std::variant<Line, Arc>;
class Countour{
public:
    Countour() = default;
    ~Countour() = default;
    void addSegment(const Shape &shape);
    void removeSegment(const Shape &shape);
    bool isValid(const Shape &shape);
    void printSegmentInfo();

private:
    std::vector<Shape> mSegments;
};
}

#endif // CONTOUR_H