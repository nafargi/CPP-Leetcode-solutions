class Solution {
public:
    int solve(int prev, int curr, int n, int k, vector<int> &nums, vector<vector<int>>& dp) {
        if (curr >= n - 1) {
            return 0;
        }
        if (dp[curr][prev + 1] != -1) {
            return dp[curr][prev + 1];
        }

        if (prev == -1) {
            int not_take = solve(prev, curr + 1, n, k, nums, dp);
            int take = INT_MIN;

            for (int j = curr + 1; j < n; j++) {
                take = max(take, 2 + solve((nums[curr] + nums[j]) % k, j, n, k, nums, dp));
            }

            return dp[curr][prev + 1] = max(take, not_take);
        }

        for (int j = curr + 1; j < n; j++) {
            if ((nums[curr] + nums[j]) % k == prev) {
                return dp[curr][prev + 1] = 1 + solve(prev, j, n, k, nums, dp);
            }
        }
        return dp[curr][prev + 1] = 0;
    }

    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(-1, 0, n, k, nums, dp);
    }
};
