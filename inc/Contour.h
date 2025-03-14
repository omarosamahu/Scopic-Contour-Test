#ifndef CONTOUR_H
#define CONTOUR_H

#include <Segment.h>

namespace Geometery{
    class Countour{
        public:
            Countour() = default;
            ~Countour() = default;
            void addSegment(const Shape &shape);
    };
}

#endif // CONTOUR_H