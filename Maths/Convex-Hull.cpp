#include <bits/stdc++.h>

#define pii pair<int, int>
#define x first
#define y second

using namespace std;


int compare_y(pii A, pii B) {
    if ((A.y < B.y) || (A.y == B.y && A.x < B.x))
        return true;
    return false;
}

pii s = {0, 0};

double get_angle(pii A) {
    double y = A.y - s.y;
    double x = A.x - s.x;
    double h = sqrt(x * x + y * y);
    double sin = y / h;
    if (x < 0)
        return 180 - (asin(sin) * (180.0 / M_PI));
    return (asin(sin) * (180.0 / M_PI));
}

int compare_angle(pii A, pii B) {
    if (A == s)
        return true;
    if (B == s)
        return false;
    if (get_angle(A) < get_angle(B))
        return true;
    return false;
}


int orientation(pii p, pii q, pii r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 1;
    return (val > 0) ? 1 : 2;
}

vector <pii> calculate_hull(vector <pii> &points) {
    vector <pii> hull;
    if (points.size() == 0)
        return hull;
    if (points.size() == 1) {
        hull.push_back(points[0]);
        return hull;
    }
    sort(points.begin(), points.end(), compare_y);
    s = points[0];
    sort(points.begin(), points.end(), compare_angle);
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    if (points.size() == 2)
        return hull;
    hull.push_back(points[2]);
    for (int k = 3; k < points.size(); k++) {
        hull.push_back(points[k]);
        int size = (int) hull.size();
        while (orientation(hull[size - 3], hull[size - 2], hull[size - 1]) == 1) {
            pii p1 = hull.back();
            hull.pop_back();
            hull.pop_back();
            hull.push_back(p1);
            size--;
        }
    }
    return hull;
}
