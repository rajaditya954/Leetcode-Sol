class Solution {
public:
    bool isBST(TreeNode* root, long long low, long long high) {
        if (root == NULL)
            return true;

    
        if (root->val <= low || root->val >= high)
            return false;

        return isBST(root->left, low, root->val) &&
               isBST(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return isBST(root, LLONG_MIN, LLONG_MAX);
    }
};