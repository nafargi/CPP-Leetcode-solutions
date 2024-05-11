//this code Beats 100.00% of users with C++
class Solution {
public:
    string truncateSentence(string s, int k) {
       
        string stringWords;
        int count = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ') count++;
            if(count == k)
             return stringWords;
            else stringWords += s[i];
        }
        return stringWords;
    }
};
    
