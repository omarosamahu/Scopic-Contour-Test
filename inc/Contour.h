#ifndef CONTOUR_H
#define CONTOUR_H

#include <Line.h>
#include <Arc.h>
#include <vector>
#include <memory>
#include <algorithm>

namespace Geometery{
using Shape = std::variant<Line, Arc>;
class Countour{
public:
    Countour() = default;
    ~Countour() = default;
    void addSegment(const Shape &shape);
    void removeSegment(const Shape &shape);
    void printSegmentInfo();
    bool isValid(const Shape &shape);

    // This is a simple implementation for getting a pointer to Line Shape
    // It's no longer needed since we are using the below template function.
    std::shared_ptr<Line> editLine(const Shape &shape);

    template <typename T>
    inline std::shared_ptr<T> getShapePointer(const Shape &shape)
    {
        auto itr = std::find(mSegments.begin(), mSegments.end(), shape);
        if (itr == mSegments.end())
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
    std::vector<Shape> mSegments;
};
}

#endif // CONTOUR_H