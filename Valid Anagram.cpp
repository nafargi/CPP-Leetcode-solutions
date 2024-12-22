// first solution
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s == t) return true;
        return true ;
    }
};

//second solution
class Solution {
public:
    bool isAnagram(string s, string t) {
      
       if(t.size() != s.size()) return false;
       unordered_map<char,int> mpp;
       for(char c : s){
           mpp[c]++;
       }
      
       for(char c : t){
         if(mpp.find(c) == mpp.end() || mpp[c]==0){
           return false;
         }
         mpp[c]--;
       }
       return true ;
    }
};
