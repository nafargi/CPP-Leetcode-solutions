class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        
        int minLen = strs[0].size();
        for(const string& str : strs){
           minLen =min(minLen,(int)str.size());
        }
        string ans = "";
        for(int i=0; i< minLen; i++){
            char letter = strs[0][i];
          for (const string& str :strs){
                if(str[i] != letter){
                    return ans;
                }
          }
         
         ans.push_back(letter);
        }
        return ans;
    }
    
};





