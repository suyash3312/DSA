class Solution {
public:
    pair<int, int> getMaxLoot(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }
        auto lsum = getMaxLoot(root->left);
        auto rsum = getMaxLoot(root->right);
        int a = root->val + lsum.second + rsum.second;
        int b = max(lsum.first, lsum.second) + max(rsum.first, rsum.second);
        return {a, b};
    }

    int rob(TreeNode* root) {
        auto ans = getMaxLoot(root);
        return max(ans.first, ans.second);
    }
};