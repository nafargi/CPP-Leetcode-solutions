//this code Beats 100.00% of users with C++
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
    
        vector<int> runningSum(nums.size());
        runningSum[0] = nums[0];

        for(int i=1;i<nums.size(); i++){
           runningSum[i]=nums[i] + runningSum[i-1];
        }
        return runningSum;
    }
};
