class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
    int maxWord=0;
    for (size_t i=0; i< sentences.size();i++){
        int counter=count(sentences[i].begin(),sentences[i].end(),' ')+1;
        maxWord=max(maxWord,counter);
    }  
     return maxWord;
    }
};
