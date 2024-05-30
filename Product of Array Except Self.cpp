//Beats 89.59% of users with C++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        answer[0] = 1;

        int prod = 1;

        for (int i = 0; i < n - 1; i++) {
            prod *= nums[i];
            answer[i+1] = prod;
        }

        prod = 1;

        for (int i = n - 1; i > 0; i--) {
            prod*=nums[i];
            answer[i-1] *= prod;
        }

        return answer;
    }
};
