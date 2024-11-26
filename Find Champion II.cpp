class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        for(auto& edge: edges)
            indegree[edge[1]]++;
        
        int start_point=0;
        int champion;
        for(int i=0;i<n;++i)
            if(indegree[i]==0){
                start_point++;
                champion=i;
            }
        
        return start_point==1?champion:-1;
    }
};
