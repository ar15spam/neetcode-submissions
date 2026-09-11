class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            res.push_back(q.back()->val);

            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }

        return res;
    }
};