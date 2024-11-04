class Solution {
public:
    void getInOrder(TreeNode* root, int k, vector<int>& inOrder){
        if(root == NULL){
            return ;
        }
        getInOrder(root -> left, k, inOrder);
        inOrder.push_back(root -> val);
        getInOrder(root -> right, k, inOrder);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL){
            return true;
        }
        vector<int>inOrder;
        getInOrder(root, k, inOrder);
        int s = 0, e = inOrder.size() - 1;
        while(s != e){
            int sum = inOrder[s] + inOrder[e];
            if(sum == k){
                return true;
            }
            if(sum < k){
                s++;
            }
            if(sum > k){
                e--;
            }
        }
        return false;
    }
};