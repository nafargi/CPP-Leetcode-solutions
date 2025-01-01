class Solution {
public:
    int maxScore(string s) {
        
        int prefixSum=0;
        for(char i:s){
            if(i=='1'){
                prefixSum+=1;
            }
        }

        int maxscore=INT_MIN;

        int prefSum=prefixSum;
        int zerosSum=0;

        int left=0;

        while(left<s.length()-1){
            if(s[left]=='0'){
                zerosSum+=1;
            }else if(s[left] == '1'){
                prefSum-=1;
            }
            
            maxscore= max(maxscore, zerosSum+prefSum);

            left++;

        }

        return maxscore;
    }
};





