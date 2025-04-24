class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;

        unordered_set<int>s;
        unordered_map<int,int>mp;

        for(auto x:nums) s.insert(x);

        int ans=0;
        
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()==s.size()){
                ans+=n-j;
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};
