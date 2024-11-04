class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* mergeLists(Node* a, Node* b){
        if(a==NULL){
            return b;
        }
        if(b==NULL){
            return a;
        }
        Node* dummy=new Node(-1);
        Node* current=dummy;
        
        while(a!=NULL && b!=NULL){
            if(a->data < b->data){
                current->bottom=a;
                a=a->bottom;
            }
            else{
                current->bottom=b;
                b=b->bottom;
            }
            current=current->bottom;
        }
        if(a!=nullptr){
            current->bottom=a;
        }else{
            current->bottom=b;
        }
        return dummy->bottom;
    }
    Node *flatten(Node *root) {
        // Your code here
            if(!root || !root->next){
                return root;
            }
            root->next=flatten(root->next);
            mergeLists(root, root->next);
    }
};
