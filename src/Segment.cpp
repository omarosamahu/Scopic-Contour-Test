#include <Segment.h>

Line::Line(float x1, float y1, float x2, float y2)
    : X1{x1}, Y1{y1}, X2{x2}, Y2{y2} {}

float Line::lengthImpl() const {
    return std::sqrt(std::pow((X2 - X1), 2) + std::pow((Y2 - Y1), 2));
}

void Line::printInfoImpl() const {
    std::cout << "Line Segment: (" << X1 << ", " << Y1 << ") -> (" << X2 << ", " << Y2 << ")"
              << " | Length: " << lengthImpl() << '\n';
}

Arc::Arc(float cx, float cy, float radius, float angle)
    : mCx{cx}, mCy{cy}, mRadius{radius}, mAngle{angle} {}

float Arc::lengthImpl() const {
    return mRadius * mAngle; // Arc length formula
}

void Arc::printInfoImpl() const {
    std::cout << "Arc Segment: Center (" << mCx << ", " << mCy << "), Radius: " << mRadius
              << ", Angle: " << mAngle << " rad"
              << " | Arc Length: " << lengthImpl() << std::endl;
}
