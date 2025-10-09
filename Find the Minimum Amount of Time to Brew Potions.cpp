#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
    ll x, y;
};

// safe cross product using 128-bit to avoid overflow
static inline __int128 cross128(const Point &o, const Point &a, const Point &b) {
    return (__int128)(a.x - o.x) * (__int128)(b.y - o.y)
         - (__int128)(a.y - o.y) * (__int128)(b.x - o.x);
}

// monotone chain convex hull assuming pts are sorted by x then y
vector<Point> convexHullFromSorted(const vector<Point>& pts) {
    int n = (int)pts.size();
    if (n <= 1) return pts;
    vector<Point> lower, upper;
    lower.reserve(n);
    upper.reserve(n);
    for (int i = 0; i < n; ++i) {
        while (lower.size() >= 2 && cross128(lower[lower.size()-2], lower.back(), pts[i]) <= 0)
            lower.pop_back();
        lower.push_back(pts[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        while (upper.size() >= 2 && cross128(upper[upper.size()-2], upper.back(), pts[i]) <= 0)
            upper.pop_back();
        upper.push_back(pts[i]);
    }
    lower.pop_back();
    upper.pop_back();
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}

// get max dot product of vector (A, -B) with convex polygon points
long long maxDotOnConvexPolygon(const vector<Point> &hull, long long A, long long B) {
    int H = (int)hull.size();
    auto val = [&](int i) -> long long {
        return hull[i].x * A - hull[i].y * B;
    };
    if (H <= 64) { // small hull: brute force is fine
        long long best = LLONG_MIN;
        for (int i = 0; i < H; ++i) best = max(best, val(i));
        return best;
    }

    int l = 0, r = H - 1;
    while (r - l > 3) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (val(m1) < val(m2)) l = m1;
        else r = m2;
    }
    long long best = LLONG_MIN;
    for (int i = l; i <= r; ++i) best = max(best, val(i));
    return best;
}

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = (int)skill.size();
        int m = (int)mana.size();
        if (n == 0 || m == 0) return 0;

        // prefix sums T_j
        vector<ll> T(n);
        T[0] = skill[0];
        for (int i = 1; i < n; ++i) T[i] = T[i-1] + skill[i];

        // points P_j = (T_j, T_{j-1})
        vector<Point> pts;
        pts.reserve(n);
        for (int j = 0; j < n; ++j) {
            ll tjm1 = (j == 0 ? 0LL : T[j-1]);
            pts.push_back({ T[j], tjm1 });
        }

        // convex hull
        vector<Point> hull = convexHullFromSorted(pts);

        long long cur_t = 0;
        for (int i = 1; i < m; ++i) {
            long long A = (long long)mana[i-1];
            long long B = (long long)mana[i];
            long long t = maxDotOnConvexPolygon(hull, A, B);
            cur_t += t;
        }
        return cur_t + T[n-1] * (long long)mana[m-1];
    }
};
