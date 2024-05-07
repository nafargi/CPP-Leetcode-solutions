//this code Beats 100.00% of users with C++
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
     vector<bool> boolArray;

        for(int i=0; i<candies.size(); i++){
             bool  isMax=true;

            for(int j=0; j<candies.size(); j++){
                if(candies[i]+extraCandies < candies[j] ){
                    isMax=false;
                    break;
                }
            }
            boolArray.push_back(isMax);
        }
        return  boolArray;
    }
};
