class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int,pair<int,int>> mp;
        vector<int> r(m,n), c(n,m);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                mp[mat[i][j]] = {i,j};
        for(int i=0;i<arr.size();i++){
            auto [row, col] = mp[arr[i]];
            if(--r[row]==0 || --c[col]==0) return i;
        }
        return -1;
    }
};
