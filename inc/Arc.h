#ifndef ARC_H
#define ARC_H

#include <Segment.h>
namespace Geometery
{
    class Arc : public Segment<Arc> {
        public:
            Arc() = default;
            Arc(const Point& center, double radius, double start_angle, double end_angle);
    
            double lengthImpl() const;
            void printInfoImpl() const;

            Point getStartPointImpl() const;
            Point getEndPointImpl() const;

            void setCenter(const Point& center);
            void setRadius(double radius);
            void setStartAngle(double startAngle);
            void setEndAngle(double endAngle);

            Point getCenter() const;
            double getRadius() const;
            double getStartAngle() const;
            double getEngAngle() const;

            bool operator==(const Arc &other) const
            { 
                return mCenter == other.mCenter && mRadius == other.mRadius && mStartAngle == other.mStartAngle && mEndAngle == other.mEndAngle; 
            }
    
        private:
            Point mCenter;
            double mRadius;
            double mStartAngle;
            double mEndAngle;
        };
}
#endif // ARC_H