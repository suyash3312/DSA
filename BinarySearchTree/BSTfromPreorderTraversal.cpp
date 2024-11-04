class Solution {
public:
    TreeNode* createBST(vector<int>& preorder, int min, int max, int& i){
        if(i >= preorder.size()){
            return nullptr;
        }
        TreeNode* root = nullptr;
        if(preorder[i] > min && preorder[i] < max){
            root = new TreeNode(preorder[i++]);
            root -> left = createBST(preorder, min, root -> val, i);
            root -> right = createBST(preorder, root -> val, max, i);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int  min = INT_MIN, max = INT_MAX;
        int i = 0;
        return createBST(preorder, min, max, i);
    }
};