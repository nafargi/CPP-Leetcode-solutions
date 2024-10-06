class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n =nums.size();
        int pairsCounter=0;
        return counterIndeticalPairs(nums,pairsCounter,0,0,n);
    }
    int counterIndeticalPairs( vector<int>& nums,int counter,int i, int j ,int size ){
        if(i==size-1){
            return counter;
        }
        
         if(j==size){
            return counterIndeticalPairs(nums,counter,i+1,i+2,size);
        }
        if(i<j && nums[i]==nums[j]){
            counter++;
        }
        return counterIndeticalPairs(nums,counter,i,j+1,size);
    }
};
