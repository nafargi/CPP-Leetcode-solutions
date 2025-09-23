class Solution {
public:
    int str_to_int(string &s) {
        int i = 0;
        int n = s.size();
        int ans = 0;
        while (i < n) {
            int digit = s[i++] - '0';
            ans = ans * 10 + digit;
        }
        return ans;
    }

    vector<int> extract_revision_versions(string &s) {
        int n = s.size();
        vector<int> ans; 

        for (int i = 0; i < n; i++) {
         
            if (s[i] == '.') {
                int j = i + 1;
                string temp = "";
                while (j < n && s[j] != '.') {
                    temp += s[j++];
                }

                i = j - 1; 
                ans.push_back(str_to_int(temp)); 
            }
        }
        return ans;
    }

    int extract_version_number(string &s) {
        int n = s.size();
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') {
                break;
            }
            ans += s[i];
        }
        return str_to_int(ans);
    }

    int compareVersion(string version1, string version2) {
        int v1 = extract_version_number(version1), v2 = extract_version_number(version2);

      
        if (v1 != v2) {
            return v1 > v2 ? 1 : -1;
        } 

        vector<int> v_nums_1 = extract_revision_versions(version1), v_nums_2 = extract_revision_versions(version2);
        
        while (v_nums_1.size() != v_nums_2.size()) {
            if (v_nums_1.size() < v_nums_2.size()) {
                v_nums_1.push_back(0);
            } else {
                v_nums_2.push_back(0);
            }
        }
        
        for (int i = 0; i < v_nums_1.size(); i++) {
            if (v_nums_1[i] > v_nums_2[i]) {
                return 1;
            } else if (v_nums_1[i] < v_nums_2[i]) {
                return -1;
            }
        }

        return 0;
    }
};
