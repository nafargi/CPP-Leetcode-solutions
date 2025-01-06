class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.length();
        vector<int>res(n);
        int c=0,s=boxes[0]-'0';
        for(int i=1;i<n;i++){
            res[i]+=s+c;
            c=res[i];
            s+=(boxes[i]-'0');
        }
        c=0,s=boxes[n-1]-'0';
        for(int i=n-2;i>=0;i--){
            res[i]+=s+c;
            c=(s+c);
            s+=(boxes[i]-'0');
        }
        return res;
    }
};
