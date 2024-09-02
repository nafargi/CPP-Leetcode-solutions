//this code Beats 95.26% of users with C++
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return false;
        unordered_map<int, int> mod {{0, -1}};
        int sum = 0, remainder;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            remainder = sum % k; 
            if (mod.count(remainder)) {
                if (i - mod[remainder] >= 2) return true;
            } else {
                mod[remainder] = i;
            }
        }
        return false;
    }
};
