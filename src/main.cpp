#include <Segment.h>
#include <vector>

using namespace Geometery;

int main(int argc, char const *argv[])
{
    Shape line = Line({0.0, 0.0}, {3.0, 4.0});
    Shape arc = Arc({0.0, 0.0}, 5.0, 30,90);

    std::vector<Shape> seg;
    seg.emplace_back(line);
    seg.emplace_back(arc);

    for (const auto& segment : seg) {
        printSegmentInfo(segment);
    }
    return 0;
}
