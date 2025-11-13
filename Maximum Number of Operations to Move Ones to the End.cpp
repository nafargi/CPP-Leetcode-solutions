class Solution {
public:
    int maxOperations(string s) {
        int one = 0;
        int total = 0;

        for (int i = 0 ; i < s.length() ; i++){
            if (s[i] == '1')
              ++one;

            else if(i + 1 == s.length() || s[i + 1] == '1')
              total += one;
        }

        return total;
    }
};
