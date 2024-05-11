//this code  Beats 100.00% of users with C++
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int result=0;
        for(int i=0; i<nums.size(); i++){
            if(k>nums[i]){
                result++;
            }
        }
        return result;
    }
};
