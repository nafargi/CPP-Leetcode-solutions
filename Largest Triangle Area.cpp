#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0.0;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    // side lengths
                    double a = getDist(points[i], points[j]);
                    double b = getDist(points[j], points[k]);
                    double c = getDist(points[k], points[i]);

                    double S = (a + b + c) / 2.0; // semi-perimeter

                    // Heron's formula
                    double radicand = S * (S - a) * (S - b) * (S - c);
                    if (radicand < 0) radicand = 0.0; // safeguard

                    double area = sqrt(radicand);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

private:
    double getDist(const vector<int>& p1, const vector<int>& p2) {
        int dx = p1[0] - p2[0];
        int dy = p1[1] - p2[1];
        return sqrt(dx * dx + dy * dy);
    }
};
