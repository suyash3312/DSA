class Solution {
public:
    void convertBTtoLL(TreeNode* root, TreeNode* &head){
        if(root == NULL){
            return;
        }
        convertBTtoLL(root -> right, head);
        convertBTtoLL(root -> left, head);
        root -> right = head;
        head = root;
        root->left = NULL;
    }
    void flatten(TreeNode* root) {
        TreeNode* head = NULL;
        convertBTtoLL(root, head);
    }
};