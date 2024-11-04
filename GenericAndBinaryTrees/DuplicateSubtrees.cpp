class Solution {
public:
    vector<TreeNode*>ans;
    unordered_map<string, int>subtreeMap;
    string preOrder(TreeNode* root){
        if(root == NULL){
            return "N";
        }
        string curr = to_string(root -> val);
        string l = preOrder(root -> left);
        string r = preOrder(root -> right);
        string s = curr + "," + l + "," + r;
        if(subtreeMap.find(s) != subtreeMap.end()){
            if(subtreeMap[s] == 1){
                ans.push_back(root);
            }
            subtreeMap[s]++;
        }
        else{
            subtreeMap[s] = 1;
        }
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preOrder(root);
        return ans;
    }
};