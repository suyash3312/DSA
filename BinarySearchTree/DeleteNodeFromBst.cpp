class Solution {
public:
    TreeNode* maxVal(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }
        return maxVal(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if (root->val == key) {
            if (root->left == NULL && root->right == NULL) {
                delete (root);
                return nullptr;
            } else if (root->left == NULL && root->right != NULL) {
                TreeNode* childSubTree = root->right;
                delete (root);
                return childSubTree;
            } else if (root->left != NULL && root->right == NULL) {
                TreeNode* childSubTree = root->left;
                delete (root);
                return childSubTree;
            } else {
                TreeNode* leftMax = maxVal(root->left);
                root->val = leftMax->val;
                root->left = deleteNode(root->left, leftMax->val);
                return root;
            }
        } else {
            if (root->val > key) {
                root->left = deleteNode(root->left, key);
            } else {
                root->right = deleteNode(root->right, key);
            }
        }
        return root;
    }
};