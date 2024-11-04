class Solution {
public:
    void rightSideViewFinder(TreeNode* root, vector<int>& rightView, int level){
        if(root == NULL){
            return;
        }
        if(rightView.size() == level){
            rightView.push_back(root -> val);
        }
        rightSideViewFinder(root -> right, rightView, level + 1);
        rightSideViewFinder(root -> left, rightView, level + 1);
        //to view from left side just interchange the above recursive relations
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        int level = 0;
        rightSideViewFinder(root, rightView, level);
        return rightView;
    }
};