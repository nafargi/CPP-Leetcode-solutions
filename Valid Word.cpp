class Solution {
public:
    bool check_vowel(int letter){
        if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u'){
            return true;
        }
        return false;
    }
    bool isValid(string word) {
        if(word.size() < 3) return false;
        int count_v = 0;
        int count_c = 0;
        for(int i = 0; i < word.size(); i++){
            if(!isalnum(word[i])) return false;
            if(isalpha(word[i])){
                if(check_vowel(tolower(word[i]))){
                    count_v++;
                }
                else{
                    count_c++;
                }
            }
        }
        if(!count_c || !count_v) return false;
        return true;
    }
};
