class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
         vector<int> arr(nums.size());

        for(int i=0; i<nums.size(); i+=2){

             int aliceMin=INT_MAX;
             int bobMin=INT_MAX;
            for(int j=0; j<nums.size(); j++){
                aliceMin=min( aliceMin,nums[j]);
            }

             arr[i+1]=aliceMin;
             for(int j=0; j<nums.size(); j++){
                if(aliceMin==nums[j]){
                    nums[j]=INT_MAX;
                    break;
                }
             }

             for(int j=0; j<nums.size(); j++){
                bobMin=min(bobMin,nums[j]);
            }

           arr[i]=bobMin;
            for(int j=0; j<nums.size(); j++){
                if(bobMin==nums[j]){
                    nums[j]=INT_MAX;
                    break;
                }
             }
           
        }
        return arr;
    }
};
