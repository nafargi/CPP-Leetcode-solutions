class Solution {
    bool dfs(int i, vector<vector<int>>& graph, unordered_map<int, bool>& safe) {
        if (safe.find(i) != safe.end()) {
            return safe[i];
        }
        safe[i] = false;
        for (auto it : graph[i]) {
            if (!dfs(it, graph, safe)) {
                return false;
            }
        }
        safe[i] = true;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, bool> safe;
        vector<int> res;

        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, safe)) {
                res.push_back(i);
            }
        }
        return res;
    }
};
