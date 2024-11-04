void reverse(Node* &head){
    Node* prev=NULL;
    Node* curr=head;
    while(curr!=NULL){
      Node* temp=curr->next;
      curr->next=prev;
      prev=curr;
      curr=temp;
    }
    head=prev;
  }