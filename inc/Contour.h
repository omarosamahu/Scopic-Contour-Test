#ifndef CONTOUR_H
#define CONTOUR_H

#include <Line.h>
#include <Arc.h>
#include <vector>
#include <memory>
#include <algorithm>

namespace Geometery{
using Shape = std::variant<Line, Arc>;
class Countour
{
public:
    Countour() = default;
    explicit Countour(double epsilon);
    ~Countour() = default;
    void addSegment(const Shape &shape);
    void insertSegment(const Shape &shape, size_t index);
    void removeSegment(const Shape &shape);
    void printSegmentInfo() const;
    bool isValid(const Shape &shape);
    void updateBorders(const Point &point);

    // This is a simple implementation for getting a pointer to Line Shape
    // It's no longer needed since we are using the below template function.
    std::shared_ptr<Line> editLine(const Shape &shape);

    template <typename T>
    inline std::shared_ptr<T> getShapePointer(const Shape &shape)
    {
        auto itr = std::find(segments.begin(), segments.end(), shape);
        if (itr == segments.end())
        {
            std::cerr << "This shape is not found\n";
            return nullptr;
        }

        return std::visit([](auto &value) -> std::shared_ptr<T>
                          {
                              if constexpr (std::is_same_v<std::decay_t<decltype(value)>, T>)
                              {
                                  return std::shared_ptr<T>(&value, [](T *) {});
                              }
                              return nullptr; // Type mismatch
                          },
                          *itr);
    }

private:
    double epsilon;
    Point current_start;
    Point current_end;
    std::vector<Shape> segments;
};
}

#endif // CONTOUR_H