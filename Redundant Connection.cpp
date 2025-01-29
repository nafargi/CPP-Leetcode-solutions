class Solution {
public:

    vector<int> parent;
    vector<int> size;

    int findParent(int x){
        if(parent[x] == x) return x;

        return parent[x] = findParent(parent[x]);
    }

    void UnionBySize(int x, int y){//Join components on based of size
        int parent_x = findParent(x);
        int parent_y = findParent(y);

        if(size[parent_x] > size[parent_y]){
            parent[parent_y] = parent_x;
            size[parent_x] += size[parent_y];
        }
        else{
            parent[parent_x] = parent_y;
            size[parent_y] += size[parent_x];   
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        for(const auto&edge : edges){
            //As Edges are from 1 to n , for our indexing we will subtract 1
            int x = edge[0] - 1;
            int y = edge[1] - 1;

            int parent_x = findParent(x);
            int parent_y = findParent(y);

            if(parent_x == parent_y){//Component is already connected
                return edge;
            }else{//Join the Components
                UnionBySize(x, y);
            }
        }

        return {};
    }
};
