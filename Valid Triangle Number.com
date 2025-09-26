#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& sides) {
        sort(sides.begin(), sides.end());
        int n = sides.size();
        int totalTriangles = 0;

        for (int longest = n - 1; longest >= 2; --longest) {
            int left = 0, right = longest - 1;
            while (left < right) {
                if (sides[left] + sides[right] > sides[longest]) {
                    totalTriangles += (right - left);
                    right--;
                } else {
                    left++;
                }
            }
        }

        return totalTriangles;
    }
};
