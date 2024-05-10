class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
    int sum=0;
    for(int i=0; i< nums.size(); i++){
        string binaryString =bitset<sizeof(int) *8>(i).to_string();
        int counter=0;
        for(char bit:binaryString ){
            if(bit == '1')
            counter++;
          } 
           if(k == counter){
            sum+=nums[i];
            }
       }
      return sum; 
    }
};
