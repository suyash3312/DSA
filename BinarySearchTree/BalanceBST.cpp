class Solution {
public:
    void findinorder(TreeNode* root, vector<int>& inorder){
        if(root == NULL){
            return ;
        }
        findinorder(root -> left, inorder);
        inorder.push_back(root -> val);
        findinorder(root -> right, inorder);
    }

    TreeNode* createBalancedBST(vector<int> inorder, int start, int end){
        if(start > end){
            return NULL;
        }
        int mid = (start + end) / 2;
        int element = inorder[mid];
        TreeNode* root = new TreeNode(element);
        root -> left = createBalancedBST(inorder, start, mid - 1);
        root -> right = createBalancedBST(inorder, mid + 1, end);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        findinorder(root, inorder);
        return createBalancedBST(inorder, 0, inorder.size() - 1);
    }
};