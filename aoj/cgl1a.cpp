#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

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
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

bool is_orthogonal(Vector a, Vector b) { return equals(dot(a, b), 0.0); }
bool is_orthogonal(Point a1, Point a2, Point b1, Point b2) { return is_orthogonal(a1 - a2, b1 - b2); }
bool is_parallel(Vector a, Vector b) { return equals(cross(a, b), 0.0); }
bool is_parallel(Point a1, Point a2, Point b1, Point b2) { return is_parallel(a1 - a2, b1 - b2); }

struct Segment {
    Point p1, p2;
    Segment(Point p1, Point p2): p1(p1), p2(p2) {}
    Segment(double p1x, double p1y, double p2x, double p2y): p1(Point(p1x, p1y)), p2(Point(p2x, p2y)) {}
};
typedef Segment Line;

bool is_orthogonal(Segment s1, Segment s2) { return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0); }
bool is_parallel(Segment s1, Segment s2) { return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0); }
Point project(Segment s, Point p) {
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / norm(base);
    return s.p1 + base * r;
}

class Circle {
public:
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0): c(c), r(r) {}
};

typedef vector<Point> Polygon;

int main() {
    cout << fixed << setprecision(12);
    double xp1, yp1, xp2, yp2; cin >> xp1 >> yp1 >> xp2 >> yp2;
    Segment s = Segment(Point(xp1, yp1), Point(xp2, yp2));
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        double xp0, yp0; cin >> xp0 >> yp0;
        Point ans = project(s, Point(xp0, yp0));
        cout << ans.x << " " << ans.y << endl;
    }
    return 0;
}