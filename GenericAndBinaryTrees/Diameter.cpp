class Solution {
public:
    int D = 0; 
    int height(TreeNode* root) {
        // base case
        if (root == NULL) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int currD = leftHeight + rightHeight;
        D = max(currD, D);
        return max(rightHeight, leftHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return D;
    }
};