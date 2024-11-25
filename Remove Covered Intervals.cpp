class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
         sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        int counter = 0;
        int j = 0;   

        for (int i = 1; i < intervals.size(); ++i) {
            int a = intervals[i][0], b = intervals[i][1];
            int c = intervals[j][0], d = intervals[j][1];
            
           if (a >= c && b <= d) {
                counter++;
            } else {
                j = i;
            }
        }

        return intervals.size() - counter; 
    }
};
