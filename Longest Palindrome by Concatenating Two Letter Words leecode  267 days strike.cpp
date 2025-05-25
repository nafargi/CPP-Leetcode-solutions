class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0, mid = 0;
        unordered_map<string,int> mp;

        for(const string &s : words){
            string t;
            t.push_back(s[1]);
            t.push_back(s[0]);

            if(mp.count(t)){
                ans+=4;
                if(mp[t] > 1) mp[t]--;
                else mp.erase(t);
            }
            else mp[s]++;
        }
        for(const auto &p : mp){
            string s = p.first, t;
            
            t.push_back(s[1]);
            t.push_back(s[0]);

            if(s == t) return ans + 2;
        }
        return ans;
    }
};
