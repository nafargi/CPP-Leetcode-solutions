class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<long> prefixSum(n + 1, 0);
        
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            
            int value = (direction == 1) ? 1 : -1;
            
            prefixSum[start] += value;
            prefixSum[end + 1] -= value;
        }
        
        for (int i = 1; i < n; i++) {
            prefixSum[i] += prefixSum[i-1];
        }
        
        for (int i = 0; i < n; i++) {
            long totalShifts = prefixSum[i];
            
            totalShifts = ((totalShifts % 26) + 26) % 26;
            
            int newChar = (s[i] - 'a' + totalShifts) % 26;
            s[i] = 'a' + newChar;
        }
        
        return s;
    }
};
