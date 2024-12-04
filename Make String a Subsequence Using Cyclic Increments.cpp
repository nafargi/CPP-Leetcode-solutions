class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int st1=0,st2=0;
        while(st1<str1.length() && st2<str2.length()){
            if(str1[st1]==str2[st2] || str2[st2]-str1[st1]==1 || (str1[st1]=='z' && str2[st2]=='a')){
                st1++;
                st2++;
            }
            else{
                st1++;
            }
        }    
        if(st2==str2.length())
        return true;
        return false;   

    }
};
