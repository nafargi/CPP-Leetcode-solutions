class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        // Declare the answer vector
        vector<string>answer;

        // Outer loop is tracking all words
        for(int i = 0 ;i<words.size();i++){
            // inner loop is searching words into word[i]th string
            for(int j = 0 ;j<words.size() ;j++){
                if(words[i] != words[j] && words[j].find(words[i]) != -1){
                    answer.push_back(words[i]);
                    break;
                }
            } 
        } 
        return answer;
    }
};
