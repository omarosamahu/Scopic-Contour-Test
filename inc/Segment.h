#ifndef SEGMENT_H
#define SEGMENT_H

#include <cmath>
#include <iostream>
#include <variant>

template <typename Type>
class Segment {
public:
    float length() const {
        return static_cast<const Type*>(this)->lengthImpl();
    }

    void printInfo() const {
        static_cast<const Type*>(this)->printInfoImpl();
    }
};

class Line : public Segment<Line> {
public:
    Line(float x1, float y1, float x2, float y2)
        : X1{x1}, Y1{y1}, X2{x2}, Y2{y2} {}

    float lengthImpl() const {
        return std::sqrt(std::pow((X2 - X1),2) + std::pow((Y2 - Y1),2));
    }

    void printInfoImpl() const {}

private:
    float X1;
    float X2;
    float Y1;
    float Y2;
};

// Arc Segment Specialization
class Arc : public Segment<Arc> {
public:
    Arc(float cx, float cy, float radius, float angle)
        : mCx{cx}, mCy{cy}, mRadius{radius}, mAngle{angle} {}

    float lengthImpl() const {
        return mRadius * mAngle; // Arc length formula
    }

    void printInfoImpl() const {
        std::cout << "Arc Segment: Center (" << mCx << ", " << mCy << "), Radius: " << mRadius
                  << ", Angle: " << mAngle << " rad"
                  << " | Arc Length: " << lengthImpl() << '\n';
    }
private:
    float mCx;
    float mCy;
    float mRadius;
    float mAngle; // Angle in radians
};

using Shape = std::variant<Line, Arc>;

void printSegmentInfo(const Shape& segment) {
    std::visit([](const auto& seg) { seg.printInfo(); }, segment);
}

#endif // SEGMENT_H
