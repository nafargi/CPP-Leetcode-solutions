class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 
        deque<pair<int, int>> dq;
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));

        dq.emplace_back(0, 0);
        cost[0][0] = 0;

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; ++i) {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newCost = cost[x][y] + (grid[x][y] != i + 1);

                    if (newCost < cost[nx][ny]) {
                        cost[nx][ny] = newCost;

                        if (grid[x][y] == i + 1) {
                            dq.emplace_front(nx, ny); 
                        } else {
                            dq.emplace_back(nx, ny); 
                        }
                    }
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};
