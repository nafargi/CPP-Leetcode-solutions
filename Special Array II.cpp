class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> maxR(n);
        int R = 0;
        for(int L = 0; L < n; L++) {
           
            R = max(R, L);
            while(R < (n - 1) && nums[R] % 2 != nums[R+1] % 2) {
                ++R;
            }

            maxR[L] = R;
        }
        vector<bool> res(queries.size());
        for(int i = 0, qn = queries.size(); i < qn; i++) {
            res[i] = queries[i][1] <= maxR[queries[i][0]];
        }
        return res;
    }
};
