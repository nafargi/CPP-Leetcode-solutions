class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int leftSum=0; // used for to know the left total sum of the array
    int totalSum =0 ;// used for t know the total sum of the array
     int rightSum =0; //used for to know the total right sum of the array
    
    //this loop helps me to find the total sum of the array
    for(int i =0; i< nums.size();i++){
        totalSum += nums[i];
    }
    
    //this loop used for checking weather the leftsum and rightSum are equal
    for(int j=0;j<nums.size();j++){
        rightSum = totalSum -leftSum -nums[j];
        if(leftSum == rightSum ){
            return j;
        }
        leftSum += nums[j]; //used for update ...adding the specific numbers to the leftSum
    }
    
    return -1;
    }
};
