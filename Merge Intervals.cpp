class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(),intervals.end(), [](const vector<int>& a, const vector<int>& b){
        return a[0]< b[0];
      });
        
        vector<vector<int>> merged;
        vector<int> prev =intervals[0];
        int size = intervals.size();

        for(int i =1; i<size ;i++){
          vector<int> interval =intervals[i];
           if(interval[0] <= prev[1]){
              prev[1] = max(interval[1],prev[1]);
           }
           else{
             merged.push_back(prev);
              prev = interval;
           }

        }
        merged.push_back(prev);
        return merged;
    }
};
