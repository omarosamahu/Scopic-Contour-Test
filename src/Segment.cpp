#include <Segment.h>
namespace Geometery{
    template <typename Type>
    float Segment<Type>::length() const
    {
        return static_cast<const Type*>(this)->lengthImpl();
    }

    template <typename Type>
    void Segment<Type>::printInfo() const {
        static_cast<const Type*>(this)->printInfoImpl();
    }

    void printSegmentInfo(const Shape& segment) {
        std::visit([](const auto& seg) { seg.printInfo(); }, segment);
    }

    Line::Line(const Point& start, const Point& end)
        : p1{start}, p2{end} {}
    
    float Line::lengthImpl() const {
        return std::sqrt(std::pow((p2.X - p1.X), 2) + std::pow((p2.Y - p1.Y), 2));
    }
    
    void Line::printInfoImpl() const {
        std::cout << "Line Segment: (" << p1.X << ", " << p1.Y << ") -> (" << p2.X << ", " << p2.Y << ")"
                  << " | Length: " << lengthImpl() << '\n';
    }
    
    Arc::Arc(const Point& center, float radius, float start_angle, float end_angle)
        : mCenter{center}, mRadius{radius}, mStartAngle{start_angle},mEndAngle{end_angle} {}
    
    float Arc::lengthImpl() const {
        float theta = (mEndAngle - mStartAngle) * M_PI / 180.0;
        return mRadius * theta;
    }
    
    void Arc::printInfoImpl() const {
        std::cout << "Arc Segment: Center (" << mCenter.X << ", " << mCenter.Y << "), Radius: " << mRadius
                  << ", Angle: " << (mEndAngle - mStartAngle) << " rad"
                  << " | Arc Length: " << lengthImpl() << '\n';
    }
}