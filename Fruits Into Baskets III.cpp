static constexpr int N=1<<18;
int seg[N];
struct segTree{
    unsigned n;
    segTree(vector<int>& A) : n(A.size()){
        build(A, 1, 0, n-1);
    }
    ~segTree(){
        fill(seg, seg+(2u*bit_ceil(n)), 0); 
    }
    void build(vector<int>& A, int idx, int l, int r) {
        if (l==r) 
            seg[idx]=A[l];
        else{
            const int m=(l+r)/2;
            build(A, 2*idx, l, m);
            build(A, 2*idx+1, m+1, r);
            seg[idx]=max(seg[2*idx], seg[2*idx+1]);
        }
    }


    int search(int idx, int l, int r, int k) {
        if (seg[idx]<k) return -1;
        if (l==r) {
            seg[idx]=-1;
            return l;
        }

        const int m=(l+r)/2;
        int pos;

        if (seg[2*idx]>=k) pos=search(2*idx, l, m, k);
        else pos=search(2*idx+1, m+1, r, k);

        seg[idx]=max(seg[2*idx], seg[2*idx+1]);
        return pos;
    }
};
void  print(int N){
    for(int i=0; i<N; i++)
        cout<<seg[i]<<",";
}
class Solution {
public:
    static int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        const int n=fruits.size();
        int ans=0;
        segTree tree(baskets);
        for (auto x: fruits)
            if (tree.search(1, 0, n-1, x)==-1)
                ans++;

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
