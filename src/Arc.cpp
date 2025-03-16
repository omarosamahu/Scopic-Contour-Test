#include <Arc.h>

namespace Geometery
{
    Arc::Arc(const Point& center, double radius, double start_angle, double end_angle)
        : mCenter{center}, mRadius{radius}, mStartAngle{start_angle},mEndAngle{end_angle} {}

    double Arc::lengthImpl() const {
        double theta = (mEndAngle - mStartAngle) * M_PI / 180.0;
        return mRadius * theta;
    }

    void Arc::printInfoImpl() const {
        std::cout << "Arc Segment: Center (" << mCenter.X << ", " << mCenter.Y << "), Radius: " << mRadius
                  << ", Angle: " << (mEndAngle - mStartAngle) << " rad"
                  << " | Arc Length: " << lengthImpl() << '\n';
    }

    Point Arc::getStartPointImpl() const
    {
        return {mCenter.X + mRadius * std::cos(mStartAngle * M_PI / 180), mCenter.Y + mRadius * std::sin(mStartAngle * M_PI / 180)};
    }

    Point Arc::getEndPointImpl() const
    {
        return {mCenter.X + mRadius * std::cos(mEndAngle * M_PI / 180), mCenter.Y + mRadius * std::sin(mEndAngle * M_PI / 180)};
    }

    void Arc::setCenter(const Point &center)
    {
        this->mCenter = center;
    }

    void Arc::setRadius(double radius)
    {
        this->mRadius = radius;
    }

    void Arc::setStartAngle(double startAngle)
    {
        this->mStartAngle = startAngle;
    }

    void Arc::setEndAngle(double endAngle)
    {
        this->mEndAngle = endAngle;
    }

    Point Arc::getCenter() const
    {
        return mCenter;
    }

    double Arc::getRadius() const
    {
        return mRadius;
    }

    double Arc::getStartAngle() const
    {
        return mStartAngle;
    }

    double Arc::getEngAngle() const
    {
        return mEndAngle;
    }
}