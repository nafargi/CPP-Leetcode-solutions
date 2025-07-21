
class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        char last = s[0];
        ans.push_back(last);
        int count = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == last) {
                count++;
                if (count < 3)
                    ans.push_back(s[i]);
            } else {
                last = s[i];
                count = 1;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
