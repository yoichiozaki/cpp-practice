#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

const int COUNTER_CLOCKWISE = 1;
const int CLOCKWISE = -1;
const int ONLINE_BACK = 2;
const int ONLINE_FRONT = -2;
const int ON_SEGMENT = 0;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
    Point operator + (Point p)  { return Point(x + p.x, y + p.y); }
    Point operator - (Point p)  { return Point(x - p.x, y - p.y); }
    Point operator * (double k) { return Point(x * k, y * k); }
    Point operator / (double k) { return Point(x / k, y / k); }
    double norm() { return x * x + y * y; }
    double abs()  { return sqrt(norm()); }
    bool operator < (const Point &p) const  { return x != p.x ? x < p.x : y < p.y; }
    bool operator == (const Point &p) const { return equals(x, p.x) && equals(y, p.y); }
    double dot(Point &p)   { return x * p.x + y * p.y; }
    double cross(Point &p) { return x * p.y - y * p.x; }
};
typedef Point Vector;
double norm(Vector a) { return a.x * a.x + a.y * a.y; }
double abs(Vector a) { return sqrt(norm(a)); }
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
double distancePP(Point a, Point b) { return abs(a - b); }
int ccw(Point p0, Point p1, Point p2) {
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (EPS < cross(a, b)) return COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS) return CLOCKWISE;
    if (dot(a, b) < -EPS) return ONLINE_BACK;
    if (a.norm() < b.norm()) return ONLINE_FRONT;
    return ON_SEGMENT;
}
bool is_orthogonal(Vector a, Vector b) { return equals(dot(a, b), 0.0); }
bool is_orthogonal(Point a1, Point a2, Point b1, Point b2) { return is_orthogonal(a1 - a2, b1 - b2); }
bool is_parallel(Vector a, Vector b) { return equals(cross(a, b), 0.0); }
bool is_parallel(Point a1, Point a2, Point b1, Point b2) { return is_parallel(a1 - a2, b1 - b2); }
bool intersect(Point p1, Point p2, Point p3, Point p4) {
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

struct Segment {
    Point p1, p2;
    Segment(Point p1, Point p2): p1(p1), p2(p2) {}
    Segment(double p1x, double p1y, double p2x, double p2y): p1(Point(p1x, p1y)), p2(Point(p2x, p2y)) {}
};
typedef Segment Line;
bool is_orthogonal(Segment s1, Segment s2) { return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0); }
bool is_parallel(Segment s1, Segment s2) { return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0); }
bool intersect(Segment s1, Segment s2) { return intersect(s1.p1, s1.p2, s2.p1, s2.p2); }
Point project(Segment s, Point p) {
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / norm(base);
    return s.p1 + base * r;
}
Point reflect(Segment s, Point p) {
    return p + (project(s, p) - p) * 2.0;
}
double distanceLP(Line l, Point p) {
    return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}
double distanceSP(Segment s, Point p) {
    if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
    if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
    return distanceLP(s, p);
}
double distanceSS(Segment s1, Segment s2) {
    if (intersect(s1, s2)) return 0.0;
    return min(
        min(distanceSP(s1, s2.p1), distanceSP(s1, s2.p2)),
        min(distanceSP(s2, s1.p1), distanceSP(s2, s1.p2))
    );
}

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
        double xp0, yp0, xp1, yp1, xp2, yp2, xp3, yp3; cin >> xp0 >> yp0 >> xp1 >> yp1 >> xp2 >> yp2 >> xp3 >> yp3;
        if (intersect(Point(xp0, yp0), Point(xp1, yp1), Point(xp2, yp2), Point(xp3, yp3))) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}