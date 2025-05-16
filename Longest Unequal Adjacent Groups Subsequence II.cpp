class Solution {
public:
    bool isOneCharDiff(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                if (++diff > 1) return false;
            }
        }
        return diff == 1;
    }

    int func(int index,int prev,vector<string>& words, vector<int>& groups, vector<vector<int>>& dp){
        if(index==words.size())
        return 0;
        if(dp[index][prev+1]!=-1)
          return dp[index][prev+1];
        int l=0,m=0;
        if(prev==-1 || (words[index].size()==words[prev].size() && groups[index]!=groups[prev] && isOneCharDiff(words[index],words[prev]))){
            l=1+func(index+1,index,words,groups,dp);
        }
        m=func(index+1,prev,words,groups,dp);

        return dp[index][prev+1]= max(l,m);
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        func(0,-1,words,groups,dp);
        vector<string> ans;
        int j=0;
        for(int i=0;i<n;i++){
            if(i==n-1)
            {
                if(dp[i][j]==1)
                ans.push_back(words[i]);
                continue;
            }
            if(dp[i+1][j]==dp[i][j])
            continue;
            else{
                ans.push_back(words[i]);
                j=i+1;
            }
        }

        return ans;
        

    }
};
