class Solution {
public:
    void InorderMapping(vector<int>& inorder, map<int, int>& valueToIndexMap){
        for(int i = 0; i < inorder.size(); i++){
            int index = i;
            int element = inorder[i];
            valueToIndexMap[element] = index;
        }
    }
    TreeNode* ConstructTreeUsingPreOrderAndInorderTraversal(map<int, int>& valueToIndexMap, vector<int> preorder, vector<int>& inorder, int &preIndex, int inOrderStart, int inOrderEnd, int size){
        if(preIndex >= size || inOrderStart > inOrderEnd){
            return NULL;
        }
        int element = preorder[preIndex];
        preIndex ++;
        TreeNode* root = new TreeNode(element);
        int position = valueToIndexMap[element];
        root -> left = ConstructTreeUsingPreOrderAndInorderTraversal(valueToIndexMap, preorder, inorder, preIndex, inOrderStart, position - 1, size);
        root -> right = ConstructTreeUsingPreOrderAndInorderTraversal(valueToIndexMap, preorder, inorder, preIndex, position + 1, inOrderEnd, size);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> valueToIndexMap;
        InorderMapping(inorder, valueToIndexMap);
        int inOrderStart = 0;
        int inOrderEnd = preorder.size() - 1;
        int preIndex = 0;
        int size = preorder.size();
        TreeNode* root = ConstructTreeUsingPreOrderAndInorderTraversal(valueToIndexMap, preorder, inorder, preIndex, inOrderStart, inOrderEnd, size);
        return root;
    }
};