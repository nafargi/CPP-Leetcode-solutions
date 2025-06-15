class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxi = s, mini = s;

        if (maxi[0] != '9') {
            for (auto& i : maxi) {
                if (i == s[0])
                    i = '9';
            }
        } 
        else {
            char ele;
            for (int i = 0; i < maxi.length(); ++i) {
                if (maxi[i] != '9') {
                    ele = maxi[i];
                    break;
                }
            }

            for (auto& i : maxi) {
                if (i == ele)
                    i = '9';
            }
        }

        if (mini[0] != '1') {
            for (auto& i : mini) {
                if (i == s[0])
                    i = '1';
            }
        } 
        else {
            char ele;
            bool isZero = s.find('0');
            for (int i = 0; i < mini.length(); ++i) {
                if (isZero) {
                    if (mini[i] != '1' && mini[i] != '0') {
                        ele = mini[i];
                        break;
                    }
                } 
                else {
                    if (mini[i] != '1') {
                        ele = mini[i];
                        break;
                    }
                }
            }

            cout<<ele<<endl;

            for (auto& i : mini) {
                if (!isdigit(ele)) break;
                if (i == ele)
                    i = '0';
            }
        }

        return stoi(maxi) - stoi(mini);
    }
};
