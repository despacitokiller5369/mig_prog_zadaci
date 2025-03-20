#include <iostream>
#include <vector>

#include "point.h"

using namespace std;

class ConvexHull {
    vector<Point> points;
    vector<Point> convex_hull;
    static bool compare(const Point& a, const Point& b);
    static int orientation(const Point& a, const Point& b, const Point& c);
public:
    ConvexHull();
    ConvexHull(const vector<Point>& points);
    friend ostream& operator<<(ostream& o, const ConvexHull& ch);
    static ConvexHull generate_points(int n, int min, int max);
    vector<Point> simple_convex_hull();
    void print_points() const;
};