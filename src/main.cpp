#include <Segment.h>
#include <vector>

int main(int argc, char const *argv[])
{
    Shape line = Line(0, 0, 3, 4);
    Shape arc = Arc(0, 0, 5, 1.57);

    std::vector<Shape> seg;
    seg.emplace_back(line);
    seg.emplace_back(arc);

    for (const auto& segment : seg) {
        printSegmentInfo(segment);
    }
    return 0;
}
