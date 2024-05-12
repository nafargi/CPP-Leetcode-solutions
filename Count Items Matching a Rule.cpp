//this code is Beats 93.22% of users with C++
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
          int counter=0;
        for(int i=0; i < items.size(); ++i){
            vector<string>& item = items[i];
            if(ruleKey =="type" && ruleValue == item[0]){
              counter++;
            }
            else if (ruleKey =="color" && ruleValue == item[1]){
              counter++;
            }
            else if(ruleKey =="name" && ruleValue == item[2]){
              counter++;
            }  
        }
        return counter;
    }
};
