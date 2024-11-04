class Solution {
  public:
    
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        if(head==NULL){
            return head;
        }
        Node* curr=head;
        for(int i=0;i<m-1;i++){
            if(curr==NULL) return head;
            curr=curr->next;
        }
        if(curr==NULL){
            return head;
        }
        Node* prev=curr;
        curr=prev->next;
        for(int i=0;i<n;i++){
            if(curr==NULL){
                break;
            }
            Node* next=curr->next;
            delete curr;
            curr=next;
        }
        prev->next=curr;
        linkdelete(curr, n, m);
        return head;
    }
};