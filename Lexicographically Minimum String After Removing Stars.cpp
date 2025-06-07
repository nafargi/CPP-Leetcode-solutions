class Solution {
public:
    string clearStars(string s) {
        int n = s.size();

        vector<vector<int>> v(26);
        priority_queue<char, vector<char>, greater<char>> pq;

        for (int i = 0; i < n; i++) {
            char *c = &(s[i]);
            if (*c == '*') {
                // assert(pq.size() > 0);
                char minChar = pq.top();

                int rightMostIndex = v[minChar].back();
                s[rightMostIndex] = '*';

                v[minChar].pop_back();
                
                // update minChar
                if (v[minChar].size() == 0)
                    pq.pop();

                continue;
            }
            
            v[*c - 'a'].push_back(i);

            if (v[*c - 'a'].size() == 1)
                pq.push(s[i] - 'a');
        }

        string ans;
        ans.reserve(n);
        for (const auto &c : s) {
            if (c != '*') ans += c;
        }

        return ans;
    }
};
