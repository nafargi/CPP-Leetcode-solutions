class Solution {
public:
    bool isMatch(string s, string p) {
        int si = 0, pi = 0, match = 0, star = -1;
        int sn = s.length(), pn = p.length();
        while (si < sn) {
            if (pi < pn && (p[pi] == '?' || p[pi] == s[si])) {
                si++;
                pi++;
            } else if (pi < pn && p[pi] == '*') {
                star = pi;
                match = si;
                pi++;
            } else if (star != -1) {
                pi = star + 1;
                match++;
                si = match;
            } else {
                return false;
            }
        }
        while (pi < pn && p[pi] == '*') {
            pi++;
        }
        return pi == pn;
    }
};
