#include "point.h"

Point::Point() {
    e[0] = 0;
    e[1] = 0;
    e[2] = 0;
    e[3] = 0;
}
Point::Point(int x, int y, int z, int w) {
    e[0] = x;
    e[1] = y;
    e[2] = z;
    e[3] = w;
}

bool Point::operator==(const Point& p) const {
    return e[0] == p.e[0] && e[1] == p.e[1] && e[2] == p.e[2] && e[3] == p.e[3];
}

ostream& operator<<(ostream& o, const Point& p) {
    o << "(" << p.e[0] << ", " << p.e[1] << ", " << p.e[2] << ", " << p.e[3] << ")";
    return o;
}