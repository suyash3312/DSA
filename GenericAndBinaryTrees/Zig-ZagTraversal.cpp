class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*>q;
        vector<vector<int>>finalAns;
        q.push(root);
        bool LeftToRight = true;
        while(!q.empty()){
            int width = q.size();
            vector<int>nodes(width);
            for(int i = 0; i < width; i++){
                TreeNode* front = q.front();
                q.pop();
                int index = (LeftToRight)? i : width - i - 1;
                nodes[index] = front -> val;

                if(front -> left){
                    q.push(front -> left);
                }
                if(front -> right){
                    q.push(front -> right);
                }
            }
            LeftToRight = !LeftToRight;
            finalAns.push_back(nodes);
        }
        return finalAns;
    }
};