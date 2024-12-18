class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxNum = -DBL_MAX;
        int sum =0;
        for(int i=0; i<k; i++){
             sum += nums[i];
        }
      maxNum = sum / (double)k;
      int startIndex=0;
      int endIndex = k;

      while(endIndex < nums.size()){
         sum -=nums[startIndex];
         sum += nums[endIndex];
        
         startIndex++;
        endIndex++;
        
         maxNum = max(maxNum,sum / (double)k);
      }
      return maxNum;
    }
};
