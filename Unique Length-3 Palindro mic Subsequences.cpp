class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        int ans=0;
        unordered_set<char> st;
        for(int i=0;i<n-2;i++){
            char ch=s[i];
            if(st.find(ch)!=st.end()) continue;
            st.insert(ch);
            unordered_set<char> temp;
            int idx=-1;
            for(int j=i+1;j<n;j++){
                if(s[j]==ch) idx=j;
            }
            for(int j=i+1;j<idx;j++){
                temp.insert(s[j]);
            }
            ans+=temp.size();
        }
        return ans;
    }
};
