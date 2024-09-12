//this code is Beats 67.39% of users with C++
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int n= mat.size()-1;
        for(int i=0; i<mat.size(); i++){
             for(int j=0; j<mat.size(); j++){
                if(i==j){
                    sum=sum + mat[i][j] + mat[i][n];
                    if(i == n){
                        sum= sum - mat[i][n];
                    }
                    n--; 
                }
             }
        }
        return sum;
    }
};
