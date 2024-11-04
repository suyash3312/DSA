class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        Node* curr=head;
        while(curr!=NULL){
            Node* copy= new Node(curr->val);
            copy->next=curr->next;
            curr->next=copy;
            curr=copy->next;
        }
        curr=head;
        while(curr!=NULL){
            Node* copy=curr->next;
            copy->random= (curr->random!=NULL) ? curr->random->next : nullptr;
            curr=copy->next;
        }
        Node* dummy=new Node(0);
        Node* curr_copy=dummy;
        curr=head;
        while(curr!=NULL){
            Node* copy=curr->next;
            Node* nextNode=curr->next->next;
            curr_copy->next=copy;
            curr_copy=copy;
            curr->next=nextNode;
            curr=nextNode;
        }
        return dummy->next;
    }
};
