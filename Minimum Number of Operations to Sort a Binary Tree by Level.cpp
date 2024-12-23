class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root)
            return 0;

        queue<TreeNode*> q;
        q.push(root);
        int operations = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            vector<int> sort_level = level;
            sort(sort_level.begin(), sort_level.end());
            unordered_map<int, int> mp;

            for (int i = 0; i < level.size(); ++i) {
                mp[level[i]] = i;
            }

            for (int i = 0; i < level.size(); ++i) {
                while (level[i] != sort_level[i]) {
                    ++operations;
                    int cur = mp[sort_level[i]];
                    mp[level[i]] = cur;
                    swap(level[i], level[cur]);
                }
            }
        }

        return operations;
    }
};
