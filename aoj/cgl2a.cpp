#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

struct Point {
    double x, y;
    Point(int x = 0, int y = 0): x(x), y(y) {}
    Point operator + (Point &p) {
        return Point(x + p.x, y + p.y);
    }
    Point operator - (Point &p) {
        return Point(x - p.x, y - p.y);
    }
    Point operator * (double k) {
        return Point(x * k, y * k);
    }
    Point operator / (double k) {
        return Point(x / k, y / k);
    }
    double norm() {
        return x*x + y*y;
    }
    double abs() {
        return sqrt(norm());
    }
    bool operator < (const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }
    bool operator == (const Point &p) const {
        return equals(x, p.x) && equals(y, p.y);
    }
    double dot(Point &p) {
        return x * p.x + y * p.y;
    }
    double cross(Point &p) {
        return x * p.y - y * p.x;
    }
};
typedef Point Vector;

double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

bool is_orthogonal(Vector a, Vector b) { return equals(dot(a, b), 0.0); }
bool is_orthogonal(Point a1, Point a2, Point b1, Point b2) { return is_orthogonal(a1 - a2, b1 - b2); }
bool is_parallel(Vector a, Vector b) { return equals(cross(a, b), 0.0); }
bool is_parallel(Point a1, Point a2, Point b1, Point b2) { return is_parallel(a1 - a2, b1 - b2); }

struct Segment {
    Point p1, p2;
};
typedef Segment Line;

bool is_orthogonal(Segment s1, Segment s2) { return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0); }
bool is_parallel(Segment s1, Segment s2) { return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0); }

class Circle {
public:
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0): c(c), r(r) {}
};

typedef vector<Point> Polygon;

int main() {
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        double p0x, p0y, p1x, p1y, p2x, p2y, p3x, p3y;
        cin >> p0x >> p0y >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y;
        if (is_orthogonal(Point(p0x, p0y), Point(p1x, p1y), Point(p2x, p2y), Point(p3x, p3y))) {
            cout << 1 << endl;
        } else if (is_parallel(Point(p0x, p0y), Point(p1x, p1y), Point(p2x, p2y), Point(p3x, p3y))) {
            cout << 2 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}