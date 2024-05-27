//Beats 97.10% of users with C++
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        std::sort(nums.begin(), nums.end());

        int maxDiff = 0;
        for (int i = 1; i < nums.size(); i++) {
            maxDiff = std::max(maxDiff, nums[i] - nums[i - 1]);
        }
        return maxDiff;
    }
};

auto speedHack = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
