class Solution {
public:
    int findLHS(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int l =0; int r =1; int MaxLen =0;

        while(l < nums.size()){
            
          while(r < nums.size() &&  abs(nums[r]-nums[l]) <= 1){
            if(abs(nums[r]-nums[l]) == 1){
               MaxLen = max(MaxLen,r-l+1);
            }
            r++;
          }
          l++;
        }
        return MaxLen;
    }
};
