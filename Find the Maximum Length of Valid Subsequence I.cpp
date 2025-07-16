#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        if (nums.empty()) return 0;

        int oddCount = 0, evenCount = 0, alternating = 0;
        bool expectOdd = nums[0] % 2 == 1;

        for (int n : nums) {
            bool isOdd = n % 2 == 1;

            if (isOdd == expectOdd) {
                ++alternating;
                expectOdd = !expectOdd;
            }

            if (isOdd) ++oddCount;
            else ++evenCount;
        }

        return max({oddCount, evenCount, alternating});
    }
};
