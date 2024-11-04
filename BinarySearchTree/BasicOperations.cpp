#include <iostream>
#include <queue>
using namespace std;

class Node{
public:
  int data;
  Node* left;
  Node* right;

  Node(int data){
    this -> data = data;
    this -> left = NULL;
    this -> right = NULL;
  }
};

Node* insertNodesInBST(Node* root, int data){
  if(root == NULL){
    root = new Node(data);
    return root;
  }
  if(data > root -> data){
    root -> right = insertNodesInBST(root -> right, data);
  }else{
    root -> left = insertNodesInBST(root -> left, data);
  }
  return root;
}

void createBST(Node* &root){
  int data;
  cout << "Enter data : " << endl;
  cin >> data;
  while(data != -1){
    root = insertNodesInBST(root, data);
    cout << "Enter data : " << endl;
    cin >> data;
  }
}

void preOrderTraversal(Node* root){
  if(root == NULL){
    return;
  }
  cout << root -> data << " ";
  preOrderTraversal(root -> left);
  preOrderTraversal(root -> right);
}

void InOrderTraversal(Node* root){
  if(root == NULL){
    return;
  }
  InOrderTraversal(root -> left);
  cout << root -> data << " ";
  InOrderTraversal(root -> right);
}

void postOrderTraversal(Node* root){
  if(root == NULL){
    return;
  }
  postOrderTraversal(root -> left);
  postOrderTraversal(root -> right);
  cout << root -> data << " ";
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

bool SearchBST(Node* root, int target){
  if(root == NULL){
    return false;
  }
  if(root -> data == target){
    return true;
  }
  bool rightAns = false;
  bool leftAns = false;
  if(target > root -> data){
    rightAns = SearchBST(root -> right, target);
  }else{
    leftAns = SearchBST(root -> left, target);
  }
  return rightAns || leftAns;
}

Node* minVal(Node* root){
  if(root -> left == NULL){
    return root;
  }
  return minVal(root -> left);
}

Node* maxVal(Node* root){
  if(root -> right == NULL){
    return root ;
  }
  return maxVal(root -> right);
}

Node* deleteNodeInBST(Node* root, int target){
  if(root -> data == target){
    if(root -> left == NULL && root -> right == NULL){
      delete(root);
      return nullptr;
    }
    else if(root -> left == NULL && root -> right != NULL){
      Node* childSubTree = root -> right;
      delete(root);
      return childSubTree;
    }
    else if(root -> left != NULL && root -> right == NULL){
      Node* childSubTree = root -> left;
      delete(root);
      return childSubTree;
    }
    else{
      Node* leftMax = maxVal(root -> left);
      root -> data = leftMax -> data;
      root->left = deleteNodeInBST(root->left, leftMax -> data);
      return root;
    }
  }
  else{
    if(root -> data > target){
      root -> left = deleteNodeInBST(root -> left, target);
    }else{
      root -> right = deleteNodeInBST(root -> right, target);
    }
  }
  return root;
}

int main(){
  Node* root = NULL;
  createBST(root);
  levelOrderTraversal(root);
  
  // cout << "PreOrder Traversal : " ;
  // preOrderTraversal(root);
  // cout << endl;
  // cout << "InOrder Traversal : ";
  // InOrderTraversal(root);
  // cout << endl;
  // cout << "PostOrder Traversal : ";
  // postOrderTraversal(root);

  // int target;
  // cout << "Enter Value to be searched in BST : ";
  // cin >> target;
  // cout << endl;

  // while(target != -1){
  //   if(SearchBST(root, target)){
  //     cout << "Target Found" << endl;
  //   }else{
  //     cout << "Target Not Found" << endl;
  //   }
  //   cout << "Enter Value to be searched in BST : ";
  //   cin >> target;
  //   cout << endl;
  // }
  // cout << "MaxValue of BST : " ;
  // maxVal(root);
  // cout << endl;
  // cout << "MinValue of BST : " ;
  // minVal(root);
  int target;
  cout << "Enter Node to be deleted from BST : ";
  cin >> target;
  cout << endl;

  while(target != -1){
    deleteNodeInBST(root, target);
    levelOrderTraversal(root);
    cout << "Enter Node to be deleted from BST : ";
    cin >> target;
    cout << endl;
  }
}