#include <Contour.h>
#include <vector>
#include <algorithm>
using namespace Geometery;

int main(int argc, char const *argv[])
{
    Shape line = Line({0.0, 0.0}, {3.0, 4.0});
    Shape arc = Arc({0.0, 0.0}, 5.0, 30,90);

    Countour cont;

    cont.addSegment(line);
    cont.addSegment(arc);
 
    cont.printSegmentInfo();
    
    return 0;
}
