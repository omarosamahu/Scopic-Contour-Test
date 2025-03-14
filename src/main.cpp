#include <Segment.h>
#include <vector>
#include <algorithm>
using namespace Geometery;

int main(int argc, char const *argv[])
{
    Shape line = Line({0.0, 0.0}, {3.0, 4.0});
    Shape arc = Arc({0.0, 0.0}, 5.0, 30,90);

    std::vector<Shape> segments;
    segments.emplace_back(line);
    segments.emplace_back(arc);

    auto itr = std::find(segments.begin(), segments.end(), line);
    segments.erase(itr);

    for (const auto& segment : segments) {
        printSegmentInfo(segment);
    }
    return 0;
}
