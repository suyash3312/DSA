class Solution
{
public:
    void InOrderTraversal1(Node* root, vector<int>& inorder1){
    if(root == NULL){
        return;
    }
    InOrderTraversal1(root -> left, inorder1);
    inorder1.push_back(root -> data);
    InOrderTraversal1(root -> right, inorder1);
    }
    
    void InOrderTraversal2(Node* root, vector<int>& inorder2){
    if(root == NULL){
        return;
    }
    InOrderTraversal2(root -> right, inorder2);
    inorder2.push_back(root -> data);
    InOrderTraversal2(root -> left, inorder2);
    }

    int countPairs(Node* root1, Node* root2, int x)
    {
        vector<int>inorder1;
        vector<int>inorder2;
        InOrderTraversal1(root1, inorder1);
        InOrderTraversal2(root2, inorder2);
        int i = 0, j = 0, count = 0;
        while(i < inorder1.size() && j < inorder2.size()){
            if(x == (inorder1[i] + inorder2[j])){
                count++;
                i++;
                j++;
            }
            else if(x > (inorder1[i] + inorder2[j])){
                i++;
            }
            else{
                j++;
            }
        }
        return count;
    }
};