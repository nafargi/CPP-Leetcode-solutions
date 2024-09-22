// this code Beats 100.00% of users with C++
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> concatenatedArray;
        for(int i=0; i<nums.size(); i+=2){
             for(int j=0; j<nums[i]; j++){
               concatenatedArray.emplace_back(nums[i+1]);
             }
        }
        return concatenatedArray;
    }

};
