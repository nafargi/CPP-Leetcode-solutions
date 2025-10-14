#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string> w) {
        vector<string> r;
        for (auto& s : w) {
            if (!r.empty()) {
                string a = r.back(), b = s;
                sort(a.begin(), a.end());
                sort(b.begin(), b.end());
                if (a == b) continue;
            }
            r.push_back(s);
        }
        return r;
    }
};
