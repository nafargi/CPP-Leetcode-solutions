class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() <k) return false;

        unordered_map<char,int> freq;
        for(char c : s){
            freq[c]++;
        }
        int odd;
        for(auto& pair : freq)
         if(pair.second % 2 != 0)
           odd++;
        return odd <= k;
    }
};
