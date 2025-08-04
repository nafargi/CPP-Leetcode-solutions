
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> fruitCounts;
        int windowStart = 0, maxLength = 0;

        for (int windowEnd = 0; windowEnd < n; ++windowEnd) {
            fruitCounts[fruits[windowEnd]]++;

            while (fruitCounts.size() > 2) {
                fruitCounts[fruits[windowStart]]--;
                if (fruitCounts[fruits[windowStart]] == 0)
                    fruitCounts.erase(fruits[windowStart]);
                windowStart++;
            }

            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }

        return maxLength;
    }
};
