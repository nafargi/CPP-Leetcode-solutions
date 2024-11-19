class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int k = 0;
       for(int i =0; i < nums.size()-1; i++){
          if(nums[i] != nums[i+1]){
            nums[k] = nums[i];
            k++;
          }
       }
       nums[k++] = nums[nums.size()-1];
        return k;
    }
};
