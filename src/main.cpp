#include <Contour.h>
#include <vector>
#include <algorithm>

using namespace Geometery;

int main(int argc, char const *argv[])
{
    Shape line = Line({0.0, 0.0}, {5.0, 0.0});
    Shape arc = Arc({5.0, 2.0}, 2.0, -90.0, 40.0);

    auto linePtr = std::make_shared<Shape>(line);
    auto arcPtr = std::make_shared<Shape>(arc);

    auto cPtr = std::make_shared<Countour>(1e-6);

    cPtr->addSegment(linePtr);
    cPtr->addSegment(arcPtr);

    auto cPtr1 = cPtr;

    std::cout << cPtr.use_count() << "\n";

    std::shared_ptr<Line> ptr = cPtr->getShapePointer<Line>(linePtr);

    // Point p;
    // p.X = 5.0;
    // p.Y = 25.0;
    // ptr->setStartPoint(p);

    cPtr->printSegmentInfo();
    cPtr->isValid();

    // if (!cPtr)
    // {
    //     std::cout << "Null\n";
    // }

    return 0;
}
