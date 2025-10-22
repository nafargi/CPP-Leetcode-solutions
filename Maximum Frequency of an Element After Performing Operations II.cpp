#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        if (n == 0) return 0;
        sort(nums.begin(), nums.end());

        unordered_map<long long,int> freq;
        freq.reserve(n*2);
        for (int x: nums) freq[x]++;

        int ans = 1;

        for (auto &p : freq) {
            long long v = p.first;
            int already = p.second;
            long long lowVal = v - k;
            long long highVal = v + k;
            auto L = lower_bound(nums.begin(), nums.end(), (int)lowVal);
            auto R = upper_bound(nums.begin(), nums.end(), (int)highVal);
            int totalInRange = int(R - L);
            int need = totalInRange - already;
            int canFix = min(need, numOperations);
            ans = max(ans, already + canFix);
        }

        int l = 0;
        for (int r = 0; r < n; ++r) {
            while (l <= r && (long long)nums[r] - nums[l] > 2LL * k) ++l;
            int w = r - l + 1;
            ans = max(ans, min(w, numOperations));
        }

        return ans;
    }
};
