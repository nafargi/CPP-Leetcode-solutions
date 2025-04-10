//first solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counterZero =0; //counter that counter the amount of existing zeros
        int counterOne =0; // counter that counts the amount of existing ones
        int counterTwo =0; // counter that counts the amount of existing twos

       //loop used to know the amount of each numbers exist in the array
        for(int i = 0; i <nums.size();i++ ){
            if(nums[i] == 0){
                counterZero++;
            }else if(nums[i] == 1){
                counterOne++;
            }else{
              counterTwo++;
            }
        }

        //loop used to replace the zeros we find to their right spot
        for(int i =0; i< counterZero; i++){
            nums[i] = 0;
        }
        for(int i = counterZero ; i<counterZero + counterOne; i++){
            nums[i] =1;
        }
         for(int i = counterZero + counterOne ; i<nums.size(); i++){
            nums[i] =2;
        }
    }
};

//second solution 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high = nums.size()-1;
        while(mid <= high){

          if(nums[mid] == 0){
            swap(nums[low], nums[mid]);
             low++;
             mid++;
          }else if(nums[mid] == 1){
              swap(nums[low], nums[mid]);
              mid++;
          }else{
             swap(nums[mid], nums[high]);
             high--;
          }
           
        } 
    }
};
