Node* inOrderToBST(vector<int>& inOrder, int start, int end){
  if(start > end){
    return NULL;
  }
  int mid = (start + end) / 2;
  Node* root = new Node(inOrder[mid]);

  root -> left = inOrderToBST(inOrder, start, mid - 1);
  root -> right = inOrderToBST(inOrder, mid + 1, end);
  return root;
}