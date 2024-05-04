class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
      
       vector<int>  ans(2*n);
       vector<int> temp1(n);
       vector<int> temp2(n);
        
         for(int i=0; i<2*n; i++){
        
            if(i < n){
                temp1[i]=nums[i];
            }
            else{
                temp2[i - n]=nums[i];
            }
        }

             int counter1=0 ;
             int counter2=0;
      for(int i=0; i < 2*n; i++){
        if(i%2==0){

            ans[i]=temp1[counter1];
            counter1++;

        }
        else{
            ans[i]=temp2[counter2];
            counter2++;
        }
      }
      return ans;
    }
};
