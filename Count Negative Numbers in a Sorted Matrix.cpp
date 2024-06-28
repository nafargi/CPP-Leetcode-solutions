class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int counter = 0;
        int rowNum = grid.size();
        int colNum = grid[0].size();

        for(const auto& row : grid){
            int left = 0; int right = colNum-1;

            while( left <= right ){
                 int midNum = left + (right - left)/2;
                 if(row[midNum] < 0){
                    right = midNum - 1;
                 }else{
                    left = midNum + 1;
                 }
            }
            counter += colNum - left;
        }
        return counter;
    }
};
b