#ifndef SEGMENT_H
#define SEGMENT_H

#include <cmath>
#include <iostream>
#include <variant>

// struct Point
// {
//     float X;
//     float Y;

//     bool operator==
// };

namespace Geometery{
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
        Line(float x1, float y1, float x2, float y2);
    
        float lengthImpl() const;
        void printInfoImpl() const;
    
    private:
        float X1;
        float X2;
        float Y1;
        float Y2;
    };
    
    // Arc Segment Specialization
    class Arc : public Segment<Arc> {
    public:
        Arc(float cx, float cy, float radius, float angle);
    
        float lengthImpl() const;
    
        void printInfoImpl() const;
    
    private:
        float mCx;
        float mCy;
        float mRadius;
        float mAngle; // Angle in radians
    };
    
    using Shape = std::variant<Line, Arc>;
    void printSegmentInfo(const Shape &segment);
}
#endif // SEGMENT_H
