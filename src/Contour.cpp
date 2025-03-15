#include "Contour.h"

namespace Geometery
{
    void Countour::addSegment(const Shape &shape)
    {
        if (!isValid(shape))
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
    // void Countour::editArc(const Shape &shape)
    // {
    // }
    bool Countour::isValid(const Shape &shape)
    {
        return true;
    }

    std::shared_ptr<Line> Countour::editLine(const Shape &shape)
    {
        auto itr = std::find(mSegments.begin(), mSegments.end(), shape);

        if (itr == mSegments.end())
        {
            std::cout << "Shape is not found\n";
            return nullptr;
        }
        Line *ptr = std::get_if<Line>(&(*itr));

        if (!ptr)
        {
            return nullptr;
        }

        return std::shared_ptr<Line>(ptr, [](Line *) {});
    }

    void Countour::printSegmentInfo()
    {
        for (const auto &segment : mSegments)
        {
            std::visit([](const auto& seg) { seg.printInfo(); }, segment);
        }
    }
}