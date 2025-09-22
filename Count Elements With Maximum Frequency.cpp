class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        short freq[101]{},max_val=-1,res;
        for(int&val:nums)
            freq[val]++;
        for(short&val:freq)
            max_val=max(max_val,val);
        for(short&val:freq)
            if(val==max_val) 
                res+=max_val;
        return res;
    }
};
