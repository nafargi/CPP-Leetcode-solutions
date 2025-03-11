class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,ans=0;
        int n=s.size();
        int a=-1,b=-1,c=-1;
        while(r<n){
            if(s[r]=='a') a=r;
            if(s[r]=='b') b=r;
            if(s[r]=='c') c=r;
            if(a!=-1 && b!=-1 && c!=-1) {
                ans+=min(a,min(b,c))+1;
            }
            r++;
        }
        return ans;
    }
};
