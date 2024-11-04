// METHOD : 1 // better approach
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == NULL) {
            return 0;
        }

        // If root->val is less than low, then only the right subtree could have values in range
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        
        // If root->val is greater than high, then only the left subtree could have values in range
        if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }
        
        // Otherwise, include root->val and search both subtrees
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};
//MY SOLUTION
class Solution {
public:
    int sum = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL){
            return 0;
        }
        rangeSumBST(root -> left, low, high);
        rangeSumBST(root -> right, low, high);
        if(root -> val >= low && root -> val <= high){
            sum = sum + root -> val;
        }
        return sum;
    }
};