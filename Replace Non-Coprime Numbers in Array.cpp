class Solution {
private:
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stk;  
        for (int x : nums) {
            long long cur = x;
            while (!stk.empty()) {
                long long top = stk.back();
                long long g = gcd(top, cur);
                if (g == 1) {
                    break;  
                }
                stk.pop_back();
                cur = lcm(top, cur);
            }
            stk.push_back(cur);
        }return stk;
    }
};
