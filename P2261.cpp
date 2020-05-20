#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

#define SQUARE(a) ((a)*(a))

struct Point {
    long long x, y;
};

inline long long dist(Point p1, Point p2) {
    return SQUARE(p1.x - p2.x) + SQUARE(p1.y - p2.y);
}

long long nearest(Point points[], size_t n) {
    if (n < 4) {
        long long d = numeric_limits<long long>::max();
        for (int i = 0; (i + 1) < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                d = min(d, dist(points[i], points[j]));
            }
        }
        return d;
    }
    long long dl = nearest(points, n / 2);
    long long dr = nearest(points + n / 2, n - n / 2);
    long long d = min(dl, dr);
    long long mid = points[n / 2 - 1].x;
    vector<Point> strip;
    for (int i = 0; i < n; ++i) {
        if (SQUARE(points[i].x - mid) < d) {
            strip.push_back(points[i]);
        }
    }
    sort(strip.begin(), strip.end(), [](auto p1, auto p2){ return p1.y < p2.y; });
    auto strip_len = strip.size();
    for (int i = 0; (i + 1) < strip_len; ++i) {
        for (int j = i + 1; j < strip_len; ++j) {
            if (SQUARE(strip[i].y - strip[j].y) < d) {
                d = min(d, dist(strip[i], strip[j]));
            } else {
                break;
            }
        }
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int size;
    cin >> size;
    Point points[100'001];
    for (int i = 0; i < size; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    sort(points, points + size, [](auto p1, auto p2){ return p1.x < p2.x; });
    cout << nearest(points, size);
}
