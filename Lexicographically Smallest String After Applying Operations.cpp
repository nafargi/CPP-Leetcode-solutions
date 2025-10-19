class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        string res = s;
        while (!q.empty()){
            string curr = q.front();
            q.pop();
            if (visited.count(curr))
                continue;
            visited.insert(curr);
            res = min(res, curr);
            string s1 = curr;
            for (int i = 1; i < s1.size(); i += 2){
                s1[i] = (s1[i] - '0' + a) % 10 + '0';
            }
            string s2 = curr.substr(curr.size() - b) + curr.substr(0, curr.size() - b);
            q.push(s1);
            q.push(s2);
        }
        return res;
    }
};
