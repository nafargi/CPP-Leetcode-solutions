class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || k >= k - 1 + maxPts)
            return 1.0;
        if (n < k)
            return 0.0;
        std::vector<double> dp (n + 1, 0.0);
        for (int i = 1; i <= n; i++)
            dp[i] = 1.0;
        int right = std::min(n, k + maxPts - 1);
        double window = 0.0;
        for (int i = k; i <= right; i++){
            window += dp[i];
        }
        for (int i = k - 1; i >= 0; i--){
            dp[i] = window / maxPts;
            window += dp[i];
            if (i + maxPts <= n)
                window -= dp[i + maxPts];
        }
        return dp[0];
    }
};
