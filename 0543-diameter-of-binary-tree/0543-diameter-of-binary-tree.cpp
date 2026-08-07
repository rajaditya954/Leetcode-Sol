/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL) return 0;

        int lefth=height(root->left);
        int righth=height(root->right);

        return max(lefth, righth)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        int leftDia=diameterOfBinaryTree(root->left);
        int rightDia=diameterOfBinaryTree(root->right);
        int currDia=height(root->left)+height(root->right);

        return max(currDia, max(leftDia, rightDia));
    }
};