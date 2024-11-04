class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int row = 0;
        int col = 0;
        queue<pair<TreeNode*, pair<int, int>>>q;
        map<int, multiset<pair<int, int>>>verticalMap;
        q.push({root, {row, col}});
        while(!q.empty()){
            TreeNode* front = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            verticalMap[col].insert({row, front -> val});
            
            if(front -> left != NULL){
                q.push({front -> left, {row + 1, col - 1}});
            }
            if(front -> right != NULL){
                q.push({front -> right, {row + 1, col + 1}});
            }
        }
        vector<vector<int>> finalAns;
        for(auto [col, nodes] : verticalMap){
            vector<int>colNodes;
            for(auto [row, value] : nodes){
                colNodes.push_back(value);
            }
            finalAns.push_back(colNodes);
        }
        return finalAns;
    }
};