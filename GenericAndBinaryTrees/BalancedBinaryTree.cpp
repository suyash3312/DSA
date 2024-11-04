class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftHeight = height(root -> left);
        int rightHeight = height(root -> right);
        int finalAns = max(leftHeight, rightHeight) + 1;
        return finalAns;
    }
    bool isBalanced(TreeNode* root) {
        if(root ==  NULL){
            return true;
        }
        int leftHeight = height(root -> left);
        int rightHeight = height(root -> right);
        int diff = abs(leftHeight - rightHeight);
        bool currNode = (diff <=1);
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root -> right);

        if(currNode && leftAns && rightAns){
            return true;
        }else{
            return false;
        }
    }
};