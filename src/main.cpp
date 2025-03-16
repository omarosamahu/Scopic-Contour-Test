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

    // Check if the contour is copyable or not
    std::cout << "Ref count: " << cPtr.use_count() << "\n";

    std::shared_ptr<Line> lPtr = cPtr->getShapePointer<Line>(linePtr);

    Point p{5.0, 25.0};
    lPtr->setStartPoint({15.0, 2.0});
    lPtr->setEndPoint({-2.0, 4.0});

    std::cout << "Line boundaries updated to: " << lPtr->getStartPoint() << " | " << lPtr->getEndPoint() << "\n";

    cPtr->printSegmentInfo();
    cPtr->isValid();

    auto cPtr2 = std::move(cPtr1);
    if (!cPtr1)
    {
        std::cout << "Null\n";
    }

    return 0;
}
