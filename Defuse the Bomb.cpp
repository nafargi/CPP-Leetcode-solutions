class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
       int  pk= abs(k);

        if( k > 0){
          vector<int> sum(code.size(),0);
          for(int i =0; i < code.size(); i++){
              for(int j =1; j <= k ; j++ ){
                   sum[i] += code[ (i+j) % code.size()];
              }
          }
          return sum;
        }

        else if(k < 0){
         vector<int> sum(code.size(),0);
         int n =  code.size()-1;
         for(int i =0; i < code.size(); i++){
              for(int j = 1;j <= pk ; j++ ){
                   sum[i] += code[(i-j+ code.size()) % code.size()];
                   n--;
              }
         }
          return sum;
        }

        else{
           vector<int> sum(code.size(),0);
           return sum;
    }
    }
};
