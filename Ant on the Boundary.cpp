class Solution {
 public:11111
  int returnToBoundaryCount(vector<int>& nums) {
    partial_sum(nums.begin(), nums.end(), nums.begin());
    return ranges::count(nums, 0);
  }
};
