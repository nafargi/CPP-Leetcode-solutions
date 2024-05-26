class Solution {
 public:
  bool canBeIncreasing(vector<int>& nums) {
    bool removed = false;

    for (int i = 1; i < nums.size(); ++i)
      if (nums[i - 1] >= nums[i]) {
        if (removed)
          return false;
        removed = true;  
        if (i > 1 && nums[i - 2] >= nums[i])
          nums[i] = nums[i - 1];  
      }

    return true;
  }
};
