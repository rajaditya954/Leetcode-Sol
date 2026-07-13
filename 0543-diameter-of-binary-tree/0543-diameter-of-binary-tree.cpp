class Solution {
    int d = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        f(root);
        return d;        
    }

private:
    int f(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int l = f(root->left);
        int r = f(root->right);

        d = max(d, l + r);

        return 1 + max(l, r);
    }    
};