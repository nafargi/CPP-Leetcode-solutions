class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long currentStreak = 0;
        
        for (int num : nums) {
            if (num == 0) {
                // If we find a zero, increment the streak length.
                currentStreak++;
                // Add the current streak length to the total count.
                // A streak of k zeros adds k new subarrays.
                ans += currentStreak;
            } else {
                // If we find a non-zero, the streak is broken.
                currentStreak = 0;
            }
        }
        
        return ans;
    }
};
