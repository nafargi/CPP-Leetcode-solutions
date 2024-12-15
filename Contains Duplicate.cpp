class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size()-1;

        for(int i =0; i < size ;i++){
           if(nums[i] == nums[i+1])
            return true;
        }
        return false;
    }
};
