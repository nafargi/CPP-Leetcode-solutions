class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> sd(bank.size(), 0);
        if (bank.empty()) return 0;

        int row = 0;
        for (auto it : bank) {
            int count = 0;
            for (int i = 0; i < bank[0].length(); i++) {
                if (it[i] == '1') count++;
            }
            sd[row++] = count;
        }

        vector<int> sdwz;
        for (int i = 0; i < sd.size(); i++) {
            if (sd[i] != 0) sdwz.push_back(sd[i]);
        }

        int ans = 0;
        if (sdwz.size() <= 1) return ans;

        for (int i = 0; i < sdwz.size() - 1; i++) {
            ans += sdwz[i] * sdwz[i + 1];
        }

        return ans;
    }
};
