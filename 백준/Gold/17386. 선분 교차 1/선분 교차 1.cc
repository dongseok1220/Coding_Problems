#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
    bool operator>(const Point& p) const {
        return x > p.x || (x == p.x && y > p.y);
    }
};


double ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool compare(Point a, Point b) {
    double res = ccw({0, 0}, a, b);
    if(res > 0) return true;
    if(res < 0) return false;
    return a.x*a.x + a.y*a.y < b.x*b.x + b.y*b.y;
}

bool isIntersect(Point a, Point b, Point c, Point d) {
    double ab = ccw(a, b, c) * ccw(a, b, d);
    double cd = ccw(c, d, a) * ccw(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}

bool isIntersectWithXRay(Point a, Point b, Point c, Point d) {
    // Assuming the ray is along the positive x-axis from the origin (0, 0)
    Point origin = {0, 0};
    Point farPoint = {1e9, 0};  // A point far along the positive x-axis
    
    if ((a.y >= 0 && b.y < 0) || (a.y < 0 && b.y >= 0)) {
        return isIntersect(a, b, c, d);
    }
    return false;
}

int main() {
    Point a,b,c,d;
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y; 
    
    if (isIntersect(a,b,c,d)) {
        cout << 1; 
    }
    else cout << 0;
    return 0;
}
