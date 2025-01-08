class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            string pfx_sfx = words[i];
            for (int j = i + 1; j < n; j++) {
                string check = words[j];
                // check if that word is present both as suffix ad prefix
                if (check.find(pfx_sfx) == 0 &&
                    (check.rfind(pfx_sfx)) == check.length() - pfx_sfx.length())
                    count++;
            }
        }
        return count;
    }
};
