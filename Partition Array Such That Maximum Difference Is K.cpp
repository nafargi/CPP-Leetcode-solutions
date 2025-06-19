#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1, l = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[l] > k) {
                ans++;
                l = i;
            }
        }
        return ans;
    }
};
