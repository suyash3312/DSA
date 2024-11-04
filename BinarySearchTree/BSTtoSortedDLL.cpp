#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

Node *insertNodesInBST(Node *root, int data) {
  if (root == NULL) {
    root = new Node(data);
    return root;
  }
  if (data > root->data) {
    root->right = insertNodesInBST(root->right, data);
  } else {
    root->left = insertNodesInBST(root->left, data);
  }
  return root;
}

void createBST(Node* &root) {
  int data;
  cout << "Enter data : " << endl;
  cin >> data;
  while (data != -1) {
    root = insertNodesInBST(root, data);
    cin >> data;
  }
}

void levelOrderTraversal(Node* root){
  queue<Node*>q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    Node* front = q.front();
    q.pop();

    if(front == NULL){
      cout << endl;
      if(!q.empty()){
        q.push(NULL);
      }
    }
    else{
      cout << front -> data << "  " ;
      if(front -> left != NULL){
        q.push(front -> left);
      }
      if(front -> right != NULL){
        q.push(front -> right);
      }
    }
  }
}

void convertBSTtoDLL(Node* root, Node* &head){
  if(root == NULL){
    return;
  }
  //RNL
  convertBSTtoDLL(root -> right, head);
  root -> right = head;
  if(head != NULL){
    head -> left = root ;  
  }
  head = root;
  convertBSTtoDLL(root -> left, head);
}

void printDLL(Node* &head){
  Node* temp = head;
  while(temp != NULL){
    cout << temp -> data << "<->";
    temp = temp -> right;
  }
  cout << "NULL";
}
int main(){
  Node* root = NULL;
  createBST(root);
  levelOrderTraversal(root);
  Node* head = NULL;
  convertBSTtoDLL(root, head);
  printDLL(head);
}