class Solution {
 public:llllll
  long long flowerGame(int n, int m) {
    const int xEven = n / 2;
    const int yEven = m / 2;
    const int xOdd = (n + 1) / 2;
    const int yOdd = (m + 1) / 2;
    return 1L * xEven * yOdd + 1L * yEven * xOdd;
  }
};
