class Node{
    public:
    Node* right;
    Node* left;
    int data;
    
    Node(int val){
        this -> right = NULL;
        this -> left = NULL;
        data = val;
    }
};
class Solution{
    public:
    Node* insert(Node* root, int val, int& succ){
        if(root == NULL){
            return new Node(val);
        }
        if(root -> data <= val){
            root -> left = insert(root -> left, val, succ);
        }else{
            succ = root -> data;
            root -> right = insert(root -> right, val, succ);
        }
        return root;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int>ans(n, -1);
        Node* root = NULL;
        for(int i = n - 1; i >= 0; i--){
            int succ = -1;
            root = insert(root, arr[i], succ);
            ans[i] = succ;
        }
        return ans;
    }
};