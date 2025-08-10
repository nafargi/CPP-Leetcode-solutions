class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> nd(10, 0);
        string ns = to_string(n);
        for(int i = 0; i < ns.size(); i++){
            nd[ns[i] - '0']++;
        }

        for(int i = 0; i <= 31; i++){
            int num = (1 << i);

            vector<int> dc(10, 0);

            string s = to_string(num);
            if(s.size() != ns.size()) continue;

            for(int j = 0; j < s.size(); j++){
                dc[s[j] - '0']++;
            }

            if(dc == nd) return true;
           
        }
        return false;
    }
};
