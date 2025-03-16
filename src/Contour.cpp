#include "Contour.h"

namespace Geometery
{
    Countour::Countour(double epsilon) : epsilon{epsilon}
    {
    }

    void Countour::addSegment(const std::shared_ptr<Shape> &shape)
    {
        segments.emplace_back(shape);
    }

    void Countour::insertSegment(const std::shared_ptr<Shape> &shape, size_t index)
    {
        // To do check if the shape is already exist or not
        segments.insert(segments.begin() + index, shape);
    }

    void Countour::removeSegment(const std::shared_ptr<Shape> &shape)
    {
        auto itr = std::find(segments.begin(), segments.end(), shape);
        segments.erase(itr);
    }

    bool Countour::isValid() const
    {
        if (segments.empty())
        {
            std::cerr << "No segements added yet\n";
            return false;
        }

        for (size_t i{1U}; i < segments.size(); i++)
        {
            const Point prevSgmentEnd = std::visit([](const auto &seg) -> Point
                                                   { return seg.getEndPoint(); }, *segments[i - 1]);

            const Point currentSegmentStart = std::visit([](const auto &seg) -> Point
                                                         { return seg.getStartPoint(); }, *segments[i]);

            if (!prevSgmentEnd.isCloseTo(currentSegmentStart, epsilon))
            {
                std::cerr << "This contour is not valid\n";
                return false;
            }
        }

        const Point start = std::visit([](const auto &seg) -> Point
                                       { return seg.getStartPoint(); }, *segments.front());

        const Point end = std::visit([](const auto &seg) -> Point
                                     { return seg.getEndPoint(); }, *segments.back());

        if (!end.isCloseTo(start, epsilon))
        {
            std::cerr << "This contour is not valid\n";
            return false;
        }
        return true;
    }

    std::shared_ptr<Line> Countour::getLine(const std::shared_ptr<Shape> &shape)
    {
        auto itr = std::find(segments.begin(), segments.end(), shape);

        if (itr == segments.end())
        {
            std::cout << "Shape is not found\n";
            return nullptr;
        }
        Line *ptr = std::get_if<Line>(itr->get());

        if (!ptr)
        {
            return nullptr;
        }

        return std::shared_ptr<Line>(ptr, [](Line *) {});
    }

    void Countour::printSegmentInfo() const
    {
        for (const auto &segment : segments)
        {
            std::visit([](const auto &seg)
                       { seg.printInfo(); }, *segment);
        }
    }
}