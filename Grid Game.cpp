class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int m = grid[0].size();
        vector<vector<long long>>dp(2, vector<long long>(m, 0));
        dp[0][0] = 0;
        dp[1][0] = (long long)grid[1][0];
        for(int j = 1; j < m; j++){
            dp[0][j] = (long long)grid[0][j] + dp[0][j - 1];
        }
        for(int j = 1; j < m - 1; j++){
            dp[1][j] = (long long)grid[1][j] + dp[1][j - 1];
        }
        dp[1][m - 1] = 0;
        long long tmp = dp[0][m - 1];
        long long res = 1e12;
        for(int j = 0; j <= m - 2; j++){
            int k = j + 1;
            res = min(res, max(dp[1][j], tmp - dp[0][k]));
        }
        return (long long)min(res, tmp);
    }
};
