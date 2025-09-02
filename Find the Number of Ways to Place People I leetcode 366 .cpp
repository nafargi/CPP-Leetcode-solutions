class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
        });
        
        int n = points.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            int x0 = points[i][0], y0 = points[i][1];
            int bot = INT_MIN, top = y0;
            for (int j = i + 1; j < n; j++) {
                int x1 = points[j][0], y1 = points[j][1];
                if (y1 <= top && y1 > bot) {
                    cnt++;
                    bot = y1;
                    if (y1 == top) top--;
                }
            }
        }
        return cnt;
    }
};
