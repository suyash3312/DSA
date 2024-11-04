class Solution
{
public:
    pair<int, int> heightSum(Node* root){
        if(!root){
            return {0, 0};
        }
        auto lh = heightSum(root -> left);
        auto rh = heightSum(root -> right);
        int sum = root -> data;
        if(lh.first == rh.first){
            sum += (lh.second > rh.second)? lh.second : rh.second;
        }
        else if(lh.first > rh.first){
            sum += lh.second;
        }
        else{
            sum += rh.second;
        }
        return {max(lh.first, rh.first) + 1, sum};
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        auto h = heightSum(root);
        return h.second;
    }
};