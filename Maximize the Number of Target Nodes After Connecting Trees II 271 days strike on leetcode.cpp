class Solution {
public:
    pair<int, int> bfs(int n, vector<int> adj[], vector<int>& color) {
        queue<int> q;
        q.push(0);
        int even = 0, odd = 0, level = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front();
                q.pop();
                color[node] = (level % 2 == 0) ? 0 : 1;
                (level % 2 == 0) ? even++ : odd++;
                for (auto it : adj[node]) {
                    if (color[it] == -1) {
                        q.push(it);
                    }
                }
            }
            level++;
        }
        return {even, odd};
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> adj1[n], adj2[m];
        for (int i = 0; i < edges1.size(); i++) {
            int u = edges1[i][0], v = edges1[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for (int i = 0; i < edges2.size(); i++) {
            int u = edges2[i][0], v = edges2[i][1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        vector<int> color(n, -1);
        pair<int, int> p1 = bfs(n, adj1, color);
        vector<int> temp(m, -1);
        pair<int, int> p2 = bfs(m, adj2, temp);
        int maxi = max(p2.first, p2.second);
        for (int i = 0; i < n; i++) {
            int even = p1.first, odd = p1.second;
            if (color[i] == 0)
                color[i] = even + maxi;
            else
                color[i] = odd + maxi;
        }
        return color;
    }
};
