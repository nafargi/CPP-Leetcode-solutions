//this code Beats 90.65% of users with C++
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>left(nums.size());
        vector<int> right(nums.size());
        left[0]=0;
        right[nums.size()-1]=0;
        
        for(int i =0; i<nums.size()-1; ++i){
           left[i+1]=nums[i] + left[i];
        }

        for(int i =nums.size() -2 ; i >= 0 ; i--) {
            right[i] = right[i+1] + nums[i+1];  
        }

        for(int i=0;i<nums.size(); ++i){
            nums[i]=abs(right[i]-left[i]);
        }

     return nums;
        
    }
};
