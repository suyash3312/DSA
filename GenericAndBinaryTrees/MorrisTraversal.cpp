class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> ans;
        while(curr){
            if(curr -> left == NULL){
                ans.push_back(curr -> val);
                curr =curr -> right;
            }
            else{
                TreeNode* pred = curr -> left;
                while(pred -> right != curr && pred -> right){
                    pred = pred -> right;
                }
                if(pred -> right == NULL){
                    pred -> right = curr;
                    curr = curr -> left;
                }
                else{
                    pred -> right = NULL;
                    ans.push_back(curr -> val);
                    curr = curr -> right;
                }
            }
        }
        return ans;
    }
};