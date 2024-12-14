class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int, int> mp;
        long long ans = 0;
        int R = -1;
        for(int L = 0, n = nums.size(); L < n; L++) {
            if(R < L) ++mp[nums[R=L]];
            while(R < (n - 1) && (
                abs(mp.begin()->first - nums[R+1]) <= 2 &&
                abs(mp.rbegin()->first - nums[R+1]) <= 2
            )) ++mp[nums[++R]];
            ans += (R-L+1);

            if(mp[nums[L]] == 1) mp.erase(nums[L]);
            else --mp[nums[L]];
        }
        return ans;
    }
};

auto speed = [](){cin.tie(0)->sync_with_stdio(0);return true;}();
