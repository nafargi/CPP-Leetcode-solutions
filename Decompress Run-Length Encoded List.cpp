// this code Beats 100.00% of users with C++
class Solution {
    public int[] decompressRLElist(int[] nums) {
        int sizeOfArray=0;
        for(int i=0; i<nums.length; i+=2){
           sizeOfArray+=nums[i];
        }
        int[] concatenatedArray = new int[sizeOfArray];
        
        int index=0;
        for(int i=0; i<nums.length; i+=2){
             for(int j=0; j<nums[i]; j++){
                concatenatedArray[index++] = nums[i+1];
             }
        }
        return concatenatedArray;
    }
}
