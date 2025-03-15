#include <Contour.h>
#include <vector>
#include <algorithm>
using namespace Geometery;

int main(int argc, char const *argv[])
{
    Shape line = Line({9.0, 6.0}, {3.0, 4.0});
    Shape arc = Arc({0.0, 0.0}, 5.0, 30,90);

    // Countour cont(1e-6);
    auto cPtr = std::make_shared<Countour>(1e-6);

    cPtr->addSegment(line);
    cPtr->addSegment(arc);

    auto cPtr1 = cPtr;

    std::shared_ptr<Line> ptr = cPtr1->getShapePointer<Line>(line);

    Point p;
    p.X = 65.0;
    p.Y = 21.0;
    ptr->setStartPoint(p);

    cPtr1->printSegmentInfo();
    cPtr1->isValid(line);

    return 0;
}
