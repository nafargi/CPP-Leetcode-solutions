class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        int dp[n][m];
        memset(dp,-1,sizeof(dp));
        dp[0][0] = grid[0][0];
        int dx[] ={1,-1,0,0};
        int dy[] ={0,0,1,-1};
        queue <pair<int,int>> q,q1;
        q.push({0,0});
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x = p.first+dx[i],y=p.second+dy[i];
                if(x>=0&&x<n&&y>=0&&y<m&&dp[x][y]==-1){
                    dp[x][y] = dp[p.first][p.second] + grid[x][y];
                    if(grid[x][y]){
                        q1.push({x,y});
                    }
                    else
                    {
                        q.push({x,y});
                    }
                }
            }
            if(q.empty()){
                swap(q,q1);
            }
        }
        return dp[n-1][m-1];
    }
};
