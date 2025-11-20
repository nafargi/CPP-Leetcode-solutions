class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int prev1 = intervals[0][1] - 1;
        int prev2 = intervals[0][1];
        int count = 2;

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end   = intervals[i][1];
            if (prev2 < start) {
                prev1 = end - 1;
                prev2 = end;
                count += 2;
            }
            else if (prev1 < start) {
                if (end == prev2)
                    prev1 = end - 1;
                else
                    prev1 = end;
                if (prev1 > prev2)
                    std::swap(prev1, prev2);

                count += 1;
            }
        }

        return count;
    }
};
