#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26, 0);
        int a = 'a';

        for (char c : s) {
            freq[c - a]++;
        }

        vector<int> output;
        int prevEnd = 0;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - a]--;

            if (isValid(prevEnd, i, s, freq)) {
                output.push_back(i - prevEnd + 1);
                prevEnd = i + 1;
            }
        }

        return output;
    }

    bool isValid(int start, int end, string &s, vector<int> &freq) {
        for (int i = start; i <= end; i++) {
            if (freq[s[i] - 'a'] != 0) return false;
        }
        return true;
    }
};
