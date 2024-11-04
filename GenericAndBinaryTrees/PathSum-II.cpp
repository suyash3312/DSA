class Solution {
public:
    void pathSumFinder(TreeNode* root, int targetSum, vector<int>& v, vector<vector<int>>& result){
        if(root == NULL){
            return;
        }
        v.push_back(root->val);
        if(root -> left == NULL && root -> right == NULL){
            if(targetSum == root -> val){
                result.push_back(v);
            }
        }
        else{
            targetSum -= root -> val;
            pathSumFinder(root -> left, targetSum, v, result);
            pathSumFinder(root -> right, targetSum, v, result);
        }
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return {};
        }
        vector<int>v;
        vector<vector<int>>result;
        pathSumFinder(root, targetSum, v, result);
        return result;
    }
};