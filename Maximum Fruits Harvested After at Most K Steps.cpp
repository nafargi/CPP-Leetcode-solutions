class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> pos(n), prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pos[i] = fruits[i][0];
            prefix[i + 1] = prefix[i] + fruits[i][1];
        }

        auto fruitInRange = [&](int left, int right) -> int {
            int l = 0, r = n - 1, start = n;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (pos[mid] >= left) {
                    start = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            l = 0, r = n - 1;
            int end = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (pos[mid] <= right) {
                    end = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (start > end) return 0;
            return prefix[end + 1] - prefix[start];
        };

        int maxFruits = 0;

        for (int x = 0; x <= k; x++) {
            int left = startPos - x;
            int right = startPos + max(0, k - 2 * x);
            maxFruits = max(maxFruits, fruitInRange(left, right));

            left = startPos - max(0, k - 2 * x);
            right = startPos + x;
            maxFruits = max(maxFruits, fruitInRange(left, right));
        }

        return maxFruits;
    }
};
