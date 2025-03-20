#pragma once

#include <iostream>
#include <vector>

using namespace std;

struct Point {
    double e[4];

    Point();
    Point(int x, int y, int z, int w);

    bool operator==(const Point& p) const;
    friend ostream& operator<<(ostream& o, const Point& p);
};