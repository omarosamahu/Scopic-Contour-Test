
#ifndef SEGMENT_H
#define SEGMENT_H

#include <cmath>
#include <iostream>
#include <variant>

struct Point
{
    float X;
    float Y;
    bool operator==(const Point& other) const { return X == other.X && Y == other.Y; }
};

namespace Geometery{
    template <typename Type>
    class Segment {
    public:
        float length() const;
        void printInfo() const;
    };
    
    class Line : public Segment<Line> {
    public:
        Line() = default;
        Line(const Point& start, const Point& end);

        float lengthImpl() const;
        void printInfoImpl() const;

        bool operator==(const Line& other) const { return p1 == other.p1 && p2 == other.p2; }

    private:
        Point p1;
        Point p2;
    };
    

    class Arc : public Segment<Arc> {
    public:
        Arc() = default;
        Arc(const Point& center, float radius, float start_angle, float end_angle);

        float lengthImpl() const;
        void printInfoImpl() const;

        bool operator==(const Arc& other) const { 
            return mCenter == other.mCenter && mRadius == other.mRadius && mStartAngle == other.mStartAngle && mEndAngle == other.mEndAngle; 
        }

    private:
        Point mCenter;
        float mRadius;
        float mStartAngle;
        float mEndAngle;
    };
    
    using Shape = std::variant<Line, Arc>;
    void printSegmentInfo(const Shape &segment);
}
#endif // SEGMENT_H
