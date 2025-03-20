#include "convex_hull.h"

#include <algorithm>

bool ConvexHull::compare(const Point& a, const Point& b) {
    return a.e[0] < b.e[0] || (a.e[0] == b.e[0] && a.e[1] < b.e[1]);
}

int ConvexHull::orientation(const Point& a, const Point& b, const Point& c) {
    return (b.e[0] - a.e[0]) * (c.e[1] - a.e[1]) - (b.e[1] - a.e[1]) * (c.e[0] - a.e[0]);
}

ConvexHull::ConvexHull() {}

ConvexHull::ConvexHull(const vector<Point>& points) : points(points) {}

ostream& operator<<(ostream& o, const ConvexHull& ch) {
    for (auto p : ch.convex_hull) {
        o << p << endl;
    }
    return o;
}

ConvexHull ConvexHull::generate_points(int n, int min, int max) {
    vector<Point> points;
    for (int i = 0; i < n; i++) {
        points.push_back(Point(rand() % (max - min + 1) + min, rand() % (max - min + 1) + min, 0, 1));
    }
    return ConvexHull(points);
}

vector<Point> ConvexHull::simple_convex_hull() {
    int n = points.size();
    if (n < 3) {
        return points;
    }

    vector<pair<Point, Point>> E;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            bool valid = true;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                if (orientation(points[i], points[j], points[k]) > 0) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                E.emplace_back(points[i], points[j]);
            }
        }
    }
    
    for (const auto &pair : E) {
        const auto &p = pair.first;
        if (find(convex_hull.begin(), convex_hull.end(), p) == convex_hull.end()) {
            convex_hull.push_back(p);
        }
    }
    sort(convex_hull.begin(), convex_hull.end(), ConvexHull::compare);
    return convex_hull;
}

void ConvexHull::print_points() const {
    for (auto p : points) {
        cout << p << endl;
    }
}