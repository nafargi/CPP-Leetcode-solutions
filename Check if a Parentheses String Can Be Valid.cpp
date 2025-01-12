class Solution {
public:
    static bool canBeValid(string& s, string& locked) {
        const int n=s.size();
        int p=0;
        if (n&1) return 0;
        for(int i=0; i<n; i++){
           if (locked[i]=='0' || s[i]=='(') p++;
           else p--;
           if (p<0) return 0;
        }
        p=0;
        for(int i=n-1; i>=0; i--){
            if (locked[i]=='0' || s[i]==')') p--;
            else p++;
            if (p>0) return 0;
        }
        return 1;
    }
};


auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
