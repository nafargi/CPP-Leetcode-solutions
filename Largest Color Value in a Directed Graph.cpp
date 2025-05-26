class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        vector<vector<int>> dp(n, vector<int>(26, 0));

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
            dp[i][colors[i] - 'a'] = 1;
        }

        int visited = 0;
        int ans = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            visited++;

            for (int v : graph[u]) {
                for (int i = 0; i < 26; i++) {
                    int val = dp[u][i] + ((colors[v] - 'a') == i);
                    dp[v][i] = max(dp[v][i], val);
                }
                if (--indegree[v] == 0)
                    q.push(v);
            }
            for (int i = 0; i < 26; i++) ans = max(ans, dp[u][i]);
        }

        return visited == n ? ans : -1;
    }
};
