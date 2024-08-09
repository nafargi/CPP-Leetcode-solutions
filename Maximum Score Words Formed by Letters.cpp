class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int letterCounts[26] = {0}; 
        for (char& letter : letters) {
            letterCounts[letter - 'a']++; 
        }
        int numWords = words.size(); 
        int maxScore = 0; 

        
        for (int combination = 0; combination < (1 << numWords); ++combination) {
            int wordCounts[26] = {0}; 
            for (int wordIndex = 0; wordIndex < numWords; ++wordIndex) {
                if (combination >> wordIndex & 1) {
                    for (char& letter : words[wordIndex]) {
                        wordCounts[letter - 'a']++; 
                    }
                }
            }

            bool isValidCombination = true; 
            int currentScore = 0; 
            for (int letterIndex = 0; letterIndex < 26; ++letterIndex) {
                if (wordCounts[letterIndex] > letterCounts[letterIndex]) {
                    isValidCombination = false;
                    break; 
                }
                currentScore += wordCounts[letterIndex] * score[letterIndex];
            }
            if (isValidCombination && maxScore < currentScore) {
                maxScore = currentScore;
            }
        }
        return maxScore;
    }
};
