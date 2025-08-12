class Solution {
public:

    long long mod = 1e9 + 7;
    long long fun(int n, int ind, int t, int x, vector<vector<int>>&dp) {
        if (t == 0) return 1;
        if (t < 0) return 0;
        if (dp[ind][t] != -1) {
            return dp[ind][t];
        }
        long long ans = 0;
        for (int i = ind; i<n+1; i++) {
            int new_t = t-(pow(i, x));
            if (new_t >= 0) {
               ans += (fun(n, i+1, new_t, x, dp)%mod);
            } else {
                break;
            }
        }
        return dp[ind][t] = ans%mod;
    }

    int numberOfWays(int num, int x) {
        double result = pow(num, 1.0 / x);
       
        int n = (int)(result + 0.5);
         vector<vector<int>>dp(301, vector<int>(num+1, -1));
        return fun(n, 1, num, x, dp);
    }
};
