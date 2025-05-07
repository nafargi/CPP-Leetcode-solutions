class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size(), res = 0;
        int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<int>> times(n, vector<int>(m, INT_MAX));

        pq.push({0, 0, 0});
        times[0][0] = 0;

        while(!pq.empty()) {
            auto [t, i, j] = pq.top(); pq.pop();

            if(t > times[i][j])
                continue;

            if(i == n - 1 && j == m - 1)
                return t;

            for(int d = 0; d < 4; ++d) {
                int nr = dirs[d][0] + i, nc = dirs[d][1] + j;

                if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                int time = max(t, moveTime[nr][nc]) + 1;

                if(time < times[nr][nc]) {
                    times[nr][nc] = time;
                    pq.push({time, nr, nc});
                }
            }
        }

        return -1;
    }
};
