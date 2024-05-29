class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
         int n= operations.size();
        int value=0;
   
        for(int i=0; i<n ;i++){
        string temp=operations[i];
         if( temp=="++X" || temp=="X++" ){
            value++;
         }

         else if(temp=="--X" || temp=="X--"){
            value--;
         }
        }
        return value;
    }
};
