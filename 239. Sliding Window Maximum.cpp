class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> output;
        deque<int> dq;

        for(int i = 0; i < size; i++){
            if(!dq.empty() && dq.front() == i - k){
                dq.pop_front();
            }

            
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i >= k - 1){
                output.push_back(nums[dq.front()]);
            }
        }
        return output;
    }
};
