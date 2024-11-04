class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int, int> getMaxSumHelper(Node* root){
        if(root == NULL){
            return {0, 0};
        }
        auto lsum = getMaxSumHelper(root -> left);
        auto rsum = getMaxSumHelper(root -> right);
        int a = root -> data + lsum.second + rsum.second;
        int b = max(lsum.first, lsum.second) + max(rsum.first, rsum.second);
        return {a, b};
    }
    
    int getMaxSum(Node *root) 
    {
        // Add your code here
        auto ans = getMaxSumHelper(root);
        return max(ans.first, ans.second);
        
    }
};