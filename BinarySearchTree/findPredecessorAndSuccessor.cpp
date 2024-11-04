class Solution
{
    public:
    void findSuccessor(Node* root, Node* &suc, int key){
        Node* curr = root;
        while(curr){
            if(curr -> key > key){
                suc = curr;
                curr = curr -> left;
            }else{
                curr = curr -> right;
            }
        }
    }
    void findPredecessor(Node* root, Node* &pre, int key){
        Node* curr = root;
        while(curr){
            if(curr -> key < key){
                pre = curr;
                curr = curr -> right;
            }else{
                curr = curr -> left;
            }
        }
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        pre = nullptr;
        suc = nullptr;
        findPredecessor(root, pre, key);
        findSuccessor(root, suc, key);
    }
};