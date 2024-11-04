Node* convertDLLtoBST(Node* &head, int n){
  if(head == NULL || n <= 0){
    return NULL;
  }
  Node* leftSubtree = convertDLLtoBST(head, n/2);
  Node* root = head;
  root -> left = leftSubtree;
  head = head -> right;
  Node* rightSubtree = convertDLLtoBST(head, n - n/2 - 1);
  root -> right = rightSubtree;
  return root;
}