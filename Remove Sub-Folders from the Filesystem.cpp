class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;

        string check = folder[0];
        result.push_back(check);

        for(int i = 1; i < folder.size(); i++) {
            string s = folder[i];

            if(s.size() > check.size() && s.substr(0, check.size()) == check && s[check.size()] == '/') {
                continue; 
            } else {
                result.push_back(s);
                check = s; 
            }
        }

        return result;
    }
};
