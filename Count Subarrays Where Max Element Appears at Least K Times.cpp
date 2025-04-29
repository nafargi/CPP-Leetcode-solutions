class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,r=0,c=0;
        long long res=0;
        while(r<n){
            if(nums[r]==mx) c++;
            while(l<=r && c>=k){
                res+=(n-r);
                if(nums[l]==mx) c--;
                l++;
            }
            r++;
        }
        return res;
    }
};
