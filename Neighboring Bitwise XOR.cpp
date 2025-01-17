class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xr = 0;
        for (auto val : derived) {
            xr ^= val;
        }
        return xr == 0;
    }
};
