class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int sum_xor=0;
        if (nums2.size()&1) 
            sum_xor=reduce(nums1.begin(), nums1.end(), 0, bit_xor<>());
        if (nums1.size()&1)
            sum_xor=reduce(nums2.begin(), nums2.end(), sum_xor, bit_xor<>());
        return sum_xor;
    }
};
