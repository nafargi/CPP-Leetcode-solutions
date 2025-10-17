class Solution {
public:
    unordered_map<long long, int> memo;

    int dfs(int index, string& s, int charMask, bool canChange, int k) {
        if (index == (int)s.size()) return 0;

        long long key = ((long long)index << 27) | ((long long)charMask << 1) | (canChange ? 1LL : 0LL);
        if (memo.count(key)) return memo[key];

        int currentBit = 1 << (s[index] - 'a');
        int updatedMask = charMask | currentBit;
        int maxPartitions;

        if (__builtin_popcount(updatedMask) > k)
            maxPartitions = 1 + dfs(index + 1, s, currentBit, canChange, k);
        else
            maxPartitions = dfs(index + 1, s, updatedMask, canChange, k);

       if (canChange) {
            for (int c = 0; c < 26; ++c) {
                int newBit = 1 << c;
                int newMask = charMask | newBit;
                int partitions;
                if (__builtin_popcount(newMask) > k)
                    partitions = 1 + dfs(index + 1, s, newBit, false, k);
                else
                    partitions = dfs(index + 1, s, newMask, false, k);
                maxPartitions = max(maxPartitions, partitions);
            }
        }

        return memo[key] = maxPartitions;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        return 1 + dfs(0, s, 0, true, k);
    }
};
