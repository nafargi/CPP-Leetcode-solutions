class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int sum[100001];
        sum[0] = 1;
        for (int i = 1; i <= high; i++)
        {
            long long sumCur = 0;
            if (i >= zero)
                sumCur += sum[i-zero];
            if (i >= one)
                sumCur += sum[i-one];
            if (sumCur > 0x3000000000000000ll)
                sumCur %= 1000000007;
            sum[i] = sumCur % 1000000007;
        }

        long long sumTotal = 0;
        for (int i = low; i <= high; i++)
            sumTotal += sum[i];
        return sumTotal % 1000000007;
    }
};
