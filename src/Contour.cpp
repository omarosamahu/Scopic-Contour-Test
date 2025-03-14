#include "Contour.h"
#include <algorithm>

namespace Geometery{
    void Countour::addSegment(const Shape &shape)
    {
        if(!isValid(shape))
        {
            throw std::invalid_argument("Invalid Segment");
        }
        mSegments.emplace_back(shape);
    }
    void Countour::removeSegment(const Shape &shape)
    {
        auto itr = std::find(mSegments.begin(), mSegments.end(), shape);
        mSegments.erase(itr);
    }
    bool Countour::isValid(const Shape &shape)
    {
        return false;
    }
}