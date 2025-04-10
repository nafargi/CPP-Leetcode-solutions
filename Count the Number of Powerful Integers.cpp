typedef long long int ll;

ll dp[2][18];

class Solution {
    
    int limit;
    int len;
    vector<int> suffix;
    vector<int> max_val;
    
    ll PowerfulIntegers (int ind, bool is_smaller) {      
        if (ind == len) return 1;
        if (dp[is_smaller][ind] != -1) return dp[is_smaller][ind];
        
        ll &ans = dp[is_smaller][ind];
        ans = 0;
    
        int st = (ind == 0)? 1 : 0;
        int ed = min(is_smaller ? 9 : max_val[ind], limit);
        
        int suffix_start_ind = len - suffix.size();
        if (suffix_start_ind <= ind) {
            st = max(st, suffix[ind - suffix_start_ind]);
            ed = min(ed, suffix[ind - suffix_start_ind]);
        }
                
        for (int i = st; i <= ed; i++) {
            bool new_is_smaller  = is_smaller  || i < max_val[ind];
            ans += PowerfulIntegers(ind + 1, new_is_smaller);
        }
        return ans;
    } 
    
    ll UptoX (ll x) {
        string s = to_string(x);
        int max_len = s.length();
        
        if (max_len < suffix.size()) return 0;
        
        ll ans = 0;
        
        for (len = suffix.size(); len < max_len; len++) {
            max_val.clear();
            for (int i = 0; i < len; i++) max_val.push_back(9);
            
            memset(dp, -1, sizeof(dp));
            ans += PowerfulIntegers(0, false);            
        }
        
        max_val.clear();
        for (auto i : s) max_val.push_back(i - '0');
        
        memset(dp, -1, sizeof(dp));
        ans += PowerfulIntegers(0, false);
        
        return ans;
    }
    
public:
    long long numberOfPowerfulInt(long long start, long long finish, int _limit, string s) {
        limit = _limit;
        
        suffix.clear();
        for (auto i : s) suffix.push_back(i - '0');
        
        return (UptoX(finish) - UptoX(start - 1));
    }
};
