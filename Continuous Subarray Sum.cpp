//this code Beats 95.26% of users with C++
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return false;
        // hash map to store the remainders
        unordered_map<int, int> mod {{0, -1}};
        int sum = 0, remainder;
        for (int i = 0; i < n; i++) {
            // prefix sum
            sum += nums[i];
            // calculate the remainder
            remainder = sum % k; 
            if (mod.count(remainder)) {
                // if remainder exists in hash map
                // check the length
                if (i - mod[remainder] >= 2) return true;
            } else {
                // mark the current index to hash map
                mod[remainder] = i;
            }
        }
        return false;
    }
};
