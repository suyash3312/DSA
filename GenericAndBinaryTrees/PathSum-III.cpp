class Solution {
public:
    int ans = 0;
    void pathSumCounter(TreeNode* root, long long targetSum){
        if(!root){
            return;
        }
        if(targetSum == root -> val){
            ++ans;
        }
        pathSumCounter(root -> left, targetSum - root -> val);
        pathSumCounter(root -> right, targetSum - root -> val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            pathSumCounter(root, targetSum);
            pathSum(root -> left, targetSum);
            pathSum(root -> right, targetSum);
        }
        return ans;
    }
};