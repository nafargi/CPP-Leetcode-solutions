class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1){
            return word;
        }

        const string  s = lastString(word);
        const size_t sz = word.length()-numFriends + 1;
        return s.substr(0,min(s.length(),sz));

    }

    private:
     string lastString(string s){
        int i = 0;
        int j = 1;
        int k = 0;

        while (j+k < s.length()){
            if(s[i+k] == s[j+k]){
                ++k;
            }else if(s[i+k] > s[j+k]){
                j = j + k + 1;
                k = 0 ;
            }else{
                i = max(i+k+1,j);
                j = i+1;
                k = 0;

            }

        }
        return s.substr(i);
     }
};
