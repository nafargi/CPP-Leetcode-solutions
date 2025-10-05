class Solution {
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int rows, cols;
    vector<vector<int>> h;

public:
    vector<vector<bool>> bfs(queue<pair<int, int>>& q) {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            visited[i][j] = true;

            for (auto& d : dir) {
                int newRow = i + d[0];
                int newCol = j + d[1];
                if (newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols)
                    continue;
                if (visited[newRow][newCol])
                    continue;
                if (h[newRow][newCol] < h[i][j])
                    continue;
                q.push({newRow, newCol});
            }
        }
        return visited;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        h = heights;

        queue<pair<int, int>> pacificbfs, atlanticbfs;
        for (int i = 0; i < rows; i++) {
            pacificbfs.push({i, 0});
            atlanticbfs.push({i, cols - 1});
        }
        for (int j = 1; j < cols; j++) pacificbfs.push({0, j});
        for (int j = 0; j < cols - 1; j++) atlanticbfs.push({rows - 1, j});

        vector<vector<bool>> pacific = bfs(pacificbfs);
        vector<vector<bool>> atlantic = bfs(atlanticbfs);

        vector<vector<int>> ans;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};
