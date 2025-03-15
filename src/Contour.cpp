#include "Contour.h"

namespace Geometery
{
    bool Countour::isApproxEqual() const
    {
        return false;
    }

    Countour::Countour(double epsilon) : epsilon{epsilon}
    {
    }

    void Countour::addSegment(const Shape &shape)
    {

        if (segments.size() == 0)
        {
            current_start = std::visit([](const auto &seg) -> Point
                                       { return seg.getStartPoint(); }, shape);
        }
        segments.emplace_back(shape);
    }

    void Countour::insertSegment(const Shape &shape, size_t index)
    {
        // To do check if the shape is already exist or not
        segments.insert(segments.begin() + index, shape);
    }
    void Countour::removeSegment(const Shape &shape)
    {
        auto itr = std::find(segments.begin(), segments.end(), shape);
        segments.erase(itr);
    }

    bool Countour::isValid(const Shape &shape)
    {
        for (size_t i{1U}; i < segments.size(); i++)
        {
            auto prevSgmentEnd = std::visit([](const auto &seg) -> Point
                                            { return seg.getEndPoint(); }, segments[i - 1]);

            auto currentSegmentStart = std::visit([](const auto &seg) -> Point
                                                  { return seg.getStartPoint(); }, segments[i]);
            if (!prevSgmentEnd.isApproxEqual(currentSegmentStart, epsilon))
            {
                std::cerr << "This contour is not valid\n";
                return false;
            }
        }

        return true;
    }

    void Countour::updateBorders(const Point &point)
    {
        this->current_end = point;
    }

    std::shared_ptr<Line> Countour::editLine(const Shape &shape)
    {
        auto itr = std::find(segments.begin(), segments.end(), shape);

        if (itr == segments.end())
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

    void Countour::printSegmentInfo() const
    {
        for (const auto &segment : segments)
        {
            std::visit([](const auto& seg) { seg.printInfo(); }, segment);
        }
    }
}