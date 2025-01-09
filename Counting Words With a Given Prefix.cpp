class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        
        int t=0;
        for(int i=0;i<n;i++){
            int m=pref.size();
           // cout<<words[i].substr(0,m-1);
            if(words[i].substr(0,m)==pref){
                t++;
            }
        }
        return t;
    }
};
