class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0); // DP array for travel days
        
        for (int i = 0; i < n; ++i) {
            // Option 1: Take a 1-day ticket
            int cost1 = dp[i] + costs[0];
            
            // Option 2: Take a 7-day ticket
            int j = i;
            while (j >= 0 && days[j] >= days[i] - 6) --j;
            int cost7 = dp[j + 1] + costs[1];
            
            // Option 3: Take a 30-day ticket
            j = i;
            while (j >= 0 && days[j] >= days[i] - 29) --j;
            int cost30 = dp[j + 1] + costs[2];
            
            // Choose the minimum of the three options
            dp[i + 1] = min({cost1, cost7, cost30});
        }
        
        return dp[n];
    }
};
