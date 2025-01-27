class Solution {
    void dfs(const int cur, const vector<vector<int>>& g, vector<int>& order, vector<bool>& state) {
        if(state[cur]) {
            return;
        }
        state[cur] = 1;
        for(const int next : g[cur]) {
            dfs(next, g, order, state);
        }
        order.emplace_back(cur);
    }

public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bitset<128>> reach(n);
        vector<vector<int>> g(n);
        for(const auto& prerequisite : prerequisites) {
            g[prerequisite[0]].emplace_back(prerequisite[1]);
            reach[prerequisite[0]].set(prerequisite[1]);
        }

        vector<int> order; order.reserve(n);
        vector<bool> state(n);
        for(int i = 0; i < n; i++) {
            dfs(i, g, order, state);
        }

        for(int i = 0; i < n; i++) {
            for(const int next : g[order[i]]) {
                reach[order[i]] |= reach[next];
            }
        }

        vector<bool> res; res.reserve(queries.size());
        for(const auto& query : queries) {
            res.emplace_back(reach[query[0]][query[1]]);
        }

        return res;
    }
};
