//Beats 100.00%
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j = height.size()-1;
        int width =0;
        int area=0;

    while(i<j){
        width = j-i;
        int  temp = width * min(height[i],height[j]);
        area = max(area,temp);
         height[i] < height[j] ? i++ : j--;
     }

     return area;
    }
};
