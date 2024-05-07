class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n=points.size();

        for(int i=0; i<n; i++)
         for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (points[j][0] > points[j + 1][0]) {
                  swap(points[j], points[j + 1]);
                }
            }
        }

       
        vector<int> listNumber(points.size());
        for (int i = 0; i < points.size(); i++) {
            listNumber[i] = points[i][0];
        }

        int maxWidth = 0;
        for (int i = 1; i < listNumber.size(); i++) {
            int widestArea = listNumber[i] - listNumber[i - 1];
            maxWidth = maxNum(maxWidth, widestArea);
        }

        return maxWidth;
    }

private:
    int maxNum(int a, int b) {
        return (a > b) ? a : b;
    }
};
