class Solution {
public:
    int possibleStringCount(string word) {
        long long ans = 1;                          // original
        for (int i = 0, n = word.size(); i < n; ) {
            int j = i;
            while (j < n && word[j] == word[i]) ++j; // same‑char block
            ans += (j - i - 1);                     // add (L‑1)
            i = j;
        }
        return static_cast<int>(ans);
    }
};
