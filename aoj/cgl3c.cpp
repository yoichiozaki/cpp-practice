#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

const int COUNTER_CLOCKWISE = 1;
const int CLOCKWISE = -1;
const int ONLINE_BACK = 2;
const int ONLINE_FRONT = -2;
const int ON_SEGMENT = 0;

const int IN = 2;
const int ON = 1;
const int OUT = 0;

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
double arg(Vector p) { return atan2(p.y, p.x); }
Vector polar(double a, double r) { return Point(cos(r) * a, sin(r) * a); }
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
Point cross_point(Segment s1, Segment s2) {
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1 / (d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
}

class Circle {
public:
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0): c(c), r(r) {}
};
pair<Point, Point> cross_points(Circle c, Line l) {
    Vector pr = project(l, c.c);
    // assert(pr.abs() <= c.r); // 「円の直径 < 中心と直線の距離」であることを確認
    Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
    double base = sqrt(c.r * c.r - norm(pr - c.c));
    return make_pair(pr + e * base, pr - e * base);
}
pair<Point, Point> cross_points(Circle c1, Circle c2) {
    double d = abs(c1.c - c2.c);
    double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
}

typedef vector<Point> Polygon;

int contains(Polygon g, Point p) {
    int n = g.size();
    bool x = false;
    for (int i = 0; i < n; i++) {
        Point a = g[i] - p, b = g[(i+1) % n] - p;
        if (abs(cross(a, b)) < EPS && dot(a, b) < EPS) {
            return 1;
        }
        if (b.y < a.y) {
            swap(a, b);
        }
        if (a.y < EPS && EPS < b.y && EPS < cross(a, b)) {
            x = !x;
        }
    }
    return (x ? 2 : 0);
}

int main() {
    cout << fixed << setprecision(12);
    int g; cin >> g;
    Polygon poly = Polygon(0);
    for (int i = 0; i < g; i++) {
        double x, y; cin >> x >> y;
            poly.push_back(Point(x, y));
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        double x, y; cin >> x >> y;
        cout << contains(poly, Point(x, y)) << endl;
    }
    return 0;
}