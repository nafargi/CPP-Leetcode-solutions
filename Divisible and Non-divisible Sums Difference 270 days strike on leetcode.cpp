class Solution {
public:

    int DFS(int node, int par, int dist, vector<vector<int>>& edge){
        if(dist < 0){
            return 0;
        }

        int cr = 1;

        for(auto adj : edge[node]){
            if(adj != par){
                cr += DFS(adj, node, dist-1, edge);
            }
        }

        return cr;
    }
    
    vector<int> maxTargetNodes(vector<vector<int>>& e1, vector<vector<int>>& e2, int k) {
        int n = e1.size()+1;
        int m = e2.size()+1;
        
        vector<vector<int>> edge1(n);
        vector<vector<int>> edge2(m);

        for(int i=0; i<n-1; i++){
            edge1[e1[i][0]].push_back(e1[i][1]);
            edge1[e1[i][1]].push_back(e1[i][0]);
        }

        for(int i=0; i<m-1; i++){
            edge2[e2[i][0]].push_back(e2[i][1]);
            edge2[e2[i][1]].push_back(e2[i][0]);
        }

        int mxIn2 = 0;
        for(int i=0; i<m; i++){
            int ifInode = DFS(i,-1,k-1,edge2);
            mxIn2 = max(mxIn2, ifInode);
        }

        vector<int> ans(n);

        for(int i=0; i<n; i++){
            int cur = DFS(i,-1,k,edge1);
            ans[i] = cur + mxIn2;
        }

        return ans;
    }
};
