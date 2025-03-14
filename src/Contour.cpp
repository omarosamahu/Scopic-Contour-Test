#include "Contour.h"
#include <algorithm>

namespace Geometery{
    void Countour::addSegment(const Shape &shape)
    {
        mSegments.emplace_back(shape);
    }
    bool Countour::removeSegment(const Shape &shape)
    {
        auto itr = std::find(mSegments.begin(), mSegments.end(), shape);
        mSegments.erase(itr);
        return true;
    }
    bool Countour::isValid(const Shape &shape)
    {
        return false;
    }
}