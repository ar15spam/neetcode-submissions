class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q; 
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* front = q.front(); 
            q.pop();
            
            // If the current node is null, skip the rest of the loop
            if (front == nullptr) {
                continue;
            }
            
            TreeNode* l = front->left; 
            TreeNode* r = front->right; 
            front->right = l;
            front->left = r; 
            
            q.push(l); 
            q.push(r); 
        }        
        return root; 
    }
};