class Solution {
public:
    static char kthCharacter(long long k, vector<int>& operations) {
        bitset<64> B(k-1), A;
        for(int b=63-countl_zero((uint64_t)k-1); b>=0; b--) A[b]=operations[b];
        return 'a'+((A & B).count()%26);
    }
};
