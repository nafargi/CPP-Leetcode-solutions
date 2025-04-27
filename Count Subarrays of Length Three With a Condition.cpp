class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;  // Count of Good Squads
        int n = nums.size();

        // Check each group of 3 consecutive soldiers
        for (int i = 0; i < n - 2; i++) {
            int first = nums[i];
            int middle = nums[i + 1];
            int third = nums[i + 2];

            // Check if the squad is a Good Squad
            if ((first + third) * 2 == middle) {
                count++;  // Good Squad!
            }
        }

        return count;  // Return total Good Squads count
    }
};
