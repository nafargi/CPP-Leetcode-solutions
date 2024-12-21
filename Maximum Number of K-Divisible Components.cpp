class Solution {
public:
    int dfs(int u, int p, vector<vector<int>>&adj, vector<int>& values, int k, int &count){
        int sum=0;
        for(auto v: adj[u]){
            if(v!=p){
                int childSum = dfs(v,u,adj,values,k,count);
                if(childSum%k==0){
                    count++;
                }
                sum=(sum+childSum)%k;
            }
        }
        return (sum+values[u])%k;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int sum=0;
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=1;
        dfs(0,-1,adj,values,k,count);
        return count;
    }
};
