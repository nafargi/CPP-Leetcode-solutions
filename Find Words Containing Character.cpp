dddddd
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> numList ;   
        for(int i=0; i<words.size(); i++){
          string  charArray= words[i];
            for(int j=0 ; j<charArray.length() ; j++){
                
                 if(charArray[j]==x){
                  numList.push_back(i);
                    break;
                 }
            }
        }
        return numList;
    }
};
