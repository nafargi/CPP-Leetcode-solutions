//Beats 79.06% of users with C++
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
       int  sumArray, max=0;
        for(int i=0; i<accounts.size(); i++){
             sumArray=0;
          for(int j=0; j< accounts[i].size(); j++){
                sumArray+=accounts[i][j];
          }
          if(sumArray>max){
            max=sumArray;
          }
    }
     return max; 
    }
};
