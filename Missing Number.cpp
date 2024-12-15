//Beats 100.00%
class Solution {
public:
    int missingNumber(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        int counter = 0;
        int size = nums.size();

        for(int i=0; i< size; i++ ){
            if(nums[i] != counter)
              break;
           counter++;
        }
     return counter;
    }
};

