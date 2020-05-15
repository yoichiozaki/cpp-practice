#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

// 点
struct Point
{
public:
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point p) { return Point(x - p.x, y - p.y); }
    Point operator*(double a) { return Point(x * a, y * a); }
    Point operator/(double a) { return Point(x / a, y / a); }
    bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
    bool operator>(const Point &p) const { return x != p.x ? x > p.x : y > p.y; }
    bool operator==(const Point &p) const { return equals(x, p.x) && equals(y, p.y); }
    double abs() { return sqrt(norm()); }
    double norm() { return x * x + y * y; }
    double dot(Point p) { return x * p.x + y * p.y; }
    double cross(Point p) { return x * p.y + y * p.x; }
};
using Vector = Point;

// 線分
struct Segment
{
    Point p1, p2;
};
using Line = Segment;

// 円
class Circle
{
public:
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0) : c(c), r(r) {}
};

// 多角形
using Polygon = vector<Point>;

double norm(Vector a) { return a.x * a.x + a.y * a.y; }
double abs(Vector a) { return sqrt(norm(a)); }
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
bool is_orthogonal(Vector a, Vector b) { return equals(dot(a, b), 0.0); }
bool is_orthogonal(Point a1, Point a2, Point b1, Point b2) { return is_orthogonal(a1 - a2, b1 - b2); }
bool is_orthogonal(Segment s1, Segment s2) { return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0); }
bool is_parallel(Vector a, Vector b) { return equals(cross(a, b), 0.0); }
bool is_parallel(Point a1, Point a2, Point b1, Point b2) { return is_parallel(a1 - a2, b1 - b2); }
bool is_parallel(Segment s1, Segment s2) { return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0); }

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;
int ccw(Point p0, Point p1, Point p2)
{
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (EPS < cross(a, b))
        return COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS)
        return CLOCKWISE;
    if (dot(a, b) < -EPS)
        return ONLINE_BACK;
    if (a.norm() < b.norm())
        return ONLINE_FRONT;
    return ON_SEGMENT;
}
bool intersect(Point p1, Point p2, Point p3, Point p4) { return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0); }
bool intersect(Segment s1, Segment s2) { return intersect(s1.p1, s1.p2, s2.p1, s2.p2); }
Point project(Segment s, Point p)
{
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / norm(base);
    return s.p1 + base * r;
}
Point reflect(Segment s, Point p) { return p + (project(s, p) - p) * 2.0; }
double get_distance(Point a, Point b) { return abs(a - b); }
double get_distanceLP(Line l, Point p) { return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1)); }
double get_distanceSP(Segment s, Point p)
{
    if (dot(s.p2 - s.p1, p - s.p1) < 0.0)
        return abs(p - s.p1);
    if (dot(s.p1 - s.p2, p - s.p2) < 0.0)
        return abs(p - s.p2);
    return get_distanceLP(s, p);
}
double get_distance(Segment s1, Segment s2)
{
    if (intersect(s1, s2))
        return 0.0;
    return min(min(get_distanceSP(s1, s2.p1), get_distanceSP(s1, s2.p2)), min(get_distanceSP(s2, s1.p1), get_distanceSP(s2, s1.p2)));
}
Point get_cross_point(Segment s1, Segment s2)
{
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1 / (d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
}
pair<Point, Point> get_cross_points(Circle c, Line l)
{
    // assert(intersect(c, l));
    Vector pr = project(l, c.c);
    Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
    double base = sqrt(c.r * c.r - norm(pr - c.c));
    return make_pair(pr + e * base, pr - e * base);
}
double arg(Vector p) { return atan2(p.y, p.x); }
Vector polar(double a, double r) { return Point(cos(r) * a, sin(r) * a); }
pair<Point, Point> get_cross_points(Circle c1, Circle c2)
{
    // assert(intersect(c1, c2));
    double d = abs(c1.c - c2.c);
    double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
}

// IN = 2, ON = 1, OUT = 0
int contains(Polygon g, Point p)
{
    int n = g.size();
    bool x = false;
    for (int i = 0; i < n; i++)
    {
        Point a = g[i] - p, b = g[(i + 1) % n] - p;
        if (abs(cross(a, b)) < EPS && dot(a, b) < EPS)
            return 1;
        if (b.y < a.y)
            swap(a, b);
        if (a.y < EPS && EPS < b.y && EPS < cross(a, b))
            x = !x;
    }
    return (x ? 2 : 0);
}

// 凸包：Andrew's Algorithm
Polygon andrew_scan(Polygon s)
{
    Polygon u, l;
    if (s.size() < 3)
        return s;
    sort(s.begin(), s.end());
    u.push_back(s[0]);
    u.push_back(s[1]);
    l.push_back(s[s.size() - 1]);
    l.push_back(s[s.size() - 2]);
    for (int i = 2; i < s.size(); i++)
    {
        for (int n = u.size(); 2 <= n && ccw(u[n - 2], u[n - 1], s[i]) != CLOCKWISE; n--)
        {
            u.pop_back();
        }
        u.push_back(s[i]);
    }
    for (int i = s.size() - 3; 0 <= i; i--)
    {
        for (int n = l.size(); 2 <= n && ccw(l[n - 2], l[n - 1], s[i]) != CLOCKWISE; n--)
        {
            l.pop_back();
        }
        l.push_back(s[i]);
    }
    reverse(l.begin(), l.end());
    for (int i = u.size() - 2; 1 <= i; i--)
    {
        l.push_back(u[i]);
    }
    return l;
}

// 多角形の凸判定
bool is_convex(Polygon p)
{
    int n = p.size();
    vector<Point> tmp = p;
    tmp.push_back(p[0]);
    vector<int> wise(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        wise[i] = ccw(tmp[i], tmp[i + 1], tmp[i + 2]);
    }
    for (int i = 0; i < n - 2; i++)
    {
        if (wise[i] != wise[i + 1])
            return false;
    }
    return true;
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        Polygon p;
        for (int i = 0; i < n; i++)
        {
            double x, y;
            char comma;
            cin >> x >> comma >> y;
            p.push_back(Point(x, y));
        }
        Polygon q = andrew_scan(p);
        cout << p.size() - q.size() << endl;
    }
    return 0;
}