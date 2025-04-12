using ll = long long;

class Solution {
public:
    ll memo[11] = {0}; // For factorial memoization
    unordered_set<string> st; // To store sorted digit strings (avoid duplicate permutations)

    long long countGoodIntegers(int n, int k) {
        string number(n, ' '); // Placeholder for the palindrome
        unordered_map<int, int> freq; // Frequency of digits used
        int end = ceil(n / 2.0) - 1; // Only generate till the middle
        ll ans = 0;
        rec(0, end, n, k, number, freq, ans);
        return ans;
    }

    void rec(int i, int& end, int& n, int& k, string& number, unordered_map<int, int>& freq, ll& ans) {
        if (i > end) {
            ans += count(number, freq, k); // Check if palindrome is good and count valid permutations
            return;
        }
        for (int j = 0; j < 10; j++) {
            if (!i && !j) continue; // Avoid leading zero at first digit
            int front = i;
            int back = (n - i - 1);
            number[front] = char(j + '0');
            freq[j]++;
            if (back > front) {
                number[back] = char(j + '0');
                freq[j]++;
            }

            rec(i + 1, end, n, k, number, freq, ans);

            if (back > front) freq[j]--;
            freq[j]--;
        }
    }

    ll count(const string& number, unordered_map<int, int>& freq, const int& k) {
        // Convert number to integer and check if divisible by k
        ll real = stoll(number);
        if (real % k) return 0;

        // Avoid counting same digit permutations
        string copy = number;
        sort(copy.begin(), copy.end());
        if (st.find(copy) != st.end()) return 0;
        st.insert(copy);

        // Count permutations using P&C
        int n = number.size();
        int zero = freq[0];

        ll r = fact(n - 1); // (n-1)! for total arrangements
        ll ans = (n - zero) * r; // Multiply by non-zero start digits

        // Divide by repeated digit factorials
        for (auto i : freq) {
            ll res = fact(i.second);
            ans = ans / res;
        }

        return ans;
    }

    ll fact(const int& n) {
        // Efficient factorial with memoization
        if (memo[n] != 0) return memo[n];
        memo[0] = 1;
        memo[1] = 1;
        for (int i = 1; i <= n; i++) {
            memo[i] = memo[i - 1] * i;
        }
        return memo[n];
    }
};
