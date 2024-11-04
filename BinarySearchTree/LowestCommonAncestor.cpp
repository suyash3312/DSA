class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(p -> val > root -> val && q -> val > root -> val){
            TreeNode* rightAns = lowestCommonAncestor(root -> right, p, q);
            return rightAns;
        }
        if(p -> val < root -> val && q -> val < root -> val){
            TreeNode* leftAns = lowestCommonAncestor(root -> left, p, q);
            return leftAns;
        }
        return root;
    }
};