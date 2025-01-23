class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<int> rc(r, 0);
        vector<int> cc(c, 0);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j]) {
                    rc[i]++;
                    cc[j]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] && (rc[i] > 1 || cc[j] > 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
