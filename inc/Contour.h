#ifndef CONTOUR_H
#define CONTOUR_H

#include <Segment.h>
#include <unordered_set>
#include <vector>

namespace Geometery{
class Countour{
public:
    Countour() = default;
    ~Countour() = default;
    void addSegment(const Shape &shape);
    bool removeSegment(const Shape &shape);
    bool isValid(const Shape &shape);

private:
    std::vector<Shape> mSegments;
};
}

#endif // CONTOUR_H