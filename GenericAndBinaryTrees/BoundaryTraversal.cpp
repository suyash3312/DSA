class Solution {
public:
    void leftPart(Node* root, vector<int>& boundaryNodes){
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            return;
        }
        boundaryNodes.push_back(root -> data);
        if(root -> left != NULL){
            leftPart(root -> left, boundaryNodes);
        }else{
            leftPart(root -> right, boundaryNodes);
        }
    }
    
    void leafNodes(Node* root, vector<int>& boundaryNodes){
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            boundaryNodes.push_back(root -> data);
        }
        leafNodes(root -> left, boundaryNodes);
        leafNodes(root -> right, boundaryNodes);
    }
    
    void rightPart(Node* root, vector<int>& boundaryNodes){
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            return;
        }
        
        if(root -> right != NULL){
            rightPart(root -> right, boundaryNodes);
        }else{
            rightPart(root -> left, boundaryNodes);
        }
        boundaryNodes.push_back(root -> data);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>boundaryNodes;
        boundaryNodes.push_back(root -> data);
        leftPart(root -> left, boundaryNodes);
        leafNodes(root -> left, boundaryNodes);
        leafNodes(root -> right, boundaryNodes);
        rightPart(root -> right, boundaryNodes);
        return boundaryNodes;
    }
};