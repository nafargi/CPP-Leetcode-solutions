
class Solution {
public:
    int rectangleArea(int left, int right, int up, int down, const std::vector<std::vector<int>> &grid) {
        int ur = grid.size(), dr = 0, lc = grid[0].size(), rc = 0;
        for (int i = up; i <= down; ++i) {
            for (int j = left; j <= right; ++j) {
                if (!grid[i][j]) continue;
                ur = std::min(ur, i);
                dr = std::max(dr, i);
                lc = std::min(lc, j);
                rc = std::max(rc, j);
            }
        }
        if (lc > rc) return INT32_MAX / 3; // didn't find any rectangle
        return (dr - ur + 1) * (rc - lc + 1);
    }

    std::vector<std::vector<int>> rotate(std::vector<std::vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        std::vector<std::vector<int>> output(m, std::vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                output[m - j - 1][i] = grid[i][j];
            }
        }
        return output;
    }

    int checkPositions(std::vector<std::vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int output = n * m;
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = 0; j + 1 < m; ++j) {
                output = std::min(
                    output,
                    rectangleArea(0, m - 1, 0, i, grid) +
                    rectangleArea(0, j, i + 1, n - 1, grid) +
                    rectangleArea(j + 1, m - 1, i + 1, n - 1, grid)
                );
                output = std::min(
                    output,
                    rectangleArea(0, j, 0, i, grid) +
                    rectangleArea(j + 1, m - 1, 0, i, grid) +
                    rectangleArea(0, m - 1, i + 1, n - 1, grid)
                );
            }
        }
        for (int i = 0; i + 2 < n; ++i) {
            for (int j = i + 1; j + 1 < n; ++j) {
                output = std::min(
                    output,
                    rectangleArea(0, m - 1, 0, i, grid) +
                    rectangleArea(0, m - 1, i + 1, j, grid) +
                    rectangleArea(0, m - 1, j + 1, n - 1, grid)
                );
            }
        }
        return output;
    }

    int minimumSum(vector<vector<int>> &grid) {
        std::vector<std::vector<int>> rotatedGrid = rotate(grid);
        return std::min(checkPositions(grid), checkPositions(rotatedGrid));
    }
};
