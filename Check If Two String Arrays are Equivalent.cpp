//this code Beats 100.00% of users with C++
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
       string stringWord1;
       string stringWord2;

       for(int i=0; i<word1.size(); i++){
            for(int j=0; j<word1[i].size(); j++){
               stringWord1.push_back(word1[i][j]);
            }
       }
       
       for(int i=0; i<word2.size(); i++){
            for(int j=0; j<word2[i].size(); j++){
               stringWord2.push_back(word2[i][j]);
            }
       }
     
    return stringWord1==stringWord2;
    }
};
