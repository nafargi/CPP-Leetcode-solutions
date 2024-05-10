class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
     vector<int> target(nums.size());
        for(int i=0;i<nums.size(); i++){
             for(int j=i+1;j<nums.size(); j++){
                if(index[i] >= index[j]){
                 index[i]++;
                }
             }
              target[index[i]] = nums[i];
        }
        return target;
    }
};
